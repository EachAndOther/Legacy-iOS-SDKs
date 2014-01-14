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

#ifndef __ATCSTEXT_CONVERTER_H
#define __ATCSTEXT_CONVERTER_H

#include "ATCSDefines.h"
#include "NonCopyable.h"
#include <string>
#include <vector>

/// A ATCSTextConverter is an aggregate of a number of individual transformations
class ATCS_EXTERN_CLASS ATCSTextConverter : NonCopyable
{
public:
	enum Conversion 
	{
		kBinaryToHex,
		kHexToBinary,
		kUtf8ToUcs2,
		kUcs2ToUtf8,
		kSmsPackedToUnpacked,
		kUnpackedToSmsPacked,
		kUcs2ToGsm7,
		kGsm7ToUcs2,
		kOctetToUcs2,
		kUcs2ToOctet,
		kUcs2ToAdn8,
		kAdn8ToUcs2,
		kOctetToGsm7,
		kEucKRToUcs2,
		kC2KSmsPackedToUnpacked,
		kC2KSmsUnpackedToPacked,
		kUcs2ToAscii7,
		kAscii7ToUcs2,
		kISOLatin1ToUcs2
	};

	// these enum must match up with the tables in kUcs2ToGsm7Tables in ATCSTextConverter.cpp
	enum Ucs2ToGsm7Tables
	{
		kGsm7Default,
		kISOLatin1,
		kISOLatin5,		// Turkish
		kISOLatinGreek,	// Greek
		kNumOfUcs2ToGsm7Tables
	};
	
	// these enum must match up with the tables in kGsm7ToUcs2Tables in TextConverter.cpp
	enum NationalLanguageId
	{
		kNone    = 0,
		kTurkish = 1,
		kSpanish = 2   // not supported
	};
	
	ATCSTextConverter();
	~ATCSTextConverter();
	void setSource(const char *base, int length);
	void pushConversion(Conversion, int extraParam = 0, int numCodes = 0x7fffffff, int extraParam2 = 0);
	void popConversion();
	int nextCode();
	bool exceptionOccurred();
	std::string readChars(int maxCount = 0x7fffffff);
	
	// How many characters have been consumed in the source
	int getSourceCount() const;

	// How many characters available for consumption
	int getSourceAvailableCount() const;
	
	
	/// Given an ASCII encoded hex number, return the value.
	static int decodeHexString(const char *inAsciiHex, int length);
	
	/// @returns the number of bits required to encode the given character
	static int getGsm7EncodedSize(int ucs2Code, ATCSTextConverter::Ucs2ToGsm7Tables tableIndex);
	
	static int countCharactersInUtf8Message(const char *utf8, int numOctets);
	static int countSeptetsInMessage(const char *utf8, int numOctets, ATCSTextConverter::Ucs2ToGsm7Tables tableIndex);
	
	/// Note: values of enum are encoded in message.  Don't change.
	enum MessageClass
	{
		/// Class 0 messages must be displayed immediately and cannot be stored
		/// on the SIM or ME
		kMessageClass0 = 0,
		
		/// Class 1 messages are stored on the SIM or ME and can be displayed in usual
		/// order
		kMessageClass1 = 1,
		
		/// Class 2 messages must be stored on the SIM.
		kMessageClass2 = 2,
		kMessageClass3 = 3,
		kMessageClassUnspecified
	};
	
	enum MessageEncoding 
	{
		kGSM7,
		k8BitData,
		kUCS2,
		kKSC5601
	};
	
	/// Decode SMS data coding scheme, per 3GPP TS 23.038, section 4
	/// @returns 
	///   - true if the DCS was decoded
	///   - false if the DCS was unrecognized
	static bool decodeSmsDataCodingScheme(int dcs, MessageClass &outClass, MessageEncoding &outEncoding,
								   bool &outAutoDelete, bool &outCompressed, bool &isVmIndication, bool &voiceMailWaiting, bool &discardStatus);
	
	/// Decode CBS (SMS cell broadcast) data coding scheme, per 3GPP TS 23.038, section 5
	/// @returns 
	///   - true if the DCS was decoded
	///   - false if the DCS was unrecognized
	static bool decodeCbsDataCodingScheme(int dcs, MessageClass &outClass, MessageEncoding &outEncoding, 
								   bool &outHasLanguagePrefix);
	
private:
	class TextTransform *fTop;
	class TextTransform *fSource;
};

#endif
