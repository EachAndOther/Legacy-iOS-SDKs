/*
 *  ATCSTimer.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 7/1/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

#ifndef _TIMER_H_
#define _TIMER_H_

#include "NonCopyable.h"
#include "ATCSThreadSupport.h"

class ATCSLogger;
class ATCSTimerDriver;

class ATCS_EXTERN_CLASS ATCSTimer: public NonCopyable
{
public:
	ATCSTimer();
	~ATCSTimer();

	/// Set a timer to expire in some number of milliseconds
	/// @param relativeTimeoutMilliseconds how many milliseconds from now the timer
	///   should expire in.
	/// @param callbackObject Data to pass into the functor
	/// @param callbackFunction Callback functor to invoke when timer expires.
	template <class U>
	void set(int relativeTimeoutMilliseconds, U *callbackObject, void (U::*callbackFunction)());
	
	template <class U>
	void set(int relativeTimeoutMilliseconds, void * cookie, U *callbackObject, void (U::*callbackFunction)(void *));
	
	template <class U, class C>
	void set(int relativeTimeoutMilliseconds, C *cookie, U *callbackObject, void (U::*callbackFunction)(C *));
	
	/// @returns
	///   - true If the timer was pending when it was cancelled.
	///   - false If the timer already expired before cancel was called.
	bool cancel();

	/// Called once at boot time by internal code to initialize global timer
	/// resources.
	static void timerBootstrap( ATCSTimerDriver * driver = 0 );

private:
	class ATCS_PRIVATE_CLASS Callback
	{
	public:
		Callback() {}
		virtual ~Callback() {}
		virtual void invoke() = 0;
	};

	template <class T>
	class ATCS_PRIVATE_CLASS MemberCallback : public Callback 
	{
	public:
		MemberCallback(T *object, void (T::*function)())
			:	fObject(object),
				fFunction(function)
		{
		}
		
		virtual void invoke()
		{
			(fObject->*fFunction)();	
		}

	private:
		T *fObject;
		void (T::*fFunction)();
	};
	
	template <class T, class C>
	class ATCS_PRIVATE_CLASS CookieMemberCallback : public Callback
	{
	public:
		CookieMemberCallback(C *cookie, T *object, void (T::*function)(C *))
			:	fObject(object),
				fCookie(cookie),
				fFunction(function)
		{
		}
		
		virtual void invoke()
		{
			(fObject->*fFunction)( fCookie );	
		}

	private:
		T *fObject;
		C *fCookie;
		void (T::*fFunction)( C * );
	};

	void set(int relativeTimeoutMilliseconds, Callback* callback);
	bool cancel_nl();
	static void dispatchExpiredTimers();
	static void printTimerQueue();

	int fDeadline;
	bool fPending;
	
	Callback *fCallback;
	
	ATCSTimer *fNext;
	ATCSTimer **fPrev;
	
	static ATCSLogger * fLogger;
	
	static ATCSTimer *fATCSTimerList;
	static ATCSMutex fsTimerListLock;
	static ATCSTimerDriver *fsDriver;
};

template <class U> inline ATCS_PRIVATE
void ATCSTimer::set(int relativeTimeoutMilliseconds, U *callbackObject, void (U::*callbackFunction)())
{
	set(relativeTimeoutMilliseconds, new MemberCallback<U>(callbackObject, callbackFunction));
}

template <class U> inline ATCS_PRIVATE
void ATCSTimer::set(int relativeTimeoutMilliseconds, void * cookie, U *callbackObject, void (U::*callbackFunction)(void *))
{
	set(relativeTimeoutMilliseconds, new CookieMemberCallback<U, void>(cookie, callbackObject, callbackFunction));
}
template <class U, class C> inline ATCS_PRIVATE
void ATCSTimer::set(int relativeTimeoutMilliseconds, C *cookie, U *callbackObject, void (U::*callbackFunction)(C *))
{
	set(relativeTimeoutMilliseconds, new CookieMemberCallback<U, C>(cookie, callbackObject, callbackFunction));
}

class ATCSTimerDriver
{
public:
	typedef void (*Callback)();

	virtual ~ATCSTimerDriver() {}
	
	static ATCSTimerDriver * create( void );
	
	void setCallback(Callback callback)
	{
		fCallback = callback;
	}

protected:
	ATCSTimerDriver();

	void invokeCallback()
	{
		if (fCallback != 0)
			(*fCallback)();
	}

private:
	Callback fCallback;
	
public:
	virtual void setNextTimeout(int absoluteTimeoutMs);
	virtual int getCurrentTime() const;

private:
	static void *startATCSTimerDispatcher(void*);
	void timerDispatcher();

	ATCSMutex fLock;
	ATCSCondition fATCSTimerReady;
	int fNextTimeout;
	bool fPending;
};

#endif
