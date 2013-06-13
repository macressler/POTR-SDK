//
//  PCContactGroup.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PCContactGroup : NSObject <NSCoding> {
    NSString *_title;
    NSMutableArray *_contacts;
}

@property(copy) NSString *title;
@property(copy) NSMutableArray *contacts;

+ (id)contactGroupWithTitle:(NSString *)title;

@end
