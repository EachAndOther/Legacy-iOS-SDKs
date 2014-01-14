/*
 *  ATCSException.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 7/1/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */
#ifndef _ATCSEXCEPTION_H_
#define _ATCSEXCEPTION_H_

#define ATCSException( ... )	_ATCSException( __FILE__, __LINE__, __VA_ARGS__ )

#define ATCSAssert( left, operand, right )		\
	if ( ! ( ( left ) operand ( right ) ) )		\
		{ _ATCSException::triggerAssertion( __FILE__, __LINE__, # left, # operand, # right, (unsigned)( left ), (unsigned)( right ) ); }
		
#define ATCSAssertNonScalar( left, operand, right )		\
	if ( ! ( ( left ) operand ( right ) ) )		\
		{ _ATCSException::triggerAssertion( __FILE__, __LINE__, # left, # operand, # right, 0, 0 ); }
		
#define __ATCSFormatCheck(_STRING_INDEX, _FIRST_TO_CHECK) __attribute__((format (printf, _STRING_INDEX, _FIRST_TO_CHECK)))


#include <exception>
#include <stdarg.h>

#include "ATCSDefines.h"

class ATCS_EXTERN_CLASS _ATCSException : public std::exception
{
private:
	static const unsigned 	kMaxMessageLength = 512;
private:
	char		fMessage[kMaxMessageLength];
	
private:
	void constructCommon( const char * file, unsigned line, const char * fmt, va_list args );

public:
	_ATCSException( const char * file, unsigned line, const char * fmt, ... );
	_ATCSException( const _ATCSException & e );
	
	virtual ~_ATCSException() throw() {}
	
	static void triggerAssertion( const char * file, unsigned line, const char * leftStr, const char * operandStr, const char * rightStr, unsigned left, unsigned right );

public:
	virtual const char * what( void ) const throw();
};

#endif
