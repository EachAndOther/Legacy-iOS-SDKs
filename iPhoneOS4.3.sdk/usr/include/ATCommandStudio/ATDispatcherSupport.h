/*
 *  ATDispatcherSupport.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 5/17/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */
 
#include "ATResponse.h"
#include "ATRequest.h"
#include "NonCopyable.h"

#include <string>

#ifndef __ATDISPATCHERSUPPORT_H_
#define __ATDISPATCHERSUPPORT_H_

class ATCSResetInvoker
{
public:
	virtual ~ATCSResetInvoker() {}
	
	virtual void reset(const char *reasonString, bool wantCrashLog = true) = 0;
};

/// Base class for any class that has reference counted objects.
class ATCS_EXTERN_CLASS ATCSCounted
{
protected:
	virtual ~ATCSCounted();	// can only be destroyed via a decRef()
	
public:
	ATCSCounted();

	/// Don't call directly, use Reference
	void incRef();
	void incRef() const;

	/// Don't call directly, use Reference
	void decRef();
	void decRef() const;

private:
	volatile mutable int fRefCount;
};

class ATCS_EXTERN_CLASS ATCSAutoReferencer
{
public:
	ATCSAutoReferencer( ATCSCounted * counted )
		: fCounted( counted )
	{
		fCounted->incRef();
	}
	
	~ATCSAutoReferencer()
	{
		fCounted->decRef();
	}
	
protected:
	ATCSCounted * fCounted;
	
};
 
class Callback
{
public:
	Callback() {};
	virtual ~Callback() {};
	virtual void invoke(const ATResponse &response) = 0;
};

template <class T>
class ClassicMemberCallback : public Callback
{
public:
	ClassicMemberCallback(T *object, void (T::*function)(const ATResponse&))
		:	fObject(object),
			fFunction(function)
	{
	}
	
	virtual void invoke(const ATResponse &response)
	{
		(fObject->*fFunction)(response);	
	}
			
protected:
	T *fObject;
	void (T::*fFunction)(const ATResponse &response);
};

template <class T>
class CountedClassMemberCallback : public ClassicMemberCallback<T>
{
public:
	CountedClassMemberCallback(T *object, void (T::*function)(const ATResponse&))
		: ClassicMemberCallback<T>(object, function)
	{
	}
	
	virtual void invoke(const ATResponse &response)
	{
		ClassicMemberCallback<T>::invoke(response);
		ClassicMemberCallback<T>::fObject->decRef();
	}
};

template <class T>
class MemberCallback : public Callback
{
public:
	MemberCallback(T *object, void (T::*function)(const ATResponse&, void * cookie), void * cookie )
		:	fObject(object),
			fFunction(function),
			fCookie( cookie )
	{
	}
	
	virtual void invoke(const ATResponse &response)
	{
		(fObject->*fFunction)(response, fCookie);	
	}
			
protected:
	T *fObject;
	void (T::*fFunction)(const ATResponse &response, void * cookie);
	void * fCookie;
};

class QueuedCommand : public NonCopyable {

private:
	typedef enum
	{
		kTypeRegular,
		kTypeHaltingFlush,
		kTypeNonHaltingFlush
	}
	CommandType;

public:
	QueuedCommand(int timeout, bool resetOnTimeout, Callback* callback, const char* command, va_list args );
	QueuedCommand(Callback *callback, bool halt );	// Flush
	~QueuedCommand();
	
	bool isFlush( void ) const
	{
		return fType != kTypeRegular;
	}
	
	bool shouldHalt( void ) const
	{
		return fType == kTypeHaltingFlush;
	}
	
	Callback*		fCallback;
	std::string		fTag;				/// This may be different than the command if explicitly specified.
	CommandType		fType;
	ATRequest		fRequest;
	int 			fTimeout;			/// Time to wait for a response, in milliseconds
	bool			fResetOnTimeout;
	bool			fCancelled;
	bool			fSendCancelByte;
	int				fCommandId;
};

typedef int (*PayloadParser)(const ATResponse&, const unsigned char *data, int length);

struct UnsolicitedHandler : public NonCopyable {
	UnsolicitedHandler(const char *_tag, Callback *_callback, bool _isMultiLine, 
		PayloadParser _payloadParser)
		:	tag(_tag),
			callback(_callback),
			isMultiLine(_isMultiLine),
			payloadParser(_payloadParser) {}

	virtual ~UnsolicitedHandler()
	{
		delete callback;
	}

	std::string	tag;
	Callback*	callback;
	bool		isMultiLine;
	PayloadParser payloadParser;
};

struct CountedClassUnsolicitedHandler : public UnsolicitedHandler
	{
		CountedClassUnsolicitedHandler(const char *_tag, Callback *_callback, bool _isMultiLine, 
			PayloadParser _payloadParser, ATCSCounted &_object)
			:	UnsolicitedHandler(_tag, _callback, _isMultiLine, _payloadParser),
				object(_object) {}

		virtual ~CountedClassUnsolicitedHandler()
		{
			object.decRef();
		}
		
		ATCSCounted &object;
};


#endif
