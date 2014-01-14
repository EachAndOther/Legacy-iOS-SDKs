//
//  MPMusicPlayerController.h
//  MediaPlayer
//
//  Copyright 2008 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayerDefines.h>
#import <MediaPlayer/MPMediaItemCollection.h>
#import <MediaPlayer/MPMediaItem.h>
#import <MediaPlayer/MPMediaQuery.h>

@class MPMediaItem, MPMediaQuery, MPMusicPlayerControllerInternal;

enum {
    MPMusicPlaybackStateStopped,
    MPMusicPlaybackStatePlaying,
    MPMusicPlaybackStatePaused,
    MPMusicPlaybackStateInterrupted,
    MPMusicPlaybackStateSeekingForward,
    MPMusicPlaybackStateSeekingBackward
};
typedef NSInteger MPMusicPlaybackState;

enum {
    MPMusicRepeatModeDefault, // the user's preference for repeat mode
    MPMusicRepeatModeNone,
    MPMusicRepeatModeOne,
    MPMusicRepeatModeAll
};
typedef NSInteger MPMusicRepeatMode;

enum {
    MPMusicShuffleModeDefault, // the user's preference for shuffle mode
    MPMusicShuffleModeOff,
    MPMusicShuffleModeSongs,
    MPMusicShuffleModeAlbums
};
typedef NSInteger MPMusicShuffleMode;

// MPMusicPlayerController allows playback of MPMediaItems through the iPod application.

MP_EXTERN_CLASS_AVAILABLE(3_0) @interface MPMusicPlayerController : NSObject {
    MPMusicPlayerControllerInternal *_internal;
}

// Playing media items with the applicationMusicPlayer will restore the user's iPod state after the application quits.
+ (MPMusicPlayerController *)applicationMusicPlayer;

// Playing media items with the iPodMusicPlayer will replace the user's current iPod state.
+ (MPMusicPlayerController *)iPodMusicPlayer;

@end

@interface MPMusicPlayerController (MPPlaybackControl)

// Returns the current playback state of the music player
@property(nonatomic, readonly) MPMusicPlaybackState playbackState;

// Determines how music repeats after playback completes. Defaults to MPMusicRepeatModeDefault.
@property(nonatomic) MPMusicRepeatMode repeatMode;

// Determines how music is shuffled when playing. Defaults to MPMusicShuffleModeDefault.
@property(nonatomic) MPMusicShuffleMode shuffleMode;

// The current volume of playing music, in the range of 0.0 to 1.0.
@property(nonatomic) float volume;

// Returns the currently playing media item, or nil if none is playing.
// Setting the nowPlayingItem to an item in the current queue will begin playback at that item.
@property(nonatomic, copy) MPMediaItem *nowPlayingItem;

// Returns the index of the now playing item in the current playback queue.
// May return NSNotFound if the index is not valid (e.g. an empty queue or an infinite playlist).
@property(nonatomic, readonly) NSUInteger indexOfNowPlayingItem NS_AVAILABLE_IPHONE(5_0);

// Call -play to begin playback after setting an item queue source. Setting a query will implicitly use MPMediaGroupingTitle.
- (void)setQueueWithQuery:(MPMediaQuery *)query;
- (void)setQueueWithItemCollection:(MPMediaItemCollection *)itemCollection;

// Plays items from the current queue, resuming paused playback if possible.
- (void)play;

// Pauses playback if the music player is playing.
- (void)pause;

// Ends playback. Calling -play again will start from the beginning of the queue.
- (void)stop;

// The current time of the now playing item in seconds.
@property(nonatomic) NSTimeInterval currentPlaybackTime;

// The seeking rate will increase the longer seeking is active.
- (void)beginSeekingForward;
- (void)beginSeekingBackward;
- (void)endSeeking;

// Skips to the next item in the queue. If already at the last item, this will end playback.
- (void)skipToNextItem;

// Restarts playback at the beginning of the currently playing media item.
- (void)skipToBeginning;

// Skips to the previous item in the queue. If already at the first item, this will end playback.
- (void)skipToPreviousItem;

// These methods determine whether playback notifications will be generated.
// Calls to begin/endGeneratingPlaybackNotifications are nestable.
- (void)beginGeneratingPlaybackNotifications;
- (void)endGeneratingPlaybackNotifications;

@end

// Posted when the playback state changes, either programatically or by the user.
MP_EXTERN NSString *const MPMusicPlayerControllerPlaybackStateDidChangeNotification;

// Posted when the currently playing media item changes.
MP_EXTERN NSString *const MPMusicPlayerControllerNowPlayingItemDidChangeNotification;

// Posted when the current volume changes.
MP_EXTERN NSString *const MPMusicPlayerControllerVolumeDidChangeNotification;
