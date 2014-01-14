/*
 *  ATCSFileDescriptorIPCDriver.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Sivasithambaresan on 7/4/08.
 *  Copyright 2008 Apple Inc. All rights reserved.
 *
 */

#ifndef _ATCSFILEDESCRIPTORIPCDRIVER_H_
#define _ATCSFILEDESCRIPTORIPCDRIVER_H_

#include "ATCSThreadedIPCDriver.h"

struct fd_set;

class ATCS_EXTERN_CLASS ATCSFileDescriptorIPCDriver: public ATCSThreadedIPCDriver
{
public:
	class ErrorHandler
	{
	public:
		virtual ~ErrorHandler() {};
	
	public:
		virtual void handleSelectFailure( int err ) = 0;
		virtual bool handleSelectException( int fd, int err ) = 0;
		virtual void handleInternalError( const char * reason ) = 0;
	};

protected:
	static const unsigned kMaxFDs		= 32;

	static const unsigned kDefaultReadBufferSize	= 2048;
	static const unsigned kDefaultWriteBufferSize	= 2048;
	
public:
	static ATCSFileDescriptorIPCDriver * create( bool autoStart = true, unsigned readBufferSize = kDefaultReadBufferSize, unsigned writeBufferSize = kDefaultWriteBufferSize );
	virtual ~ATCSFileDescriptorIPCDriver();

public:
	virtual void handleWriteReady( ATCSDispatcherCallback *dispatcher, void * cookie ) = 0;
	virtual void clearWriteReady( ATCSDispatcherCallback *dispatcher, void * cookie ) = 0;
	virtual void registerDispatcher( ATCSDispatcherCallback *dispatcher, void * cookie, void * & privateData ) = 0;
	virtual void unregisterDispatcher( ATCSDispatcherCallback *dispatcher, void * privateData ) = 0;	

protected:
	ATCSFileDescriptorIPCDriver();
	
	virtual void kickReader( void ) = 0;
	virtual void kickWriter( void ) = 0;
	
	virtual void writeWorkerMainLoop( WhichWorker me ) = 0;
	virtual void readWorkerMainLoop( WhichWorker me ) = 0;
	
public:
	virtual void setErrorHandler( ErrorHandler * handler ) = 0;
	
	virtual void startWorkers( void ) = 0;
	virtual void stopWorkers( void ) = 0;
	
	virtual void handleWriteReadyForAll() = 0;
	
	virtual void reconfigureWithMask( fd_set * mask ) = 0; 
};


#endif
