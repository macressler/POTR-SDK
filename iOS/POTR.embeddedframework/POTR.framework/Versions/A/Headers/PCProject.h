//
//  PCProject.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/13/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <UIKit/UIKit.h>

@class PCContact;
@class PCSmell;
@class PCPhoto;


@protocol PCProjectProcol

@property (nonatomic, retain, readonly) NSString *ID;
@property (nonatomic, retain) NSNumber *onlineID;

@property (nonatomic, retain) NSDate *createdDate;
@property (nonatomic, retain) NSDate *sendDate;

@property (nonatomic, retain) NSArray *recipients;
@property (nonatomic, retain) NSString *message;
@property (nonatomic, retain) UIImage *videoThumbnail;
@property (nonatomic) BOOL isVideoUploaded;

@end


@interface PCProject : NSObject <NSCoding, PCProjectProcol> {
    BOOL _hasDomestic;
    BOOL _hasInternational;
    BOOL _hasPostalGopher;
    
    UIImage *_back;
    UIImage *_backMessage;
    UIImage *_front;
    PCContact *_backRecipient;
    
    BOOL _frontDirty;
    BOOL _backDirty;
    BOOL _isUploaded;
    
    BOOL _allowFrame;
    BOOL _allowBorder;

    CGSize _size;
    CGSize _minSize;
    CGRect _photoCrop;
    UIImageOrientation _photoOrientation;
    float _photoScale;
    
    UIColor *_borderColor;
    UIImage *_borderImage;
    int _borderSize;
    
    NSArray *_recipients;
    
    PCPhoto *_photo;
    
    UIColor *_frontBackgroundColor;
    UIImage *_frontBackgroundImage;
    
    UIColor *_backBackgroundColor;
    UIImage *_backBackgroundImage;
    
	NSString *_message;
    UIColor *_color;
    UIFont *_font;
    
    UIImage *_signature;
    UIImage *_mapImage;
    PCSmell *_smell;

    NSDate *_createdDate;
    NSDate *_sendDate;
    NSDate *_domesticDeliveryDate;
    NSDate *_internationalDeliveryDate;
    
    NSString *_ID;
    NSNumber *_onlineID;
    NSNumber *_price;
    NSNumber *_discount;
    NSString *_paypalToken;
    NSString *_promoCode;
    NSString *_promoDescription;
    NSDate *_promoExpiration;

    // video props
    BOOL _isVideoUploaded;
    NSData *_videoData;
    
    //////////////////////////////////////////////////////////////
    ///[ version 1.1 : Asynch uploading of photos ]
    BOOL _isFrontUploaded;
    BOOL _isMessageUploaded;
    BOOL _isMapUploaded;
   
    NSMutableDictionary* _photoIDs;
    //////////////////////////////////////////////////////////////
}

@property (nonatomic, readonly) BOOL hasDomestic;
@property (nonatomic, readonly) BOOL hasInternational;
@property (nonatomic, readonly) BOOL hasPostalGopher;

@property (nonatomic, assign) BOOL allowFrame;
@property (nonatomic, assign) BOOL allowBorder;

@property (nonatomic, assign) CGSize size;
@property (nonatomic, readonly) CGSize minSize;
@property (nonatomic, assign) CGRect photoCrop;
@property (nonatomic, assign) UIImageOrientation photoOrientation;
@property (nonatomic, assign) float photoScale;
@property (nonatomic, retain) UIColor *borderColor;
@property (nonatomic, retain) UIImage *borderImage;
@property (nonatomic, assign) int borderSize;

@property (retain, nonatomic) NSArray *recipients;

@property (retain, nonatomic) PCPhoto *photo;

@property (retain, nonatomic) UIColor *frontBackgroundColor;
@property (retain, nonatomic) UIImage *frontBackgroundImage;

@property (retain, nonatomic) UIColor *backBackgroundColor;
@property (retain, nonatomic) UIImage *backBackgroundImage;

@property (retain, nonatomic) NSString *message;
@property (retain, nonatomic) UIColor *color;
@property (retain, nonatomic) UIFont *font;

@property (retain, nonatomic) UIImage *signature;
@property (retain, nonatomic) UIImage *mapImage;
@property (retain, nonatomic) PCSmell *smell;

@property (retain, nonatomic) NSDate *createdDate;
@property (retain, nonatomic) NSDate *sendDate;
@property (retain, nonatomic) NSDate *domesticDeliveryDate;
@property (retain, nonatomic) NSDate *internationalDeliveryDate;

@property (nonatomic, retain, readonly) NSString *ID;
@property (nonatomic, retain) NSNumber *onlineID;
@property (nonatomic, retain) NSNumber *price;
@property (nonatomic, retain) NSNumber *discount;
@property (nonatomic, retain) NSString *paypalToken;
@property (nonatomic, retain) NSString *promoCode;
@property (nonatomic, retain) NSString *promoDescription;
@property (nonatomic, retain) NSDate *promoExpiration;

@property (nonatomic, retain) NSData *videoData;
@property (nonatomic, retain) NSString *videoName;
@property (nonatomic, retain) NSString *videoExtension;
@property (nonatomic, retain) NSURL *videoURL;
@property (nonatomic, retain) UIImage *videoThumbnail;
@property (nonatomic) BOOL isVideoUploaded;


- (id) initWithProject:(PCProject *)project;
- (UIImage *) renderFront;
- (UIImage *) renderMessage;
- (UIImage *) renderBack:(PCContact *)recipient;

//////////////////////////////////////////////////////////////
///[ version 1.1 : Asynch uploading of photos ]
@property (nonatomic, retain) NSMutableDictionary* photoIDs;
@property (nonatomic) BOOL isFrontUploaded;
@property (nonatomic) BOOL isMessageUploaded;
@property (nonatomic) BOOL isMapUploaded;


-(void) uploadFrontPhoto;
-(void) uploadFrontPhotoAndExecute:(void(^) (NSError *error))completionBlock;
-(void) uploadMapPhoto;
-(void) uploadMapPhotoAndExecute:(void(^) (NSError *error))completionBlock;
-(void) uploadMessagePhoto;
-(void) uploadMessagePhotoAndExecute:(void(^) (NSError *error))completionBlock;
-(void) deleteVideo;
-(void) deleteVideoAndExecute:(void(^) (NSError *error))completionBlock;
-(void) uploadVideo;
-(void) uploadVideoAndExecute:(void(^) (NSError *error))completionBlock;
//////////////////////////////////////////////////////////////

- (void) upload;
- (void) uploadAndExecute:(void (^)(NSError *error))completionBlock;

-(void) getVideoURL;
-(void) getVideoURLAndExecute:(void(^) (NSError *error)) completionBlock;
@end
