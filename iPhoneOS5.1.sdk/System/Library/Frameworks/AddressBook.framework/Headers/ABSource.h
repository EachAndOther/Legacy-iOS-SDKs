/*
 *  ABSource.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 */


#ifndef __ABSource__
#define __ABSource__

#include <AddressBook/ABAddressBook.h>
#include <AddressBook/ABRecord.h>
#include <AddressBook/ABPerson.h>

#include <Availability.h>

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

#define kABSourceTypeSearchableMask  0x01000000

enum {
    kABSourceTypeLocal       = 0x0,
    kABSourceTypeExchange    = 0x1,
    kABSourceTypeExchangeGAL = kABSourceTypeExchange | kABSourceTypeSearchableMask,

    kABSourceTypeMobileMe    = 0x2,

    kABSourceTypeLDAP        = 0x3 | kABSourceTypeSearchableMask,
    
    kABSourceTypeCardDAV     = 0x4,
    kABSourceTypeCardDAVSearch = kABSourceTypeCardDAV | kABSourceTypeSearchableMask,
};
typedef int ABSourceType;

#endif

#if defined(__cplusplus)
extern "C" {
#endif

extern const ABPropertyID kABSourceNameProperty __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0); // string
extern const ABPropertyID kABSourceTypeProperty __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0); // CFNumberRef of ABSourceType (int)

extern ABRecordRef ABAddressBookCopyDefaultSource(ABAddressBookRef addressBook) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern ABRecordRef ABAddressBookGetSourceWithRecordID(ABAddressBookRef addressBook, ABRecordID sourceID) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern CFArrayRef ABAddressBookCopyArrayOfAllSources(ABAddressBookRef addressBook) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

#if defined(__cplusplus)
}
#endif

#endif
