/*	CFCalendar.h
	Copyright (c) 2004-2010, Apple Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFCALENDAR__)
#define __COREFOUNDATION_CFCALENDAR__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFLocale.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFTimeZone.h>

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <=  __IPHONE_OS_VERSION_MAX_ALLOWED

CF_EXTERN_C_BEGIN

typedef struct __CFCalendar * CFCalendarRef;

CF_EXPORT
CFTypeID CFCalendarGetTypeID(void) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFCalendarRef CFCalendarCopyCurrent(void) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFCalendarRef CFCalendarCreateWithIdentifier(CFAllocatorRef allocator, CFStringRef identifier) CF_AVAILABLE(10_4, 2_0);
	// Create a calendar.  The identifiers are the kCF*Calendar
	// constants in CFLocale.h.

CF_EXPORT
CFStringRef CFCalendarGetIdentifier(CFCalendarRef calendar) CF_AVAILABLE(10_4, 2_0);
	// Returns the calendar's identifier.

CF_EXPORT
CFLocaleRef CFCalendarCopyLocale(CFCalendarRef calendar) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
void CFCalendarSetLocale(CFCalendarRef calendar, CFLocaleRef locale) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFTimeZoneRef CFCalendarCopyTimeZone(CFCalendarRef calendar) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
void CFCalendarSetTimeZone(CFCalendarRef calendar, CFTimeZoneRef tz) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFIndex CFCalendarGetFirstWeekday(CFCalendarRef calendar) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
void CFCalendarSetFirstWeekday(CFCalendarRef calendar, CFIndex wkdy) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFIndex CFCalendarGetMinimumDaysInFirstWeek(CFCalendarRef calendar) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
void CFCalendarSetMinimumDaysInFirstWeek(CFCalendarRef calendar, CFIndex mwd) CF_AVAILABLE(10_4, 2_0);


enum {
	kCFCalendarUnitEra = (1UL << 1),
	kCFCalendarUnitYear = (1UL << 2),
	kCFCalendarUnitMonth = (1UL << 3),
	kCFCalendarUnitDay = (1UL << 4),
	kCFCalendarUnitHour = (1UL << 5),
	kCFCalendarUnitMinute = (1UL << 6),
	kCFCalendarUnitSecond = (1UL << 7),
	kCFCalendarUnitWeek = (1UL << 8),
	kCFCalendarUnitWeekday = (1UL << 9),
	kCFCalendarUnitWeekdayOrdinal = (1UL << 10),
#if MAC_OS_X_VERSION_10_6 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_4_0 <=  __IPHONE_OS_VERSION_MAX_ALLOWED
	kCFCalendarUnitQuarter = (1UL << 11),
#endif
};
typedef CFOptionFlags CFCalendarUnit;

CF_EXPORT
CFRange CFCalendarGetMinimumRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFRange CFCalendarGetMaximumRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFRange CFCalendarGetRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit smallerUnit, CFCalendarUnit biggerUnit, CFAbsoluteTime at) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
CFIndex CFCalendarGetOrdinalityOfUnit(CFCalendarRef calendar, CFCalendarUnit smallerUnit, CFCalendarUnit biggerUnit, CFAbsoluteTime at) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
Boolean CFCalendarGetTimeRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit, CFAbsoluteTime at, CFAbsoluteTime *startp, CFTimeInterval *tip) CF_AVAILABLE(10_5, 2_0);

CF_EXPORT
Boolean CFCalendarComposeAbsoluteTime(CFCalendarRef calendar, /* out */ CFAbsoluteTime *at, const char *componentDesc, ...) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
Boolean CFCalendarDecomposeAbsoluteTime(CFCalendarRef calendar, CFAbsoluteTime at, const char *componentDesc, ...) CF_AVAILABLE(10_4, 2_0);


enum {
    kCFCalendarComponentsWrap = (1UL << 0)  // option for adding
};

CF_EXPORT
Boolean CFCalendarAddComponents(CFCalendarRef calendar, /* inout */ CFAbsoluteTime *at, CFOptionFlags options, const char *componentDesc, ...) CF_AVAILABLE(10_4, 2_0);

CF_EXPORT
Boolean CFCalendarGetComponentDifference(CFCalendarRef calendar, CFAbsoluteTime startingAT, CFAbsoluteTime resultAT, CFOptionFlags options, const char *componentDesc, ...) CF_AVAILABLE(10_4, 2_0);


CF_EXTERN_C_END

#endif

#endif /* ! __COREFOUNDATION_CFCALENDAR__ */

