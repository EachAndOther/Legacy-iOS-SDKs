/*
 * File: MecabraFacemarkCandidate.h
 *
 * Copyright: 2011 by Apple Inc. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>

@interface MecabraFacemarkCandidate : NSObject {    
@private
    NSString *_string;
    NSString *_category;
}
@property (readonly) NSString *string;
@property (readonly) NSString *category;

+ (NSArray *)copyFacemarkCandidatesForLocale:(NSLocale *)loc;

@end
