/*
	File:  AVAudioSession.h
	
	Framework:  AVFoundation
	
	Copyright 2009-2010 Apple Inc. All rights reserved.
	
*/

#import <AVFoundation/AVBase.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>	/* for NSTimeInterval */
#import <AvailabilityMacros.h>

/* This protocol is available with iPhone 3.0 or later */
@protocol AVAudioSessionDelegate;
@class NSError, NSString;

/* values for the category property */
extern NSString *const AVAudioSessionCategoryAmbient;
extern NSString *const AVAudioSessionCategorySoloAmbient;
extern NSString *const AVAudioSessionCategoryPlayback;
extern NSString *const AVAudioSessionCategoryRecord;
extern NSString *const AVAudioSessionCategoryPlayAndRecord;
extern NSString *const AVAudioSessionCategoryAudioProcessing;

/* flags passed to you when endInterruptionWithFlags: is called on the delegate */
enum {
	AVAudioSessionInterruptionFlags_ShouldResume = 1
};

/* flags for use when calling setActive:withFlags:error: */
enum {	
	AVAudioSessionSetActiveFlags_NotifyOthersOnDeactivation = 1
};

NS_CLASS_AVAILABLE(NA, 3_0)
@interface AVAudioSession : NSObject {
@private
    __strong void *_impl;
}

 /* returns singleton instance */
+ (id)sharedInstance;

@property(assign) id<AVAudioSessionDelegate> delegate;

/* set the session active or inactive */
- (BOOL)setActive:(BOOL)beActive error:(NSError**)outError;
- (BOOL)setActive:(BOOL)beActive withFlags:(NSInteger)flags error:(NSError**)outError NS_AVAILABLE_IPHONE(4_0);

- (BOOL)setCategory:(NSString*)theCategory error:(NSError**)outError; /* set session category */
- (BOOL)setPreferredHardwareSampleRate:(double)sampleRate error:(NSError**)outError;
- (BOOL)setPreferredIOBufferDuration:(NSTimeInterval)duration error:(NSError**)outError;

@property(readonly) NSString* category; /* get session category */
@property(readonly) double preferredHardwareSampleRate;
@property(readonly) NSTimeInterval preferredIOBufferDuration;

@property(readonly) BOOL inputIsAvailable; /* is input available or not? */
@property(readonly) double currentHardwareSampleRate;
@property(readonly) NSInteger currentHardwareInputNumberOfChannels;
@property(readonly) NSInteger currentHardwareOutputNumberOfChannels;

@end


/* A protocol for delegates of AVAudioSession */
@protocol AVAudioSessionDelegate <NSObject>
@optional 

- (void)beginInterruption; /* something has caused your audio session to be interrupted */

/* the interruption is over */
- (void)endInterruptionWithFlags:(NSUInteger)flags NS_AVAILABLE_IPHONE(4_0); /* Currently the only flag is AVAudioSessionInterruptionFlags_ShouldResume. */
		
- (void)endInterruption; /* endInterruptionWithFlags: will be called instead if implemented. */

/* notification for input become available or unavailable */
- (void)inputIsAvailableChanged:(BOOL)isInputAvailable;

@end
