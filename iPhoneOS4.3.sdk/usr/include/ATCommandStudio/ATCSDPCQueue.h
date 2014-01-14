#ifndef _ATCSDPCQUEUE_H_
#define _ATCSDPCQUEUE_H_

#include <queue>

#include "ATCSTimer.h"

class ATCS_EXTERN_CLASS ATCSDPCQueue
{
public:
	class Callback
	{
	public:
		Callback();
		virtual ~Callback(); 
		virtual void invoke() = 0;
		virtual unsigned getTimeout( void ) const = 0;
	};

protected:
	template <class T, class Cookie>
	class ATCS_PRIVATE_CLASS CookieMemberCallback : public Callback
	{
	public:
		CookieMemberCallback(unsigned timeout, Cookie* cookie, T *object, void (T::*function)(Cookie *))
			:	fObject(object),
				fFunction(function),
				fCookie(cookie),
				fTimeout(timeout)
		{
		}
		
		virtual void invoke()
		{
			(fObject->*fFunction)( fCookie );	
		}
		
		virtual unsigned getTimeout( void ) const
		{
			return fTimeout;
		}

	private:
		T *fObject;
		void (T::*fFunction)(Cookie * );
		
		Cookie *fCookie;
		unsigned fTimeout;
	};
	
	typedef std::queue<Callback *> CallbackQueue;

public:
	ATCSDPCQueue();
	~ATCSDPCQueue();
	
public:
	template <class U>
	void enqueue( void *cookie, U * object, void (U::*function)( void * ) );
	template <class U>
	void enqueue( unsigned timeout, void *cookie, U * object, void (U::*function)( void * ) );
	template <class U, class C>
	void enqueue( C *cookie, U * object, void (U::*function)( C * ) );
	template <class U, class C>
	void enqueue( unsigned timeout, C *cookie, U * object, void (U::*function)( C * ) );
	void enqueue( Callback * callback );
	
	void cancel( void );
	
private:
	void handleTimer( void );
	void startTimer( unsigned timeout );

private:
	ATCSTimer			fTimer;
	ATCSMutex			fMutex;
	bool				fActive;
	
	CallbackQueue		fQueue;
};

template <class U> inline 
void ATCSDPCQueue::enqueue( void *cookie, U * object, void (U::*function)( void * ) )
{
	enqueue<U, void>( 0, cookie, object, function );
}

template <class U> inline
void ATCSDPCQueue::enqueue( unsigned timeout, void *cookie, U * object, void (U::*function)( void * ) )
{
	enqueue<U, void>( timeout, cookie, object, function );	
}

template <class U, class Cookie> inline
void ATCSDPCQueue::enqueue( Cookie *cookie, U * object, void (U::*function)( Cookie * ) )
{
	enqueue( 0, cookie, object, function );
}

template <class U, class Cookie> inline
void ATCSDPCQueue::enqueue( unsigned timeout, Cookie *cookie, U * object, void (U::*function)( Cookie * ) )
{
	enqueue( new CookieMemberCallback<U, Cookie>( timeout, cookie, object, function ) );	
}

#endif
