//
//  PKPass.h
//  PassKit
//
//  Copyright (c) 2011 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIImage;

NS_CLASS_AVAILABLE_IOS(6_0)
@interface PKPass : NSObject

- (id)initWithData:(NSData *)data error:(NSError **)error; 

@property (nonatomic,copy,readonly) NSString     *serialNumber;
@property (nonatomic,copy,readonly) NSString     *passTypeIdentifier;
@property (nonatomic,copy,readonly) NSURL        *webServiceURL;
@property (nonatomic,copy,readonly) NSString     *authenticationToken;

@property (nonatomic,copy,readonly) UIImage      *icon;
@property (nonatomic,copy,readonly) NSString     *localizedName; // e.g. "Boarding Pass"
@property (nonatomic,copy,readonly) NSString     *localizedDescription; // e.g. "SFO -> LHR"
@property (nonatomic,copy,readonly) NSString     *organizationName; // e.g. "Great Airways"
@property (nonatomic,copy,readonly) NSDate       *relevantDate; // may be useful for sorting

@property (nonatomic,copy,readonly) NSURL        *passURL; // open to view pass in Passbook.app

- (id)localizedValueForFieldKey:(NSString *)key; // IBOutlet-like; allows access to field data from pass file format

@end

// domain for NSError
extern NSString *const PKPassKitErrorDomain NS_AVAILABLE_IOS(6_0);

typedef NS_ENUM(NSInteger, PKPassKitErrorCode) {
    PKUnknownError = -1,
    PKInvalidDataError = 1,
    PKUnsupportedVersionError,
    PKInvalidSignature,
} NS_ENUM_AVAILABLE_IOS(6_0);


