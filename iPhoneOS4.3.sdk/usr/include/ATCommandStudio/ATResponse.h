/*
 *  ATResponse.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 5/17/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */
 
#ifndef __ATRESPONSE_H__
#define __ATRESPONSE_H__

#include "ATCSDefines.h"
#include <string>

class ATCSLogger;

/// AT Response parsing utilities
class ATCS_EXTERN_CLASS ATResponse
{
public:
	enum FinalResultType
	{
		kOK,
		kERROR,
		kCME_ERROR,
		kCMS_ERROR,
		kCONNECT,
		kBUSY,
		kNO_CARRIER,
		
		// If some internal error prevents the command from completion,
		// it get flagged like this.  The final result code will be an CSI
		// specific internal code
		kInternalError	
	};

	enum InternalErrorType
	{
		kOutOfMemory,
		kTimeout,
		kModuleReset,
		kCommandCancelled
	};
	
	/// In 3GPP TS 27.007, you will find commands use a number of different formats, even
	/// though +CSCS is supposed to set the format for all commands.
	enum FieldFormat
	{
		kFormatIRA,					// International Reference Alphabet
		kFormatGSM7HexPacked,		// GSM-7 Hex, packed
		kFormatGSM7HexUnpacked,		// GSM-7 Hex, not packed (each character padded to 8 bits)
		kFormatIRAHex,				// IRA-7, 8 bits per character
		kFormatUCS2Hex,				// UCS-2, 16 bits per character
		kFormatEfAdn,				// Encoding for EF(ADN) GSM 11.11 Annex B
		kFormatCbsPrefix,			// Hex encoded, first encoded octet is CBS DCS describing rest
		kFormatRawHex,				// Just pass-through the hex string
		kFormatEfAdnExtended		// Encoding for EF(ADN) GSM 11.11 Annex B + KSC5601 support
	};

	ATResponse();
	ATResponse(const ATResponse &copyFrom);
	ATResponse(FinalResultType type, int resultCode);
	ATResponse(const char *line);
	ATResponse(const char *line, int length, FinalResultType type, int resultCode);
	
	~ATResponse() {}

	ATResponse &operator=(const ATResponse &copyFrom);

	void clear();

	bool hasFinalResult() const { return fHasFinalResult; }

	/// Get the type of final response code that was returned
	FinalResultType getFinalResultType() const;

	/// For a +CME ERROR or +CMS ERROR, numeric code that was associated with
	/// it.
	int getFinalResultCode() const;
	
	bool isError() const;

	/// @param fieldIndex Field number, numbered starting at zero from left to right
	/// @param line Line number or group number (if the output is divided into parenthesized groups,
	///   groups will be numbered left to right starting at 0).
	/// @param string We expect to find a string in this field
	/// @returns
	///   - true if the field is present
	///   - false if the field is empty or doesn't exist
	bool isFieldPresent(int fieldIndex, int line = 0, bool string = false) const;

	/// Return the tag for the given line (if there is no tag, an empty string will be returned).
	/// The returned tag will including the leading character (+, etc), but not the trailing colon.
	std::string getTag(int line = 0) const;

	/// @param format Encoding of this field
	/// @param fieldIndex Field number, numbered starting at zero from left to right
	/// @param line Line number or group number (if the output is divided into parenthesized groups,
	///   groups will be numbered left to right starting at 0).
	/// @returns
	///   - String contents of field if present
	///   - Empty string if the field is not present.
	inline std::string getStringField(FieldFormat format, int fieldIndex, int line = 0) const;

	/// @param dcs SMS data coding scheme of the string
	/// @param fieldIndex Field number, numbered starting at zero from left to right
	/// @param line Line number or group number (if the output is divided into parenthesized groups,
	///   groups will be numbered left to right starting at 0).
	/// @returns
	///   - String contents of field if present
	///   - Empty string if the field is not present.
	std::string getSmsDcsStringField(unsigned dcs, int fieldIndex, int line = 0) const;
	
	/// @param dcs CBS data coding scheme of the string
	/// @param fieldIndex Field number, numbered starting at zero from left to right
	/// @param line Line number or group number (if the output is divided into parenthesized groups,
	///   groups will be numbered left to right starting at 0).
	/// @returns
	///   - String contents of field if present
	///   - Empty string if the field is not present.
	std::string getCbsDcsStringField(unsigned dcs, int fieldIndex, int line = 0) const;
	
	/// Same as getStringField, except uses IRA encoding by default.
	inline std::string getStringField(int fieldIndex, int line = 0) const;

	/// @param fieldIndex Field number, numbered starting at zero from left to right
	/// @param line Line number or group number (if the output is divided into parenthesized groups,
	///   groups will be numbered left to right starting at 0).
	/// @returns Integer value of this field.  
	int getIntField(int fieldIndex, int line = 0, int radix = 10) const;
	
	/// @param fieldIndex Field number, numbered starting at zero from left to right
	/// @param line Line number or group number (if the output is divided into parenthesized groups,
	///   groups will be numbered left to right starting at 0).
	/// @returns Value of this field as an unsigned long.  
	unsigned long getUnsignedIntField(int fieldIndex, int line = 0, int radix = 10) const;

	double getFloatField(int fieldIndex, int line = 0) const;

	/// Read an HEX encoded binary field
	int getBinaryField(void *outBinaryData, int length, int fieldIndex, int line = 0) const;

	/// @returns number of non-empty lines or the number of parenthesized groups.
	/// @note This is not thread safe.
	int countLines() const;
	
	bool append(const char* line);
	bool append(const char* line, int length);
	
	void setFinalResult(FinalResultType type, int resultCode) { fHasFinalResult = true; fFinalResultType = type; fFinalResultCode = resultCode; }

	const std::string getRawResponse() const;
	
	/// Strips carriage returns
	void stripCarriageReturns( void );

private:
	inline void initCommon( void );

	bool getField(int field, int line, const char **outStart, int *outLength, int *lineCount = NULL, bool *quoted = NULL) const;

	/// @param skip Number of characters to skip in source string
	std::string getStringFieldInternal(FieldFormat format, int fieldIndex, int line, int skip) const;

	std::string fString;
	mutable int fNumLines;	
	bool fHasFinalResult;
	FinalResultType fFinalResultType;
	int fFinalResultCode;
	
	ATCSLogger * fLogger;
};

inline std::string ATResponse::getStringField(int fieldIndex, int line) const 
{
	return getStringField(kFormatIRA, fieldIndex, line);
}

inline std::string ATResponse::getStringField(FieldFormat format, int fieldIndex, int line) const
{
	return getStringFieldInternal(format, fieldIndex, line, 0);
}

#endif
