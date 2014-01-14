/*
 *  GKMatchmakerViewController.h
 *  GameKit
 *
 *  Copyright 2010 Apple, Inc. All rights reserved.
 *
 */

#import <UIKit/UIKit.h>

@class GKMatchRequest, GKInvite, GKMatch;

@protocol GKMatchmakerViewControllerDelegate;

// View controller to invite friends, respond to invites, and perform auto-matching. Present modally from the top view controller.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKMatchmakerViewController : UINavigationController {
}

@property(nonatomic, assign) id<GKMatchmakerViewControllerDelegate> matchmakerDelegate;
@property(nonatomic, readonly, retain) GKMatchRequest *matchRequest;
@property(nonatomic, assign, getter=isHosted) BOOL hosted;  // set to YES to receive hosted (eg. not peer-to-peer) match results. Will cause the controller to return an array of players instead of a match.

// Initialize with a matchmaking request, allowing the user to send invites and/or start matchmaking
- (id)initWithMatchRequest:(GKMatchRequest *)request;

// Initialize with an accepted invite, allowing the user to see the status of other invited players and get notified when the game starts
- (id)initWithInvite:(GKInvite *)invite;

// Update the status of a server-hosted player to ready, this should be called once an invited player has connected to the app's server
- (void)setHostedPlayerReady:(NSString *)playerID;

@end

@protocol GKMatchmakerViewControllerDelegate <NSObject>
@required
// The user has cancelled matchmaking
- (void)matchmakerViewControllerWasCancelled:(GKMatchmakerViewController *)viewController;

// Matchmaking has failed with an error
- (void)matchmakerViewController:(GKMatchmakerViewController *)viewController didFailWithError:(NSError *)error;

@optional
// A peer-to-peer match has been found, the game should start
- (void)matchmakerViewController:(GKMatchmakerViewController *)viewController didFindMatch:(GKMatch *)match;

// Players have been found for a server-hosted game, the game should start
- (void)matchmakerViewController:(GKMatchmakerViewController *)viewController didFindPlayers:(NSArray *)playerIDs;
@end

