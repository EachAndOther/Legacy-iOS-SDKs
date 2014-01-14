/*
 *  ATCSLogger.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 7/1/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */
 
 
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "ATCSException.h"

#define ATCS_DEBUG			0

enum ATCSLogGroup {
	kATRecvLog,
	kATSendLog,
	kATFlushLog,
	kATTimerLog,
	kATResponseLog,
	kATDispatcherLog,
	kQMIMuxLog
};

class ATCS_EXTERN_CLASS ATCSLogger
{
public:
	class CommandFormatter
	{
	public:
		virtual ~CommandFormatter();
		
		virtual unsigned bufferSizeForCommandHeader( unsigned commandLength ) const = 0;
		virtual unsigned interpretCommandHeader( char * destBuff, unsigned destBuffCapacity, 
			const void * commandBuffer, unsigned commandLength,
			unsigned * consumed ) const = 0;
	};

protected:
	ATCSLogger();
	
public:
	virtual ~ATCSLogger();
	
	static void instantiate( ATCSLogger * logger );
	
	static ATCSLogger * getInstance( void );
	
public:
	void logCommand( ATCSLogGroup group, const char * who, const char * buffer, unsigned length,
		const CommandFormatter * formatter );
	virtual void logWithLabel( ATCSLogGroup group, const char * who, const char * format, ... ) __ATCSFormatCheck( 4, 5 ) = 0;
	virtual void log( ATCSLogGroup group, const char * format, ... ) __ATCSFormatCheck( 3, 4 )  = 0;
	
protected:
	virtual void logCommandInternal( ATCSLogGroup group, const char * who, 
		const char * headerBuffer, unsigned headerBufferLength,
		unsigned headerConsumed, const char * buffer, unsigned length ) = 0;
	
private:
	static ATCSLogger *			fsInstance;
};

#endif
