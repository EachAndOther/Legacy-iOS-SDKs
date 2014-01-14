/*
 *  ATDispatcher.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 5/17/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */
 
#ifndef __ATDispatcher_H__
#define __ATDispatcher_H__
 
#include <stdarg.h>

#include "ATCSDispatcherCallback.h"
#include "ATResponse.h"
#include "ATDispatcherSupport.h"
#include "ATCSException.h"

#define ATCS_VERSION	4

class ATCSIPCDriver;
class ATCSMutex;
class ATCSCondition;

class ATCS_EXTERN_CLASS ATDispatcher : public ATCSDispatcherCallback
{
public:
	static const unsigned kDefaultCommandTimeout = 45000;
	
private:
	static void bootstrap( void );
	
	static bool fsBootstrapped;
	
public:
	static ATDispatcher * create( ATCSIPCDriver * driver, void * cookie, const std::string & name,
		ATCSResetInvoker * resetInvoker = NULL, bool canFlush = true, bool logIO = true );
	
	virtual void setDriverAndCookie( ATCSIPCDriver * driver, void * cookie );

protected:
	ATDispatcher();
	
	virtual void init( ATCSIPCDriver * driver, void * cookie, const std::string & name );
	
public:
	virtual ~ATDispatcher();
	
public:
	// support specifically for CommCenter
	
	int send(const char *command, ...) __ATCSFormatCheck(2, 3);
	int send(int timeout, const char *command, ...) __ATCSFormatCheck(3, 4);
	template <class U>
	int send( void * callbackObject, void (U::*callbackMethod)(const ATResponse&), const char * fmt, ... )  __ATCSFormatCheck(3, 4);
	template <class U>
	int send( ATCSCounted *callbackObject, void (U::*callbackMethod)(const ATResponse&), const char* command, ... )  __ATCSFormatCheck(3, 4);
	template <class U>
	int send( unsigned timeout, void * callbackObject, void (U::*callbackMethod)(const ATResponse&), const char * fmt, ... )  __ATCSFormatCheck(4, 5);
	template <class U>
	int send( unsigned timeout, ATCSCounted *callbackObject, void (U::*callbackMethod)(const ATResponse&), const char* command, ... )  __ATCSFormatCheck(4, 5);
	
	int sendBulk(const char *command, ...) __ATCSFormatCheck(2, 3);
	template <class U>
	int sendBulk(int timeout, void *callbackObject, void (U::*callbackMethod)(const ATResponse&), const char* command, ...)  __ATCSFormatCheck(4, 5);
	template <class U>
	int sendBulk(int timeout, void *callbackObject, void (U::*callbackMethod)(const ATResponse&, void * cookie), void * cookie, const char* command, ...)  __ATCSFormatCheck(4, 5);
	template <class U>
	int sendBulk(int timeout, ATCSCounted *callbackObject, void (U::*callbackMethod)(const ATResponse&), const char* command, ...)  __ATCSFormatCheck(4, 5);
	
	template <class U>
	int sendExpectTag(void *callbackObject, void (U::*callbackMethod)(const ATResponse&), const char *tag, const char* command, ...)  __ATCSFormatCheck(4, 5);
	template <class U>
	int sendExpectTag(ATCSCounted *callbackObject, void (U::*callbackMethod)(const ATResponse&), const char *tag, const char* command, ...)  __ATCSFormatCheck(4, 5);
	
	int sendMultiLine(const char *multiLinePayload, const char *command, ...) __ATCSFormatCheck(3, 4);
	template <class U>
	int sendMultiLine(void *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *multiLinePayload, const char *command,
		...) __ATCSFormatCheck(6, 7);
	template <class U>
	int sendMultiLine(ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *multiLinePayload, const char *command,
		...) __ATCSFormatCheck(6, 7);
	template <class U>
	int sendMultiLine(int timeout, ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *multiLinePayload, const char *command,
		...) __ATCSFormatCheck(7, 8);
	
	template <class U>
	void registerUnsolicitedHandler(const char *tag, void *callbackObject, void (U::*callbackFunction)(const ATResponse&));
	template <class U>
	void registerUnsolicitedHandler(const char *tag, ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&));
	template <class U>
	void registerMultiLineUnsolicitedHandler(const char *tag, PayloadParser payloadParser, 
		void *callbackObject, void (U::*callbackFunction)(const ATResponse&));
	template <class U>
	void registerMultiLineUnsolicitedHandler(const char *tag, PayloadParser payloadParser, 
		ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&));
	
	template <class U>
	bool queueFlushNotification(void *callbackObject, void (U::*callbackMethod)(const ATResponse&), bool haltIfFlush = true);
	
	template <class U>
	bool queueFlushNotification(void *callbackObject, void (U::*callbackMethod)(const ATResponse&), void * cookie, bool haltIfFlush = true);

	virtual void enterQuiescentState( void ) = 0;

	virtual void exitQuiescentState( void ) = 0;
		
public:
	template <class U>
	int send( void * callbackObject, void (U::*callbackMethod)(const ATResponse&, void * cookie), void * cookie, const char * fmt, ... );
	
	template <class U>
	int send( void * callbackObject, void (U::*callbackMethod)(const ATResponse&, void * cookie), void * cookie, unsigned timeout, const char * fmt, ... );
	
	template <class U>
	void registerUnsolicitedHandler(const char *tag, void *callbackObject, void (U::*callbackFunction)(const ATResponse&, void * cookie), void * cookie );
		
	virtual bool cancelCommand(int id) = 0;
	
	ATResponse sendBlocking( const char * fmt, ... )
	{
		ATResponse r;
		va_list list;
		
		va_start( list, fmt );
		r =  sendBlockingInternal( kDefaultCommandTimeout, fmt, list );
		va_end( list );
		
		return r;
	}
	
	ATResponse sendBlocking( unsigned timeout, const char * fmt, ... )
	{
		ATResponse r;
		va_list list;
		
		va_start( list, fmt );
		r =  sendBlockingInternal( timeout, fmt, list );
		va_end( list );
		
		return r;
	}
		
	void handleSendBlocking( const ATResponse & response, void * cookie );
	
	virtual void setFlushable( bool flushable ) = 0;
	
	virtual void resetState( void ) = 0;
	
	virtual void dumpState( void ) = 0;
	
protected:
	virtual int queueCommandInternal(int timeout, bool resetOnTimeout, Callback *callback, const char *multiLinePayload, 
		const char *tag, const char *command, va_list args, bool haltIfFlush = true) = 0;
		
	virtual unsigned countUnsolicitedHandlers( const char *tag, bool isMultiline ) const = 0;
		
	virtual bool canFlush( void ) const = 0;
		
	virtual void registerUnsolicitedHandlerInternal( UnsolicitedHandler * handler ) = 0;
		
	ATResponse sendBlockingInternal( unsigned timeout, const char * fmt, va_list args );

	void tearDown( void );
		
    // inherited from DispatchCallback
public:
	virtual const std::string & getDebugName( void ) const
	{
		return fDebugName;
	};
	
	virtual void * getPrivateData( void ) const
	{
		return fPrivateData;
	};

	virtual int handleReadData( const unsigned char * buff, unsigned length ) = 0;
	virtual int getWriteData( unsigned char * buff, unsigned capacity ) = 0;
	
private:
	bool				fTornDown;
	
protected:
	std::string		 fDebugName;
	ATCSIPCDriver	*fDriver;
	void			*fPrivateData;
};

template <class U> inline
int ATDispatcher::send( void * callbackObject, void (U::*callbackMethod)(const ATResponse&, void * cookie), void * cookie, const char * fmt, ... )
{
	va_list list;
	
	va_start( list, fmt );
	
	MemberCallback<U> * cb = new MemberCallback<U>( static_cast<U *>(callbackObject), callbackMethod, cookie);
	
	int id = queueCommandInternal( kDefaultCommandTimeout,
		true,
		cb,
		"", NULL, fmt, list );
	
	va_end( list );
	
	return id;
}

template <class U> inline
int ATDispatcher::send( void * callbackObject, void (U::*callbackMethod)(const ATResponse&, void * cookie), void * cookie, unsigned timeout, const char * fmt, ... )
{
	va_list list;
	
	va_start( list, fmt );
	
	int id = queueCommandInternal( timeout,
		true,
		new MemberCallback<U>( static_cast<U *>(callbackObject), callbackMethod, cookie),
		"", NULL, fmt, list );
	
	va_end( list );
	
	return id;
}

template <class U> inline
void ATDispatcher::registerUnsolicitedHandler(const char *tag, void *callbackObject, 
	void (U::*callbackFunction)(const ATResponse&, void * cookie), void * cookie )
{

	MemberCallback<U> *pCallback = new MemberCallback<U>( static_cast<U *>(callbackObject), callbackFunction, cookie );
	UnsolicitedHandler *pHandler = new UnsolicitedHandler( tag, pCallback, false, NULL );
	
	registerUnsolicitedHandlerInternal( pHandler );
}

template <class U> inline
int ATDispatcher::send( void * callbackObject, void (U::*callbackMethod)(const ATResponse&), const char * fmt, ... )
{
	va_list list;
	
	va_start( list, fmt );
	
	ClassicMemberCallback<U> * cb = new ClassicMemberCallback<U>( static_cast<U *>(callbackObject), callbackMethod);
	
	int id = queueCommandInternal( kDefaultCommandTimeout,
		true,
		cb,
		"", NULL, fmt, list );
	
	va_end( list );
	
	return id;
}

template <class U> inline
int ATDispatcher::send(ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char* command, ...)
{
	callbackObject->incRef();

	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(kDefaultCommandTimeout, true, new CountedClassMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), "", NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::send( unsigned timeout, void * callbackObject, void (U::*callbackMethod)(const ATResponse&), const char * fmt, ... )
{
	va_list list;
	
	va_start( list, fmt );
	
	ClassicMemberCallback<U> * cb = new ClassicMemberCallback<U>( static_cast<U *>(callbackObject), callbackMethod);
	
	int id = queueCommandInternal( timeout,
		true,
		cb,
		"", NULL, fmt, list );
	
	va_end( list );
	
	return id;
}

template <class U> inline
int ATDispatcher::send(unsigned timeout, ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char* command, ...)
{
	callbackObject->incRef();
	
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(timeout, true, new CountedClassMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), "", NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendBulk(int timeout, void *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char* command, ...)
{
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(timeout, false, new ClassicMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), "", NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendBulk(int timeout, void *callbackObject, void (U::*callbackFunction)(const ATResponse&, void *), void * cookie, const char* command, ...)
{
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(timeout, false, new MemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction, cookie), "", NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendBulk(int timeout, ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char* command, ...)
{
	callbackObject->incRef();
	
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(timeout, false, new CountedClassMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), "", NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendExpectTag(void *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *tag,
	const char* command, ...)
{
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(kDefaultCommandTimeout, true, new ClassicMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), "", tag, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendExpectTag(ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *tag,
	const char* command, ...)
{
	callbackObject->incRef();
	
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(kDefaultCommandTimeout, true, new CountedClassMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), "", tag, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendMultiLine(void *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *multiLinePayload, const char *command,
	...)
{
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(kDefaultCommandTimeout, true, new ClassicMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), multiLinePayload, NULL, command, list);
	va_end(list);

	return id;
}

template <class U> inline
int ATDispatcher::sendMultiLine(ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *multiLinePayload, const char *command,
	...)
{
	callbackObject->incRef();
	
	va_list list;

	va_start(list, command);
	int id = queueCommandInternal(kDefaultCommandTimeout, true, new CountedClassMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), multiLinePayload, NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
int ATDispatcher::sendMultiLine(int timeout, ATCSCounted *callbackObject, void (U::*callbackFunction)(const ATResponse&), const char *multiLinePayload, const char *command,
	...)
{
	callbackObject->incRef();	
	va_list list;
	va_start(list, command);
	int id = queueCommandInternal(timeout, true, new CountedClassMemberCallback<U>(
		static_cast<U *>(callbackObject), callbackFunction), multiLinePayload, NULL, command, list);
	va_end(list);
	
	return id;
}

template <class U> inline
void ATDispatcher::registerUnsolicitedHandler(const char *tag, void *callbackObject, void (U::*callbackFunction)(const ATResponse&))
{
	ClassicMemberCallback<U> *pCallback = new ClassicMemberCallback<U>( static_cast<U *>(callbackObject), callbackFunction);
	UnsolicitedHandler *pHandler = new UnsolicitedHandler( tag, pCallback, false, NULL );
	
	registerUnsolicitedHandlerInternal( pHandler );
}

template <class U> inline
void ATDispatcher::registerUnsolicitedHandler( const char *tag, 
											   ATCSCounted *callbackObject, 
											   void (U::*callbackFunction)(const ATResponse&) )
{
	callbackObject->incRef();

	MemberCallback<U> *pCallback = new MemberCallback<U>( static_cast<U *>(callbackObject), callbackFunction );
	CountedClassUnsolicitedHandler *pHandler = new CountedClassUnsolicitedHandler( tag, pCallback, false, NULL,
																				   (*callbackObject) );
	registerUnsolicitedHandlerInternal( pHandler );
}

template <class U> inline
void ATDispatcher::registerMultiLineUnsolicitedHandler(const char *tag, PayloadParser payloadParser, 
	void *callbackObject,  void (U::*callbackFunction)(const ATResponse&))
{
	ClassicMemberCallback<U> *pCallback = new ClassicMemberCallback<U>( static_cast<U *>(callbackObject), callbackFunction );
	UnsolicitedHandler *pHandler = new UnsolicitedHandler( tag, pCallback, true, payloadParser );
	
	registerUnsolicitedHandlerInternal( pHandler );

	// Only one multi-line unsolicited handler can be registered currently.
	ATCSAssert( countUnsolicitedHandlers(tag, true), <=, 1 );
}

template <class U> inline
void ATDispatcher::registerMultiLineUnsolicitedHandler(const char *tag, PayloadParser payloadParser, 
	ATCSCounted *callbackObject,  void (U::*callbackFunction)(const ATResponse&))
{
	callbackObject->incRef();

	ClassicMemberCallback<U> *pCallback = new ClassicMemberCallback<U>( static_cast<U *>(callbackObject), callbackFunction );
	CountedClassUnsolicitedHandler *pHandler = new CountedClassUnsolicitedHandler( tag, pCallback, true, payloadParser,
																				   *static_cast<U *>(callbackObject) );	
	registerUnsolicitedHandlerInternal( pHandler );

	// Only one multi-line unsolicited handler can be registered currently.
	ATCSAssert( countUnsolicitedHandlers(tag, true), <=, 1 );
}

template <class U> inline
bool ATDispatcher::queueFlushNotification(void *callbackObject, void (U::*callbackMethod)(const ATResponse&), bool haltIfFlush)
{
	if ( !canFlush() ) {
		return false;
	}

	va_list list = 0; // silence build warning

	queueCommandInternal(0, false, new ClassicMemberCallback<U>(static_cast<U*>(callbackObject), callbackMethod),
		NULL, NULL, NULL, list, haltIfFlush);
		
	return true;
}


template <class U> inline
bool ATDispatcher::queueFlushNotification(void *callbackObject, void (U::*callbackMethod)(const ATResponse&), void * cookie, bool haltIfFlush)
{
	if ( !canFlush() ) {
		return false;
	}

	va_list list = 0; // silence build warning

	queueCommandInternal(0, false, new MemberCallback<U>(static_cast<U*>(callbackObject), callbackMethod, cookie),
		NULL, NULL, NULL, list, haltIfFlush);
		
	return true;
}

#endif
