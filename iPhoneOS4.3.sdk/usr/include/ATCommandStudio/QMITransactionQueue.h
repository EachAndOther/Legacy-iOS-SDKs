/*
 *  QMITransactionQueue.h
 *
 *  Created on 8/26/09.
 *  Copyright 2009 Apple Inc.. All rights reserved.
 *
 */

#ifndef _QMITRANSACTIONQUEUE_H_
#define _QMITRANSACTIONQUEUE_H_

#include <list>
#include <stdint.h>

#include "QMIServiceMsg.h"
#include "ATCSThreadSupport.h"	// for ATCSMutex
#include <dispatch/dispatch.h>

class QMux;
class QMuxClientIface;
class QMIControl;

class QCallback {
public:
	QCallback() {};
	virtual ~QCallback() {};

	// id is the transaction id
	// response is the QMI service messages
	virtual void invoke(QMITransactionID id, const QMIServiceMsg &response) = 0;
};

// This callback is for clients for QMux
template <class T, typename QMIServiceMsgType = const QMIServiceMsg>
class PayloadCallback : public QCallback {
public:
	PayloadCallback(T *object, void (T::*function)(QMITransactionID id, QMIServiceMsgType &response))
	:	fObject(object), fFunction(function)
	{}
	
	virtual void invoke(const QMITransactionID id, const QMIServiceMsg &response)
	{
		(fObject->*fFunction)(id, const_cast<QMIServiceMsgType&>(response));	
	}

protected:
	T *fObject;
	void (T::*fFunction)(QMITransactionID id, QMIServiceMsgType &response);
};

// This callback is for clients of QMIClient. 
template <class T, typename QMIServiceMsgType = const QMIServiceMsg>
class MessageCallback : public QCallback {
public:
	MessageCallback(T *object, void (T::*function)(QMIServiceMsgType &response))
	:	fObject(object), fFunction(function)
	{}
	
	virtual void invoke(const QMITransactionID id, const QMIServiceMsg &response)
	{
		(fObject->*fFunction)(const_cast<QMIServiceMsgType&>(response));	
	}
	
protected:
	T *fObject;
	void (T::*fFunction)(QMIServiceMsgType &response);
};

template <typename T> struct strip_ref     { typedef T storage_type; };
template <typename T> struct strip_ref<T&> { typedef T storage_type; };

// This callback (with cookie) is for clients of QMIClient.
//   'T' is the callback object type
//   'Cookie' is the value type of the callback object (ie, the type physically stored inside this CookieMessageCallback object)
//   'CookieArg' is the arg type of the callback method; usually this is the same as 'Cookie'
template <class T, class Cookie, class CookieArg = Cookie, typename QMIServiceMsgType = const QMIServiceMsg>
class CookieMessageCallback : public QCallback {
public:
	typedef typename strip_ref<Cookie>::storage_type CookieObj;	 // strip off the reference if there was one
	
	CookieMessageCallback(T *object, void (T::*function)(QMIServiceMsgType &response, CookieArg cookie), Cookie cookie)
	:	fObject(object), fFunction(function), fCookie(cookie)
	{}
	
	virtual void invoke(const QMITransactionID id, const QMIServiceMsg &response)
	{
		(fObject->*fFunction)(const_cast<QMIServiceMsgType&>(response), fCookie);	
	}
		
protected:
	T *fObject;
	void (T::*fFunction)(QMIServiceMsgType &response, CookieArg cookie);
	CookieObj fCookie;
};

class QMITransaction : NonCopyable {
public:
	QMITransaction(QCallback *callback, const QMIServiceMsg &request, int timeout, QMITransactionID id);
	~QMITransaction();

public:
	void cancel();		// cancel the transaction: the timer and also invoke the current callback with error, if necessary
	void cancelTimer();	// abort the timer, if possible, but leave callback in place
	
	void startTimer(dispatch_time_t timerStartRef, void (^timeoutCallback)(QMITransactionID id));

	void invoke(dispatch_group_t group, dispatch_queue_t where, const QMIServiceMsg &message);

	QMITransactionID getTransactionId() const { return fTransactionId; }
	const QMIServiceMsg &getMessage() const { return fMessage; }
	
	bool wasSent() const { return fSent; }
	void setSent() { fSent = true; }
	
	const dispatch_source_t getTimer() const { return fTimer; }		// for test
	
	bool hasCallback() const { return fCallback; }

private:
	dispatch_source_t	 fTimer;
	
	QCallback			*fCallback;		// called when the transaction completes (due to response or due to error, including timeout)
	const QMIServiceMsg	&fMessage;
	int					 fTimeout;
	QMITransactionID	 fTransactionId;
	bool				 fSent;
};

class QMITransactionQueue : NonCopyable {
public:
	QMITransactionQueue(dispatch_queue_t callbackQueue, QMux *transport, QMuxClientIface *client);
	QMITransactionQueue(dispatch_queue_t callbackQueue, QMux *transport, QMIControl *client);
	~QMITransactionQueue();

	// Dispatch the QMI message to the callback for the given transaction
	void sendTransactionResponse(QMITransactionID txId, const QMIServiceMsg &message);
	
	// Cancels any transactions that have not yet been completed and mark the queue as "not sendable" (eg, a call to setSendable must happen later)
	void asyncClear();		// returns immediately
	void syncClear();		// blocks until all transactions are cancelled and all callbacks are complete
	
	// Places a marker in the the queues that signals the group once all operations have been pushed through
	void join(dispatch_group_t group);

	// Once the QMITransactionQueue has nothing more to do it will signal the group; all transactions previously sent and all those
	// sent up until a point when the queue is empty will be resolved. After the queue is successfully idle, it's "sendable" count
	// is set to zero. Further transactions will pend.
	void finishThenSignal(dispatch_group_t group, void (^prepareBlock)(dispatch_group_t) = NULL);
	
	// Signal that the given transaction has been transmitted and the timer should be started
	void startTimer(QMITransactionID id);

	// Create a transaction and return the txid of the transaction
	void asyncSend(QCallback *callback, const QMIServiceMsg &request, int timeout = -1);	// in milliseconds
	void asyncForceSend(QCallback *callback, const QMIServiceMsg &request, int timeout = -1);	// in milliseconds
	QMITransactionID syncSend(QCallback *callback, const QMIServiceMsg &request, int timeout = -1);	// in milliseconds
	QMITransactionID syncForceSend(QCallback *callback, const QMIServiceMsg &request, int timeout = -1);	// in milliseconds

	// Begin sending messages to the QMux
	void setSendable(int maxOutstanding);
	
	// Dispatch a block in the context of the QMITransactionQueue's dispatch queue
	void dispatchCallback(QCallback *callback, const QMIServiceMsg &msg) const;
	
	int debugGetQueueSendableCount() const;
	int debugGetQueueSize() const;

private:
	dispatch_queue_t	fDispatchQueue;		// modifications to the transactions go here, which dispatch queues out to the queue given by ctor
};

#endif /* _QMITRANSACTIONQUEUE_H_ */
