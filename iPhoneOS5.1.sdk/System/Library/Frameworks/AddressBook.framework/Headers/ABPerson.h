/*
 *  ABPerson.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 *  An ABPerson corresponds to a contact such as a person or organization.
 *
 */

#ifndef __ABPerson__
#define __ABPerson__

#include <CoreFoundation/CoreFoundation.h>

#include <AddressBook/ABAddressBook.h>
#include <AddressBook/ABRecord.h>
#include <AddressBook/ABSource.h>

#include <Availability.h>

#if defined(__cplusplus)
extern "C" {
#endif

// ABPersonCreate creates a new person in the default source
extern ABRecordRef ABPersonCreate(void);
extern ABRecordRef ABPersonCreateInSource(ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern ABRecordRef ABPersonCopySource(ABRecordRef person) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

// Returns an array of all the linked people, including the person passed in. If the person is not linked, returns an array with the person passed in.
extern CFArrayRef ABPersonCopyArrayOfAllLinkedPeople(ABRecordRef person) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern ABPropertyType ABPersonGetTypeOfProperty(ABPropertyID property);
extern CFStringRef ABPersonCopyLocalizedPropertyName(ABPropertyID property);

typedef uint32_t ABPersonSortOrdering;
enum {
    kABPersonSortByFirstName = 0,
    kABPersonSortByLastName  = 1
};

extern ABPersonSortOrdering ABPersonGetSortOrdering(void);

typedef uint32_t ABPersonCompositeNameFormat;
enum  {
    kABPersonCompositeNameFormatFirstNameFirst = 0,
    kABPersonCompositeNameFormatLastNameFirst  = 1
};

extern ABPersonCompositeNameFormat ABPersonGetCompositeNameFormat(void);

// Images
typedef enum {
    kABPersonImageFormatThumbnail = 0,      // the square thumbnail
    kABPersonImageFormatOriginalSize = 2    // the original image as set by ABPersonSetImageData
} ABPersonImageFormat;

extern bool ABPersonSetImageData(ABRecordRef person, CFDataRef imageData, CFErrorRef* error);
extern CFDataRef ABPersonCopyImageData(ABRecordRef person);
extern CFDataRef ABPersonCopyImageDataWithFormat(ABRecordRef person, ABPersonImageFormat format) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern bool ABPersonHasImageData(ABRecordRef person);
extern bool ABPersonRemoveImageData(ABRecordRef person, CFErrorRef* error);

// Sorting
extern CFComparisonResult ABPersonComparePeopleByName(ABRecordRef person1, ABRecordRef person2, ABPersonSortOrdering ordering);

// Finding people
extern CFIndex ABAddressBookGetPersonCount(ABAddressBookRef addressBook);
extern ABRecordRef ABAddressBookGetPersonWithRecordID(ABAddressBookRef addressBook, ABRecordID recordID);

extern CFArrayRef ABAddressBookCopyArrayOfAllPeople(ABAddressBookRef addressBook);
extern CFArrayRef ABAddressBookCopyArrayOfAllPeopleInSource(ABAddressBookRef addressBook, ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);
extern CFArrayRef ABAddressBookCopyArrayOfAllPeopleInSourceWithSortOrdering(ABAddressBookRef addressBook, ABRecordRef source, ABPersonSortOrdering sortOrdering) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern CFArrayRef ABAddressBookCopyPeopleWithName(ABAddressBookRef addressBook, CFStringRef name);

// VCard
    // Creates an array of people from a vcard representation. Source is optional. The people
    // will be created in the source given as the first argument, or the default source if NULL.
extern CFArrayRef ABPersonCreatePeopleInSourceWithVCardRepresentation(ABRecordRef source, CFDataRef vCardData) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
    // Creates a vCard representation of the people passed in.
extern CFDataRef ABPersonCreateVCardRepresentationWithPeople(CFArrayRef people) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

// Generic labels
extern const CFStringRef kABWorkLabel;
extern const CFStringRef kABHomeLabel;
extern const CFStringRef kABOtherLabel;

// Property keys
extern const ABPropertyID kABPersonFirstNameProperty;          // First name - kABStringPropertyType
extern const ABPropertyID kABPersonLastNameProperty;           // Last name - kABStringPropertyType
extern const ABPropertyID kABPersonMiddleNameProperty;         // Middle name - kABStringPropertyType
extern const ABPropertyID kABPersonPrefixProperty;             // Prefix ("Sir" "Duke" "General") - kABStringPropertyType
extern const ABPropertyID kABPersonSuffixProperty;             // Suffix ("Jr." "Sr." "III") - kABStringPropertyType
extern const ABPropertyID kABPersonNicknameProperty;           // Nickname - kABStringPropertyType
extern const ABPropertyID kABPersonFirstNamePhoneticProperty;  // First name Phonetic - kABStringPropertyType
extern const ABPropertyID kABPersonLastNamePhoneticProperty;   // Last name Phonetic - kABStringPropertyType
extern const ABPropertyID kABPersonMiddleNamePhoneticProperty; // Middle name Phonetic - kABStringPropertyType
extern const ABPropertyID kABPersonOrganizationProperty;       // Company name - kABStringPropertyType
extern const ABPropertyID kABPersonJobTitleProperty;           // Job Title - kABStringPropertyType
extern const ABPropertyID kABPersonDepartmentProperty;         // Department name - kABStringPropertyType
extern const ABPropertyID kABPersonEmailProperty;              // Email(s) - kABMultiStringPropertyType
extern const ABPropertyID kABPersonBirthdayProperty;           // Birthday associated with this person - kABDateTimePropertyType
extern const ABPropertyID kABPersonNoteProperty;               // Note - kABStringPropertyType
extern const ABPropertyID kABPersonCreationDateProperty;       // Creation Date (when first saved)
extern const ABPropertyID kABPersonModificationDateProperty;   // Last saved date

// Addresses
extern const ABPropertyID kABPersonAddressProperty;            // Street address - kABMultiDictionaryPropertyType
extern const CFStringRef kABPersonAddressStreetKey;
extern const CFStringRef kABPersonAddressCityKey;
extern const CFStringRef kABPersonAddressStateKey;
extern const CFStringRef kABPersonAddressZIPKey;
extern const CFStringRef kABPersonAddressCountryKey;
extern const CFStringRef kABPersonAddressCountryCodeKey;

/*
 * kABPersonAddressCountryCodeKey code must be in the form of 2 character iso 3166 country codes
 *
 * eg:
 *    fr = France
 *    us = United States
 * etc.
 *
 */

// Dates
extern const ABPropertyID kABPersonDateProperty;               // Dates associated with this person - kABMultiDatePropertyType
extern const CFStringRef kABPersonAnniversaryLabel;

// Kind
extern const ABPropertyID kABPersonKindProperty;               // Person/Organization - kABIntegerPropertyType
extern const CFNumberRef kABPersonKindPerson;
extern const CFNumberRef kABPersonKindOrganization;

// Phone numbers
extern const ABPropertyID kABPersonPhoneProperty;              // Generic phone number - kABMultiStringPropertyType
extern const CFStringRef kABPersonPhoneMobileLabel;
extern const CFStringRef kABPersonPhoneIPhoneLabel __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
extern const CFStringRef kABPersonPhoneMainLabel;
extern const CFStringRef kABPersonPhoneHomeFAXLabel;
extern const CFStringRef kABPersonPhoneWorkFAXLabel;
extern const CFStringRef kABPersonPhoneOtherFAXLabel __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonPhonePagerLabel;

// IM
extern const ABPropertyID kABPersonInstantMessageProperty;     // Instant Messaging - kABMultiDictionaryPropertyType
extern const CFStringRef kABPersonInstantMessageServiceKey;     // Service ("Yahoo", "Jabber", etc.)
extern const CFStringRef kABPersonInstantMessageServiceYahoo;
extern const CFStringRef kABPersonInstantMessageServiceJabber;
extern const CFStringRef kABPersonInstantMessageServiceMSN;
extern const CFStringRef kABPersonInstantMessageServiceICQ;
extern const CFStringRef kABPersonInstantMessageServiceAIM;
extern const CFStringRef kABPersonInstantMessageServiceQQ __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonInstantMessageServiceGoogleTalk __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonInstantMessageServiceSkype __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonInstantMessageServiceFacebook __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonInstantMessageServiceGaduGadu __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

extern const CFStringRef kABPersonInstantMessageUsernameKey;    // Username

// URLs
extern const ABPropertyID kABPersonURLProperty;                // URL - kABMultiStringPropertyType
extern const CFStringRef kABPersonHomePageLabel; // Home Page

// Related names
extern const ABPropertyID kABPersonRelatedNamesProperty;       // Names - kABMultiStringPropertyType
extern const CFStringRef kABPersonFatherLabel;    // Father
extern const CFStringRef kABPersonMotherLabel;    // Mother
extern const CFStringRef kABPersonParentLabel;    // Parent
extern const CFStringRef kABPersonBrotherLabel;   // Brother
extern const CFStringRef kABPersonSisterLabel;    // Sister
extern const CFStringRef kABPersonChildLabel;      // Child
extern const CFStringRef kABPersonFriendLabel;    // Friend
extern const CFStringRef kABPersonSpouseLabel;    // Spouse
extern const CFStringRef kABPersonPartnerLabel;   // Partner
extern const CFStringRef kABPersonAssistantLabel; // Assistant
extern const CFStringRef kABPersonManagerLabel;   // Manager
    
// Social Profile
extern const ABPropertyID kABPersonSocialProfileProperty __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);		// kABMultiDictionaryPropertyType
extern const CFStringRef kABPersonSocialProfileURLKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);			// string representation of a url for the social profile
    // the following properties are optional
    extern const CFStringRef kABPersonSocialProfileServiceKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);			// string representing the name of the service (Twitter, Facebook, LinkedIn, etc.)
    extern const CFStringRef kABPersonSocialProfileUsernameKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);			// string representing the user visible name
    extern const CFStringRef kABPersonSocialProfileUserIdentifierKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);	// string representing the service specific identifier (optional)

extern const CFStringRef kABPersonSocialProfileServiceTwitter __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonSocialProfileServiceGameCenter __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonSocialProfileServiceFacebook __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonSocialProfileServiceMyspace __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonSocialProfileServiceLinkedIn __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
extern const CFStringRef kABPersonSocialProfileServiceFlickr __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

#if defined(__cplusplus)
}
#endif

#endif
