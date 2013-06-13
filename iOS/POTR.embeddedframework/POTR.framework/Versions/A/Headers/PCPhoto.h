//
//  PCPhoto.h
//  POTR
//
//  Created by Anthony Osibov on 5/2/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface PCPhoto : NSObject <NSCopying, NSCoding> {
    
    UIImage *_image;
    BOOL _dirty;
    float _quality;
    NSMutableDictionary *_metadata;
    NSData *_jpeg;
    NSData *_png;
}

@property (nonatomic, retain, readonly) UIImage *image;
@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) NSDictionary *metadata;
@property (nonatomic) float quality;
@property (nonatomic, assign) CLLocation *location;
@property (nonatomic, assign) CLLocationDirection trueHeading;
@property (nonatomic, readonly) NSData *jpeg;
@property (nonatomic, readonly) NSData *png;

- (id) initWithUIImage:(UIImage *)image;
- (id) initWithUIImage:(UIImage *)image quality:(float)quality;
- (id) initWithUIImage:(UIImage *)image metadata:(NSDictionary *)metadata quality:(float)quality;
- (id) initWithData:(NSData *)data;
- (id) initWithData:(NSData *)data quality:(float)quality;

- (PCPhoto *) rotateClockwise;
- (PCPhoto *) rotateCounterClockwise;

- (void) setUserComment:(NSString*)comment;
- (void) setDateOriginal:(NSDate *)date;
- (void) setDateDigitized:(NSDate *)date;
- (void) setMake:(NSString*)make model:(NSString*)model software:(NSString*)software;
- (void) setDescription:(NSString*)description;
- (void) setKeywords:(NSString*)keywords;
- (void) setImageOrientarion:(UIImageOrientation)orientation;
- (void) setDigitalZoom:(CGFloat)zoom;
- (void) setHeading:(CLHeading*)heading;

- (void) saveToPhotoAlbum;

@end
