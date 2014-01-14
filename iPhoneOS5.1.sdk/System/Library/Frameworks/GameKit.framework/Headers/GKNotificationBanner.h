//
//  GKNotificationBanner.h
//  GameKit
//
//  Created by Nathan Taylor on 1/31/11.
//  Copyright 2011 Apple, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

// Asynchronously shows a notification banner like the one used for Game Center’s “Welcome Back” message. 
// If a banner is already being displayed, additional banners will be shown in sequence. Use this to notify the user of game events, high scores, completed achievements, etc.

NS_CLASS_AVAILABLE(NA, 5_0)
@interface GKNotificationBanner : NSObject
+ (void)showBannerWithTitle:(NSString *)title message:(NSString *)message completionHandler:(void(^)(void))completionHandler __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
@end

