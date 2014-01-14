/*
 *  TLV.h
 *  ATCommandStudio
 *
 *  Created by HIRAL SHAH on 8/27/09.
 *  Copyright 2009 Apple Inc.. All rights reserved.
 *
 */



#ifndef __TLV_H__
#define __TLV_H__


#include <string>
#include <stdint.h>
#include "NonCopyable.h"
#include "ATCSDefines.h"

#define QMI_TLV_HDR_SIZE         (3)

/* Tlv: 
 
 Tlv stands for type length value. Messages are composed of tlv's. 
 This class contains member data: type and length, and provides
 getters for this data. The value buffer gets created when an object
 is instantiated.
 
 */

class ATCS_EXTERN_CLASS Tlv : NonCopyable
{
	
public:
		
	/* Factory methods to always create the object on heap */
	static Tlv* create(uint8_t type, uint16_t length);
	static Tlv* create(uint8_t type, uint16_t length, const void *src);
	static Tlv* create(const Tlv& tlv);	
	
	~Tlv();
	
	uint16_t getLength() const { return fLength; }
	uint8_t getType() const { return fType; }
	const uint8_t * getValue() const { return fValue; }
	uint8_t * getValue() { return fValue; }

	class Writer {
		// These two definitions implement the "safe bool" idiom
		typedef void (Writer::*bool_type)() const;
		void this_type_does_not_support_comparisons() const {}
	public:
		Writer(Tlv *tlv) : fTlv(tlv), fIndex() {}
		Writer(const Writer &other) : fTlv(other.fTlv), fIndex(other.fIndex) {}

		Writer &operator=(const Writer &other) { fTlv = other.fTlv; fIndex = other.fIndex; return *this; }

		// Bool type to support code like "if (myWriter) {...}" to test whether the writer is valid
		operator bool_type() const { return (fTlv!=NULL) ? &Writer::this_type_does_not_support_comparisons : 0; }
			
		uint8_t getType() const { return fTlv->getType(); }
		void setType(uint8_t type) { fTlv->setType(type); }
		
		uint16_t getIndex() const { return fIndex; }
		void resetIndex() { fIndex = 0; }

		uint16_t getLength() const { return fTlv->getLength(); }
		uint16_t getRemainingBytes() const {return getLength() - fIndex;}
		
		void putByte(uint8_t value);
		void putWord(uint16_t value);
		void putDWord(uint32_t value);
		void putQWord(uint64_t value);
		void putFloat(float value);
		void putDouble(double value);
		void putByteAt(uint8_t value, uint16_t index);
		uint16_t putWordAt(uint16_t value, uint16_t index);
		uint16_t putDWordAt(uint32_t value, uint16_t index);
		uint16_t putQWordAt(uint64_t value, uint16_t index);
		uint16_t putFloatAt(float value, uint16_t index);
		uint16_t putDoubleAt(double value, uint16_t index);
		void putStringField(const std::string& var);
		void putData(const void *src, uint16_t length);
	private:
		Tlv     *fTlv;
		uint16_t fIndex;			//current pointer while writing/reading value
	};
	
	class Reader {
		// These two definitions implement the "safe bool" idiom
		typedef void (Reader::*bool_type)() const;
		void this_type_does_not_support_comparisons() const {}
	public:
		Reader(const Tlv *tlv) : fTlv(tlv), fIndex() {}
		Reader(const Reader &other) : fTlv(other.fTlv), fIndex(other.fIndex) {}
		
		Reader &operator=(const Reader &other) { fTlv = other.fTlv; fIndex = other.fIndex; return *this; }

		// Bool type to support code like "if (myReader) {...}" to test whether the writer is valid
		operator bool_type() const { return (fTlv!=NULL) ? &Reader::this_type_does_not_support_comparisons : 0; }

		uint8_t getType() const { return fTlv->getType(); }
		
		uint16_t getIndex() const { return fIndex; }
		void resetIndex() { fIndex = 0; }

		uint16_t getLength() const { return fTlv->getLength(); }
		uint16_t getRemainingBytes() const {return getLength() - fIndex;}
		
		uint8_t getByte();
		uint16_t getWord();
		uint32_t getDWord();
		uint64_t getQWord();
		float getFloat();
		double getDouble();
		uint8_t getByteAt(uint16_t index) const;
		uint16_t getWordAt(uint16_t index) const;
		uint32_t getDWordAt(uint16_t index) const;
		uint64_t getQWordAt(uint16_t index) const;
		float getFloatAt(uint16_t index) const;
		double getDoubleAt(uint16_t index) const;
		const uint8_t * getValue() const { return fTlv->getValue(); }
		std::string getStringField();
		std::string getStringFieldAt(uint16_t index) const;
		const uint8_t * getData(uint16_t length);
		const uint8_t * getDataAt(uint16_t index, uint16_t length) const;
	private:
		const Tlv *fTlv;
		uint16_t   fIndex;			//current pointer while writing/reading value
	};

public:	// Deprecated API: Use Writer/Reader objects instead
	void resetIndex() { fIndex = 0; }
	void setType(uint8_t type) { fType = type; }
	void putByte(uint8_t value);
	void putWord(uint16_t value);
	void putDWord(uint32_t value);
	void putQWord(const uint64_t &value);
	void putByteAt(uint8_t value, uint16_t index);
	uint16_t putWordAt(uint16_t value, uint16_t index);
	uint16_t putDWordAt(uint32_t value, uint16_t index);
	uint16_t putQWordAt(const uint64_t &value, uint16_t index);
	void putStringField(const std::string& var);
	void putData(const void *src, uint16_t length);
	
	uint16_t getIndex() const { return fIndex; }
	uint16_t getRemainingBytes() const {return fLength - fIndex;}
	
	uint8_t getByte();
	uint16_t getWord();
	uint32_t getDWord();
	uint64_t getQWord();
	uint8_t getByteAt(uint16_t index);
	uint16_t getWordAt(uint16_t index);
	uint32_t getDWordAt(uint16_t index);
	uint64_t getQWordAt(uint16_t index);
	std::string getStringField();
	std::string getStringFieldAt(uint16_t index);
	const uint8_t * getData(uint16_t length);
	const uint8_t * getDataAt(uint16_t index, uint16_t length);
	
private:
	uint8_t  fType;				//Type of the tlv
	uint16_t fLength;			//Length of the value field; does not include the size of other fields
	uint8_t * fValue;			//pointer to the buffer used for storing value
	
private: // Deprecated members
	uint16_t fIndex;			//current pointer while writing/reading value
	
private:
	/* Constructors */
	Tlv(uint8_t type, uint16_t length);
	Tlv(uint8_t type, uint16_t length, const void * src);
	Tlv(const Tlv& tlv);		//Copy constructor
	void operator=(const Tlv&); // not assignable (so not defined)
};	


#endif		/* __TLV_H__ */
