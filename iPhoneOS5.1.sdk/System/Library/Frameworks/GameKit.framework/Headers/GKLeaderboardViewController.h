//
//  GKLeaderboardViewController.h
//  GameKit
//
//  Copyright 2010 Apple, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GameKit/GKLeaderboard.h>

@protocol GKLeaderboardViewControllerDelegate;

// View controller that provides the standard user interface for leaderboards.  Present modally from the top view controller.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKLeaderboardViewController : UINavigationController

@property (nonatomic, assign) GKLeaderboardTimeScope timeScope;
@property (nonatomic, retain) NSString *category;
@property (nonatomic, assign) id <GKLeaderboardViewControllerDelegate> leaderboardDelegate;

@end

@protocol GKLeaderboardViewControllerDelegate
@required
// The leaderboard view has finished
- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController;
@end
