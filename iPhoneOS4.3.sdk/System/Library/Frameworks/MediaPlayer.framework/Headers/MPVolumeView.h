//
//  MPVolumeView.h
//  MediaPlayer
//
//  Copyright 2008-2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayerDefines.h>

MP_EXTERN_CLASS_AVAILABLE(2_0) @interface MPVolumeView : UIView <NSCoding> {
@private
    void *_internal;
}

- (CGSize)sizeThatFits:(CGSize)size;

@property (nonatomic) BOOL showsVolumeSlider NS_AVAILABLE_IPHONE(4_2); // Default is YES.
@property (nonatomic) BOOL showsRouteButton NS_AVAILABLE_IPHONE(4_2);  // Default is YES.

@end
