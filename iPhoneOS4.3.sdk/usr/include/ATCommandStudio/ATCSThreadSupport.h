/*
 *  ATCSThreadSupport.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 5/17/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

//
//
//    Copyright (c) 2005-2006 Apple Computer, Inc.
//    All rights reserved.
//
//    This document is the property of Apple Computer, Inc. It is
//    considered confidential and proprietary information.
//
//    This document may not be reproduced or transmitted in any form,
//    in whole or in part, without the express written permission of
//    Apple Computer, Inc.
//

#ifndef __ATCSTHREAD_SUPPORT_H__
#define __ATCSTHREAD_SUPPORT_H__

#include "ATCSDefines.h"

#define ASSERT_LOCKED(mutex) CSI_ASSERT((mutex).isLocked());
#define ASSERT_UNLOCKED(mutex) CSI_ASSERT((mutex).isUnlocked());

class ATCS_EXTERN_CLASS ATCSMutex {
public:
	ATCSMutex(const char *name = "");
	~ATCSMutex();
	
	void lock();
	void unlock();

	// For debug macros only.  Do not call directly.
	bool isLocked();
	bool isUnlocked();
private:
	friend class ATCSCondition;
	void*	_internal;
};

/// This is a convenience class that will automatically lock a mutex when
/// it is created, and will automatically unlock it when it goes out of scope.
class ATCS_EXTERN_CLASS ATCSAutoLocker {
public:
	ATCSAutoLocker(ATCSMutex* mutex)
	: _mutex(mutex)
	{
		_mutex->lock();
	}
	
	~ATCSAutoLocker() {
		_mutex->unlock();
	}
	
private:
	ATCSMutex*	_mutex;
};

class ATCS_EXTERN_CLASS ATCSCondition {
public:
	ATCSCondition(const char *name);
	~ATCSCondition();

	enum WaitStatus {
		kInterrupted = -1,
		kSuccess     =  0,
		kTimeout     =  1
	};

	/// @param lock
	///    Mutex that will be released while waiting. It will be re-acquired
	///    when the condition is met.
	/// @param timeout
	///    - -1 wait forever
	///    - > 0 timeout in milliseconds
	/// @return
	///    - kInterrupted error / interrupted
	///    - kSuccess     success
	///    - kTimeout     wait timed out
	WaitStatus wait(ATCSMutex *lock, int timeout = -1);
	void broadcast();
	void signal();
	
private:
	void*	_internal;
};

// Returns an opaque pointer to a thread identifier.
ATCS_EXTERN void *ATCSThreadSpawn(const char *name, void* (*func)(void *), void* arg, bool detached = true);

// Joins the thread specified by the identifier.  Returns true on success.
ATCS_EXTERN bool ATCSThreadJoin( void *thread );

// Kills the thread specified by the identifier.  Returns true on success.
ATCS_EXTERN bool ATCSThreadKill( void *thread );

#endif
