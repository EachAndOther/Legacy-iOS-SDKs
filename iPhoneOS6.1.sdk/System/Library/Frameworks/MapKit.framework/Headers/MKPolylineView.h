//
//  MKPolylineView.h
//  MapKit
//
//  Copyright (c) 2010-2012, Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <MapKit/MKPolyline.h>
#import <MapKit/MKOverlayPathView.h>
#import <MapKit/MKFoundation.h>

MK_CLASS_AVAILABLE(NA, 4_0)
@interface MKPolylineView : MKOverlayPathView

- (id)initWithPolyline:(MKPolyline *)polyline;

@property (nonatomic, readonly) MKPolyline *polyline;

@end
