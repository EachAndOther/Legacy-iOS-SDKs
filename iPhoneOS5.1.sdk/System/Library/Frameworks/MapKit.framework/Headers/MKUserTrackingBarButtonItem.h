//
//  MKUserTrackingBarButtonItem.h
//  MapKit
//
//  Copyright (c) 2010-2011, Apple Inc. All rights reserved.
//

#import <UIKit/UIBarButtonItem.h>
#import <MapKit/MKFoundation.h>

@class MKMapView;

MK_CLASS_AVAILABLE(NA, 5_0)
@interface MKUserTrackingBarButtonItem : UIBarButtonItem {

}

- (id)initWithMapView:(MKMapView *)mapView;
@property (nonatomic, retain) MKMapView *mapView;

@end
