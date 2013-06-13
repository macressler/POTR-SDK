//
//  PCApiRequest.h
//  POTR
//
//  Created by Anthony Osibov on 5/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <POTR/PCAccount.h>
#import "ASIFormDataRequest.h"

@interface PCApiRequest : NSObject {
    PCAccount *_account;
    NSMutableDictionary *_get;
    NSString *_path;
    NSMutableDictionary *_post;
    BOOL _secure;
    ASIHTTPRequest* _request;
}

@property (nonatomic, retain) PCAccount *account;
@property (nonatomic, retain) NSDictionary *get;
@property (nonatomic, retain) NSString *path;
@property (nonatomic, retain) NSDictionary *post;
@property (nonatomic) BOOL secure;
@property (nonatomic, retain) ASIHTTPRequest *request;

- (id) initWithAccount:(PCAccount *)account path:(NSString *)path;
- (id) initWithAccount:(PCAccount *)account path:(NSString *)path get:(NSMutableDictionary *)getVars;
- (id) initWithAccount:(PCAccount *)account path:(NSString *)path post:(NSMutableDictionary *)postVars;
- (id) initWithAccount:(PCAccount *)account path:(NSString *)path get:(NSMutableDictionary *)getVars post:(NSMutableDictionary *)postVars;

- (id) send;
- (id) send1;
- (void) cancel;

@end
