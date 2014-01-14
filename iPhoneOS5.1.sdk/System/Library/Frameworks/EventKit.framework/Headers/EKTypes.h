/*
 *  EKTypes.h
 *  Calendar
 *
 *  Created by Ed Voas on 3/14/11.
 *  Copyright 2011 Apple Inc. All rights reserved.
 *
 */

enum {
    EKSunday = 1,
    EKMonday,
    EKTuesday,
    EKWednesday,
    EKThursday,
    EKFriday,
    EKSaturday
};

/*!
    @enum       EKRecurrenceFrequency
    @abstract   The frequency of a recurrence
    @discussion EKRecurrenceFrequency designates the unit of time used to describe the recurrence.
                It has four possible values, which correspond to recurrence rules that are defined
                in terms of days, weeks, months, and years.
*/
typedef enum {
    EKRecurrenceFrequencyDaily,
    EKRecurrenceFrequencyWeekly,
    EKRecurrenceFrequencyMonthly,
    EKRecurrenceFrequencyYearly
} EKRecurrenceFrequency;

/*!
 @enum       EKParticipantType
 @abstract   Value representing the type of attendee.
 */
typedef enum {
    EKParticipantTypeUnknown,
    EKParticipantTypePerson,
    EKParticipantTypeRoom,
    EKParticipantTypeResource,
    EKParticipantTypeGroup
} EKParticipantType;

/*!
 @enum       EKParticipantRole
 @abstract   Value representing the role of a meeting participant.
 */
typedef enum {
    EKParticipantRoleUnknown,
    EKParticipantRoleRequired,
    EKParticipantRoleOptional,
    EKParticipantRoleChair,
    EKParticipantRoleNonParticipant
} EKParticipantRole;

/*!
 @enum       EKParticipantStatus
 @abstract   Value representing the status of a meeting participant.
 */
typedef enum {
    EKParticipantStatusUnknown,
    EKParticipantStatusPending,
    EKParticipantStatusAccepted,
    EKParticipantStatusDeclined,
    EKParticipantStatusTentative,
    EKParticipantStatusDelegated,
    EKParticipantStatusCompleted,
    EKParticipantStatusInProcess
} EKParticipantStatus;


/*!
 @enum       EKCalendarType
 @abstract   An enum representing the type of a calendar.
 
 @constant   EKCalendarTypeLocal        This calendar is sync'd from either Mobile Me or tethered.
 @constant   EKCalendarTypeCalDAV       This calendar is from a CalDAV server.
 @constant   EKCalendarTypeExchange     This calendar comes from an Exchange server.
 @constant   EKCalendarTypeSubscription This is a subscribed calendar.
 @constant   EKCalendarTypeBirthday     This is the built-in birthday calendar.
 */

typedef enum {
    EKCalendarTypeLocal,
    EKCalendarTypeCalDAV,
    EKCalendarTypeExchange,
    EKCalendarTypeSubscription,
    EKCalendarTypeBirthday,
} EKCalendarType;

// Event availability support (free/busy)
enum {
    EKCalendarEventAvailabilityNone         = 0,    // calendar doesn't support event availability
    
    EKCalendarEventAvailabilityBusy         = (1 << 0),
    EKCalendarEventAvailabilityFree         = (1 << 1),
    EKCalendarEventAvailabilityTentative    = (1 << 2),
    EKCalendarEventAvailabilityUnavailable  = (1 << 3),
};
typedef NSUInteger EKCalendarEventAvailabilityMask;

typedef enum {
    EKSourceTypeLocal,
    EKSourceTypeExchange,
    EKSourceTypeCalDAV,
    EKSourceTypeMobileMe,
    EKSourceTypeSubscribed,
    EKSourceTypeBirthdays
} EKSourceType;
