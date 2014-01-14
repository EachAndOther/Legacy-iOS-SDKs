/*
 *  ATCSThreadedIPCDriver.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 9/5/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

#ifndef _ATCSTHREADEDIPCDRIVER_
#define _ATCSTHREADEDIPCDRIVER_

#include "ATCSThreadSupport.h"
#include "ATCSException.h"
#include "ATCSIPCDriver.h"

class ATCS_EXTERN_CLASS ATCSThreadedIPCDriver: public ATCSIPCDriver
{
protected:	
	typedef enum
	{
		kNobody			= 0,
		kReadWorker		= 1UL << 0,
		kWriteWorker	= 1UL << 1,
		kBothWorkers	= kReadWorker | kWriteWorker
	}
	WhichWorker;

protected:
	ATCSThreadedIPCDriver();
	
public:
	void bootstrapInternal( bool startWorkers );
	
protected:
	virtual void tearDownInternal( void );

	virtual void registerDispatcher( ATCSDispatcherCallback *dispatcher, void * cookie, void * & privateData ) = 0;
	virtual void unregisterDispatcher( ATCSDispatcherCallback *dispatcher, void * privateData ) = 0;
	
	virtual void writeWorkerMainLoop( WhichWorker me ) = 0;
	virtual void readWorkerMainLoop( WhichWorker me ) = 0;
	
	virtual void kickReader( void ) = 0;
	virtual void kickWriter( void ) = 0;

protected:
	static void * readWorkerStatic( void * arg );
	static void * writeWorkerStatic( void * arg );
	
	void * readWorker( void );
	void * writeWorker( void );
	
	void signalWorkerStarted( WhichWorker me )
	{
		fRunningWorkers |= me;
		fWorkerStartRequested &= ~me;
		
		fWorkerCondition.signal();
	};
	
	void signalWorkerStopped( WhichWorker me )
	{
		fRunningWorkers &= ~me;
		fWorkerStopRequested &= ~me;
		
		fWorkerCondition.signal();
	};
	
	bool workerStopRequested( WhichWorker me )
	{
		return fWorkerStopRequested & me;
	};
	
	void waitForWorkerStart( WhichWorker who )
	{
		while( fWorkerStartRequested & who )
		{
			fWorkerCondition.wait( &fLock );
		} 
	}
	
	void waitForWorkerStop( WhichWorker who )
	{
		while( fWorkerStopRequested & who )
		{
			fWorkerCondition.wait( &fLock );
		}
	}
	
	WhichWorker stopWorkersIfNeeded( void )
	{
		WhichWorker runningWorkers = (WhichWorker)fRunningWorkers;
	
		if ( runningWorkers != kNobody )
		{
			stopWorkersInternal();
		}
		
		return runningWorkers;
	}
	
	void startWorkersIfNeeded_nl( WhichWorker whoToStart )
	{
		if ( whoToStart != kNobody )
		{
			startWorkersInternal();
		}
	}
	
	void startRemainingWorkers( void );
	void startRemainingWorkers_nl( void );
	
	void lock( void )
	{
		fLock.lock();
	}
	
	void unlock( void )
	{
		fLock.unlock();
	}
	
private:
	void startWorkersInternal( void );
	void stopWorkersInternal( void );
	
	void restartWorkersInternal( void )
	{
		stopWorkersInternal();
		startWorkersInternal();
	}

	
protected:
	ATCSMutex		fLock;

private:
	void		* fReaderThread;
	void		* fWriterThread;
		
	ATCSCondition	fWorkerCondition;
	
	unsigned	fRunningWorkers;
	unsigned	fWorkerStartRequested;
	unsigned	fWorkerStopRequested;
};

#endif
