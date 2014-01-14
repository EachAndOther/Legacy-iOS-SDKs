//
//  GKLocalPlayer.h
//  GameKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GKPlayer.h>
#import <GameKit/GKDefines.h>

NS_CLASS_AVAILABLE(NA, 4_1)
GK_EXTERN_CLASS @interface GKLocalPlayer : GKPlayer {
}

// Obtain the GKLocalPlayer object.
// The player is only available for offline play until logged in.
// A temporary player is created if no account is set up.
+ (GKLocalPlayer *)localPlayer;

@property(nonatomic, readonly, getter=isAuthenticated)  BOOL authenticated; // Authentication state
@property(nonatomic, readonly, getter=isUnderage)       BOOL underage;      // Underage state

// Authenticate the player for access to player details and game statistics. This may present UI to the user if necessary to login or create an account. The user must be authenticated in order to use other APIs. This should be called for each launch of the application as soon as the UI is ready.
// Authentication happens automatically on return to foreground, and the completion handler will be called again. Game Center UI may be presented during this authentication as well. Apps should check the local player's authenticated and player ID properties to determine if the local player has changed.
// Possible reasons for error:
// 1. Communications problem
// 2. User credentials invalid
// 3. User cancelled
- (void)authenticateWithCompletionHandler:(void(^)(NSError *error))completionHandler;

@property(nonatomic, readonly, retain) NSArray *friends;  // Array of player identifiers of friends for the local player. Not valid until loadFriendsWithCompletionHandler: has completed.

// Asynchronously load the friends list as an array of player identifiers. Calls completionHandler when finished. Error will be nil on success.
// Possible reasons for error:
// 1. Communications problem
// 2. Unauthenticated player
- (void)loadFriendsWithCompletionHandler:(void(^)(NSArray *friends, NSError *error))completionHandler;

@end

// Notification will be posted whenever authentication status changes.
GK_EXTERN NSString *GKPlayerAuthenticationDidChangeNotificationName __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_1);

