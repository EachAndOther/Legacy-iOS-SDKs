/*
 *  GKAchievementViewController.h
 *  GameKit
 *
 *  Copyright 2010 Apple, Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <GameKit/GKGameCenterViewController.h>

@protocol GKAchievementViewControllerDelegate;

// View controller that provides the standard user interface for achievements. Present modally from the top view controller.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKAchievementViewController : GKGameCenterViewController

// Optional delegate
@property (nonatomic, assign) id<GKAchievementViewControllerDelegate> achievementDelegate;

@end

// Optional delegate
@protocol GKAchievementViewControllerDelegate
@required
// The achievement view has finished
- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController;
@end


