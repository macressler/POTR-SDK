//
//  PCAccount.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PCPartner;


@interface PCAccount : NSObject <NSCoding> {
    NSString *_authToken;
    NSString *_cardCVV;
    NSDate *_cardExpiration;
    NSString *_cardNumber;
    BOOL _dirty;
    NSString *_email;
    NSString *_firstName;
    BOOL _isDeviceRegistered;
    NSString *_lastName;
    PCPartner *_partner;
    NSString *_paymentPIN;
    NSString *_paymentToken;
    NSString *_promoCode;
    NSString *_userID;
}

@property (nonatomic, retain) NSString *authToken;
@property (nonatomic, retain) NSString *cardCVV;
@property (nonatomic, retain) NSDate *cardExpiration;
@property (nonatomic, retain) NSString *cardNumber;
@property (nonatomic, retain) NSString *email;
@property (nonatomic, retain) NSString *firstName;
@property (nonatomic) BOOL isDeviceRegistered;
@property (nonatomic, retain) NSString *lastName;
@property (nonatomic, retain) PCPartner *partner;
@property (nonatomic, retain) NSString *paymentPIN;
@property (nonatomic, retain) NSString *paymentToken;
@property (nonatomic, retain) NSString *promoCode;
@property (nonatomic, retain) NSString *userID;

- (id) initWithAccount:(PCAccount *)account;
- (BOOL) isRegistered;
- (void) maskCardData;
- (void) save;
- (BOOL) validate:(NSError **)error;

@end
