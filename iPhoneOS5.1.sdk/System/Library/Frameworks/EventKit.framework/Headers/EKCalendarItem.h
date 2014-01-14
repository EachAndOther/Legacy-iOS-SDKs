//
//  EKCalendarItem.h
//  EventKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <EventKit/EKObject.h>

@class EKRecurrenceRule, EKAlarm, EKCalendar, EKLocation;

@interface EKCalendarItem : EKObject {

}

@property(nonatomic, readonly) NSString *UUID;

@property(nonatomic, retain) EKCalendar *calendar;


@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *location;
@property(nonatomic, copy) NSString *notes;
@property(nonatomic, copy) NSURL *URL __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

@property(nonatomic, readonly) NSDate *lastModifiedDate;
@property(nonatomic, readonly) NSDate *creationDate __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0); // might be nil
@property(nonatomic, copy) NSTimeZone *timeZone  __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

// These exist to do simple checks for the presence of data without
// loading said data. While at present only hasRecurrenceRules has a
// fast path, it is a good idea to use these if you only need to know
// the data exists anyway since at some point they will all be a
// simple check.
@property(nonatomic, readonly) BOOL hasAlarms  __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
@property(nonatomic, readonly) BOOL hasRecurrenceRules  __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
@property(nonatomic, readonly) BOOL hasAttendees  __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
@property(nonatomic, readonly) BOOL hasNotes  __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

// An array of EKParticipant objects
@property(nonatomic, readonly) NSArray *attendees;

// An array of EKAlarm objects
@property(nonatomic, copy) NSArray *alarms;

/*!
    @method     addAlarm:
    @abstract   Adds an alarm to this item.
    @discussion This method add an alarm to an item. Be warned that some calendars can only
                allow a certain maximum number of alarms. When this item is saved, it will
                truncate any extra alarms from the array.
*/
- (void)addAlarm:(EKAlarm *)alarm;

/*!
    @method     removeAlarm:
    @abstract   Removes an alarm from this item.
*/
- (void)removeAlarm:(EKAlarm *)alarm;


/*!
    @property   recurrenceRules
    @abstract   An array of EKRecurrenceRules, or nil if none.
*/
@property(nonatomic, copy) NSArray *recurrenceRules __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

- (void)addRecurrenceRule:(EKRecurrenceRule *)rule;
- (void)removeRecurrenceRule:(EKRecurrenceRule *)rule;

@end
