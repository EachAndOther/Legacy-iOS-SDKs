/*
 *  ABGroup.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 *  An ABGroup is a non-ordered collection of records.
 *
 */

#ifndef __ABGroup__
#define __ABGroup__

#include <AddressBook/ABAddressBook.h>
#include <AddressBook/ABRecord.h>
#include <AddressBook/ABPerson.h>
#include <AddressBook/ABSource.h>

#if defined(__cplusplus)
extern "C" {
#endif

extern const int kABGroupNameProperty;

// ABGroupCreate creates a new group in the default source
extern ABRecordRef ABGroupCreate(void);
extern ABRecordRef ABGroupCreateInSource(ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern ABRecordRef ABGroupCopySource(ABRecordRef group) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

extern CFArrayRef ABGroupCopyArrayOfAllMembers(ABRecordRef group);
extern CFArrayRef ABGroupCopyArrayOfAllMembersWithSortOrdering(ABRecordRef group, ABPersonSortOrdering sortOrdering);
extern bool ABGroupAddMember(ABRecordRef group, ABRecordRef person, CFErrorRef* error);
extern bool ABGroupRemoveMember(ABRecordRef group, ABRecordRef member, CFErrorRef* error);

// Finding groups
extern ABRecordRef ABAddressBookGetGroupWithRecordID(ABAddressBookRef addressBook, ABRecordID recordID);
extern CFIndex ABAddressBookGetGroupCount(ABAddressBookRef addressBook);

extern CFArrayRef ABAddressBookCopyArrayOfAllGroups(ABAddressBookRef addressBook);
extern CFArrayRef ABAddressBookCopyArrayOfAllGroupsInSource(ABAddressBookRef addressBook, ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

#if defined(__cplusplus)
}
#endif

#endif

