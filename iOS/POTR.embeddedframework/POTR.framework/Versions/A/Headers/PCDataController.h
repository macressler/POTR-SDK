//
//  PCDataController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <POTR/PCConstants.h>
#import <POTR/PCApiOperations.h>


@class PCProject;
@class PCAccount;


typedef void(^LocationCompleteBlock)(CLLocation *location, NSError *error);

@interface PCDataController : NSObject <CLLocationManagerDelegate> {
    NSOperationQueue *_operationQueue;
    CLLocationManager *_locationManager;
    
    BOOL _enableCancelButton;
    BOOL _enableLocationServices;
    BOOL _enablePhotoBorders;
    BOOL _enablePhotoFraming;
    BOOL _enableProjectSave;
    BOOL _enableSmellMail;
    BOOL _updateLocation;
    
    PCAccount *_account;
    NSString *_apiKey;
    UIColor *_applicationTintColor;
    NSMutableDictionary *_coachmarks;
    NSMutableArray *_contactGroups;
    CLLocation *_currentLocation;
    UIImage *_currentLocationImage;
    NSString *_deviceToken;
    PCMode _mode;
    int _numRegAttempts;
    NSString *_partner;
    NSArray *_partners;
    UIImage *_photoLocationImage;
    PCProject *_project;
    NSString *_promoCode;
    NSArray *_smells;
    NSMutableArray *isolatedOperations ;
}


@property (nonatomic, retain) NSOperationQueue *operationQueue;
@property (nonatomic, copy) LocationCompleteBlock locationCompleteBlock;

@property (nonatomic, assign) BOOL enableCancelButton;
@property (nonatomic, assign) BOOL enableLocationServices;
@property (nonatomic, assign) BOOL enablePhotoBorders;
@property (nonatomic, assign) BOOL enablePhotoFraming;
@property (nonatomic, assign) BOOL enableProjectSave;
@property (nonatomic, assign) BOOL enableSmellMail;

@property (nonatomic, retain) PCAccount *account;
@property (nonatomic, retain) NSString *apiKey;
@property (nonatomic, retain) UIColor *applicationTintColor;
@property (nonatomic, retain) NSMutableDictionary *coachmarks;
@property (nonatomic, retain) NSMutableArray *contactGroups;
@property (nonatomic, retain) NSMutableArray *isolatedOperations;
@property (nonatomic, retain) CLLocation *currentLocation;
@property (nonatomic, retain) UIImage *currentLocationImage;
@property (nonatomic, assign) PCMode mode;
@property (nonatomic, retain) NSString *partner;
@property (nonatomic, retain) NSArray *partners;
@property (nonatomic, retain) UIImage *photoLocationImage;
@property (nonatomic, retain) PCProject *project;
@property (nonatomic, retain) NSString *promoCode;
@property (nonatomic, retain) NSArray *smells;


- (void) purchase;
- (void) purchase:(void (^)(NSError *error))completionBlock;

// In the following methods, the completion block MUST be guaranteed to run 
// on the main thread.
- (void) refreshGpsLocation;
- (void) refreshGpsLocationAndExecute:(LocationCompleteBlock)completionBlock;
- (void) refreshPartners;
- (void) refreshPartnersAndExecute:(void (^)(NSArray *partners, NSError *error))completionBlock;
- (void) refreshSmells;
- (void) refreshSmellsAndExecute:(void (^)(NSArray *smells, NSError *error))completionBlock;
- (void) registerDevice:(NSString *)deviceToken;
- (void) saveSharedData;
- (BOOL) showCoachmarkForKey:(NSString *)key;
- (void) uploadPostcard;
- (void) uploadPostcard:(void (^)(NSError *error))completionBlock;
- (void) updatePricing:(NSString *)promoCode;
- (void) updatePricing:(NSString *)promoCode completionBlock:(void (^)(NSDictionary *pricing, NSError *error))completionBlock;

//- (void) deleteVideo:(void (^)(NSError *error))completionBlock;
- (void) uploadPostcardFrontPhoto:(void (^)(NSError *error))completionBlock;
- (void) uploadPostcardMessagePhoto:(void (^)(NSError *error))completionBlock;
- (void) uploadPostcardMapPhoto:(void (^)(NSError *error))completionBlock;

- (void) uploadPostcardVideo:(void (^)(NSError *error))completionBlock;
- (void) getPostcardVideoURL:(void (^)(NSError *error))completionBlock;

+ (id) sharedDataController;
+ (void) update;

@end
