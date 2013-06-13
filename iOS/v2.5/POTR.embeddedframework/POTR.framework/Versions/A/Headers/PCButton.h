//
//  PCButton.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <UIKit/UIKit.h>


typedef enum {
    PCButtonTagNormal = 0,
    PCButtonTagLeft = 500,
    PCButtonTagRight = 1000
} PCButtonTag;


@interface PCButton : UIButton { }

- (id)initWithFrame:(CGRect)frame andTag:(PCButtonTag)tag;

@end