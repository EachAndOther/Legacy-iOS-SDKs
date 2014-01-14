//
//  TWTweetComposeViewController.h
//  Twitter
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

enum TWTweetComposeViewControllerResult {
    TWTweetComposeViewControllerResultCancelled,
    TWTweetComposeViewControllerResultDone
};
typedef enum TWTweetComposeViewControllerResult TWTweetComposeViewControllerResult;   // available in iPhone 5.0

// Completion handler for TWTweetComposeViewController
typedef void (^TWTweetComposeViewControllerCompletionHandler)(TWTweetComposeViewControllerResult result); 

UIKIT_CLASS_AVAILABLE(5_0) @interface TWTweetComposeViewController : UIViewController {
}

// Returns if Twitter is accessible and at least one account has been setup.
+ (BOOL)canSendTweet;

// Sets the initial text to be tweeted. Returns NO if the specified text will
// not fit within the character space currently available, or if the sheet
// has already been presented to the user.
- (BOOL)setInitialText:(NSString *)text;

// Adds an image to the tweet. Returns NO if the additional image will not fit
// within the character space currently available, or if the sheet has already
// been presented to the user.
- (BOOL)addImage:(UIImage *)image;

// Removes all images from the tweet. Returns NO and does not perform an operation
// if the sheet has already been presented to the user. 
- (BOOL)removeAllImages;

// Adds a URL to the tweet. Returns NO if the additional URL will not fit
// within the character space currently available, or if the sheet has already
// been presented to the user.
- (BOOL)addURL:(NSURL *)url;

// Removes all URLs from the tweet. Returns NO and does not perform an operation
// if the sheet has already been presented to the user.
- (BOOL)removeAllURLs;

// Specify a block to be called when the user is finished. This block is not guaranteed
// to be called on any particular thread.
@property (nonatomic, copy) TWTweetComposeViewControllerCompletionHandler completionHandler;

@end
