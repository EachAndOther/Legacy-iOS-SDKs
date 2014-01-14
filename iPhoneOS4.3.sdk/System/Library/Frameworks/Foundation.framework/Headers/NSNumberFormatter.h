/*	NSNumberFormatter.h
	Copyright (c) 1996-2010, Apple Inc. All rights reserved.
*/

#import <Foundation/NSFormatter.h>
#include <CoreFoundation/CFNumberFormatter.h>

@class NSLocale, NSError, NSMutableDictionary;

@interface NSNumberFormatter : NSFormatter {
@private
    NSMutableDictionary	*_attributes;
    __strong CFNumberFormatterRef _formatter;
    NSUInteger _counter;
    void *_reserved[12];
}

// - (id)init; // designated initializer

// Report the used range of the string and an NSError, in addition to the usual stuff from NSFormatter

- (BOOL)getObjectValue:(out id *)obj forString:(NSString *)string range:(inout NSRange *)rangep error:(out NSError **)error NS_AVAILABLE(10_4, 2_0);

// Even though NSNumberFormatter responds to the usual NSFormatter methods,
//   here are some convenience methods which are a little more obvious.

- (NSString *)stringFromNumber:(NSNumber *)number NS_AVAILABLE(10_4, 2_0);
- (NSNumber *)numberFromString:(NSString *)string NS_AVAILABLE(10_4, 2_0);

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

enum {
    NSNumberFormatterNoStyle = kCFNumberFormatterNoStyle,
    NSNumberFormatterDecimalStyle = kCFNumberFormatterDecimalStyle,
    NSNumberFormatterCurrencyStyle = kCFNumberFormatterCurrencyStyle,
    NSNumberFormatterPercentStyle = kCFNumberFormatterPercentStyle,
    NSNumberFormatterScientificStyle = kCFNumberFormatterScientificStyle,
    NSNumberFormatterSpellOutStyle = kCFNumberFormatterSpellOutStyle
};
typedef NSUInteger NSNumberFormatterStyle;

enum {
    NSNumberFormatterBehaviorDefault = 0,
#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
    NSNumberFormatterBehavior10_0 = 1000,
#endif
    NSNumberFormatterBehavior10_4 = 1040,
};
typedef NSUInteger NSNumberFormatterBehavior;

#endif

+ (NSString *)localizedStringFromNumber:(NSNumber *)num numberStyle:(NSNumberFormatterStyle)nstyle NS_AVAILABLE(10_6, 4_0);

// Attributes of an NSNumberFormatter

- (NSNumberFormatterStyle)numberStyle NS_AVAILABLE(10_4, 2_0);
- (void)setNumberStyle:(NSNumberFormatterStyle)style NS_AVAILABLE(10_4, 2_0);

- (NSLocale *)locale NS_AVAILABLE(10_4, 2_0);
- (void)setLocale:(NSLocale *)locale NS_AVAILABLE(10_4, 2_0);

- (BOOL)generatesDecimalNumbers NS_AVAILABLE(10_4, 2_0);
- (void)setGeneratesDecimalNumbers:(BOOL)b NS_AVAILABLE(10_4, 2_0);

- (NSNumberFormatterBehavior)formatterBehavior NS_AVAILABLE(10_4, 2_0);
- (void)setFormatterBehavior:(NSNumberFormatterBehavior)behavior NS_AVAILABLE(10_4, 2_0);

+ (NSNumberFormatterBehavior)defaultFormatterBehavior NS_AVAILABLE(10_4, 2_0);
+ (void)setDefaultFormatterBehavior:(NSNumberFormatterBehavior)behavior NS_AVAILABLE(10_4, 2_0);

- (NSString *)negativeFormat;
- (void)setNegativeFormat:(NSString *)format;

- (NSDictionary *)textAttributesForNegativeValues;
- (void)setTextAttributesForNegativeValues:(NSDictionary *)newAttributes;

- (NSString *)positiveFormat;
- (void)setPositiveFormat:(NSString *)format;

- (NSDictionary *)textAttributesForPositiveValues;
- (void)setTextAttributesForPositiveValues:(NSDictionary *)newAttributes;

- (BOOL)allowsFloats;
- (void)setAllowsFloats:(BOOL)flag;

- (NSString *)decimalSeparator;
- (void)setDecimalSeparator:(NSString *)string;

- (BOOL)alwaysShowsDecimalSeparator NS_AVAILABLE(10_4, 2_0);
- (void)setAlwaysShowsDecimalSeparator:(BOOL)b NS_AVAILABLE(10_4, 2_0);

- (NSString *)currencyDecimalSeparator NS_AVAILABLE(10_4, 2_0);
- (void)setCurrencyDecimalSeparator:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (BOOL)usesGroupingSeparator NS_AVAILABLE(10_4, 2_0);
- (void)setUsesGroupingSeparator:(BOOL)b NS_AVAILABLE(10_4, 2_0);

- (NSString *)groupingSeparator NS_AVAILABLE(10_4, 2_0);
- (void)setGroupingSeparator:(NSString *)string NS_AVAILABLE(10_4, 2_0);


- (NSString *)zeroSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setZeroSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSDictionary *)textAttributesForZero NS_AVAILABLE(10_4, 2_0);
- (void)setTextAttributesForZero:(NSDictionary *)newAttributes NS_AVAILABLE(10_4, 2_0);

- (NSString *)nilSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setNilSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSDictionary *)textAttributesForNil NS_AVAILABLE(10_4, 2_0);
- (void)setTextAttributesForNil:(NSDictionary *)newAttributes NS_AVAILABLE(10_4, 2_0);

- (NSString *)notANumberSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setNotANumberSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSDictionary *)textAttributesForNotANumber NS_AVAILABLE(10_4, 2_0);
- (void)setTextAttributesForNotANumber:(NSDictionary *)newAttributes NS_AVAILABLE(10_4, 2_0);

- (NSString *)positiveInfinitySymbol NS_AVAILABLE(10_4, 2_0);
- (void)setPositiveInfinitySymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSDictionary *)textAttributesForPositiveInfinity NS_AVAILABLE(10_4, 2_0);
- (void)setTextAttributesForPositiveInfinity:(NSDictionary *)newAttributes NS_AVAILABLE(10_4, 2_0);

- (NSString *)negativeInfinitySymbol NS_AVAILABLE(10_4, 2_0);
- (void)setNegativeInfinitySymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSDictionary *)textAttributesForNegativeInfinity NS_AVAILABLE(10_4, 2_0);
- (void)setTextAttributesForNegativeInfinity:(NSDictionary *)newAttributes NS_AVAILABLE(10_4, 2_0);


- (NSString *)positivePrefix NS_AVAILABLE(10_4, 2_0);
- (void)setPositivePrefix:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)positiveSuffix NS_AVAILABLE(10_4, 2_0);
- (void)setPositiveSuffix:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)negativePrefix NS_AVAILABLE(10_4, 2_0);
- (void)setNegativePrefix:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)negativeSuffix NS_AVAILABLE(10_4, 2_0);
- (void)setNegativeSuffix:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)currencyCode NS_AVAILABLE(10_4, 2_0);
- (void)setCurrencyCode:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)currencySymbol NS_AVAILABLE(10_4, 2_0);
- (void)setCurrencySymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)internationalCurrencySymbol NS_AVAILABLE(10_4, 2_0);
- (void)setInternationalCurrencySymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)percentSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setPercentSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)perMillSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setPerMillSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)minusSign NS_AVAILABLE(10_4, 2_0);
- (void)setMinusSign:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)plusSign NS_AVAILABLE(10_4, 2_0);
- (void)setPlusSign:(NSString *)string NS_AVAILABLE(10_4, 2_0);

- (NSString *)exponentSymbol NS_AVAILABLE(10_4, 2_0);
- (void)setExponentSymbol:(NSString *)string NS_AVAILABLE(10_4, 2_0);


- (NSUInteger)groupingSize NS_AVAILABLE(10_4, 2_0);
- (void)setGroupingSize:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

- (NSUInteger)secondaryGroupingSize NS_AVAILABLE(10_4, 2_0);
- (void)setSecondaryGroupingSize:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

- (NSNumber *)multiplier NS_AVAILABLE(10_4, 2_0);
- (void)setMultiplier:(NSNumber *)number NS_AVAILABLE(10_4, 2_0);

- (NSUInteger)formatWidth NS_AVAILABLE(10_4, 2_0);
- (void)setFormatWidth:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

- (NSString *)paddingCharacter NS_AVAILABLE(10_4, 2_0);
- (void)setPaddingCharacter:(NSString *)string NS_AVAILABLE(10_4, 2_0);

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

enum {
    NSNumberFormatterPadBeforePrefix = kCFNumberFormatterPadBeforePrefix,
    NSNumberFormatterPadAfterPrefix = kCFNumberFormatterPadAfterPrefix,
    NSNumberFormatterPadBeforeSuffix = kCFNumberFormatterPadBeforeSuffix,
    NSNumberFormatterPadAfterSuffix = kCFNumberFormatterPadAfterSuffix
};
typedef NSUInteger NSNumberFormatterPadPosition;

enum {
    NSNumberFormatterRoundCeiling = kCFNumberFormatterRoundCeiling,
    NSNumberFormatterRoundFloor = kCFNumberFormatterRoundFloor,
    NSNumberFormatterRoundDown = kCFNumberFormatterRoundDown,
    NSNumberFormatterRoundUp = kCFNumberFormatterRoundUp,
    NSNumberFormatterRoundHalfEven = kCFNumberFormatterRoundHalfEven,
    NSNumberFormatterRoundHalfDown = kCFNumberFormatterRoundHalfDown,
    NSNumberFormatterRoundHalfUp = kCFNumberFormatterRoundHalfUp
};
typedef NSUInteger NSNumberFormatterRoundingMode;

#endif

- (NSNumberFormatterPadPosition)paddingPosition NS_AVAILABLE(10_4, 2_0);
- (void)setPaddingPosition:(NSNumberFormatterPadPosition)position NS_AVAILABLE(10_4, 2_0);

- (NSNumberFormatterRoundingMode)roundingMode NS_AVAILABLE(10_4, 2_0);
- (void)setRoundingMode:(NSNumberFormatterRoundingMode)mode NS_AVAILABLE(10_4, 2_0);

- (NSNumber *)roundingIncrement NS_AVAILABLE(10_4, 2_0);
- (void)setRoundingIncrement:(NSNumber *)number NS_AVAILABLE(10_4, 2_0);

- (NSUInteger)minimumIntegerDigits NS_AVAILABLE(10_4, 2_0);
- (void)setMinimumIntegerDigits:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

- (NSUInteger)maximumIntegerDigits NS_AVAILABLE(10_4, 2_0);
- (void)setMaximumIntegerDigits:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

- (NSUInteger)minimumFractionDigits NS_AVAILABLE(10_4, 2_0);
- (void)setMinimumFractionDigits:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

- (NSUInteger)maximumFractionDigits NS_AVAILABLE(10_4, 2_0);
- (void)setMaximumFractionDigits:(NSUInteger)number NS_AVAILABLE(10_4, 2_0);

#if MAC_OS_X_VERSION_10_4 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

- (NSNumber *)minimum;
- (void)setMinimum:(NSNumber *)number;

- (NSNumber *)maximum;
- (void)setMaximum:(NSNumber *)number;

#endif

- (NSString *)currencyGroupingSeparator NS_AVAILABLE(10_5, 2_0);
- (void)setCurrencyGroupingSeparator:(NSString *)string NS_AVAILABLE(10_5, 2_0);

- (BOOL)isLenient NS_AVAILABLE(10_5, 2_0);
- (void)setLenient:(BOOL)b NS_AVAILABLE(10_5, 2_0);

- (BOOL)usesSignificantDigits NS_AVAILABLE(10_5, 2_0);
- (void)setUsesSignificantDigits:(BOOL)b NS_AVAILABLE(10_5, 2_0);

- (NSUInteger)minimumSignificantDigits NS_AVAILABLE(10_5, 2_0);
- (void)setMinimumSignificantDigits:(NSUInteger)number NS_AVAILABLE(10_5, 2_0);

- (NSUInteger)maximumSignificantDigits NS_AVAILABLE(10_5, 2_0);
- (void)setMaximumSignificantDigits:(NSUInteger)number NS_AVAILABLE(10_5, 2_0);

- (BOOL)isPartialStringValidationEnabled NS_AVAILABLE(10_5, 2_0);
- (void)setPartialStringValidationEnabled:(BOOL)b NS_AVAILABLE(10_5, 2_0);

@end

@class NSDecimalNumberHandler;

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
@interface NSNumberFormatter (NSNumberFormatterCompatibility)

- (BOOL)hasThousandSeparators;
- (void)setHasThousandSeparators:(BOOL)flag;
- (NSString *)thousandSeparator;
- (void)setThousandSeparator:(NSString *)newSeparator;

- (BOOL)localizesFormat;
- (void)setLocalizesFormat:(BOOL)flag;

- (NSString *)format;
- (void)setFormat:(NSString *)string;

- (NSAttributedString *)attributedStringForZero;
- (void)setAttributedStringForZero:(NSAttributedString *)newAttributedString;
- (NSAttributedString *)attributedStringForNil;
- (void)setAttributedStringForNil:(NSAttributedString *)newAttributedString;
- (NSAttributedString *)attributedStringForNotANumber;
- (void)setAttributedStringForNotANumber:(NSAttributedString *)newAttributedString;

- (NSDecimalNumberHandler *)roundingBehavior;
- (void)setRoundingBehavior:(NSDecimalNumberHandler *)newRoundingBehavior;

#if MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_3

- (NSDecimalNumber *)minimum;
- (void)setMinimum:(NSDecimalNumber *)aMinimum;
- (NSDecimalNumber *)maximum;
- (void)setMaximum:(NSDecimalNumber *)aMaximum;

#endif

@end
#endif

