/*	CFLocale.h
	Copyright (c) 2002-2010, Apple Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFLOCALE__)
#define __COREFOUNDATION_CFLOCALE__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFDictionary.h>

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <=  __IPHONE_OS_VERSION_MAX_ALLOWED

CF_EXTERN_C_BEGIN

typedef const struct __CFLocale *CFLocaleRef;

CF_EXPORT
CFTypeID CFLocaleGetTypeID(void) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFLocaleRef CFLocaleGetSystem(void) CF_AVAILABLE(10_3, 2_0);
	// Returns the "root", canonical locale.  Contains fixed "backstop" settings.

CF_EXPORT
CFLocaleRef CFLocaleCopyCurrent(void) CF_AVAILABLE(10_3, 2_0);
	// Returns the logical "user" locale for the current user.
	// [This is Copy in the sense that you get a retain you have to release,
	// but we may return the same cached object over and over.]  Settings
	// you get from this locale do not change under you as CFPreferences
	// are changed (for safety and correctness).  Generally you would not
	// grab this and hold onto it forever, but use it to do the operations
	// you need to do at the moment, then throw it away.  (The non-changing
	// ensures that all the results of your operations are consistent.)

CF_EXPORT
CFArrayRef CFLocaleCopyAvailableLocaleIdentifiers(void) CF_AVAILABLE(10_4, 2_0);
	// Returns an array of CFStrings that represents all locales for
	// which locale data is available.

CF_EXPORT
CFArrayRef CFLocaleCopyISOLanguageCodes(void) CF_AVAILABLE(10_4, 2_0);
	// Returns an array of CFStrings that represents all known legal ISO
	// language codes.  Note: many of these will not have any supporting
	// locale data in Mac OS X.

CF_EXPORT
CFArrayRef CFLocaleCopyISOCountryCodes(void) CF_AVAILABLE(10_4, 2_0);
	// Returns an array of CFStrings that represents all known legal ISO
	// country codes.  Note: many of these will not have any supporting
	// locale data in Mac OS X.

CF_EXPORT
CFArrayRef CFLocaleCopyISOCurrencyCodes(void) CF_AVAILABLE(10_4, 2_0);
	// Returns an array of CFStrings that represents all known legal ISO
	// currency codes.  Note: some of these currencies may be obsolete, or
	// represent other financial instruments.

CF_EXPORT
CFArrayRef CFLocaleCopyCommonISOCurrencyCodes(void) CF_AVAILABLE(10_5, 2_0);
	// Returns an array of CFStrings that represents ISO currency codes for
	// currencies in common use.

CF_EXPORT
CFArrayRef CFLocaleCopyPreferredLanguages(void) CF_AVAILABLE(10_5, 2_0);
	// Returns the array of canonicalized CFString locale IDs that the user prefers.

CF_EXPORT
CFStringRef CFLocaleCreateCanonicalLanguageIdentifierFromString(CFAllocatorRef allocator, CFStringRef localeIdentifier) CF_AVAILABLE(10_4, 2_0);
	// Map an arbitrary language identification string (something close at
	// least) to a canonical language identifier.

CF_EXPORT
CFStringRef CFLocaleCreateCanonicalLocaleIdentifierFromString(CFAllocatorRef allocator, CFStringRef localeIdentifier) CF_AVAILABLE(10_3, 2_0);
	// Map an arbitrary locale identification string (something close at
	// least) to the canonical identifier.

CF_EXPORT
CFStringRef CFLocaleCreateCanonicalLocaleIdentifierFromScriptManagerCodes(CFAllocatorRef allocator, LangCode lcode, RegionCode rcode) CF_AVAILABLE(10_3, 2_0);
	// Map a Mac OS LangCode and RegionCode to the canonical locale identifier.

CF_EXPORT
CFStringRef CFLocaleCreateLocaleIdentifierFromWindowsLocaleCode(CFAllocatorRef allocator, uint32_t lcid) CF_AVAILABLE(10_6, 4_0);
	// Map a Windows LCID to the canonical locale identifier.

CF_EXPORT
uint32_t CFLocaleGetWindowsLocaleCodeFromLocaleIdentifier(CFStringRef localeIdentifier) CF_AVAILABLE(10_6, 4_0);
	// Map a locale identifier to a Windows LCID.

enum {
    kCFLocaleLanguageDirectionUnknown = 0,
    kCFLocaleLanguageDirectionLeftToRight = 1,
    kCFLocaleLanguageDirectionRightToLeft = 2,
    kCFLocaleLanguageDirectionTopToBottom = 3,
    kCFLocaleLanguageDirectionBottomToTop = 4
};
typedef CFIndex CFLocaleLanguageDirection;

CF_EXPORT
CFLocaleLanguageDirection CFLocaleGetLanguageCharacterDirection(CFStringRef isoLangCode) CF_AVAILABLE(10_6, 4_0);

CF_EXPORT
CFLocaleLanguageDirection CFLocaleGetLanguageLineDirection(CFStringRef isoLangCode) CF_AVAILABLE(10_6, 4_0);

CF_EXPORT
CFDictionaryRef CFLocaleCreateComponentsFromLocaleIdentifier(CFAllocatorRef allocator, CFStringRef localeID) CF_AVAILABLE(10_4, 2_0);
	// Parses a locale ID consisting of language, script, country, variant,
	// and keyword/value pairs into a dictionary. The keys are the constant
	// CFStrings corresponding to the locale ID components, and the values
	// will correspond to constants where available.
	// Example: "en_US@calendar=japanese" yields a dictionary with three
	// entries: kCFLocaleLanguageCode=en, kCFLocaleCountryCode=US, and
	// kCFLocaleCalendarIdentifier=kCFJapaneseCalendar.

CF_EXPORT
CFStringRef CFLocaleCreateLocaleIdentifierFromComponents(CFAllocatorRef allocator, CFDictionaryRef dictionary) CF_AVAILABLE(10_4, 2_0);
	// Reverses the actions of CFLocaleCreateDictionaryFromLocaleIdentifier,
	// creating a single string from the data in the dictionary. The
	// dictionary {kCFLocaleLanguageCode=en, kCFLocaleCountryCode=US,
	// kCFLocaleCalendarIdentifier=kCFJapaneseCalendar} becomes
	// "en_US@calendar=japanese".

CF_EXPORT
CFLocaleRef CFLocaleCreate(CFAllocatorRef allocator, CFStringRef localeIdentifier) CF_AVAILABLE(10_3, 2_0);
	// Returns a CFLocaleRef for the locale named by the "arbitrary" locale identifier.

CF_EXPORT
CFLocaleRef CFLocaleCreateCopy(CFAllocatorRef allocator, CFLocaleRef locale) CF_AVAILABLE(10_3, 2_0);
	// Having gotten a CFLocale from somebody, code should make a copy
	// if it is going to use it for several operations
	// or hold onto it.  In the future, there may be mutable locales.

CF_EXPORT
CFStringRef CFLocaleGetIdentifier(CFLocaleRef locale) CF_AVAILABLE(10_3, 2_0);
	// Returns the locale's identifier.  This may not be the same string
	// that the locale was created with (CFLocale may canonicalize it).

CF_EXPORT
CFTypeRef CFLocaleGetValue(CFLocaleRef locale, CFStringRef key) CF_AVAILABLE(10_3, 2_0);
	// Returns the value for the given key.  This is how settings and state
	// are accessed via a CFLocale.  Values might be of any CF type.

CF_EXPORT
CFStringRef CFLocaleCopyDisplayNameForPropertyValue(CFLocaleRef displayLocale, CFStringRef key, CFStringRef value) CF_AVAILABLE(10_4, 2_0);
	// Returns the display name for the given value.  The key tells what
	// the value is, and is one of the usual locale property keys, though
	// not all locale property keys have values with display name values.


CF_EXPORT const CFStringRef kCFLocaleCurrentLocaleDidChangeNotification CF_AVAILABLE(10_5, 2_0);


// Locale Keys
CF_EXPORT const CFStringRef kCFLocaleIdentifier CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleLanguageCode CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleCountryCode CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleScriptCode CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleVariantCode CF_AVAILABLE(10_4, 2_0);

CF_EXPORT const CFStringRef kCFLocaleExemplarCharacterSet CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleCalendarIdentifier CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleCollationIdentifier CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleUsesMetricSystem CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFLocaleMeasurementSystem CF_AVAILABLE(10_3, 2_0); // "Metric" or "U.S."
CF_EXPORT const CFStringRef kCFLocaleDecimalSeparator CF_AVAILABLE(10_3, 2_0);
CF_EXPORT const CFStringRef kCFLocaleGroupingSeparator CF_AVAILABLE(10_3, 2_0);
CF_EXPORT const CFStringRef kCFLocaleCurrencySymbol CF_AVAILABLE(10_3, 2_0);
CF_EXPORT const CFStringRef kCFLocaleCurrencyCode CF_AVAILABLE(10_3, 2_0); // ISO 3-letter currency code
CF_EXPORT const CFStringRef kCFLocaleCollatorIdentifier CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFLocaleQuotationBeginDelimiterKey CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFLocaleQuotationEndDelimiterKey CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFLocaleAlternateQuotationBeginDelimiterKey CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFLocaleAlternateQuotationEndDelimiterKey CF_AVAILABLE(10_6, 4_0);

// Values for kCFLocaleCalendarIdentifier
CF_EXPORT const CFStringRef kCFGregorianCalendar CF_AVAILABLE(10_3, 2_0);
CF_EXPORT const CFStringRef kCFBuddhistCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFChineseCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFHebrewCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFIslamicCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFIslamicCivilCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFJapaneseCalendar CF_AVAILABLE(10_4, 2_0);
CF_EXPORT const CFStringRef kCFRepublicOfChinaCalendar CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFPersianCalendar CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFIndianCalendar CF_AVAILABLE(10_6, 4_0);
CF_EXPORT const CFStringRef kCFISO8601Calendar CF_AVAILABLE(10_6, 4_0);

CF_EXTERN_C_END

#endif

#endif /* ! __COREFOUNDATION_CFLOCALE__ */

