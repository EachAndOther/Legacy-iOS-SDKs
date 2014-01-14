//
//  MKReverseGeocoder.h
//  MapKit
//
//  Important: The MapKit framework uses Google services to provide map data. Use of this class and
//  the associated interfaces binds you to the Google Maps/Google Earth API terms of service. You can
//  find these terms of service at http://code.google.com/apis/maps/iphone/terms.html
//  
//  Copyright (c) 2009-2011, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <MapKit/MKTypes.h>
#import <MapKit/MKFoundation.h>

@class MKPlacemark;
@class MKReverseGeocoderInternal;
@protocol MKReverseGeocoderDelegate;

// MKReverseGeocoder is now deprecated.
// Use CLGeocoder in CoreLocation instead.
MK_CLASS_DEPRECATED(NA, NA, 3_0, 5_0)
@interface MKReverseGeocoder : NSObject {
@private
    MKReverseGeocoderInternal *_internal;
}

- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate NS_DEPRECATED_IOS(3_0,5_0);


// A MKReverseGeocoder object should only be started once.
- (void)start NS_DEPRECATED_IOS(3_0,5_0);
- (void)cancel NS_DEPRECATED_IOS(3_0,5_0);

@property (nonatomic, assign) id<MKReverseGeocoderDelegate> delegate    NS_DEPRECATED_IOS(3_0,5_0);
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate       NS_DEPRECATED_IOS(3_0,5_0);
@property (nonatomic, readonly) MKPlacemark *placemark                  NS_DEPRECATED_IOS(3_2,5_0);
@property (nonatomic, readonly, getter=isQuerying) BOOL querying        NS_DEPRECATED_IOS(3_0,5_0);

@end

MK_CLASS_DEPRECATED(NA, NA, 3_0, 5_0)
@protocol MKReverseGeocoderDelegate <NSObject>
@required
- (void)reverseGeocoder:(MKReverseGeocoder *)geocoder didFindPlacemark:(MKPlacemark *)placemark NS_DEPRECATED_IOS(3_0,5_0);
// There are at least two types of errors:
//   - Errors sent up from the underlying connection (temporary condition)
//   - Result not found errors (permanent condition).  The result not found errors
//     will have the domain MKErrorDomain and the code MKErrorPlacemarkNotFound
- (void)reverseGeocoder:(MKReverseGeocoder *)geocoder didFailWithError:(NSError *)error NS_DEPRECATED_IOS(3_0,5_0);
@end
