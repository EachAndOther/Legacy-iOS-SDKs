//
//  GKAchievementDescription.h
//  GKAPI
//
//  Copyright 2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// GKAchievementDescription is a full description of the achievement as defined before app submission in iTunes Connect.
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKAchievementDescription : NSObject <NSCoding> {
}

// Asynchronously load all achievement descriptions
+ (void)loadAchievementDescriptionsWithCompletionHandler:(void(^)(NSArray *descriptions, NSError *error))completionHandler;
    
+ (UIImage *)incompleteAchievementImage; // The default image for any incomplete achievement
+ (UIImage *)placeholderCompletedAchievementImage; // A placeholder image to be used for any completed achievement until the description image has loaded.

@property(nonatomic, retain, readonly) NSString *identifier;
@property(nonatomic, retain, readonly) NSString *title;                 // The title of the achievement.
@property(nonatomic, retain, readonly) NSString *achievedDescription;   // The description for an unachieved achievement.
@property(nonatomic, retain, readonly) NSString *unachievedDescription; // The description for an achieved achievement.
@property(nonatomic, assign, readonly) NSInteger maximumPoints;         // Maximum points available for completing this achievement.
@property(nonatomic, getter = isHidden, assign, readonly) BOOL hidden;  // Whether or not the achievement should be listed or displayed if not yet unhidden by the game.
@property(nonatomic, retain, readonly) UIImage *image;                  // Image for completed achievement. Not valid until loadImage: has completed.

// Asynchronously load the image. Error will be nil on success.
- (void)loadImageWithCompletionHandler:(void(^)(UIImage *image, NSError *error))completionHandler;
                                          
@end
