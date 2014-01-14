//
//  GKMatchmaker.h
//  GameKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//


@class GKPlayer;
@class GKMatch;

// GKMatchRequest represents the parameters needed to create the match.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKMatchRequest : NSObject {
}

@property(nonatomic, assign) NSUInteger minPlayers;     // Minimum number of players for the match
@property(nonatomic, assign) NSUInteger maxPlayers;     // Maximum number of players for the match
@property(nonatomic, assign) NSUInteger playerGroup;    // The player group identifier. Matchmaking will only take place between players in the same group.
@property(nonatomic, assign) uint32_t playerAttributes; // optional flags such that when all player flags are OR'ed together in a match they evaluate to 0xFFFFFFFF
@property(nonatomic, retain) NSArray *playersToInvite;  // Array of player IDs to invite, or nil if none

@end

// GKInvite represents an accepted game invite, it is used to create a GKMatchmakerViewController
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKInvite : NSObject {
}

@property(nonatomic, readonly, retain) NSString *inviter;
@property(nonatomic, readonly, getter=isHosted) BOOL hosted;

@end


// GKMatchmaker is a singleton object to manage match creation from invites and auto-matching.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKMatchmaker : NSObject {
}

// The shared matchmaker
+ (GKMatchmaker*)sharedMatchmaker;

// An inviteHandler must be set in order to receive game invites or respond to external requests to initiate an invite. The inviteHandler will be called when an invite or request is received. It may be called immediately if there is a pending invite or request when the application is launched. The inviteHandler may be called multiple times.
// Either acceptedInvite or playersToInvite will be present, but never both.
@property(nonatomic, copy) void(^inviteHandler)(GKInvite *acceptedInvite, NSArray *playersToInvite);

// Auto-matching to find a peer-to-peer match for the specified request. Error will be nil on success:
// Possible reasons for error:
// 1. Communications failure
// 2. Unauthenticated player
// 3. Timeout
- (void)findMatchForRequest:(GKMatchRequest *)request withCompletionHandler:(void(^)(GKMatch *match, NSError *error))completionHandler;

// Matchmaking for host-client match request. This returns a list of player identifiers to be included in the match. Determination and communication with the host is not part of this API.
// Possible reasons for error:
// 1. Communications failure
// 2. Unauthenticated player
// 3. Timeout
- (void)findPlayersForHostedMatchRequest:(GKMatchRequest *)request withCompletionHandler:(void(^)(NSArray *playerIDs, NSError *error))completionHandler;

// Auto-matching to add additional players to a peer-to-peer match for the specified request. Error will be nil on success:
// Possible reasons for error:
// 1. Communications failure
// 2. Timeout
- (void)addPlayersToMatch:(GKMatch *)match matchRequest:(GKMatchRequest *)matchRequest completionHandler:(void (^)(NSError *))completionHandler;

// Cancel matchmaking
- (void)cancel;

// Query the server for recent activity in the specified player group. A larger value indicates that a given group has seen more recent activity. Error will be nil on success.
// Possible reasons for error:
// 1. Communications failure
- (void)queryPlayerGroupActivity:(NSUInteger)playerGroup withCompletionHandler:(void(^)(NSInteger activity, NSError *error))completionHandler;

// Query the server for recent activity for all the player groups of that game. Error will be nil on success.
// Possible reasons for error:
// 1. Communications failure
- (void)queryActivityWithCompletionHandler:(void(^)(NSInteger activity, NSError *error))completionHandler;

@end
