//
//  PKError.h
//  PassKit
//
//  Copyright (c) 2011 Apple, Inc. All rights reserved.
//


extern NSString * const PKErrorDomain;

typedef enum PKErrorCode {
    PKErrorUnknown = 1,
    PKErrorPassSignatureInvalid,
    PKErrorNotEntitled
} PKErrorCode;