//
//  PCPartner.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 10/25/11.
//  Copyright (c) 2011 ELC Technologies. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PCPartner : NSObject <NSCoding> {
    NSString *_name;
    NSNumber *_webID;
}

@property(retain) NSString *name;
@property(retain) NSNumber *webID;

+ (id)partnerWithName:(NSString *)name webID:(NSNumber *)webID;

@end
