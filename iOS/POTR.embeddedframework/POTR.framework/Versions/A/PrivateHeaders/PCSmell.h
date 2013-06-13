//
//  PCSmell.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 9/1/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface PCSmell : NSObject <NSCoding> {
    NSNumber *_webID;
    NSString *_title;
    UIImage *_icon;
    UIImage *_image;
}

@property(retain, nonatomic) NSNumber *webID;
@property(retain, nonatomic) NSString *title;
@property(retain, nonatomic) UIImage *icon;
@property(retain, nonatomic) UIImage *image;

+ (id)smellWithID:(NSNumber *)webID title:(NSString *)title icon:(UIImage *)icon image:(UIImage *)image;

@end
