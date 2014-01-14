//
//  MKDirectionsRequest.h
//  MapKit
//
//  Copyright (c) 2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MKMapItem.h>

MK_CLASS_AVAILABLE(NA, 6_0)
@interface MKDirectionsRequest : NSObject

@property (nonatomic, retain, readonly) MKMapItem *source;
@property (nonatomic, retain, readonly) MKMapItem *destination;

- (id)initWithContentsOfURL:(NSURL *)url;
+ (BOOL)isDirectionsRequestURL:(NSURL *)url;

@end
