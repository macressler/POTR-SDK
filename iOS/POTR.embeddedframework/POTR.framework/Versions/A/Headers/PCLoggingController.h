//
//  PCLoggingController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 8/31/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <POTR/PCConstants.h>


@interface PCLoggingController : NSObject {
    BOOL _consoleEnabled;
    BOOL _flurryEnabled;
    BOOL _flurrySessionStarted;
    NSString *_testFlightApiKey;
    BOOL _testFlightEnabled;
    PCMode _mode;
}


@property (nonatomic, assign) BOOL flurryEnabled;
@property (nonatomic, assign) BOOL consoleEnabled;
@property (nonatomic, assign) PCMode mode;
@property (nonatomic, readonly) BOOL testFlightEnabled;
@property (nonatomic, assign) NSString *testFlightApiKey;


+ (id) sharedLoggingController;

+ (void) endTimedEvent:(NSString *)eventName;
+ (void) log:(NSString *)format, ...;
+ (void) logEvent:(NSString *)eventName;
+ (void) startTimedEvent:(NSString *)eventName;


@end
