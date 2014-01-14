//
//  SKPaymentTransaction.h
//  StoreKit
//
//  Copyright 2009 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

@class SKPayment;

enum {
    SKPaymentTransactionStatePurchasing,    // Transaction is being added to the server queue.
    SKPaymentTransactionStatePurchased,     // Transaction is in queue, user has been charged.  Client should complete the transaction.
    SKPaymentTransactionStateFailed,        // Transaction was cancelled or failed before being added to the server queue.
    SKPaymentTransactionStateRestored       // Transaction was restored from user's purchase history.  Client should complete the transaction.
};
typedef NSInteger SKPaymentTransactionState;

SK_EXTERN_CLASS_AVAILABLE(3_0) @interface SKPaymentTransaction : NSObject {
@private
    id _internal;
}

// Only set if state is SKPaymentTransactionFailed
@property(nonatomic, readonly) NSError *error __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// Only valid if state is SKPaymentTransactionStateRestored.
@property(nonatomic, readonly) SKPaymentTransaction *originalTransaction __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly) SKPayment *payment __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// The date when the transaction was added to the server queue.  Only valid if state is SKPaymentTransactionStatePurchased or SKPaymentTransactionStateRestored.
@property(nonatomic, readonly) NSDate *transactionDate __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// The unique server-provided identifier.  Only valid if state is SKPaymentTransactionStatePurchased or SKPaymentTransactionStateRestored.
@property(nonatomic, readonly) NSString *transactionIdentifier __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// Only valid if state is SKPaymentTransactionStatePurchased.
@property(nonatomic, readonly) NSData *transactionReceipt __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, readonly) SKPaymentTransactionState transactionState __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@end
