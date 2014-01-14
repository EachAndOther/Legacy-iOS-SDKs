//
//  ADBannerView.h
//  iAd
//
//  Copyright 2010 Apple, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>


enum {
#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
    ADErrorUnknown = 0,
    ADErrorServerFailure = 1,
    ADErrorLoadingThrottled = 2,
    ADErrorInventoryUnavailable = 3,
#endif
#if __IPHONE_4_1 <= __IPHONE_OS_VERSION_MAX_ALLOWED
    ADErrorConfigurationError = 4,
    ADErrorBannerVisibleWithoutContent = 5,
#endif
#if __IPHONE_4_3 <= __IPHONE_OS_VERSION_MAX_ALLOWED
    ADErrorApplicationInactive = 6,
#endif
};
typedef NSUInteger ADError;

@protocol ADBannerViewDelegate;

/*!
 ADBannerView provides a view to display advertisements inline with other application views.
 Advertisements are automatically loaded and presented. When a banner view is tapped, the current
 advertisement will begin its "action". In most cases, the action displays a full screen,
 "mini-application", an immersive advertisement based on HTML5 with custom extensions for using
 maps and direct purchasing from iTunes.

 ADBannerView must be added to a view hierarchy managed by a UIViewController.
 */

NS_CLASS_AVAILABLE(NA, 4_0) @interface ADBannerView : UIView

// The banner view delegate is notified when advertisements are loaded, when errors occur in
// getting ads, and when banner actions begin and end.
// Applications built against the iOS 5.0 or later SDK and when running on iOS 5.0 or later
// may treat the delegate as if it was 'weak' instead of 'assign' (aka _unsafe_unretained).
@property (nonatomic, assign) id <ADBannerViewDelegate> delegate;

// YES if an advertisement is loaded, NO otherwise.
@property (nonatomic, readonly, getter=isBannerLoaded) BOOL bannerLoaded;

// Set of content size identifiers the banner needs for display. Multiple size identifiers should only
// be specified necessary if the banner view will actually change size while ad content is loaded,
// such as when its view controller autorotates. This indicates to the ad server that it must only
// provide ads which have a visible representation for all of the specified size identifiers. The set
// must include only supported constants.
// On iOS 4.0-4.1, defaults to {ADBannerContentSizeIdentifier320x50}.
// On iOS 4.2, defaults to {ADBannerContentSizeIdentifierPortrait, ADBannerContentSizeIdentifierLandscape}.
@property (nonatomic, copy) NSSet *requiredContentSizeIdentifiers;

// The content size identifier for the current display mode. This will resize the banner view appropriately.
// This value must be one of the specified requiredContentSizeIdentifiers, or an exception will be thrown.
// If not specified, a content size identifier will be selected from the requiredContentSizeIdentifiers set.
// Generally this property should be set immediately any time requiredContentSizeIdentifiers is changed.
@property (nonatomic, copy) NSString *currentContentSizeIdentifier;

// This method returns a CGSize matching the dimensions of the associated content size identifier.
// An exception will be thrown if the identifier is not one of the supported constants.
+ (CGSize)sizeFromBannerContentSizeIdentifier:(NSString *)contentSizeIdentifier;

// Reserved for future use.
@property (nonatomic, copy) NSString *advertisingSection;

// Some banner actions display full screen content in a modal session. Use this property to determine
// if such an action is currently in progress.
@property (nonatomic, readonly, getter=isBannerViewActionInProgress) BOOL bannerViewActionInProgress;

// Cancels the current in-progress banner view action. This should only be used in cases where the
// user's attention is required immediately.
- (void)cancelBannerViewAction;

@end

@protocol ADBannerViewDelegate <NSObject>
@optional

// This method is invoked when the banner has confirmation that an ad will be presented, but before the ad
// has loaded resources necessary for presentation.
- (void)bannerViewWillLoadAd:(ADBannerView *)banner __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

// This method is invoked each time a banner loads a new advertisement. Once a banner has loaded an ad,
// it will display that ad until another ad is available. The delegate might implement this method if
// it wished to defer placing the banner in a view hierarchy until the banner has content to display.
- (void)bannerViewDidLoadAd:(ADBannerView *)banner;

// This method will be invoked when an error has occurred attempting to get advertisement content.
// The ADError enum lists the possible error codes.
- (void)bannerView:(ADBannerView *)banner didFailToReceiveAdWithError:(NSError *)error;

// This message will be sent when the user taps on the banner and some action is to be taken.
// Actions either display full screen content in a modal session or take the user to a different
// application. The delegate may return NO to block the action from taking place, but this
// should be avoided if possible because most advertisements pay significantly more when
// the action takes place and, over the longer term, repeatedly blocking actions will
// decrease the ad inventory available to the application. Applications may wish to pause video,
// audio, or other animated content while the advertisement's action executes.
- (BOOL)bannerViewActionShouldBegin:(ADBannerView *)banner willLeaveApplication:(BOOL)willLeave;

// This message is sent when a modal action has completed and control is returned to the application.
// Games, media playback, and other activities that were paused in response to the beginning
// of the action should resume at this point.
- (void)bannerViewActionDidFinish:(ADBannerView *)banner;

@end

extern NSString * const ADErrorDomain;

// Supported sizes of banner ads available from ad server. Dimensions are in points, not pixels.
// The dimensions are part of the value names to assist with design-time planning for view layout.
extern NSString * const ADBannerContentSizeIdentifier320x50 __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_4_0,__IPHONE_4_2);
extern NSString * const ADBannerContentSizeIdentifier480x32 __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_4_0,__IPHONE_4_2);
extern NSString * const ADBannerContentSizeIdentifierPortrait __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_2);
extern NSString * const ADBannerContentSizeIdentifierLandscape __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_2);
