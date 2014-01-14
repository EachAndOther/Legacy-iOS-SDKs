/* Copyright (c) 2010 Apple Inc. All rights reserved.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _CDEFS_H_
# error "Never use <sys/_symbol_aliasing.h> directly.  Use <sys/cdefs.h> instead."
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_2_0
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_0(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_0(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_2_1
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_1(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_1(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_2_2
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_2(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_2(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_3_0
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_0(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_0(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_3_1
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_1(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_1(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_3_2
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_2(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_2(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_4_0
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_0(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_0(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_4_1
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_1(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_1(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_4_2
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_2(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_2(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_4_3
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_3(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_3(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_5_0
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_5_0(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_5_0(x)
#endif

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= __IPHONE_5_1
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_5_1(x) x
#else
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_5_1(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_0
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_0(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_0(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_1
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_1(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_1(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_2
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_2(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_2(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_3
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_3(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_3(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_4
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_4(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_4(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_5
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_5(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_5(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_6
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_6(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_6(x)
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= __MAC_10_7
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_7(x) x
#else
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_7(x)
#endif

