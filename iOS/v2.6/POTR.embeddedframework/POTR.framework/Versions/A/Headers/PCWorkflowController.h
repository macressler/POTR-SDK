//
//  PCWorkflowController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <POTR/PCPhoto.h>
#import <POTR/PCProject.h>
#import <POTR/PCConstants.h>

@protocol PCWorkflowControllerDelegate;


@interface PCWorkflowController : NSObject <UINavigationControllerDelegate> {
    id <PCWorkflowControllerDelegate> _delegate;
    
    BOOL _allowPendingProjects;
    BOOL _allowPhotoBorders;
    BOOL _allowPhotoEditing;
    BOOL _allowPhotoFraming;
    BOOL _allowSmellMail;
    BOOL _allowStatisticsGathering;
    BOOL _showCancelButton;
    BOOL _useLocationServices;

    
    NSString *_partnerName;
    NSString *_promoCode;
    UIColor *_tintColor;
    PCMode _mode;
}

@property(nonatomic, assign) id <PCWorkflowControllerDelegate> delegate;
@property(nonatomic, readonly) CGSize minPhotoResolution;

- (id) initWithAPIKey:(NSString *)apiKey;
- (id) initWithAPIKey:(NSString *)apiKey mode:(PCMode)mode;

- (void) registerDevice:(NSString *)deviceToken;

// Returns NO if postcardPhoto does not meet the minimum resolution 
// requirements for printing.
- (BOOL) isValidPostcardSize:(CGSize)size;

- (BOOL) isValidPostcardImage:(UIImage *)postcardPhoto;

- (BOOL) isValidPostcardPhoto:(PCPhoto *)postcardPhoto;

// Returns a view controller to start the POTR workflow. You must add the view
// controller to a UINavigationController for it to function properly. Use this
// method if you want to integrate POTR into an existing navigation hierarchy
// in your app. Raises an exception if postcardPhoto does not meet the minimum
// resolution requirements. 
- (UIViewController *) viewControllerForPhoto:(PCPhoto *)postcardPhoto;
- (UIViewController *) viewControllerForProject:(PCProject *)project;

// Returns a view controller which can be used as a stand-alone modal view
// controller. Use this method if your app does not have a suitable navigation 
// controller. Raises an exception if postcardPhoto does not meet the minimum
// resolution requirements. 
- (UIViewController *) modalViewControllerForPhoto:(PCPhoto *)postcardPhoto;
- (UIViewController *) modalViewControllerForProject:(PCProject *)project;

- (BOOL) allowPendingProjects;
- (BOOL) allowPhotoBorders;
- (BOOL) allowPhotoEditing;
- (BOOL) allowPhotoFraming;
- (BOOL) allowSmellMail;
- (BOOL) allowStatisticsGathering;
- (BOOL) showCancelButton;
- (BOOL) useLocationServices;

- (PCMode) mode;
- (NSString *) partnerName;
- (NSString *) promoCode;
- (UIColor *) tintColor;

+ (BOOL) canAccessContacts;
+ (CLLocation *) currentLocation;
+ (void) verifyContactsPermissionAndExecute:(void (^)())executeBlock;

@end


@protocol PCWorkflowControllerDelegate <NSObject>

@optional
- (BOOL) allowPendingProjects;
- (BOOL) allowPhotoBorders;
- (BOOL) allowPhotoEditing;
- (BOOL) allowPhotoFraming;
- (BOOL) allowSmellMail;
- (BOOL) allowStatisticsGathering;
- (NSString *) partnerName;
- (NSString *) promoCode;
- (BOOL) showCancelButton;
- (UIColor *) tintColor;
- (BOOL) useLocationServices;

@required
// Called when the user completes the POTR workflow. It is your responsibility
// to dismiss the view controller and show a confirmation if necessary.
- (void) potr:(UIViewController *)potr canceled:(BOOL)canceled;

@end
