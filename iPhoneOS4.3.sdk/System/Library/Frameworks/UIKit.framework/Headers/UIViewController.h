//
//  UIViewController.h
//  UIKit
//
//  Copyright 2007-2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIApplication.h>

/*!
 UIViewController is a generic controller base class that manages a view.
 It has methods that are called when a view appears or disappears.
 
 Subclasses can override -loadView to create their custom view hierarchy, or specify a nib name to be loaded automatically.
 This class is also a good place for delegate & datasource methods, and other controller stuff.
 */

@class UIView, UIImage;
@class UINavigationItem, UIBarButtonItem, UITabBarItem;
@class UITabBarController, UINavigationController, UISearchDisplayController;
@class NSHashTable;
@class UIPopoverController, UIDimmingView, UIDropShadowView;

typedef enum {
    UIModalTransitionStyleCoverVertical = 0,
    UIModalTransitionStyleFlipHorizontal,
    UIModalTransitionStyleCrossDissolve,
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
    UIModalTransitionStylePartialCurl,
#endif
} UIModalTransitionStyle;

typedef enum {
    UIModalPresentationFullScreen = 0,
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
    UIModalPresentationPageSheet,
    UIModalPresentationFormSheet,
    UIModalPresentationCurrentContext,
#endif
} UIModalPresentationStyle;


UIKIT_CLASS_AVAILABLE(2_0) @interface UIViewController : UIResponder <NSCoding> {
    @package
    UIView           *_view;
    UITabBarItem     *_tabBarItem;
    UINavigationItem *_navigationItem;
    NSArray			 *_toolbarItems;
    NSString         *_title;
    
    NSString         *_nibName;
    NSBundle         *_nibBundle;
    
    UIViewController *_parentViewController; // Nonretained
    NSHashTable      *_childViewControllers; // Nonretained
    
    UIViewController *_childModalViewController;
    UIViewController *_parentModalViewController; // This is vestigial.
    UIView           *_modalTransitionView;
    UIResponder		 *_modalPreservedFirstResponder;
    UIResponder      *_defaultFirstResponder;
    UIDimmingView    *_dimmingView;
    UIDropShadowView *_dropShadowView;
    UIView           *_presentationSuperview;
    UIView           *_sheetView;
    id                _currentAction;
    
    UIView           *_savedHeaderSuperview;
    UIView           *_savedFooterSuperview;
    
    UIBarButtonItem  *_editButtonItem;
    
    UISearchDisplayController   *_searchDisplayController;
    
    UIPopoverController*    _popoverController;

    
    UIModalTransitionStyle _modalTransitionStyle;
    UIModalPresentationStyle _modalPresentationStyle;
    
    UIInterfaceOrientation _lastKnownInterfaceOrientation;
    CGSize _contentSizeForViewInPopover;
    CGSize _formSheetSize;
    
    struct {
        unsigned int appearState:2;
        unsigned int isEditing:1;
        unsigned int isPerformingModalTransition:1;
        unsigned int hidesBottomBarWhenPushed:1;
        unsigned int autoresizesArchivedViewToFullSize:1;
        unsigned int viewLoadedFromControllerNib:1;
        unsigned int isRootViewController:1;
        unsigned int isSheet:1;
        unsigned int isSuspended:1;
        unsigned int wasApplicationFrameAtSuspend:1;
        unsigned int wantsFullScreenLayout:1;
        unsigned int shouldUseFullScreenLayout:1;
        unsigned int allowsAutorotation:1;
        unsigned int searchControllerRetained:1;
	unsigned int oldModalInPopover:1;
	unsigned int isModalInPopover:1;
        unsigned int restoreDeepestFirstResponder:1;
        unsigned int isInWillRotateCallback:1;
        unsigned int disallowMixedOrientationPresentations:1;
        unsigned int modalPresentationsAreCurrentContext:1;                
    } _viewControllerFlags;
}

// The designated initializer. If you subclass UIViewController, you must call the super implementation of this method, even if you aren't using a NIB.
// (As a convenience, the default init method will do this for you, and specify nil for both of this methods arguments.) In the specified NIB, the File's Owner proxy should
// have its class set to your view controller subclass, with the view outlet connected to the main view. If you invoke this method with a nil nib name, then this class' -loadView 
// method will attempt to load a NIB whose name is the same as your view controller's class. If no such NIB in fact exists then you must either call -setView: before -view is 
// invoked, or override the -loadView method to set up your views programatically.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;

@property(nonatomic,retain) UIView *view; // The getter first invokes [self loadView] if the view hasn't been set yet. Subclasses must call super if they override the setter or getter.
- (void)loadView; // This is where subclasses should create their custom view hierarchy if they aren't using a nib. Should never be called directly.
- (void)viewDidLoad; // Called after the view has been loaded. For view controllers created in code, this is after -loadView. For view controllers unarchived from a nib, this is after the view is set.
- (void)viewDidUnload __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0); // Called after the view controller's view is released and set to nil. For example, a memory warning which causes the view to be purged. Not invoked as a result of -dealloc.
- (BOOL)isViewLoaded __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly, copy) NSString *nibName;     // The name of the nib to be loaded to instantiate the view.
@property(nonatomic, readonly, retain) NSBundle *nibBundle; // The bundle from which to load the nib.

- (void)viewWillAppear:(BOOL)animated;    // Called when the view is about to made visible. Default does nothing
- (void)viewDidAppear:(BOOL)animated;     // Called when the view has been fully transitioned onto the screen. Default does nothing
- (void)viewWillDisappear:(BOOL)animated; // Called when the view is dismissed, covered or otherwise hidden. Default does nothing
- (void)viewDidDisappear:(BOOL)animated;  // Called after the view was dismissed, covered or otherwise hidden. Default does nothing

@property(nonatomic,copy) NSString *title;  // Localized title for use by a parent controller.

- (void)didReceiveMemoryWarning; // Called when the parent application receives a memory warning. Default implementation releases the view if it doesn't have a superview.

- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated; // Display another view controller as a modal child. Uses a vertical sheet transition if animated.
- (void)dismissModalViewControllerAnimated:(BOOL)animated; // Dismiss the current modal child. Uses a vertical sheet transition if animated.

@property(nonatomic,readonly) UIViewController *modalViewController;

// Defines the transition style that will be used for this view controller when it is presented modally. Set this property on the view controller to be presented, not the presenter.
// Defaults to UIModalTransitionStyleCoverVertical.
@property(nonatomic,assign) UIModalTransitionStyle modalTransitionStyle __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic,assign) UIModalPresentationStyle modalPresentationStyle __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_2);

// Presentation modes may keep the keyboard visible when not required. Default implementation affects UIModalPresentationFormSheet visibility.
- (BOOL)disablesAutomaticKeyboardDismissal __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_3);

@property(nonatomic,assign) BOOL wantsFullScreenLayout __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic,readonly) UIViewController *parentViewController; // If this view controller is inside a navigation controller or tab bar controller, or has been presented modally by another view controller, return it.
@end

// To make it more convenient for applications to adopt rotation, a view controller may implement the below methods.
// Your UIWindow's frame should use [UIScreen mainScreen].bounds as its frame.
@interface UIViewController (UIViewControllerRotation)

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation; // Override to allow rotation. Default returns YES only for UIInterfaceOrientationPortrait

// The rotating header and footer views will slide out during the rotation and back in once it has completed.
- (UIView *)rotatingHeaderView;     // Must be in the view hierarchy. Default returns nil.
- (UIView *)rotatingFooterView;     // Must be in the view hierarchy. Default returns the active keyboard.

@property(nonatomic,readonly) UIInterfaceOrientation interfaceOrientation;

// Notifies when rotation begins, reaches halfway point and ends.
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;

// Faster one-part variant, called from within a rotating animation block, for additional animations during rotation.
// A subclass may override this method, or the two-part variants below, but not both.
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// Slower two-part variant, called from within a rotating animation block, for additional animations during rotation.
// A subclass may override these methods, or the one-part variant above, but not both.
- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)didAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation; // The rotating header and footer views are offscreen.
- (void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation duration:(NSTimeInterval)duration; // A this point, our view orientation is set to the new orientation.

@end

// Many view controllers have a view that may be in an editing state or not- for example, a UITableView.
// These view controllers can track the editing state, and generate an Edit|Done button to be used in a navigation bar.
@interface UIViewController (UIViewControllerEditing)

@property(nonatomic,getter=isEditing) BOOL editing;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated; // Updates the appearance of the Edit|Done button item as necessary. Clients who override it must call super first.

- (UIBarButtonItem *)editButtonItem; // Return an Edit|Done button that can be used as a navigation item's custom view. Default action toggles the editing state with animation.

@end

@interface UIViewController (UISearchDisplayControllerSupport)

@property(nonatomic, readonly, retain) UISearchDisplayController *searchDisplayController;

@end
