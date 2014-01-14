//
//  GKGameCenterViewController.h
//  GameKit
//
//  Copyright 2012 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GameKit/GKLeaderboard.h>

@class GKMatch, GKMatchRequest, GKInvite;
@protocol GKGameCenterControllerDelegate;

typedef enum /*: NSInteger */ {
    GKGameCenterViewControllerStateDefault = -1,
    GKGameCenterViewControllerStateLeaderboards ,
    GKGameCenterViewControllerStateAchievements,
    GKGameCenterViewControllerStateChallenges,
} GKGameCenterViewControllerState;

NS_CLASS_AVAILABLE(NA, 6_0)
@interface GKGameCenterViewController : UINavigationController

@property (nonatomic, assign)   id<GKGameCenterControllerDelegate>      gameCenterDelegate;
@property (nonatomic, assign)   GKGameCenterViewControllerState         viewState;

@end

@interface GKGameCenterViewController (Leaderboards)

@property (nonatomic, assign)   GKLeaderboardTimeScope                  leaderboardTimeScope;   // Implies showing leaderboards
@property (nonatomic, retain)   NSString                                *leaderboardCategory;   // Implies showing leaderboards

@end

@protocol GKGameCenterControllerDelegate <NSObject>

- (void)gameCenterViewControllerDidFinish:(GKGameCenterViewController *)gameCenterViewController;

@end


