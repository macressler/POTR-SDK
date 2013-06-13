//
//  PCApiOperation.h
//  POTR
//
//  Created by Anthony Osibov on 6/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <POTR/PCApiRequest.h>

typedef enum {
    kPCApiCheckout,
    kPCApiGetGpsImageForLocation,
    kPCApiGetPartners,
    kPCApiGetPricing,
    kPCApiGetSmells,
    kPCApiIsPromoCodeValid,
    kPCApiRegisterAccount,
    kPCApiRegisterDevice,
    kPCApiUpdateAccount,
    kPCApiDeleteVideoFromProject,
    kPCApiUploadProject,
    kPCApiUploadProjectFront,
    kPCApiUploadProjectMessage,
    kPCApiUploadProjectMap,
    kPCApiUploadProjectVideo,
    kPCApiGetProjectVideoURL
    
} PCApiMethod;

typedef enum {
    kPCApiPromoCodeInvalid = 1000
} PCApiError;


@interface PCApiOperation : NSObject


typedef void (^PCApiCompletionBlock)(PCApiOperation *op);


@property (nonatomic) PCApiMethod method;
@property (nonatomic, retain) NSDictionary *params;
@property (nonatomic, retain) NSDictionary *data;
@property (nonatomic, retain) NSError *error;
@property (nonatomic) BOOL isExecuted;
@property (nonatomic, copy) PCApiCompletionBlock completionBlock;
@property (nonatomic, retain) PCApiRequest *request;

@end
