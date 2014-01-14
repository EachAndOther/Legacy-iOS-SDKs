//
//  SKDownload.h
//  iTunesStore
//
//  Created by Sean Kelly on 1/19/12.
//  Copyright (c) 2012 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

@class SKPaymentTransaction;

enum {
    SKDownloadStateWaiting,     // Download is inactive, waiting to be downloaded
    SKDownloadStateActive,      // Download is actively downloading
    SKDownloadStatePaused,      // Download was paused by the user
    SKDownloadStateFinished,    // Download is finished, content is available
    SKDownloadStateFailed,      // Download failed
    SKDownloadStateCancelled,   // Download was cancelled
};
typedef NSInteger SKDownloadState;

SK_EXTERN NSTimeInterval SKDownloadTimeRemainingUnknown __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

SK_EXTERN_CLASS_AVAILABLE(6_0) @interface SKDownload : NSObject

// State of the download
@property(nonatomic, readonly) SKDownloadState downloadState __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Total size of the content, in bytes
@property(nonatomic, readonly) long long contentLength __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Identifier for this content
@property(nonatomic, readonly) NSString *contentIdentifier __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Location of the content data, if downloadState is SKDownloadStateFinished
@property(nonatomic, readonly) NSURL *contentURL __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Content version
@property(nonatomic, readonly) NSString *contentVersion __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Failure error, if downloadState is SKDownloadStateFailed
@property(nonatomic, readonly) NSError *error __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Overall progress for the download [0..1]
@property(nonatomic, readonly) float progress __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Estimated time remaining to complete the download, in seconds.  Value is SKDownloadTimeRemainingUnknown if estimate is unknown.
@property(nonatomic, readonly) NSTimeInterval timeRemaining __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Transaction for this download
@property(nonatomic, readonly) SKPaymentTransaction *transaction __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

@end
