/*	NSOperation.h
	Copyright (c) 2006-2010, Apple Inc. All rights reserved.
*/

#import <Foundation/NSObject.h>

#if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

@class NSArray, NSSet;

@interface NSOperation : NSObject {
@private
    id _private;
    void *_reserved;
}

- (id)init; // designated initializer

- (void)start;
- (void)main;

- (BOOL)isCancelled;
- (void)cancel;

- (BOOL)isExecuting;
- (BOOL)isFinished;

- (BOOL)isConcurrent;

- (BOOL)isReady;

- (void)addDependency:(NSOperation *)op;
- (void)removeDependency:(NSOperation *)op;

- (NSArray *)dependencies;

enum {
	NSOperationQueuePriorityVeryLow = -8,
	NSOperationQueuePriorityLow = -4,
	NSOperationQueuePriorityNormal = 0,
	NSOperationQueuePriorityHigh = 4,
	NSOperationQueuePriorityVeryHigh = 8
};
typedef NSInteger NSOperationQueuePriority;

- (NSOperationQueuePriority)queuePriority;
- (void)setQueuePriority:(NSOperationQueuePriority)p;

#if NS_BLOCKS_AVAILABLE
- (void (^)(void))completionBlock NS_AVAILABLE(10_6, 4_0);
- (void)setCompletionBlock:(void (^)(void))block NS_AVAILABLE(10_6, 4_0);
#endif

- (void)waitUntilFinished NS_AVAILABLE(10_6, 4_0);

- (double)threadPriority NS_AVAILABLE(10_6, 4_0);
- (void)setThreadPriority:(double)p NS_AVAILABLE(10_6, 4_0);

@end


#if NS_BLOCKS_AVAILABLE

NS_CLASS_AVAILABLE(10_6, 4_0)
@interface NSBlockOperation : NSOperation {
@private
    id _private2;
    void *_reserved2;
}

+ (id)blockOperationWithBlock:(void (^)(void))block NS_AVAILABLE(10_6, 4_0);

- (void)addExecutionBlock:(void (^)(void))block NS_AVAILABLE(10_6, 4_0);
- (NSArray *)executionBlocks NS_AVAILABLE(10_6, 4_0);

@end

#endif


@interface NSInvocationOperation : NSOperation {
@private
    id _inv;
    id _exception;
    void *_reserved2;
}

- (id)initWithTarget:(id)target selector:(SEL)sel object:(id)arg;
- (id)initWithInvocation:(NSInvocation *)inv;		// designated initializer

- (NSInvocation *)invocation;

- (id)result;

@end

FOUNDATION_EXPORT NSString * const NSInvocationOperationVoidResultException;
FOUNDATION_EXPORT NSString * const NSInvocationOperationCancelledException;


@interface NSOperationQueue : NSObject {
@private
    id _private;
    void *_reserved;
}

- (void)addOperation:(NSOperation *)op;
- (void)addOperations:(NSArray *)ops waitUntilFinished:(BOOL)wait NS_AVAILABLE(10_6, 4_0);

#if NS_BLOCKS_AVAILABLE
- (void)addOperationWithBlock:(void (^)(void))block NS_AVAILABLE(10_6, 4_0);
#endif

- (NSArray *)operations;
- (NSUInteger)operationCount NS_AVAILABLE(10_6, 4_0);

- (NSInteger)maxConcurrentOperationCount;
- (void)setMaxConcurrentOperationCount:(NSInteger)cnt;

enum {
    NSOperationQueueDefaultMaxConcurrentOperationCount = -1
};

- (void)setSuspended:(BOOL)b;
- (BOOL)isSuspended;

- (void)setName:(NSString *)n NS_AVAILABLE(10_6, 4_0);
- (NSString *)name NS_AVAILABLE(10_6, 4_0);

- (void)cancelAllOperations;

- (void)waitUntilAllOperationsAreFinished;

+ (id)currentQueue NS_AVAILABLE(10_6, 4_0);
+ (id)mainQueue NS_AVAILABLE(10_6, 4_0);

@end

#endif

