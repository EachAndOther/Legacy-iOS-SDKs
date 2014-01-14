/*	NSDateFormatter.h
	Copyright (c) 1995-2010, Apple Inc. All rights reserved.
*/

#import <Foundation/NSFormatter.h>
#include <CoreFoundation/CFDateFormatter.h>

@class NSLocale, NSDate, NSCalendar, NSTimeZone, NSError, NSArray, NSMutableDictionary;

@interface NSDateFormatter : NSFormatter {
@private
    NSMutableDictionary *_attributes;
    __strong CFDateFormatterRef _formatter;
    NSUInteger _counter;
}

// - (id)init; // designated initializer

// Report the used range of the string and an NSError, in addition to the usual stuff from NSFormatter

- (BOOL)getObjectValue:(out id *)obj forString:(NSString *)string range:(inout NSRange *)rangep error:(out NSError **)error NS_AVAILABLE(10_4, 2_0);

// Even though NSDateFormatter responds to the usual NSFormatter methods,
//   here are some convenience methods which are a little more obvious.

- (NSString *)stringFromDate:(NSDate *)date NS_AVAILABLE(10_4, 2_0);
- (NSDate *)dateFromString:(NSString *)string NS_AVAILABLE(10_4, 2_0);

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

enum {    // date and time format styles
    NSDateFormatterNoStyle = kCFDateFormatterNoStyle,
    NSDateFormatterShortStyle = kCFDateFormatterShortStyle,
    NSDateFormatterMediumStyle = kCFDateFormatterMediumStyle,
    NSDateFormatterLongStyle = kCFDateFormatterLongStyle,
    NSDateFormatterFullStyle = kCFDateFormatterFullStyle
};
typedef NSUInteger NSDateFormatterStyle;

enum {
    NSDateFormatterBehaviorDefault = 0,
#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
    NSDateFormatterBehavior10_0 = 1000,
#endif
    NSDateFormatterBehavior10_4 = 1040,
};
typedef NSUInteger NSDateFormatterBehavior;

#endif

+ (NSString *)localizedStringFromDate:(NSDate *)date dateStyle:(NSDateFormatterStyle)dstyle timeStyle:(NSDateFormatterStyle)tstyle NS_AVAILABLE(10_6, 4_0);

+ (NSString *)dateFormatFromTemplate:(NSString *)tmplate options:(NSUInteger)opts locale:(NSLocale *)locale NS_AVAILABLE(10_6, 4_0);
	// no options defined, pass 0 for now

// Attributes of an NSDateFormatter

- (NSString *)dateFormat;

- (NSDateFormatterStyle)dateStyle NS_AVAILABLE(10_4, 2_0);
- (void)setDateStyle:(NSDateFormatterStyle)style NS_AVAILABLE(10_4, 2_0);

- (NSDateFormatterStyle)timeStyle NS_AVAILABLE(10_4, 2_0);
- (void)setTimeStyle:(NSDateFormatterStyle)style NS_AVAILABLE(10_4, 2_0);

- (NSLocale *)locale NS_AVAILABLE(10_4, 2_0);
- (void)setLocale:(NSLocale *)locale NS_AVAILABLE(10_4, 2_0);

- (BOOL)generatesCalendarDates NS_AVAILABLE(10_4, 2_0);
- (void)setGeneratesCalendarDates:(BOOL)b NS_AVAILABLE(10_4, 2_0);

- (NSDateFormatterBehavior)formatterBehavior NS_AVAILABLE(10_4, 2_0);
- (void)setFormatterBehavior:(NSDateFormatterBehavior)behavior NS_AVAILABLE(10_4, 2_0);

+ (NSDateFormatterBehavior)defaultFormatterBehavior NS_AVAILABLE(10_4, 2_0);
+ (void)setDefaultFormatterBehavior:(NSDateFormatterBehavior)behavior NS_AVAILABLE(10_4, 2_0);

- (void)setDateFormat:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSTimeZone *)timeZone NS_AVAILABLE(10_4, 2_0);
- (void)setTimeZone:(NSTimeZone *)tz NS_AVAILABLE(10_4, 2_0);

- (NSCalendar *)calendar NS_AVAILABLE(10_4, 2_0);
- (void)setCalendar:(NSCalendar *)calendar NS_AVAILABLE(10_4, 2_0);

- (BOOL)isLenient NS_AVAILABLE(10_4, 2_0);
- (void)setLenient:(BOOL)b NS_AVAILABLE(10_4, 2_0);

- (NSDate *)twoDigitStartDate NS_AVAILABLE(10_4, 2_0);
- (void)setTwoDigitStartDate:(NSDate *)date NS_AVAILABLE(10_4, 2_0);

- (NSDate *)defaultDate NS_AVAILABLE(10_4, 2_0);
- (void)setDefaultDate:(NSDate *)date NS_AVAILABLE(10_4, 2_0);

- (NSArray *)eraSymbols NS_AVAILABLE(10_4, 2_0);
- (void)setEraSymbols:(NSArray *)array NS_AVAILABLE(10_4, 2_0);

- (NSArray *)monthSymbols NS_AVAILABLE(10_4, 2_0);
- (void)setMonthSymbols:(NSArray *)array NS_AVAILABLE(10_4, 2_0);

- (NSArray *)shortMonthSymbols NS_AVAILABLE(10_4, 2_0);
- (void)setShortMonthSymbols:(NSArray *)array NS_AVAILABLE(10_4, 2_0);

- (NSArray *)weekdaySymbols NS_AVAILABLE(10_4, 2_0);
- (void)setWeekdaySymbols:(NSArray *)array NS_AVAILABLE(10_4, 2_0);

- (NSArray *)shortWeekdaySymbols NS_AVAILABLE(10_4, 2_0);
- (void)setShortWeekdaySymbols:(NSArray *)array NS_AVAILABLE(10_4, 2_0);

- (NSString *)AMSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setAMSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)PMSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setPMSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSArray *)longEraSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setLongEraSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)veryShortMonthSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setVeryShortMonthSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)standaloneMonthSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setStandaloneMonthSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)shortStandaloneMonthSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setShortStandaloneMonthSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)veryShortStandaloneMonthSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setVeryShortStandaloneMonthSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)veryShortWeekdaySymbols NS_AVAILABLE(10_5, 2_0);
- (void)setVeryShortWeekdaySymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)standaloneWeekdaySymbols NS_AVAILABLE(10_5, 2_0);
- (void)setStandaloneWeekdaySymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)shortStandaloneWeekdaySymbols NS_AVAILABLE(10_5, 2_0);
- (void)setShortStandaloneWeekdaySymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)veryShortStandaloneWeekdaySymbols NS_AVAILABLE(10_5, 2_0);
- (void)setVeryShortStandaloneWeekdaySymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)quarterSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setQuarterSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)shortQuarterSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setShortQuarterSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)standaloneQuarterSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setStandaloneQuarterSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSArray *)shortStandaloneQuarterSymbols NS_AVAILABLE(10_5, 2_0);
- (void)setShortStandaloneQuarterSymbols:(NSArray *)array NS_AVAILABLE(10_5, 2_0);

- (NSDate *)gregorianStartDate NS_AVAILABLE(10_5, 2_0);
- (void)setGregorianStartDate:(NSDate *)date NS_AVAILABLE(10_5, 2_0);

- (BOOL)doesRelativeDateFormatting NS_AVAILABLE(10_6, 4_0);
- (void)setDoesRelativeDateFormatting:(BOOL)b NS_AVAILABLE(10_6, 4_0);

@end

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
@interface NSDateFormatter (NSDateFormatterCompatibility)

- (id)initWithDateFormat:(NSString *)format allowNaturalLanguage:(BOOL)flag;
- (BOOL)allowsNaturalLanguage;

@end
#endif

