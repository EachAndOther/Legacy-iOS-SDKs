/*
 *  QMIClient.h
 *
 *  Created on 8/25/09.
 *  Copyright 2009 Apple Inc.. All rights reserved.
 *
 */

#ifndef _QMICLIENT_H_
#define _QMICLIENT_H_

#include <map>
#include <set>
#include <bitset>
#include <string>

#include "QMITransactionQueue.h"
#include "ATCSThreadSupport.h"	// for ATCSMutex

enum { QMUX_EXTRA_POWER_LOGGING = 1 };		// 0==off, 0==on

class QMux;
class QMIClient;
class QMIServiceMsg;

/* 
 * Client of QMIClient needs to pass an instance of this class to get notified of
 * any state change in QMIClient.
 */
class ATCS_EXTERN_CLASS QMIClientCallback {
public:	
	enum QMIPowerProfile {
		kQMIPower_Normal,
		kQMIPower_Low,
		kQMIPower_MaxValue
	};
	
	virtual ~QMIClientCallback() {}
	
	// Called only when registration succeeds; this is often the trigger for a Model to set up its state
	virtual void registered(QMIClient *) = 0;
	
	// Called when a prior registration has been revoked (eg, when a QMI client is revoked, or baseband resets)
	virtual void deregistered(QMIClient *) = 0;
	
	virtual void enterPowerMode(QMIClient *client, dispatch_group_t group, QMIPowerProfile targetProfile);

	virtual void exitPowerMode(QMIClient *client);
};


/* This class represents the abstract API that the QMux calls onto */
class QMuxClientIface {
public:
	typedef QMIClientCallback::QMIPowerProfile QMIPowerProfile;
	
	typedef unsigned char QMIClientID;
	static const unsigned char INVALID_CLIENT_ID = 0xff;
	
	enum QMIServiceType {
		QMI_CTL   = 0x00,		// QMI Control Service
		QMI_WDS   = 0x01,		// QMI Wireless Data Service
		QMI_DMS   = 0x02,		// QMI Device Management Service
		QMI_NAS   = 0x03,		// QMI Network Access Service
		QMI_WMS   = 0x05,		// QMI Wireless Messaging Service
		QMI_PDS   = 0x06,		// QMI Position Determination Service
		QMI_VS    = 0x09,		// QMI Voice Service
		QMI_AUDIO = 0xE1,		// QMI Audio Service (0xE1 = 225) 
		QMI_BSP   = 0xE2,		// QMI Board Support Package Service (0xE2 = 226)
		QMI_CIQ   = 0xE3,		// QMI Carrier IQ Service (0xE3 = 227)
	};
		
	QMuxClientIface(QMIServiceType type);
	virtual ~QMuxClientIface() {}
	
	// Called when a client id request succeeds or fails
	virtual void handleClientIdRequest(QMITransactionID txid, const QMIServiceMsg &response) = 0;

	// Called for all received QMI responses messages for that client
	virtual void handleReceivedData(QMITransactionID txId, const QMIServiceMsg &response) = 0;
	
	// Called for all received QMI indications for that client
	virtual void handleReceivedIndication(const QMIServiceMsg &message) = 0;
	
	// Called for control indications (eg, client id revocation, sync)
	virtual void handleControlIndications(const QMIServiceMsg &message) = 0;
	
	// Called once a message is serialized out
	virtual void handleSentData(QMITransactionID txId) = 0;
	
	virtual void join(dispatch_group_t group) = 0;
	
	// Called when QMux is ready to go into/out of low-power mode
	//    profile: the profile being enabled
	//    group: a dispatch group to signal that the client is fully ready for power-down
	// returns a set of indications that should be enabled in this profile
	virtual void enterPowerMode(dispatch_group_t group, QMIPowerProfile profile) = 0;
	
	typedef std::set<QMIMessageID> IndSet;
	virtual void appendPowerModeSet(IndSet &set, QMIPowerProfile profile) const = 0;
	
	QMIClientID getClientID() const { return fClientId; }
	QMIServiceType getServiceType() const { return fServiceType; }
	bool shouldLogIO() const { return fShouldLogIO; }
	bool shouldResetOnTimeout() const { return fShouldResetOnTimeout; }
	
protected:
	static const int MAX_CLIENT_MESSAGES_SENT;
	static const int MAX_CONTROL_MESSAGES_SENT;

	friend class QMux;
	
	QMIClientID			 fClientId;
	const QMIServiceType fServiceType;
	bool				 fShouldLogIO;
	bool				 fShouldResetOnTimeout;
};

/*
 * This class represents a QMI control point. All clients of QMI services will 
 * communicate with the QMI services via this class.
 */
class ATCS_EXTERN_CLASS QMIClient : public QMuxClientIface {
public:
	static const unsigned kDefaultCommandTimeout = 25000;

	static const char * getServiceTypeAsString( QMIServiceType type );
	static const char * getShortServiceTypeAsString( QMIServiceType type );

	// factory method
	static QMIClient *requestClient(const std::string &name, 
									const QMIServiceType type, 
									QMux &transport, 
									QMIClientCallback *callbackObject);
	// public destructor
	~QMIClient();

	void releaseClient();
	void resetClient();
	bool isValid() const;
	void join();
	
	void setShouldLogIO(bool shouldLogIO);
	void setShouldResetOnTimeout(bool shouldReset);

	std::string getServiceTypeAsString() const;

	typedef void (^ResponseCallbackBlock)(const QMIServiceMsg &);
	
	void send(const QMIServiceMsg &request, ResponseCallbackBlock callbackBlock) { return send(request, kDefaultCommandTimeout, callbackBlock); }
	void send(const QMIServiceMsg &request, unsigned int timeout, ResponseCallbackBlock callbackBlock);
	QMITransactionID syncSend(const QMIServiceMsg &request, ResponseCallbackBlock callbackBlock) { return syncSend(request, kDefaultCommandTimeout, callbackBlock); }
	QMITransactionID syncSend(const QMIServiceMsg &request, unsigned int timeout, ResponseCallbackBlock callbackBlock);
	
	void registerUnsolicitedHandler(QMIMessageID messageId, ResponseCallbackBlock callbackBlock);
	
	// Register a callback when a given INDICATION is sent by the modem; by default the INDICATION will not be added to any power modes
	template <class T, typename QMIServiceMsgType>
	void registerUnsolicitedHandler(QMIMessageID messageId,
									T *callbackObject,
									void (T::*callbackMethod)(QMIServiceMsgType &));
	
	

	// Change whether a given INDICATION should be sent during the specified power mode; by default an IND does not wake the AP
	// The given messageId must have a handler (via registerUnsolicitedHandler) before calling this function.
	// The IND can be removed from the power mode by setting shouldWake to false.
	void addToPowerMode(QMIMessageID messageId, QMIClientCallback::QMIPowerProfile targetProfile, bool shouldWake = true);

	//
	// To send a message on a client, invoke one of the following send() functions:
	//
	//   To invoke "callbackObj->method(responseMsg)"
	//      send(qmiMsg, callbackObj, &CallbackObject::method);
	//      send(qmiMsg, callbackObj, &CallbackObject::method, timeout);
	//
	//   To invoke "callbackObj->method(responseMsg, cookie)"
	//      send(qmiMsg, callbackObj, &CallbackObject::method, cookie);
	//      send(qmiMsg, callbackObj, &CallbackObject::method, cookie, timeout);
	//
	// 'callbackObj' must be of type 'CallbackObject*'.
	//
	// 'cookie' is either a pointer (eg: any type 'C*') or non-pointer type (eg: std::auto_ptr<C>). 
	// For non-pointers, the object must be an lvalue with a suitable copy-constructor (which is invoked to 
	// construct the QCallback object)
	//
	// The 'timeout' argument is optional (and in milliseconds) with kDefaultCommandTimeout by default.
	// A timeout of '0' indicates "wait forever". 
	//
	// If no response is received from the client after 'timeout' milliseconds, then the callback
	// is invoked with an error (kInternalError and type==kTimeout). If the client is reset/revoked, 
	// the callback is invoked with an error (kInternalError and type==kCancelled).
	//
	// send dispatches immediately, whereas sendSync waits for a QMI transaction id to be assigned.

	// ASYNC: callback with no cookie
	template <class T, typename QMIServiceMsgType>
	void send(const QMIServiceMsg &request,
			  T *callbackObject,
			  void (T::*callbackMethod)(QMIServiceMsgType &),
			  unsigned int timeout = kDefaultCommandTimeout);	
	
	// ASYNC: callback with cookie
	template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType>
	void send(const QMIServiceMsg &request,
			  T *callbackObject,
			  void (T::*callbackMethod)(QMIServiceMsgType &, ArgType),
			  CookieType cookie,
			  unsigned int timeout = kDefaultCommandTimeout);	
	
	// ASYNC: callback with no cookie on const member function
	template <class T, typename QMIServiceMsgType>
	void send(const QMIServiceMsg &request,
			  const T *callbackObject,
			  void (T::*callbackMethod)(QMIServiceMsgType &) const,
			  unsigned int timeout = kDefaultCommandTimeout);	
	
	// ASYNC: callback with cookie on const member function
	template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType>
	void send(const QMIServiceMsg &request,
			  const T *callbackObject,
			  void (T::*callbackMethod)(QMIServiceMsgType &, ArgType) const,
			  CookieType cookie,
			  unsigned int timeout = kDefaultCommandTimeout);	

	// SYNC: callback with no cookie
	template <class T, typename QMIServiceMsgType>
	QMITransactionID syncSend(const QMIServiceMsg &request,
							  T *callbackObject,
							  void (T::*callbackMethod)(QMIServiceMsgType &),
							  unsigned int timeout = kDefaultCommandTimeout);	
	
	// callback with cookie
	template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType>
	QMITransactionID syncSend(const QMIServiceMsg &request,
							  T *callbackObject,
							  void (T::*callbackMethod)(QMIServiceMsgType &, ArgType),
							  CookieType cookie,
							  unsigned int timeout = kDefaultCommandTimeout);	

	// callback with no cookie on const member function
	template <class T, typename QMIServiceMsgType>
	QMITransactionID syncSend(const QMIServiceMsg &request,
							  const T *callbackObject,
							  void (T::*callbackMethod)(QMIServiceMsgType &) const,
							  unsigned int timeout = kDefaultCommandTimeout);	
	
	// callback with cookie on const member function
	template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType>
	QMITransactionID syncSend(const QMIServiceMsg &request,
							  const T *callbackObject,
							  void (T::*callbackMethod)(QMIServiceMsgType &, ArgType) const,
							  CookieType cookie,
							  unsigned int timeout = kDefaultCommandTimeout);	
	
	/* debug/logging only! blocking calls */
	int debugGetQueueSendableCount() const;
	int debugGetQueueSize() const;
	
private:
	QMIClient(const std::string &name, const QMIServiceType type, QMux &transport, QMIClientCallback *callbackObject);
				  
private: /* QMuxClientIface */
	virtual void handleClientIdRequest(QMITransactionID id, const QMIServiceMsg &response);
	virtual void handleControlIndications(const QMIServiceMsg &response);
	virtual void handleReceivedData(QMITransactionID txId, const QMIServiceMsg &message);
	virtual void handleReceivedIndication(const QMIServiceMsg &message);
	virtual void handleSentData(QMITransactionID txId);
	virtual void enterPowerMode(dispatch_group_t group, QMIPowerProfile profile);
	virtual void appendPowerModeSet(IndSet &set, QMIPowerProfile profile) const;
	virtual void join(dispatch_group_t group);

private:
	// handles QMI command timeout. The parameter is the message that did not get a response
	void handleQMITimeout(const QMIServiceMsg &cancelledMsg);

	void sendInternal(const QMIServiceMsg &request, QCallback *callbackMethod, int timeout);
	QMITransactionID syncSendInternal(const QMIServiceMsg &request, QCallback *callbackMethod, int timeout);
	void sendNotReady_nl(const QMIServiceMsg &request, QCallback *callbackMethod) const;
	void registerUnsolicitedHandlerInternal(QMIMessageID messageId, QCallback *callbackMethod);

	enum ClientState {
		kOffline,
		kInit,
		kReady,
		kReleased,
		kRevoked,
		kInvalid
	};
	void setState_nl(ClientState newState);
				 
	void resetClient_nl();
	void releaseClient_nl();
	void setDeregistered_nl();
	
	struct IndInfo {
		QCallback *callback;
		std::bitset<QMIClientCallback::kQMIPower_MaxValue> enabledProfiles;
	};
	typedef std::map<QMIMessageID, IndInfo> QMIIndicationsMap;
	
	mutable ATCSMutex	 fMutex;
	ATCSLogger			*fLogger;

	const std::string	 fName;
	ClientState			 fState;

	dispatch_queue_t	 fCallbackDispatch;
	QMITransactionQueue	*fTxQueue;
	QMux				*fTransport;

	QMIClientCallback	*fRequestCallback;  // callback for client creation request
	QMIIndicationsMap	 fIndicationsMap;
};

// template definitions

// callback with no cookie
template <class T, typename QMIServiceMsgType> inline
void QMIClient::send(const QMIServiceMsg &request,
					 T *callbackObject,
					 void (T::*callbackMethod)(QMIServiceMsgType &), 
					 unsigned int timeout)
{
	QCallback *callback = new MessageCallback<T, QMIServiceMsgType>(callbackObject, callbackMethod);
	return sendInternal(request, callback, timeout);
}

// callback with cookie
template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType> inline
void QMIClient::send(const QMIServiceMsg &request,
					 T *callbackObject,
					 void (T::*callbackMethod)(QMIServiceMsgType &, ArgType),
					 CookieType cookie,
									 unsigned int timeout )
{
	QCallback *callback = new CookieMessageCallback<T, CookieType, ArgType, QMIServiceMsgType>(callbackObject, callbackMethod, cookie);
	return sendInternal(request, callback, timeout);
}

// callback with no cookie on const member function
template <class T, typename QMIServiceMsgType> inline
void QMIClient::send(const QMIServiceMsg &request,
					 const T *callbackObject,
					 void (T::*callbackMethod)(QMIServiceMsgType &) const, 
					 unsigned int timeout)
{
	QCallback *callback = new MessageCallback<T, QMIServiceMsgType>(callbackObject, callbackMethod);
	return sendInternal(request, callback, timeout);
}


// callback with cookie on const member function
template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType> inline
void QMIClient::send(const QMIServiceMsg &request,
					 const T *callbackObject,
					 void (T::*callbackMethod)(QMIServiceMsgType &, ArgType) const,
					 CookieType cookie,
					 unsigned int timeout )
{
	QCallback *callback = new CookieMessageCallback<const T, CookieType, ArgType, QMIServiceMsgType>(callbackObject, callbackMethod, cookie);
	return sendInternal(request, callback, timeout);
}

// callback with no cookie
template <class T, typename QMIServiceMsgType> inline
QMITransactionID QMIClient::syncSend(const QMIServiceMsg &request,
									 T *callbackObject,
									 void (T::*callbackMethod)(QMIServiceMsgType &), 
									 unsigned int timeout)
{
	QCallback *callback = new MessageCallback<T, QMIServiceMsgType>(callbackObject, callbackMethod);
	return syncSendInternal(request, callback, timeout);
}

// callback with cookie
template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType> inline
QMITransactionID QMIClient::syncSend(const QMIServiceMsg &request,
									 T *callbackObject,
									 void (T::*callbackMethod)(QMIServiceMsgType &, ArgType),
									 CookieType cookie,
									 unsigned int timeout )
{
	QCallback *callback = new CookieMessageCallback<T, CookieType, ArgType, QMIServiceMsgType>(callbackObject, callbackMethod, cookie);
	return syncSendInternal(request, callback, timeout);
}

// callback with no cookie on const member function
template <class T, typename QMIServiceMsgType> inline
QMITransactionID QMIClient::syncSend(const QMIServiceMsg &request,
									 const T *callbackObject,
									 void (T::*callbackMethod)(QMIServiceMsgType &) const, 
									 unsigned int timeout)
{
	QCallback *callback = new MessageCallback<T, QMIServiceMsgType>(callbackObject, callbackMethod);
	return syncSendInternal(request, callback, timeout);
}


// callback with cookie on const member function
template <class T, typename QMIServiceMsgType, typename ArgType, typename CookieType> inline
QMITransactionID QMIClient::syncSend(const QMIServiceMsg &request,
									 const T *callbackObject,
									 void (T::*callbackMethod)(QMIServiceMsgType &, ArgType) const,
									 CookieType cookie,
									 unsigned int timeout )
{
	QCallback *callback = new CookieMessageCallback<const T, CookieType, ArgType, QMIServiceMsgType>(callbackObject, callbackMethod, cookie);
	return syncSendInternal(request, callback, timeout);
}

template <class T, typename QMIServiceMsgType> inline
void QMIClient::registerUnsolicitedHandler(QMIMessageID messageId,
										   T *callbackObject,
										   void (T::*callbackMethod)(QMIServiceMsgType &))
{
	QCallback *callback = new MessageCallback<T, QMIServiceMsgType>(callbackObject, callbackMethod);
	registerUnsolicitedHandlerInternal(messageId, callback);
}

#endif /* _QMICLIENT_H_ */

