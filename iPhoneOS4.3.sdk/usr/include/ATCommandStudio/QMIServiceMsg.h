/*
 *  QMIServiceMessage.h
 *  ATCommandStudio
 *
 *  Created by HIRAL SHAH on 8/27/09.
 *  Copyright 2009 Apple Inc.. All rights reserved.
 *
 */



#ifndef __QMI_MSG_H__
#define __QMI_MSG_H__


#include <vector>
#include <stdint.h>
#include "TLV.h"
#include "ATDispatcherSupport.h"


#define QMI_RESULT_SUCCESS			0x0000
#define QMI_RESULT_FAILURE			0x0001
#define TLV_TYPE_FOR_RESULT_CODE	0x02

typedef uint16_t QMIMessageID;
typedef uint16_t QMITransactionID;

static const QMITransactionID INVALID_TRANSACTION_ID = 0;

/* QMIServiceMsg: 
 
 This is the class which stores one QMI message which has to be sent/recieved. 
 It consists of the message ID, length and a vector of Tlvs contained
 in that message. This is the object which gets dispatched to and from
 the underlying control point/service.  
 
 */
class ATCS_EXTERN_CLASS QMIServiceMsg : public ATCSCounted, NonCopyable
{
	typedef std::vector<Tlv*> TlvList;
public:
	// 2 bytes Msg ID + 2 bytes length
	static const uint16_t kQMIServiceMessageHeaderSize     = 0x04;

	enum ResultType
	{
		kQMI,				// error returned from baseband
		kInternalError		// internal error prevents the command from completion
	};
	
	enum InternalErrorType	// the values if result type == kInternalerror
	{
		kTimeout,
		kClientNotReady,
		kCancelled,
		kResultCodeMissing,
	};

	enum QMIErrorType {		// the values if result type == kQMI; these are defined by the QMI architecture
		QMI_ERR_NONE=0x0000,
		QMI_ERR_MALFORMED_MSG=0x0001,
		QMI_ERR_NO_MEMORY=0x0002,
		QMI_ERR_INTERNAL=0x0003,
		QMI_ERR_ABORTED=0x0004,
		QMI_ERR_CLIENT_IDS_EXHAUSTED=0x0005,
		QMI_ERR_UNABORTABLE_TRANSACTION=0x0006,
		QMI_ERR_INVALID_CLIENT_ID=0x0007,
		QMI_ERR_INVALID_HANDLE=0x0009,
		QMI_ERR_INVALID_PROFILE=0x000A,
		QMI_ERR_INVALID_PINID=0x000B,
		QMI_ERR_INCORRECT_PIN=0x000C,
		QMI_ERR_NO_NETWORK_FOUND=0x000D,
		QMI_ERR_CALL_FAILED=0x000E,
		QMI_ERR_OUT_OF_CALL=0x000F,
		QMI_ERR_NOT_PROVISIONED=0x0010,
		QMI_ERR_MISSING_ARG=0x0011,
		QMI_ERR_ARG_TOO_LONG=0x0013,
		QMI_ERR_INVALID_TX_ID=0x0016,
		QMI_ERR_DEVICE_IN_USE=0x0017,
		QMI_ERR_OP_NETWORK_UNSUPPORTED=0x0018,
		QMI_ERR_OP_DEVICE_UNSUPPORTED=0x0019,
		QMI_ERR_NO_EFFECT=0x001A,
		QMI_ERR_NO_FREE_PROFILE=0x001B,
		QMI_ERR_INVALID_PDP_TYPE=0x001C,
		QMI_ERR_INVALID_TECH_PREF=0x001D,
		QMI_ERR_INVALID_PROFILE_TYPE=0x001E,
		QMI_ERR_INVALID_SERVICE_TYPE=0x001F,
		QMI_ERR_INVALID_REGISTER_ACTION=0x0020,
		QMI_ERR_INVALID_PS_ATTACH_ACTION=0x0021,
		QMI_ERR_AUTHENTICATION_FAILED=0x0022,
		QMI_ERR_PIN_BLOCKED=0x0023,
		QMI_ERR_PIN_PERM_BLOCKED=0x0024,
		QMI_ERR_UIM_NOT_INITIALIZED=0x0025,
		QMI_ERR_MAX_QOS_REQUESTS_IN_USE=0x0026,
		QMI_ERR_INCORRECT_FLOW_FILTER=0x0027,
		QMI_ERR_NETWORK_QOS_UNAWARE=0x0028,
		QMI_ERR_INVALID_QOS_ID=0x0029,
		QMI_ERR_NUM_QOS_IDS=0x002A,
		QMI_ERR_FLOW_SUSPENDED=0x002C,
		QMI_ERR_INVALID_DATA_FORMAT=0x002D,
		QMI_ERR_INVALID_ARG=0x0030,
		QMI_ERR_INVALID_TRANSITION=0x003C,
		QMI_ERR_INVALID_QMI_CMD=0x0047,
		QMI_ERR_INFO_UNAVAILABLE=0x004A
	};

public:	
	/* Factory methods to always create the object on heap */
	//   -- Messages to send to the baseband
	static QMIServiceMsg* create(uint16_t msgID);

	//   -- Messages received from the baseband
	static const QMIServiceMsg* create(const void *buf, uint16_t buf_length);

	//   -- Dummy error messages to substitute for messages that will never come from the baseband
	static const QMIServiceMsg* create(uint16_t msgID, ResultType type, InternalErrorType error);
		

	uint16_t getTotalLength() const { return fMsgLength + getHeaderSize(); }
	QMIMessageID getMsgID() const { return fMsgID; }
	
	// get the TLV identified by the type
	/*const*/ Tlv *getTlv(uint8_t type) const;
	Tlv *getTlv(uint8_t type);
	
	// Iterators to iterate over all Tlv's
	typedef TlvList::const_iterator TlvIterator;
	TlvIterator tlvBegin() const { return fTlvList.begin(); }
	TlvIterator tlvEnd()   const { return fTlvList.end(); }


public:	// -- Sent Message Interface: should not be called on received/dummy messages
	Tlv::Writer createTlv(uint8_t type, uint16_t length);	// Creates a zero-initialized Tlv with the given type, returns a Writer than can be used to modify the Tlv

	void setMsgID(uint16_t msgID) { fMsgID = msgID; }

	std::vector<char> serialize() const;
	void serialize(void *buffer, size_t bufferLen) const;
	

public:	// -- Received Message Interface: should not be called on send messages
	bool isError() const;
	uint16_t getResultCode() const { return fResultCode; }
	QMIServiceMsg::ResultType getResultType() const { return fResultType; }
	const char *getErrorString() const;


public: // DEPRECATED FUNCTIONS
	void addTlv(Tlv *value);								// use createTlv instead
	void resetIterator() { fIter = fTlvList.begin(); }		// use tlvBegin/tlvEnd instead
	Tlv *getTlv();											// use tlvBegin/tlvEnd instead; get the next TLV (based on the fIter)
	
	uint16_t getLength() const { return fMsgLength; }

private:
	uint16_t		fMsgID;		// Type of message send/recv
	uint16_t		fMsgLength;	// Length of all the TLVs; does not include Tx id and other fields

	TlvList			fTlvList;	// List of TLVs for the message

	// Members that only apply to received/dummy messages
	ResultType		fResultType;    // QMI or internal
	uint16_t		fResultCode;	// Error code when the response has error

	// Deprecated members that will be removed shortly
	TlvIterator		fIter;			// Iterator to point to the next Tlv

private:
	static uint8_t	decodeByte(const void *buffer);
	static uint16_t	decodeWord(const void *buffer);
	static void		encodeByte(char **buffer, uint8_t byte);
	static void		encodeWord(char **buffer, uint16_t word);
	static const uint16_t getHeaderSize() { return kQMIServiceMessageHeaderSize; }
	void setErrorValues();

	/* Constructors */
	QMIServiceMsg(uint16_t msgID);
	QMIServiceMsg(const void *buf, uint16_t buf_length);
	QMIServiceMsg(uint16_t msgID, ResultType type, InternalErrorType error);
	/* Private dtor: can only be deleted via decRef */
	~QMIServiceMsg();
};

#endif /* __QMI_MSG_H__ */

