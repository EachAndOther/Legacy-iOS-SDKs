/*
 *  QMux.h
 *
 *  Created on 8/25/09.
 *  Copyright 2009 Apple Inc.. All rights reserved.
 *
 */

#ifndef _QMUX_H_
#define _QMUX_H_

#include <map>
#include <queue>
#include <vector>
#include <stdint.h>

#include "QMIClient.h"
#include "QMITransactionQueue.h"
#include "ATCSDispatcherCallback.h"  // for MUX driver callbacks
#include "ATCSThreadSupport.h"   // for ATCSMutex
#include "ATDispatcherSupport.h" // for ATCSResetInvoker
#include "ATCSIPCDriver.h"       // for ATCSIPCDriver

class QMIControl;
class QMuxQueueItem;

struct QMIMuxHeader
{
	unsigned char		interfaceType;
	unsigned short		length;				/* declared packed, compiler handles the fun */
	unsigned char		controlFlags;
	unsigned char		serviceType;
	unsigned char		clientID;
	
} __attribute__((__packed__));

ATCS_EXTERN bool QMuxDecodeHeader( QMIMuxHeader * header, const unsigned char * buffer, unsigned bufferLength );

/* 
 * This class is responsible for multiplexing and de-multiple all QMI messages 
 * to a pair of logical MUX channels (control and data). It is also handling 
 * the QMI Control service.
 */

class ATCS_EXTERN_CLASS QMux : public ATCSDispatcherCallback {
public:
	QMux(ATCSIPCDriver *driver, 
		 void *cookie,
		 const std::string & name,
		 ATCSResetInvoker * resetInvoker = NULL, 
		 bool canFlush = true, 
		 bool logIO = true);
	~QMux();

	// client management 
	void requestClientID(QMuxClientIface *client);
	void releaseClientID(QMuxClientIface *client);
	void cancelClientIDRequest(QMuxClientIface *client);

	// register client with QMUX SDU callback
	void registerClient(QMuxClientIface *client);

	void send(QMuxClientIface *client, QMITransactionID transactionId, const QMIServiceMsg &message);

	void invokeReset(const std::string &msg, bool throwException);

	typedef QMuxClientIface::QMIPowerProfile QMIPowerProfile;
	void enterPowerMode(dispatch_group_t group, QMIPowerProfile targetProfile);

	bool isPoweredDown() const;
	
public: // inherited from DispatchCallback
	virtual int handleReadData(const unsigned char *buff, unsigned length);
	virtual int getWriteData(unsigned char *buff, unsigned capacity);
	
	virtual void *getPrivateData() const;
	virtual const std::string &getDebugName() const;

public: 
	// hook up the IPC driver with the QMux
	// cookie here is the file descriptor of the ASM DLCI interface for the
	// QMux control channel
	// 
	void setDriverAndCookie(ATCSIPCDriver *driver, void *cookie);
	void dumpState() const;
	
	void resetQMux();
	void join();		// pushes all pending actions through all QMI clients
	void joinControl();	// pushes all pending actions through the control channels

	// bit 7 for sender type
	enum QMISenderType {
		QMI_SENDER_TYPE_CONTROL_POINT = 0x00,
		QMI_SENDER_TYPE_SERVICE       = 0x80
	};
	
	// general QMI service message type (bit 1-2)
	enum QMIServiceMessageType {
		QMI_SVC_MESSAGE_TYPE_REQUEST  = 0x00,
		QMI_SVC_MESSAGE_TYPE_RESPONSE = 0x02,
		QMI_SVC_MESSAGE_TYPE_INDICATE = 0x04,
		QMI_SVC_MESSAGE_TYPE_RESERVED = 0x06
	};

	// this is different from the general QMI service message type (bit 0-1)
	enum QMIControlMessageType {
		QMI_CTL_MESSAGE_TYPE_REQUEST     = 0x00,
		QMI_CTL_MESSAGE_TYPE_RESPONSE    = 0x01,
		QMI_CTL_MESSAGE_TYPE_INDICATE    = 0x02,
		QMI_CTL_MESSAGE_TYPE_RESERVED    = 0x03
	};

private:
	typedef enum 
	{
		kInitializing,
		kRunning,
		kPoweringDown,
		kPoweredDown,
		kPoweringUp,
		kOffline
	} QState;

	void handleControlIndication(QMITransactionID id, const QMIServiceMsg &indication);

	void handleSyncRequest(QMITransactionID id, const QMIServiceMsg &response);
	
	void resetQMux_nl();
	void clearQueues_nl();

	void powerUp(dispatch_group_t group);
	void finalizePowerUp(dispatch_group_t group);

	void powerDown(dispatch_group_t group, QMIPowerProfile targetProfile);
	void configurePowerDown(dispatch_group_t group, QMIPowerProfile targetProfile);
	void finalizePowerDown(dispatch_group_t group, QMIPowerProfile targetProfile);

	static unsigned char decodeByte(const unsigned char *& buf);
	static unsigned int  decodeWord(const unsigned char *& buf);

	int getWriteDataInternal(unsigned char *buffer, unsigned capacity);

	const char *getStateAsString() const;

	typedef std::queue<QMuxQueueItem *> TxQueue;

	// service type and client uniquely identifies a QMI control point
	typedef std::pair<const QMuxClientIface::QMIServiceType, const QMuxClientIface::QMIClientID> QMIUniqueClient;

	typedef std::map<QMIUniqueClient, QMuxClientIface*> ClientMap;

private:
	dispatch_queue_t	 fDispatchQueue;
	const std::string	 fDebugName;
	
	QMIControl			*fQMI_CTL_delegate;
	ClientMap			 fClientMap;

	ATCSIPCDriver		*fDriver;
	void				*fPrivateData;

	mutable ATCSMutex	 fMutex;
	ATCSLogger			*fLogger;
	ATCSResetInvoker	*fResetInvoker;
	bool				 fLogIO;
	void				*fCookie;
	QState				 fState;

	int					 fSendOffset;
	TxQueue				 fSendQueue;
};


/*
 * This queue item is to represent each QMI message from all the different clients, and write them
 * out to the DLCI channels.
 *
 * TODO: we may need the client id together with the queued item, in the event that we want to flush
 * the queue for this client id.
 */
class QMuxQueueItem : NonCopyable {		
public:
	QMuxQueueItem(QMIClient::QMIServiceType type, 
				  QMIClient::QMIClientID client, 
				  QMITransactionID transactionId, 
				  const QMIServiceMsg &message);
	~QMuxQueueItem();
	
	// to write out the QMUX message into the buffer
	unsigned int serialize(void *buffer, uint16_t offset, uint16_t length);

	uint16_t getLength() const;
	unsigned int getCurrentPos() const;
	QMITransactionID getTransactionId() const { return fTransactionId; }
	QMIClient::QMIServiceType getServiceType() const { return fServiceType; }
	QMIClient::QMIClientID getClientId() const { return fClientId; }

protected:
	void encodeByte(unsigned char byte);
	void encodeWord(uint16_t word);

private:

	inline unsigned int getTransactionHeaderSize() const;

	QMIClient::QMIServiceType	 fServiceType;
	QMIClient::QMIClientID		 fClientId;
	QMITransactionID			 fTransactionId;
	const QMIServiceMsg			*fMessage;				// may need to generalize to multiple messages in a single SDU
	uint16_t					 fQMuxMessageLength;
	unsigned char				*fQMuxMessageBuffer;
	unsigned int				 fCurrentPos;

};
#endif /* _QMUX_H_ */
