//
//  PCApiOperations.h
//  POTR
//
//  Created by Anthony Osibov on 5/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <POTR/PCAccount.h>
#import <POTR/PCProject.h>
#import <POTR/PCApiOperation.h>


typedef enum {
    kPCApiAsynchronous,
    kPCApiSynchronous
} PCApiMode;


@interface PCApiOperations : NSObject {
    NSString *_apiKey;
    PCAccount *_account;
    PCApiMode _mode;
    NSMutableArray *_operations;
    dispatch_queue_t _queue;
   // NSData*   _videoData;
}

@property (nonatomic, retain) PCAccount *account;
@property (nonatomic, retain) NSString *apiKey;
@property (nonatomic) PCApiMode mode;
@property (nonatomic, readonly, copy) NSArray *operations;
//**//
//@property (nonatomic, retain) NSData *videoData;
//**//

- (id) initWithApiKey:(NSString *)apiKey account:(PCAccount *)account;
- (id) initWithApiKey:(NSString *)apiKey account:(PCAccount *)account mode:(PCApiMode)mode;

- (PCApiOperation *) checkout:(PCProject *)project;
- (PCApiOperation *) checkout:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) getGpsImageForLocation:(CLLocation *)location;
- (PCApiOperation *) getGpsImageForLocation:(CLLocation *)location andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) getPartners;
- (PCApiOperation *) getPartnersAndExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) getPricing:(PCProject *)project;
- (PCApiOperation *) getPricing:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) getSmells;
- (PCApiOperation *) getSmellsAndExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) isPromoCodeValid:(NSString *)promoCode;
- (PCApiOperation *) isPromoCodeValid:(NSString *)promoCode andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) registerAccount;
- (PCApiOperation *) registerAccount:(PCAccount *)account;
- (PCApiOperation *) registerAccount:(PCAccount *)account andExecute:(PCApiCompletionBlock)completionBlock;
- (PCApiOperation *) registerAccountAndExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) registerDevice:(NSString *)deviceToken;
- (PCApiOperation *) registerDevice:(NSString *)deviceToken andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) updateAccount:(PCAccount *)account;
- (PCApiOperation *) updateAccount:(PCAccount *)account andExecute:(PCApiCompletionBlock)completionBlock;
- (PCApiOperation *) updateAccountAndExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) uploadProject:(PCProject *)project;
- (PCApiOperation *) uploadProject:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

#pragma mark -
#pragma mark [ version 1.1 : Asynch uploading of photos ]
- (PCApiOperation *) deleteVideoFromProject:(PCProject *)project;
- (PCApiOperation *) deleteVideoFromProject:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) uploadProjectFrontPhoto:(PCProject *)project;
- (PCApiOperation *) uploadProjectFrontPhoto:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) uploadProjectVideo:(PCProject *)project;
- (PCApiOperation *) uploadProjectVideo:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

- (PCApiOperation *) getProjectVideoURL:(PCProject *)project;
- (PCApiOperation *) getProjectVideoURL:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlock;

-(PCApiOperation *) uploadProjectMessagePhoto:(PCProject *)project;
-(PCApiOperation *) uploadProjectMessagePhoto:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlcok;

-(PCApiOperation *) uploadProjectMapPhoto:(PCProject *)project;
-(PCApiOperation *) uploadProjectMapPhoto:(PCProject *)project andExecute:(PCApiCompletionBlock)completionBlcok;

#pragma mark -

- (void) cancel;
- (void) cancel:(PCApiOperation *)op;
- (void) run;
- (void) runAndExecute:(void (^)(NSArray *operations))completionBlock;

+ (NSNumber *) checkout:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project;
+ (NSNumber *) getDiscount:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project;
+ (UIImage *) getGpsImage:(NSString *)apiKey account:(PCAccount *)account location:(CLLocation *)location;
+ (NSArray *) getPartners:(NSString *)apiKey account:(PCAccount *)account;
+ (NSDictionary *) getPricing:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project;
+ (NSArray *) getSmells:(NSString *)apiKey account:(PCAccount *)account;
+ (NSNumber *) getTotal:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project;
+ (BOOL) isPromoCodeValid:(NSString *)apiKey account:(PCAccount *)account promoCode:(NSString *)promoCode;
+ (NSDictionary *) registerAccount:(NSString *)apiKey account:(PCAccount *)account;
+ (BOOL) registerDevice:(NSString *)apiKey account:(PCAccount *)account token:(NSString *)deviceToken;
+ (BOOL) updateAccount:(NSString *)apiKey account:(PCAccount *)account;
+ (NSNumber *) uploadProject:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project;
+ (NSNumber *) uploadPhoto:(NSString *)apiKey account:(PCAccount *)account photo:(UIImage *)image name:(NSString *)name;
+ (NSNumber *) uploadPhoto:(NSString *)apiKey account:(PCAccount *)account photo:(UIImage *)image name:(NSString *)name operation:(PCApiOperation *)op;

+ (BOOL) deleteVideoFromProject:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project operation:(PCApiOperation *)op;
+ (NSString *) getVideoURL:(NSString *)apiKey account:(PCAccount *)account postcardId:(NSString *)postcardId operation:(PCApiOperation *)op;
+ (NSNumber *) uploadVideo:(NSString *)apiKey account:(PCAccount *)account project:(PCProject *)project operation:(PCApiOperation *)op;

@end
