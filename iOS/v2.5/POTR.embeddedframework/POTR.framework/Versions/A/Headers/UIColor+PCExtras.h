//
//  UIColor+PCExtras.h
//  POTR SDK
//
//  Created by Anthony Osibov on 3/14/12.
//  Copyright (c) 2011 Postcard On The Run. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (PCExtras)

+ (UIColor *) colorWithHexString: (NSString *) hexString;

+ (CGFloat) colorComponentFrom: (NSString *) string start: (NSUInteger) start length: (NSUInteger) length;

- (BOOL) isEqualToColor:(UIColor *)color;

@end
