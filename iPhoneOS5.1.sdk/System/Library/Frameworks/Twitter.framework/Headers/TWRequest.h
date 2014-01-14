//
//  TWRequest.h
//  Twitter
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ACAccount;

enum TWRequestMethod {
    TWRequestMethodGET,
    TWRequestMethodPOST,
    TWRequestMethodDELETE
};

typedef enum TWRequestMethod TWRequestMethod; // available in iPhone 5.0

// Completion block for performRequestWithHandler. 
typedef void(^TWRequestHandler)(NSData *responseData, NSHTTPURLResponse *urlResponse, NSError *error);

NS_CLASS_AVAILABLE(NA, 5_0) 
@interface TWRequest : NSObject {
}

- (id)initWithURL:(NSURL *)url parameters:(NSDictionary *)parameters requestMethod:(TWRequestMethod)requestMethod;

// Optional account information used to authenticate the request. Defaults to nil.
@property (nonatomic, retain) ACAccount *account;

// The request method
@property (nonatomic, readonly) TWRequestMethod requestMethod;

// The request URL
@property (nonatomic, readonly) NSURL *URL;

// The parameters 
@property (nonatomic, readonly) NSDictionary *parameters;

// Specify a named MIME multi-part value.
- (void)addMultiPartData:(NSData*)data withName:(NSString*)name type:(NSString*)type; 

// Returns an OAuth compatible NSURLRequest for use with NSURLConnection. 
- (NSURLRequest *)signedURLRequest;

// Issue the request. This block is not guaranteed to be called on any particular thread.
- (void)performRequestWithHandler:(TWRequestHandler)handler;

@end
