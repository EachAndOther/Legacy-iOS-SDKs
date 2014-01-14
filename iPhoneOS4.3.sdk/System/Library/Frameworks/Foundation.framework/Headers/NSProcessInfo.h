/*	NSProcessInfo.h
	Copyright (c) 1994-2010, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>

enum {	/* Constants returned by -operatingSystem */
	NSWindowsNTOperatingSystem = 1,
	NSWindows95OperatingSystem,
	NSSolarisOperatingSystem,
	NSHPUXOperatingSystem,
	NSMACHOperatingSystem,
	NSSunOSOperatingSystem,
	NSOSF1OperatingSystem
};

@class NSArray, NSString, NSDictionary;

@interface NSProcessInfo : NSObject {
    @private	
    NSDictionary	*environment;
    NSArray		*arguments;
    NSString		*hostName;    
    NSString		*name;
    void		*reserved;
}

+ (NSProcessInfo *)processInfo;	

- (NSDictionary *)environment;

- (NSArray *)arguments;

- (NSString *)hostName;

- (NSString *)processName;

- (int)processIdentifier;

- (void)setProcessName:(NSString *)newName;

- (NSString *)globallyUniqueString;

- (NSUInteger)operatingSystem;
- (NSString *)operatingSystemName;

- (NSString *)operatingSystemVersionString NS_AVAILABLE(10_2, 2_0);
	/* Human readable, localized; appropriate for displaying to user or using in bug emails and such; NOT appropriate for parsing */

- (NSUInteger)processorCount NS_AVAILABLE(10_5, 2_0);
- (NSUInteger)activeProcessorCount NS_AVAILABLE(10_5, 2_0);
- (unsigned long long)physicalMemory NS_AVAILABLE(10_5, 2_0);

- (NSTimeInterval)systemUptime NS_AVAILABLE(10_6, 4_0);

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))

/* Disable or reenable the ability to be quickly killed. The default implementations of these methods increment or decrement, respectively, a counter whose value is 1 when the process is first created. When the counter's value is 0 the application is considered to be safely killable and may be killed by the operating system without any notification or event being sent to the process first. If an application's Info.plist has an NSSupportsSuddenTermination entry whose value is true then NSApplication invokes -enableSuddenTermination automatically during application launch, which typically renders the process killable right away. You can also manually invoke -enableSuddenTermination right away in, for example, agents or daemons that don't depend on AppKit. After that, you can invoke these methods whenever the process has work it must do before it terminates. For example:
 - NSUserDefaults uses these to prevent process killing between the time at which a default has been set and the time at which the preferences file including that default has been written to disk.
 - NSDocument uses these to prevent process killing between the time at which the user has made a change to a document and the time at which the user's change has been written to disk.
 - You can use these whenever your application defers work that must be done before the application terminates. If for example your application ever defers writing something to disk, and it has an NSSupportsSuddenTermination entry in its Info.plist so as not to contribute to user-visible delays at logout or shutdown time, it must invoke -disableSuddenTermination when the writing is first deferred and -enableSuddenTermination after the writing is actually done.
*/
- (void)disableSuddenTermination NS_AVAILABLE(10_6, 4_0);
- (void)enableSuddenTermination NS_AVAILABLE(10_6, 4_0);

#endif

@end

