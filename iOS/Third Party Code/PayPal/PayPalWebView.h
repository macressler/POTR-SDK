//
//  PayPalWebView.h
//  POTR
//
//  Created by Anthony Osibov on 5/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PayPalWebView : UIViewController <UIWebViewDelegate> {
    @private
	NSString *_startURL;
	NSString *_endURL;
	NSUInteger _step;
    UIWebView *_webView;
    UIToolbar *_toolbar;
}

@property (nonatomic, retain) NSString *startURL;
@property (nonatomic, retain) NSString *endURL;
@property (nonatomic, assign) NSUInteger step;
@property (nonatomic, readonly) UIActivityIndicatorView *loadingView;

- (id) initWithDevice:(NSString *)device token:(NSString *)token endURL:(NSString *)theEndURL;

@end
