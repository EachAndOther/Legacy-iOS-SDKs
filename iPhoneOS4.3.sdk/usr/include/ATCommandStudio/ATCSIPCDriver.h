/*
 *  ATCSIPCDriver.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 5/17/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

#ifndef _ATCSIPCDRIVER_H_
#define _ATCSIPCDRIVER_H_

#include "ATCSDefines.h"

class ATCSDispatcherCallback;

class ATCS_EXTERN_CLASS ATCSIPCDriver
{
protected:
	friend class ATDispatcher;
	friend class QMux;

	void bootstrap( void );

	ATCSIPCDriver();
	virtual ~ATCSIPCDriver();

private:
	bool			fBootstrapped;
	
protected:
	bool isBootstrapped( void ) const
	{
		return fBootstrapped;
	};

public: 
	// virtuals to override

	virtual void bootstrapInternal( void );

	// These functions MUST NOT call back dispatcher synchronously:
	//   * registerDispatcher 
	//   * handleWriteReady 
	//   * clearWriteReady 
	// These functions MAY call back synchronously:
	//   * unregisterDispatcher 
	
	virtual void registerDispatcher( ATCSDispatcherCallback *dispatcher, void * cookie, void * & privateData ) = 0;			
	virtual void unregisterDispatcher( ATCSDispatcherCallback *dispatcher, void * privateData ) = 0;

	virtual void handleWriteReady( ATCSDispatcherCallback *dispatcher, void * cookie ) = 0;
	virtual void clearWriteReady( ATCSDispatcherCallback *dispatcher, void * cookie ) = 0;
	
	virtual void enterLowPower( void );
	virtual void exitLowPower( void );
};

#endif
