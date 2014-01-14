/**********************************************************************************************************************************
*
*   OpenAL cross platform audio library
*	Copyright (c) 2004-2006, Apple Computer, Inc. All rights reserved.
*	Copyright (c) 2007-2008, Apple Inc. All rights reserved.
*
*	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following 
*	conditions are met:
*
*	1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 
*	2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
*		disclaimer in the documentation and/or other materials provided with the distribution. 
*	3.  Neither the name of Apple Inc. ("Apple") nor the names of its contributors may be used to endorse or promote products derived 
*		from this software without specific prior written permission. 
*
*	THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
*	TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS 
*	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
*	AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
*	ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
**********************************************************************************************************************************/

#ifndef __OAL_MAC_OSX_OAL_EXTENSIONS_H__
#define __OAL_MAC_OSX_OAL_EXTENSIONS_H__

#include <OpenAL/al.h>

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	ALC_EXT_MAC_OSX
   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// Retrieve functions via alGetProcAddress() by passing in strings: alcMacOSXMixerOutputRate or alcMacOSXGetMixerOutputRate

// Setting the Mixer Output Rate effectively sets the samnple rate at which the mixer
typedef ALvoid (*alcMacOSXRenderingQualityProcPtr) (ALint value);
typedef ALvoid (*alMacOSXRenderChannelCountProcPtr) (ALint value);
typedef ALvoid (*alcMacOSXMixerMaxiumumBussesProcPtr) (ALint value);
typedef ALvoid (*alcMacOSXMixerOutputRateProcPtr) (ALdouble value);

typedef ALint (*alcMacOSXGetRenderingQualityProcPtr) ();
typedef ALint (*alMacOSXGetRenderChannelCountProcPtr) ();
typedef ALint (*alcMacOSXGetMixerMaxiumumBussesProcPtr) ();
typedef ALdouble (*alcMacOSXGetMixerOutputRateProcPtr) ();

/* Render Quality. Used with alcMacOSXRenderingQuality() */
	
	#define ALC_MAC_OSX_SPATIAL_RENDERING_QUALITY_HIGH			'rqhi'
	#define ALC_MAC_OSX_SPATIAL_RENDERING_QUALITY_LOW			'rdlo'
	
	// High Quality Spatial Algorithm suitable only for headphone use
	#define ALC_IPHONE_SPATIAL_RENDERING_QUALITY_HEADPHONES		'hdph'		

/*	
	Render Channels. Used with alMacOSXRenderChannelCount()
	Allows a user to force OpenAL to render to stereo, regardless of the audio hardware being used
*/
	#define ALC_MAC_OSX_RENDER_CHANNEL_COUNT_STEREO         'rcst'

/* GameKit extension */

	#define AL_GAMEKIT											'gksr'
							
#endif // __OAL_MAC_OSX_OAL_EXTENSIONS_H__