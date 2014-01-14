/*	NSInvocation.h
	Copyright (c) 1994-2010, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>
#include <stdbool.h>

@class NSMethodSignature;

@interface NSInvocation : NSObject {
@private
    void *_frame;
    __strong void *_retdata;
    id _signature;
    id _container;
    uint8_t _retainedArgs;
    uint8_t _reserved[15];
}

+ (NSInvocation *)invocationWithMethodSignature:(NSMethodSignature *)sig;

- (NSMethodSignature *)methodSignature;

- (void)retainArguments;
- (BOOL)argumentsRetained;

- (id)target;
- (void)setTarget:(id)target;

- (SEL)selector;
- (void)setSelector:(SEL)selector;

- (void)getReturnValue:(void *)retLoc;
- (void)setReturnValue:(void *)retLoc;

- (void)getArgument:(void *)argumentLocation atIndex:(NSInteger)idx;
- (void)setArgument:(void *)argumentLocation atIndex:(NSInteger)idx;

- (void)invoke;
- (void)invokeWithTarget:(id)target;

@end


#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
#if MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_5

enum _NSObjCValueType {
    NSObjCNoType = 0,
    NSObjCVoidType = 'v',
    NSObjCCharType = 'c',
    NSObjCShortType = 's',
    NSObjCLongType = 'l',
    NSObjCLonglongType = 'q',
    NSObjCFloatType = 'f',
    NSObjCDoubleType = 'd',
#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
    NSObjCBoolType = 'B',
#endif
    NSObjCSelectorType = ':',
    NSObjCObjectType = '@',
    NSObjCStructType = '{',
    NSObjCPointerType = '^',
    NSObjCStringType = '*',
    NSObjCArrayType = '[',
    NSObjCUnionType = '(',
    NSObjCBitfield = 'b'
} NS_DEPRECATED(10_0, 10_5, 2_0, 2_0);

typedef struct {
    NSInteger type NS_DEPRECATED(10_0, 10_5, 2_0, 2_0);
    union {
    	char charValue;
	short shortValue;
	long longValue;
	long long longlongValue;
	float floatValue;
	double doubleValue;
#if MAC_OS_X_VERSION_10_2 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
	bool boolValue;
#endif
	SEL selectorValue;
	id objectValue;
	void *pointerValue;
	void *structLocation;
	char *cStringLocation;
    } value NS_DEPRECATED(10_0, 10_5, 2_0, 2_0);
} NSObjCValue NS_DEPRECATED(10_0, 10_5, 2_0, 2_0);

#endif
#endif

