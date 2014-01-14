/*
    File:  AVMediaFormat.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

// Media types

extern NSString *const AVMediaTypeVideo                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeAudio                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeText                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeClosedCaption         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeSubtitle              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeTimecode              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeTimedMetadata         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaTypeMuxed                 NS_AVAILABLE(10_7, 4_0);


// Media characteristics

extern NSString *const AVMediaCharacteristicVisual      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaCharacteristicAudible     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaCharacteristicLegible     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMediaCharacteristicFrameBased  NS_AVAILABLE(10_7, 4_0);

// File format UTIs

/*!
 @constant AVFileTypeQuickTimeMovie
 @abstract A UTI for the QuickTime movie file format.
 @discussion
 The value of this UTI is @"com.apple.quicktime-movie".
 Files are identified with the .mov and .qt extensions.
 */
extern NSString *const AVFileTypeQuickTimeMovie NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeMPEG4
 @abstract A UTI for the MPEG-4 file format.
 @discussion
 The value of this UTI is @"public.mpeg-4".
 Files are identified with the .mp4 extension.
 */
extern NSString *const AVFileTypeMPEG4 NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAppleM4V
 @discussion
 The value of this UTI is @"com.apple.m4v-video".
 Files are identified with the .m4v extension.
 */
extern NSString *const AVFileTypeAppleM4V NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAppleM4A
 @discussion
 The value of this UTI is @"com.apple.m4a-audio".
 Files are identified with the .m4a extension.
 */
extern NSString *const AVFileTypeAppleM4A NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileType3GPP
 @abstract A UTI for the 3GPP file format.
 @discussion
 The value of this UTI is @"public.3gp".
 Files are identified with the .3gp, .3gpp, and .sdv extensions.
 */
extern NSString *const AVFileType3GPP NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeCoreAudioFormat
 @abstract A UTI for the CoreAudio file format.
 @discussion
 The value of this UTI is @"com.apple.coreaudio-format".
 Files are identified with the .caf extension.
 */
extern NSString *const AVFileTypeCoreAudioFormat NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeWAVE
 @abstract A UTI for the WAVE audio file format.
 @discussion
 The value of this UTI is @"com.microsoft.waveform-audio".
 Files are identified with the .wav, .wave, and .bwf extensions.
 */
extern NSString *const AVFileTypeWAVE NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAIFF
 @abstract A UTI for the AIFF audio file format.
 @discussion
 The value of this UTI is @"public.aiff-audio".
 Files are identified with the .aif and .aiff extensions.
 */
extern NSString *const AVFileTypeAIFF NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAIFC
 @abstract A UTI for the AIFC audio file format.
 @discussion
 The value of this UTI is @"public.aifc-audio".
 Files are identified with the .aifc and .cdda extensions.
 */
extern NSString *const AVFileTypeAIFC NS_AVAILABLE(10_7, 4_0);

/*!
 @constant AVFileTypeAMR
 @abstract A UTI for the adaptive multi-rate audio file format.
 @discussion
 The value of this UTI is @"org.3gpp.adaptive-multi-rate-audio".
 Files are identified with the .amr extension.
 */
extern NSString *const AVFileTypeAMR NS_AVAILABLE(10_7, 4_0);
