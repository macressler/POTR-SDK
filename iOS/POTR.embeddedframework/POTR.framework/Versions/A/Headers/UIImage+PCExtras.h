//
//  UIImage+PCExtras.h
//  POTR SDK
//
//  Created by Anthony Osibov on 4/5/12.
//  Copyright (c) 2011 Postcard On The Run. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (PCExtras)

- (UIImage *) rotateClockwise;
- (UIImage *) rotateCounterClockwise;

- (UIImage *) rotate:(UIImageOrientation)orientation;

- (UIImage *) scale:(float)scale;

- (UIImage *) scale:(float)scale rotate:(UIImageOrientation)orientation;

+ (UIImage *) imageWithColor:(UIColor *)color;

@end
