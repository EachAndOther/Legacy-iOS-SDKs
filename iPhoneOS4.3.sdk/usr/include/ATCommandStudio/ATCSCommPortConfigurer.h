/*
 *  ATCSCommPortConfigurer.h
 *  ATCommandStudio
 *
 *  Created by Arjuna Siva on 9/9/08.
 *  Copyright 2008 Apple. All rights reserved.
 *
 */

#ifndef _ATCSCOMMPORTCONFIGURER_H_
#define _ATCSCOMMPORTCONFIGURER_H_

#include "ATCSDefines.h"

class ATCS_EXTERN_CLASS ATCSCommPortConfigurer
{
public:
	static const unsigned kDefaultBaud = 115200;
	static const unsigned kDefaultVMIN = 0;
	static const unsigned kDefaultVTIME = 0;
	static const bool kDefaultHardwareFlowControl = false;

public:
	ATCSCommPortConfigurer( 
		int fd,
		unsigned baud = kDefaultBaud,
		unsigned vmin = kDefaultVMIN,
		unsigned vtime = kDefaultVTIME,
		bool hardwareFlowControl = kDefaultHardwareFlowControl );
		
	
	~ATCSCommPortConfigurer()
	{
	}
	
private:
	void configure( void );
	
private:
	int				fFD;
	unsigned		fBaud;
	unsigned		fVMIN;
	unsigned		fVTIME;
	bool			fHardwareFlowControl;

};


#endif
