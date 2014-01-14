//
//  EKSource.h
//  EventKit
//
//  Copyright 2009-2011 Apple Inc. All rights reserved.
//

#import <EventKit/EventKitDefines.h>
#import <EventKit/EKObject.h>
#import <EventKit/EKTypes.h>

@class EKEventStore;

EVENTKIT_CLASS_AVAILABLE(5_0)
@interface EKSource : EKObject

@property(nonatomic, readonly) NSString        *sourceIdentifier;
@property(nonatomic, readonly) EKSourceType     sourceType;
@property(nonatomic, readonly) NSString        *title;
@property(nonatomic, readonly) NSSet           *calendars;

@end
