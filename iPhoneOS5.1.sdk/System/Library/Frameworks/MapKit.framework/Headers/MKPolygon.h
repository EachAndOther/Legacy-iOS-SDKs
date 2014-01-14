//
//  MKPolygon.h
//  MapKit
//
//  Copyright (c) 2010-2011, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MapKit/MKMultiPoint.h>
#import <MapKit/MKOverlay.h>
#import <MapKit/MKFoundation.h>

MK_CLASS_AVAILABLE(NA, 4_0)
@interface MKPolygon : MKMultiPoint <MKOverlay> {
@package
    CLLocationCoordinate2D _centroid;
    NSArray *_interiorPolygons;
    BOOL _isDefinitelyConvex;
}

+ (MKPolygon *)polygonWithPoints:(MKMapPoint *)points count:(NSUInteger)count;
+ (MKPolygon *)polygonWithPoints:(MKMapPoint *)points count:(NSUInteger)count interiorPolygons:(NSArray *)interiorPolygons;

+ (MKPolygon *)polygonWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;
+ (MKPolygon *)polygonWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count interiorPolygons:(NSArray *)interiorPolygons;

@property (readonly) NSArray *interiorPolygons;

@end
