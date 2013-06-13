//
//  NSString+PCExtras.h
//  POTR
//
//  Created by Anthony Osibov on 6/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (PCExtras)

- (NSString *) formatPhoneString;

+ (NSString *) pcDoubleToString:(double)num;
+ (NSString *) pcFloatToString:(float)num;
+ (NSString *) pcIntToString:(int)num;
+ (NSString *) pcLongToString:(long)num;

@end
