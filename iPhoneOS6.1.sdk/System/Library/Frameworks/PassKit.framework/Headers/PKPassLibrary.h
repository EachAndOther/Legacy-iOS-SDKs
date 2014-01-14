
#import <Foundation/Foundation.h>

@class PKPass;

/* Threading contract: no concurrent usage.
 */
NS_CLASS_AVAILABLE_IOS(6_0)
@interface PKPassLibrary : NSObject

/* The library is not available on iPad in 6.0.
 */
+ (BOOL)isPassLibraryAvailable;

/* These return only passes the process is entitled to access.
 */
- (NSArray *)passes;
- (PKPass *)passWithPassTypeIdentifier:(NSString *)identifier serialNumber:(NSString *)serialNumber;
- (void)removePass:(PKPass *)pass;

/* This returns YES even if the process is not entitled to access the pass in the library.
 An app like Mail is not entitled to get pass from the library, but it should avoid presenting UI for adding an email attachment pass that is already in the library.
 */ 
- (BOOL)containsPass:(PKPass *)pass;

/* This will fail if a pass with matching identifier and serial number is not already present in the library, or if the process is not entitled to access the pass.
 To add a completely new pass, use PKAddPassesViewController.
 */
- (BOOL)replacePassWithPass:(PKPass *)pass;

@end

/* This notification is issued by a library instance, with that instance as the sender.  If there are no instantiated library objects, no notifications.
 There are no guarantees about what thread or queue these come in on.
 */
extern NSString *const PKPassLibraryDidChangeNotification NS_AVAILABLE_IOS(6_0);

/* Entries in user info dictionary for PKPassLibraryDidChangeNotification.

 PKPassLibraryAddedPassesUserInfoKey is the key for an array of passes
 PKPassLibraryReplacementPassesUserInfoKey is the key for an array of passes
 PKPassLibraryRemovedPassInfosUserInfoKey is the key for an array of dictionaries, each of which has keys PKPassLibraryPassTypeIdentifierUserInfoKey and PKPassLibrarySerialNumberUserInfoKey mapping to strings.
  */
extern NSString *const PKPassLibraryAddedPassesUserInfoKey NS_AVAILABLE_IOS(6_0);
extern NSString *const PKPassLibraryReplacementPassesUserInfoKey NS_AVAILABLE_IOS(6_0);
extern NSString *const PKPassLibraryRemovedPassInfosUserInfoKey NS_AVAILABLE_IOS(6_0);

extern NSString *const PKPassLibraryPassTypeIdentifierUserInfoKey NS_AVAILABLE_IOS(6_0);
extern NSString *const PKPassLibrarySerialNumberUserInfoKey NS_AVAILABLE_IOS(6_0);