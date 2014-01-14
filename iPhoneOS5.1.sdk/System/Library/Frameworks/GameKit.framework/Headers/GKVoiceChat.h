//
//  GKVoiceChat.h
//  GameKit
//
//  Copyright 2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

enum {
    GKVoiceChatPlayerConnected,
    GKVoiceChatPlayerDisconnected,
    GKVoiceChatPlayerSpeaking,
    GKVoiceChatPlayerSilent
};
typedef NSInteger GKVoiceChatPlayerState;

// GKVoiceChat represents an instance of a named voice communications channel
NS_CLASS_AVAILABLE(NA, 4_1)
@interface GKVoiceChat : NSObject {
}
	
- (void)start;  // start receiving audio from the chat
- (void)stop;   // stop receiving audio from the chat

- (void)setMute:(BOOL)isMuted forPlayer:(NSString *)playerID;

@property(nonatomic, copy) void(^playerStateUpdateHandler)(NSString *playerID, GKVoiceChatPlayerState state);
@property(nonatomic, readonly) NSString *name;  // name the chat was created with
@property(nonatomic, assign, getter=isActive) BOOL active; // make this session active and route the microphone 
@property(nonatomic, assign) float volume; // default 1.0 (max is 1.0, min is 0.0)


@property(nonatomic, readonly) NSArray *playerIDs __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0); // list of GKPlayerIDs

+ (BOOL)isVoIPAllowed;

@end
