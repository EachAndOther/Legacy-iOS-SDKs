/*
 *  ATCSUtils.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 9/20/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

#ifndef _ATCSUTILS_H_
#define _ATCSUTILS_H_

#include "ATCSDefines.h"
#include "ATResponse.h"

class ATDispatcher;

class ATCS_EXTERN_CLASS ATCSUtils
{
public:
	typedef enum
	{
		kOperationPinging
	}
	Operation;

	class Callback
	{
	public:
		virtual ~Callback() {};

	public:
		virtual void resetModem( unsigned currentTry, unsigned totalTries ) = 0;
		virtual void handleTimeout( Operation duringWhat, const ATResponse & response, unsigned currentTry, unsigned totalTries ) = 0;
	};

public:
	static bool pingModem( ATDispatcher * dispatcher, Callback * callback, unsigned timeout,
		unsigned triesPerReset, unsigned numResetTries, int firstTimeAdjustment = 0 );

};

#endif
