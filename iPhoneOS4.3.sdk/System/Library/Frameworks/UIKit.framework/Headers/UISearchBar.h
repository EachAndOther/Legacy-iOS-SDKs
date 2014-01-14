//
//  UISearchBar.h
//  UIKit
//
//  Copyright 2008-2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIKitDefines.h>

@protocol UISearchBarDelegate;
@class UITextField, UILabel, UIButton, UIColor;

UIKIT_CLASS_AVAILABLE(2_0) @interface UISearchBar : UIView { 
  @private
    UITextField            *_searchField;
    UILabel                *_promptLabel;
    UIButton               *_cancelButton;
    id<UISearchBarDelegate> _delegate;
    id                      _controller;
    UIColor                *_tintColor;
    UIImageView            *_separator;
    NSString               *_cancelButtonText;
    NSArray                *_scopes;
    NSInteger               _selectedScope;
    UIView                 *_background;
    UIView                 *_scopeBar;
    UIEdgeInsets            _contentInset;
    id                      _appearance;
    struct {
        unsigned int barStyle:3;
        unsigned int showsBookmarkButton:1;
        unsigned int showsCancelButton:1;
        unsigned int isTranslucent:1;
        unsigned int autoDisableCancelButton:1;
        unsigned int showsScopeBar:1;
        unsigned int hideBackground:1;
        unsigned int combinesLandscapeBars:1;
        unsigned int usesEmbeddedAppearance:1;
        unsigned int showsSearchResultsButton:1;
        unsigned int searchResultsButtonSelected:1;
        unsigned int pretendsIsInBar:1;
        unsigned int disabled:1;
    } _searchBarFlags;
}

@property(nonatomic)        UIBarStyle              barStyle;              // default is UIBarStyleDefault (blue)
@property(nonatomic,assign) id<UISearchBarDelegate> delegate;              // weak reference. default is nil
@property(nonatomic,copy)   NSString               *text;                  // current/starting search text
@property(nonatomic,copy)   NSString               *prompt;                // default is nil
@property(nonatomic,copy)   NSString               *placeholder;           // default is nil
@property(nonatomic)        BOOL                    showsBookmarkButton;   // default is NO
@property(nonatomic)        BOOL                    showsCancelButton;     // default is NO
@property(nonatomic)        BOOL                    showsSearchResultsButton __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_2); // default is NO
@property(nonatomic, getter=isSearchResultsButtonSelected) BOOL searchResultsButtonSelected __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_2); // default is NO
- (void)setShowsCancelButton:(BOOL)showsCancelButton animated:(BOOL)animated __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic,retain) UIColor                *tintColor;             // default is nil
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0); // Default is NO. Always YES if barStyle is set to UIBarStyleBlackTranslucent

// available text input traits
@property(nonatomic) UITextAutocapitalizationType autocapitalizationType;  // default is UITextAutocapitalizationTypeNone
@property(nonatomic) UITextAutocorrectionType     autocorrectionType;      // default is UITextAutocorrectionTypeDefault
@property(nonatomic) UIKeyboardType               keyboardType;            // default is UIKeyboardTypeDefault

@property(nonatomic,copy) NSArray   *scopeButtonTitles        __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0); // array of NSStrings. no scope bar shown unless 2 or more items
@property(nonatomic)      NSInteger  selectedScopeButtonIndex __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0); // index into array of scope button titles. default is 0. ignored if out of range
@property(nonatomic)      BOOL       showsScopeBar            __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0); // default is NO. if YES, shows the scope bar. call sizeToFit: to update frame

@end

@protocol UISearchBarDelegate <NSObject>

@optional

- (BOOL)searchBarShouldBeginEditing:(UISearchBar *)searchBar;                      // return NO to not become first responder
- (void)searchBarTextDidBeginEditing:(UISearchBar *)searchBar;                     // called when text starts editing
- (BOOL)searchBarShouldEndEditing:(UISearchBar *)searchBar;                        // return NO to not resign first responder
- (void)searchBarTextDidEndEditing:(UISearchBar *)searchBar;                       // called when text ends editing
- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText;   // called when text changes (including clear)
- (BOOL)searchBar:(UISearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0); // called before text changes

- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar;                     // called when keyboard search button pressed
- (void)searchBarBookmarkButtonClicked:(UISearchBar *)searchBar;                   // called when bookmark button pressed
- (void)searchBarCancelButtonClicked:(UISearchBar *) searchBar;                    // called when cancel button pressed
- (void)searchBarResultsListButtonClicked:(UISearchBar *)searchBar __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_2); // called when search results button pressed

- (void)searchBar:(UISearchBar *)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@end
