/*
 *  ATRequest.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 5/17/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

#ifndef __ATRequest_H__
#define __ATRequest_H__

#include <stdarg.h>
#include <string>

/// AT Request parsing utilities
class ATRequest
{
public:
	ATRequest();
	ATRequest(const char* command, ...);
	ATRequest(const char* command, va_list args);
	
	ATRequest(const ATRequest& original);
	
	~ATRequest();
	
	ATRequest& operator=(const ATRequest& rhs);
	
	static bool isTagPrefix(char character);

	std::string getTag() const;
	
	bool isMultiLine() const;
	
	void setMultiLinePayload(const char* payload);
	void setMultiLinePayload(const char* payload, int lenth);
	
	int copyCommand(char* buffer, int offset, int length) const;
	int copyMultiLinePayload(char* buffer, int offset, int length) const;
	
	const char *getCommand() const;
	int getCommandLength() const;
	const char *getMultiLinePayload() const;
	int getMultiLinePayloadLength() const;
	
private:
	void sharedInit(const char* command, va_list args);
	
	int		fCommandLength;
	char*	fCommand;
	
	int		fMultiLinePayloadLength;
	char*	fMultiLinePayload;
};


/* static */ inline bool
ATRequest::isTagPrefix(char character) {

	return ((character == '+') || (character == '#') || (character == '*') || (character == '%'));
}

#endif
