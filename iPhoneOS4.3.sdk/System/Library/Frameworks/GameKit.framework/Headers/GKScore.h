//
//  GKScore.h
//  GameKit
//
//  Copyright 2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <GameKit/GKLeaderboard.h>

@class GKPlayer;

// GKScore represents a score in the leaderboards.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKScore : NSObject <NSCoding> {
}

// Designated initializer. Will initialize the score with the local player and current date. 
- (id)initWithCategory:(NSString *)category;

@property(nonatomic, assign)            int64_t     value;              // The score value as a 64bit integer.
@property(nonatomic, readonly, retain)  NSString    *formattedValue;    // The score formatted as a string, localized with a label

@property(nonatomic, retain)            NSString    *category;          // leaderboard category (required)

@property(nonatomic, readonly, retain)  NSDate      *date;              // The date the score was recorded, defaults to [NSDate date].
@property(nonatomic, readonly, retain)  NSString    *playerID;          // The identifier of the player that recorded the score.
@property(nonatomic, readonly, assign)  NSInteger   rank;               // The rank of the player within the leaderboard, only valid when returned from GKLeaderboard

// Report this score to the server. The value must be set, and date may be changed.
// Possible reasons for error:
// 1. Value not set
// 2. Local player not authenticated
// 3. Communications problem
- (void)reportScoreWithCompletionHandler:(void(^)(NSError *error))completionHandler;

@end
