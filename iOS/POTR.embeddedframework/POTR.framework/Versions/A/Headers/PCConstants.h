//
//  PCConstants.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/22/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>


extern NSString *PCDevWebServiceBaseURL;
extern NSString *PCDevWebServiceSecureBaseURL;

extern NSString *PCWebServiceBaseURL;
extern NSString *PCWebServiceSecureBaseURL;

extern NSString *PCFlurryAPIKey;
extern NSString *PCErrorDomain;

extern NSString *PCWorkflowFinishedNotification;
extern NSString *PCWorkflowCompletedKey;
extern NSString *PCWorkflowCanceledKey;

extern NSString  *PCVideoUrlRetrievalNotification;
extern NSString  *PCVideoUrlRetrievalFailedNotification;
extern NSString  *PCVideoWebURL;

extern NSString  *PCWorkflowAlertClickedToSaveKey;


static const CGFloat PCMinPhotoWidth = 1112.0;
static const CGFloat PCMinPhotoHeight = 788.0f;

static const CGFloat PCMinFramedPhotoWidth = 604.0f;
static const CGFloat PCMinFramedPhotoHeight = 428.0;

static const NSInteger PCOnlineAppID = 10;

typedef enum {
    kPCModeCenveo,
    kPCModeDevelopment,
    kPCModeBeta,
    kPCModeProduction
} PCMode;

typedef enum {
    CheckoutError = 1014,
    DeviceError = 1011,
    InvalidRequestError = 1003,
    NetworkError = 1004,
    PartnerError = 1007,
    PaymentError = 1005,
    PricingError = 1009,
    PromoCodeError = 1008,
    SmellError = 1006,
    TotalError = 1010,
    UpdateAccountError = 1012,
    UploadProjectError = 1013,
    VideoUploadError = 1014,
    DeleteVideoError = 1015
} PCErrorCode;


/*
 *  System Versioning Preprocessor Macros
 */

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)
