//
//  GKPlayer.h
//  GameKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GKDefines.h>
#import <GameKit/GKError.h>

@class UIImage;

NS_CLASS_AVAILABLE(NA, 4_1)
GK_EXTERN_CLASS @interface GKPlayer : NSObject

// Load the players for the identifiers provided. Error will be nil on success.
// Possible reasons for error:
// 1. Unauthenticated local player
// 2. Communications failure
// 3. Invalid player identifier
+ (void)loadPlayersForIdentifiers:(NSArray *)identifiers withCompletionHandler:(void(^)(NSArray *players, NSError *error))completionHandler;

@property(nonatomic, readonly, retain)  NSString *playerID;     // Invariant player identifier.
@property(nonatomic, readonly, copy)    NSString *alias;        // The player's alias
@property(nonatomic, readonly)          BOOL isFriend;          // True if this player is a friend of the local player


// Available photo sizes.  Actual pixel dimensions will vary on different devices.
enum {
    GKPhotoSizeSmall = 0,
    GKPhotoSizeNormal,
};
typedef NSInteger GKPhotoSize;

// Asynchronously load the player's photo. Error will be nil on success.
// Possible reasons for error:
// 1. Communications failure
- (void)loadPhotoForSize:(GKPhotoSize)size withCompletionHandler:(void(^)(UIImage *photo, NSError *error))completionHandler __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

@end

// Notification will be posted whenever the player details changes. The object of the notification will be the player.
GK_EXTERN_WEAK NSString *GKPlayerDidChangeNotificationName;

