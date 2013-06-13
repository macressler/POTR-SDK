//
//  PCContact.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>

typedef enum {
    kContactNoError,
    kContactNameError,
    kContactEmailError,
    kContactPhoneError,
    kContactAddressError,
    kContactEmptyError
} ContactErrorCode;


@interface PCContact : NSObject <NSCoding> {
    ABRecordRef _recordRef;
    ABRecordID _recordID;
    ABPropertyID _propertyID;
    
    CFIndex _emailIndex;
    CFIndex _phoneIndex;
    CFIndex _addressIndex;
    
    NSString *_firstName;
    NSString *_lastName;
    NSString *_email;
    NSString *_phone;
    NSString *_address;
    NSString *_address2;
    NSString *_city;
    NSString *_state;
    NSString *_zipcode;
    NSString *_country;
    
    NSString *_fullName;
    NSMutableDictionary *_fullAddress;
    NSString *_fullAddressString;
    
    ContactErrorCode _errorCode;
    
    BOOL _isValid;
    BOOL _isInternational;
    BOOL _isPostalGopher;
}


@property (readonly) ABRecordID recordID;
@property (copy, nonatomic) NSString *firstName;
@property (copy, nonatomic) NSString *lastName;
@property (copy, nonatomic) NSString *email;
@property (copy, nonatomic) NSString *phone;
@property (copy, nonatomic) NSString *address;
@property (copy, nonatomic) NSString *address2;
@property (copy, nonatomic) NSString *city;
@property (copy, nonatomic) NSString *state;
@property (copy, nonatomic) NSString *zipcode;
@property (copy, nonatomic) NSString *country;

@property (copy, readonly) NSString *fullName;
@property (copy, readonly) NSString *fullAddress;

@property (readonly) ContactErrorCode errorCode;
@property (readonly) ABPropertyID propertyID;

@property (readonly) BOOL isValid;
@property (readonly) BOOL isPostalGopher;
@property (readonly) BOOL isInternational;


- (id) initWithPerson:(ABRecordRef)person;
- (id) initWithPerson:(ABRecordRef)person property:(ABPropertyID)property identifier:(ABMultiValueIdentifier)identifier;

- (BOOL) save;


+ (BOOL) validateEmail:(NSString *)email;
+ (BOOL) validatePhone:(NSString *)phone;
+ (BOOL) validateAddress:(NSString *)address city:(NSString *)city state:(NSString *)state zipcode:(NSString *)zipcode country:(NSString *)country;


+ (NSInteger) propCount:(ABPropertyID)property forPerson:(ABRecordRef)person;
+ (NSInteger) addressCountForPerson:(ABRecordRef)person;
+ (NSInteger) emailCountForPerson:(ABRecordRef)person;
+ (NSInteger) phoneCountForPerson:(ABRecordRef)person;


@end
