/*
	File:  AVVideoSettings.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

/*!
	@class			AVVideoSettings
 
	@abstract		NSDictionary keys for configuring video compression
*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

extern NSString *const AVVideoCodecKey /* NSString (CMVideoCodecType) */                                 NS_AVAILABLE(10_7, 4_0);
	extern NSString *const AVVideoCodecH264 /* @"avc1" */                                                NS_AVAILABLE(10_7, 4_0);
    extern NSString *const AVVideoCodecJPEG /* @"jpeg" */                                                NS_AVAILABLE(10_7, 4_0);
    extern NSString *const AVVideoCodecAppleProRes4444 /* @"ap4h" */                                     NS_AVAILABLE(10_7, NA);
    extern NSString *const AVVideoCodecAppleProRes422   /* @"apcn" */                                    NS_AVAILABLE(10_7, NA);
extern NSString *const AVVideoWidthKey /* NSNumber (encoded pixels) */                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVVideoHeightKey /* NSNumber (encoded pixels) */                                  NS_AVAILABLE(10_7, 4_0);

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))

extern NSString *const AVVideoScalingModeKey /* NSString */                                              NS_AVAILABLE(10_7, NA);
	/* AVVideoScalingModeFit - Crop to remove edge processing region; preserve aspect ratio of cropped source by reducing specified width or height if necessary.  Will not scale a small source up to larger dimensions. */
	extern NSString *const AVVideoScalingModeFit                                                         NS_AVAILABLE(10_7, NA);
	/* AVVideoScalingModeResize - Crop to remove edge processing region; scale remainder to destination area.  Does not preserve aspect ratio. */
	extern NSString *const AVVideoScalingModeResize                                                      NS_AVAILABLE(10_7, NA);
	/* AVVideoScalingModeResizeAspect - Preserve aspect ratio of the source, and fill remaining areas with black to fit destination dimensions. */
	extern NSString *const AVVideoScalingModeResizeAspect                                                NS_AVAILABLE(10_7, NA);
	/* AVVideoScalingModeResizeAspectFill - Preserve aspect ratio of the source, and crop picture to fit destination dimensions. */
	extern NSString *const AVVideoScalingModeResizeAspectFill                                            NS_AVAILABLE(10_7, NA);

#endif // (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))

extern NSString *const AVVideoCompressionPropertiesKey /* NSDictionary */                                NS_AVAILABLE(10_7, 4_0);
	extern NSString *const AVVideoAverageBitRateKey /* NSNumber (bits per second) */                     NS_AVAILABLE(10_7, 4_0);
	extern NSString *const AVVideoMaxKeyFrameIntervalKey /* NSNumber (1 means key frames only) */        NS_AVAILABLE(10_7, 4_0);
	extern NSString *const AVVideoProfileLevelKey                                                        NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoProfileLevelH264Baseline30 /* Baseline Profile Level 3.0 */        NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoProfileLevelH264Baseline31 /* Baseline Profile Level 3.1 */        NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoProfileLevelH264Main30 /* Main Profile Level 3.0 */                NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoProfileLevelH264Main31 /* Main Profile Level 3.1 */                NS_AVAILABLE(10_7, 4_0);
	extern NSString *const AVVideoPixelAspectRatioKey /* NSDictionary */                                 NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoPixelAspectRatioHorizontalSpacingKey /* NSNumber */                NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoPixelAspectRatioVerticalSpacingKey /* NSNumber */                  NS_AVAILABLE(10_7, 4_0);
	extern NSString *const AVVideoCleanApertureKey /* NSDictionary */                                    NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoCleanApertureWidthKey /* NSNumber */                               NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoCleanApertureHeightKey /* NSNumber */                              NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoCleanApertureHorizontalOffsetKey /* NSNumber */                    NS_AVAILABLE(10_7, 4_0);
		extern NSString *const AVVideoCleanApertureVerticalOffsetKey /* NSNumber */                      NS_AVAILABLE(10_7, 4_0);

