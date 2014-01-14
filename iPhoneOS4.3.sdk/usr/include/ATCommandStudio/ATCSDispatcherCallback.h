/*
 *  DispatcherCallBack.h
 *  ATCommandStudio
 *
 *  Created on 9/10/09.
 *  Copyright 2009 Apple Inc.. All rights reserved.
 *
 */

#ifndef _DISPATCHERCALLBACK_H_
#define _DISPATCHERCALLBACK_H_

#include <string>

/* 
 * This is an interface class for ATCSIPCDriver to callback into a dispatcher 
 * (AT, QMI, etc). This allows ATCSIPCDriver to work with different types of
 * dispatchers.
 */
class ATCSDispatcherCallback {
	public:
		virtual int handleReadData(const unsigned char * buff, unsigned available) = 0;
		virtual int getWriteData(unsigned char * buff, unsigned capacity) = 0;

		virtual void *getPrivateData(void) const = 0;
		virtual const std::string &getDebugName(void) const = 0;
};

#endif /* _DISPATCHERCALLBACK_H_ */
