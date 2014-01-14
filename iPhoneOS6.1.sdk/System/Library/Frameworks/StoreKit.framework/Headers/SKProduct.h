//
//  SKProduct.h
//  StoreKit
//
//  Copyright 2009 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

SK_EXTERN_CLASS_AVAILABLE(3_0) @interface SKProduct : NSObject {
@private
    id _internal;
}

@property(nonatomic, readonly) NSString *localizedDescription __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly) NSString *localizedTitle __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly) NSDecimalNumber *price __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly) NSLocale *priceLocale __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly) NSString *productIdentifier __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// YES if this product has content downloadable using SKDownload
@property(nonatomic, readonly, getter=isDownloadable) BOOL downloadable __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Sizes in bytes (NSNumber [long long]) of the downloads available for this product
@property(nonatomic, readonly) NSArray *downloadContentLengths __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

// Version of the downloadable content
@property(nonatomic, readonly) NSString *downloadContentVersion __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

@end
