//
//  PCApiFile.h
//  POTR
//
//  Created by Anthony Osibov on 7/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PCApiFile : NSObject

@property (nonatomic, retain) NSData *data;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *type;

+ (PCApiFile *) file:(NSString *)name data:(NSData *)data type:(NSString *)type;

@end
