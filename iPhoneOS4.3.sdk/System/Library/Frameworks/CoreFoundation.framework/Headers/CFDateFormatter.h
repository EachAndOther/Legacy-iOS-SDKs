/*	CFDateFormatter.h
	Copyright (c) 2003-2010, Apple Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFDATEFORMATTER__)
#define __COREFOUNDATION_CFDATEFORMATTER__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFLocale.h>

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <=  __IPHONE_OS_VERSION_MAX_ALLOWED

CF_EXTERN_C_BEGIN

typedef struct __CFDateFormatter *CFDateFormatterRef;

// CFDateFormatters are not thread-safe.  Do not use one from multiple threads!

CF_EXPORT
CFStringRef CFDateFormatterCreateDateFormatFromTemplate(CFAllocatorRef allocator, CFStringRef tmplate, CFOptionFlags options, CFLocaleRef locale) CF_AVAILABLE(10_6, 4_0);
	// no options defined, pass 0 for now

CF_EXPORT
CFTypeID CFDateFormatterGetTypeID(void) CF_AVAILABLE(10_3, 2_0);

enum {	// date and time format styles
	kCFDateFormatterNoStyle = 0,
	kCFDateFormatterShortStyle = 1,
	kCFDateFormatterMediumStyle = 2,
	kCFDateFormatterLongStyle = 3,
	kCFDateFormatterFullStyle = 4
};
typedef CFIndex CFDateFormatterStyle;

// The exact formatted result for these date and time styles depends on the
// locale, but generally:
//     Short is completely numeric, such as "12/13/52" or "3:30pm"
//     Medium is longer, such as "Jan 12, 1952"
//     Long is longer, such as "January 12, 1952" or "3:30:32pm"
//     Full is pretty complete; e.g. "Tuesday, April 12, 1952 AD" or "3:30:42pm PST"
// The specifications though are left fuzzy, in part simply because a user's
// preference choices may affect the output, and also the results may change
// from one OS release to another.  To produce an exactly formatted date you
// should not rely on styles and localization, but set the format string and
// use nothing but numbers.

CF_EXPORT
CFDateFormatterRef CFDateFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFDateFormatterStyle dateStyle, CFDateFormatterStyle timeStyle) CF_AVAILABLE(10_3, 2_0);
	// Returns a CFDateFormatter, localized to the given locale, which
	// will format dates to the given date and time styles.

CF_EXPORT
CFLocaleRef CFDateFormatterGetLocale(CFDateFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFDateFormatterStyle CFDateFormatterGetDateStyle(CFDateFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFDateFormatterStyle CFDateFormatterGetTimeStyle(CFDateFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);
	// Get the properties with which the date formatter was created.

CF_EXPORT
CFStringRef CFDateFormatterGetFormat(CFDateFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
void CFDateFormatterSetFormat(CFDateFormatterRef formatter, CFStringRef formatString) CF_AVAILABLE(10_3, 2_0);
	// Set the format description string of the date formatter.  This
	// overrides the style settings.  The format of the format string
	// is as defined by the ICU library.  The date formatter starts with a
	// default format string defined by the style arguments with
	// which it was created.


CF_EXPORT
CFStringRef CFDateFormatterCreateStringWithDate(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFDateRef date) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFStringRef CFDateFormatterCreateStringWithAbsoluteTime(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFAbsoluteTime at) CF_AVAILABLE(10_3, 2_0);
	// Create a string representation of the given date or CFAbsoluteTime
	// using the current state of the date formatter.


CF_EXPORT
CFDateRef CFDateFormatterCreateDateFromString(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
Boolean CFDateFormatterGetAbsoluteTimeFromString(CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep, CFAbsoluteTime *atp) CF_AVAILABLE(10_3, 2_0);
	// Parse a string representation of a date using the current state
	// of the date formatter.  The range parameter specifies the range
	// of the string in which the parsing should occur in input, and on
	// output indicates the extent that was used; this parameter can
	// be NULL, in which case the whole string may be used.  The
	// return value indicates whether some date was computed and
	// (if atp is not NULL) stored at the location specified by atp.


CF_EXPORT
void CFDateFormatterSetProperty(CFDateFormatterRef formatter, CFStringRef key, CFTypeRef value) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFTypeRef CFDateFormatterCopyProperty(CFDateFormatterRef formatter, CFStringRef key) CF_AVAILABLE(10_3, 2_0);
	// Set and get various properties of the date formatter, the set of
	// which may be expanded in the future.

CF_EXPORT const CFStringRef kCFDateFormatterIsLenient CF_AVAILABLE(10_3, 2_0);	// CFBoolean
CF_EXPORT const CFStringRef kCFDateFormatterTimeZone CF_AVAILABLE(10_3, 2_0);		// CFTimeZone
CF_EXPORT const CFStringRef kCFDateFormatterCalendarName CF_AVAILABLE(10_3, 2_0);	// CFString
CF_EXPORT const CFStringRef kCFDateFormatterDefaultFormat CF_AVAILABLE(10_3, 2_0);	// CFString
CF_EXPORT const CFStringRef kCFDateFormatterTwoDigitStartDate CF_AVAILABLE(10_4, 2_0); // CFDate
CF_EXPORT const CFStringRef kCFDateFormatterDefaultDate CF_AVAILABLE(10_4, 2_0);	// CFDate
CF_EXPORT const CFStringRef kCFDateFormatterCalendar CF_AVAILABLE(10_4, 2_0);		// CFCalendar
CF_EXPORT const CFStringRef kCFDateFormatterEraSymbols CF_AVAILABLE(10_4, 2_0);	// CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterMonthSymbols CF_AVAILABLE(10_4, 2_0);	// CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterShortMonthSymbols CF_AVAILABLE(10_4, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterWeekdaySymbols CF_AVAILABLE(10_4, 2_0);	// CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterShortWeekdaySymbols CF_AVAILABLE(10_4, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterAMSymbol CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFDateFormatterPMSymbol CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFDateFormatterLongEraSymbols CF_AVAILABLE(10_5, 2_0);   // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterVeryShortMonthSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterStandaloneMonthSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterShortStandaloneMonthSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterVeryShortStandaloneMonthSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterVeryShortWeekdaySymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterStandaloneWeekdaySymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterShortStandaloneWeekdaySymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterVeryShortStandaloneWeekdaySymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterQuarterSymbols CF_AVAILABLE(10_5, 2_0); 	// CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterShortQuarterSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterStandaloneQuarterSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterShortStandaloneQuarterSymbols CF_AVAILABLE(10_5, 2_0); // CFArray of CFString
CF_EXPORT const CFStringRef kCFDateFormatterGregorianStartDate CF_AVAILABLE(10_5, 2_0); // CFDate
CF_EXPORT const CFStringRef kCFDateFormatterDoesRelativeDateFormattingKey CF_AVAILABLE(10_6, 4_0); // CFBoolean

// See CFLocale.h for these calendar constants:
//	const CFStringRef kCFGregorianCalendar;
//	const CFStringRef kCFBuddhistCalendar;
//	const CFStringRef kCFJapaneseCalendar;
//	const CFStringRef kCFIslamicCalendar;
//	const CFStringRef kCFIslamicCivilCalendar;
//	const CFStringRef kCFHebrewCalendar;
//	const CFStringRef kCFChineseCalendar;
//	const CFStringRef kCFRepublicOfChinaCalendar;
//	const CFStringRef kCFPersianCalendar;
//	const CFStringRef kCFIndianCalendar;
//	const CFStringRef kCFISO8601Calendar;   not yet implemented

CF_EXTERN_C_END

#endif

#endif /* ! __COREFOUNDATION_CFDATEFORMATTER__ */

