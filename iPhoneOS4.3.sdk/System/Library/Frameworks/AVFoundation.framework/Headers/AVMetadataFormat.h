/*
    File:  AVMetadataFormat.h

    Framework:  AVFoundation
 
    Copyright 2010 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

// CommonMetadata
extern NSString *const AVMetadataKeySpaceCommon                                      NS_AVAILABLE(10_7, 4_0);

// Metadata common keys
extern NSString *const AVMetadataCommonKeyTitle                                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyCreator                                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeySubject                                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyDescription                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyPublisher                                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyContributor                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyCreationDate                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyLastModifiedDate                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyType                                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyFormat                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyIdentifier                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeySource                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyLanguage                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyRelation                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyLocation                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyCopyrights                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyAlbumName                                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyAuthor                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyArtist                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyArtwork                                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyMake                                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeyModel                                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataCommonKeySoftware                                   NS_AVAILABLE(10_7, 4_0);

// QuickTimeUserData
extern NSString *const AVMetadataFormatQuickTimeUserData                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataKeySpaceQuickTimeUserData                           NS_AVAILABLE(10_7, 4_0);

// QuickTimeUserData keys
extern NSString *const AVMetadataQuickTimeUserDataKeyAlbum                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyArranger                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyArtist                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyAuthor                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyChapter                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyComment                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyComposer                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyCopyright                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyCreationDate                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyDescription                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyDirector                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyDisclaimer                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyEncodedBy                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyFullName                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyGenre                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyHostComputer                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyInformation                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyKeywords                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyMake                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyModel                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyOriginalArtist                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyOriginalFormat                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyOriginalSource                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyPerformers                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyProducer                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyPublisher                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyProduct                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeySoftware                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeySpecialPlaybackRequirements     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyTrack                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyWarning                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyWriter                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyURLLink                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyLocationISO6709                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyTrackName                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyCredits                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyPhonogramRights                 NS_AVAILABLE(10_7, 4_0);

extern NSString *const AVMetadataISOUserDataKeyCopyright                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyCopyright                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyAuthor                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyPerformer                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyGenre                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyRecordingYear                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyLocation                              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyTitle                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadata3GPUserDataKeyDescription                           NS_AVAILABLE(10_7, 4_0);

// QuickTimeMetadata
extern NSString *const AVMetadataFormatQuickTimeMetadata                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataKeySpaceQuickTimeMetadata                           NS_AVAILABLE(10_7, 4_0);

// QuickTimeMetadata keys. For more information, see the QuickTime File Format Specification, available as part of the Mac OS X Reference Library at http://developer.apple.com/library/mac/navigation/
extern NSString *const AVMetadataQuickTimeMetadataKeyAuthor                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyComment                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCopyright                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCreationDate                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyDirector                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyDisplayName                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyInformation                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyKeywords                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyProducer                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyPublisher                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyAlbum                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyArtist                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyArtwork                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyDescription                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeySoftware                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyYear                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyGenre                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyiXML                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationISO6709                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyMake                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyModel                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyArranger                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyEncodedBy                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyOriginalArtist                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyPerformer                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyComposer                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCredits                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyPhonogramRights                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCameraIdentifier                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCameraFrameReadoutTime          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyTitle		                     NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyCollectionUser                  NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyRatingUser                      NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationName                    NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationBody                    NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationNote                    NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationRole                    NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationDate                    NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyDirectionFacing                 NS_AVAILABLE(10_7, 4_3);
extern NSString *const AVMetadataQuickTimeMetadataKeyDirectionMotion                 NS_AVAILABLE(10_7, 4_3);

// iTunesMetadata
extern NSString *const AVMetadataFormatiTunesMetadata                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataKeySpaceiTunes                                      NS_AVAILABLE(10_7, 4_0);

// iTunesMetadata keys
extern NSString *const AVMetadataiTunesMetadataKeyAlbum                              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArtist                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyUserComment                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyCoverArt                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyCopyright                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyReleaseDate                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyEncodedBy                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPredefinedGenre                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyUserGenre                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeySongName                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyTrackSubTitle                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyEncodingTool                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyComposer                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAlbumArtist                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAccountKind                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAppleID                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArtistID                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeySongID                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDiscCompilation                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDiscNumber                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyGenreID                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyGrouping                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPlaylistID                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyContentRating                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyBeatsPerMin                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyTrackNumber                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArtDirector                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArranger                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAuthor                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyLyrics                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAcknowledgement                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyConductor                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDescription                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDirector                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyEQ                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyLinerNotes                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyRecordCompany                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyOriginalArtist                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPhonogramRights                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyProducer                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPerformer                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPublisher                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeySoundEngineer                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeySoloist                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyCredits                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyThanks                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyOnlineExtras                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataiTunesMetadataKeyExecProducer                       NS_AVAILABLE(10_7, 4_0);

// ID3Metadata
extern NSString *const AVMetadataFormatID3Metadata                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataKeySpaceID3                                         NS_AVAILABLE(10_7, 4_0);

// ID3Metadata keys
extern NSString *const AVMetadataID3MetadataKeyAudioEncryption                       /* AENC Audio encryption */                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyAttachedPicture                       /* APIC Attached picture */                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyAudioSeekPointIndex                   /* ASPI Audio seek point index */                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyComments                              /* COMM Comments */                                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyCommerical                            /* COMR Commercial frame */                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEncryption                            /* ENCR Encryption method registration */                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEqualization                          /* EQUA Equalization */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEqualization2                         /* EQU2 Equalisation (2) */                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEventTimingCodes                      /* ETCO Event timing codes */                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyGeneralEncapsulatedObject             /* GEOB General encapsulated object */                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyGroupIdentifier                       /* GRID Group identification registration */                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyInvolvedPeopleList_v23                /* IPLS Involved people list */                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyLink                                  /* LINK Linked information */                                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyMusicCDIdentifier                     /* MCDI Music CD identifier */                                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyMPEGLocationLookupTable               /* MLLT MPEG location lookup table */                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOwnership                             /* OWNE Ownership frame */                                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPrivate                               /* PRIV Private frame */                                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPlayCounter                           /* PCNT Play counter */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPopularimeter                         /* POPM Popularimeter */                                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPositionSynchronization               /* POSS Position synchronisation frame */                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyRecommendedBufferSize                 /* RBUF Recommended buffer size */                              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyRelativeVolumeAdjustment              /* RVAD Relative volume adjustment */                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyRelativeVolumeAdjustment2             /* RVA2 Relative volume adjustment (2) */                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyReverb                                /* RVRB Reverb */                                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySeek                                  /* SEEK Seek frame */                                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySignature                             /* SIGN Signature frame */                                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySynchronizedLyric                     /* SYLT Synchronized lyric/text */                              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySynchronizedTempoCodes                /* SYTC Synchronized tempo codes */                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyAlbumTitle                            /* TALB Album/Movie/Show title */                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyBeatsPerMinute                        /* TBPM BPM (beats per minute) */                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyComposer                              /* TCOM Composer */                                             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyContentType                           /* TCON Content type */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyCopyright                             /* TCOP Copyright message */                                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyDate                                  /* TDAT Date */                                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEncodingTime                          /* TDEN Encoding time */                                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPlaylistDelay                         /* TDLY Playlist delay */                                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalReleaseTime                   /* TDOR Original release time */                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyRecordingTime                         /* TDRC Recording time */                                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyReleaseTime                           /* TDRL Release time */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyTaggingTime                           /* TDTG Tagging time */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEncodedBy                             /* TENC Encoded by */                                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyLyricist                              /* TEXT Lyricist/Text writer */                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyFileType                              /* TFLT File type */                                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyTime                                  /* TIME Time */                                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyInvolvedPeopleList_v24                /* TIPL Involved people list */                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyContentGroupDescription               /* TIT1 Content group description */                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyTitleDescription                      /* TIT2 Title/songname/content description */                   NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySubTitle                              /* TIT3 Subtitle/Description refinement */                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyInitialKey                            /* TKEY Initial key */                                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyLanguage                              /* TLAN Language(s) */                                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyLength                                /* TLEN Length */                                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyMusicianCreditsList                   /* TMCL Musician credits list */                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyMediaType                             /* TMED Media type */                                           NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyMood                                  /* TMOO Mood */                                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalAlbumTitle                    /* TOAL Original album/movie/show title */                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalFilename                      /* TOFN Original filename */                                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalLyricist                      /* TOLY Original lyricist(s)/text writer(s) */                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalArtist                        /* TOPE Original artist(s)/performer(s) */                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalReleaseYear                   /* TORY Original release year */                                NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyFileOwner                             /* TOWN File owner/licensee */                                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyLeadPerformer                         /* TPE1 Lead performer(s)/Soloist(s) */                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyBand                                  /* TPE2 Band/orchestra/accompaniment */                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyConductor                             /* TPE3 Conductor/performer refinement */                       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyModifiedBy                            /* TPE4 Interpreted, remixed, or otherwise modified by */       NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPartOfASet                            /* TPOS Part of a set */                                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyProducedNotice                        /* TPRO Produced notice */                                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPublisher                             /* TPUB Publisher */                                            NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyTrackNumber                           /* TRCK Track number/Position in set */                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyRecordingDates                        /* TRDA Recording dates */                                      NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyInternetRadioStationName              /* TRSN Internet radio station name */                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyInternetRadioStationOwner             /* TRSO Internet radio station owner */                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySize                                  /* TSIZ Size */                                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyAlbumSortOrder                        /* TSOA Album sort order */                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPerformerSortOrder                    /* TSOP Performer sort order */                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyTitleSortOrder                        /* TSOT Title sort order */                                     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyInternationalStandardRecordingCode    /* TSRC ISRC (international standard recording code) */         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyEncodedWith                           /* TSSE Software/Hardware and settings used for encoding */     NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeySetSubtitle                           /* TSST Set subtitle */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyYear                                  /* TYER Year */                                                 NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyUserText                              /* TXXX User defined text information frame */                  NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyUniqueFileIdentifier                  /* UFID Unique file identifier */                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyTermsOfUse                            /* USER Terms of use */                                         NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyUnsynchronizedLyric                   /* USLT Unsynchronized lyric/text transcription */              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyCommercialInformation                 /* WCOM Commercial information */                               NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyCopyrightInformation                  /* WCOP Copyright/Legal information */                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialAudioFileWebpage              /* WOAF Official audio file webpage */                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialArtistWebpage                 /* WOAR Official artist/performer webpage */                    NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialAudioSourceWebpage            /* WOAS Official audio source webpage */                        NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialInternetRadioStationHomepage  /* WORS Official Internet radio station homepage */             NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyPayment                               /* WPAY Payment */                                              NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialPublisherWebpage              /* WPUB Publishers official webpage */                          NS_AVAILABLE(10_7, 4_0);
extern NSString *const AVMetadataID3MetadataKeyUserURL                               /* WXXX User defined URL link frame */                          NS_AVAILABLE(10_7, 4_0);
