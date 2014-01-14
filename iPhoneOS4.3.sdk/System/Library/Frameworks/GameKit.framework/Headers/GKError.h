/*
 *  GKError.h
 *  GameKit
 *
 *  Copyright 2010 Apple, Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <GameKit/GKDefines.h>

GK_EXTERN NSString *GKErrorDomain;

enum {
    GKErrorUnknown = 1,
    GKErrorCancelled,
    GKErrorCommunicationsFailure,
    GKErrorUserDenied,
    GKErrorInvalidCredentials,
    GKErrorNotAuthenticated,
    GKErrorAuthenticationInProgress,
    GKErrorInvalidPlayer,
    GKErrorScoreNotSet,
    GKErrorParentalControlsBlocked,
    GKErrorPlayerStatusExceedsMaximumLength,
    GKErrorPlayerStatusInvalid,
    GKErrorMatchRequestInvalid,
    GKErrorUnderage,
    GKErrorGameUnrecognized,
    GKErrorNotSupported,
    GKErrorInvalidParameter,
};
typedef NSInteger GKErrorCode;

