//
//  PayPalWebView.m
//  POTR
//
//  Created by Anthony Osibov on 5/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "PayPalWebView.h"
#import <POTR/PCDataController.h>

@implementation PayPalWebView

@synthesize startURL = _startURL;
@synthesize endURL = _endURL;
@synthesize step = _step;
@dynamic loadingView;


- (id) initWithDevice:(NSString *)device token:(NSString *)token endURL:(NSString *)theEndURL {
    if(self = [super init]){
		self.startURL = [NSString stringWithFormat:@"https://www.paypal.com/cgi-bin/webscr?cmd=_express-checkout-mobile&drt=%@&token=%@", device, token];
        
		self.endURL = theEndURL;
    }
    
    return self;
}

- (void) cancel:(id)selector {
    [self dismissModalViewControllerAnimated:YES];
}

// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void) loadView {
    [super loadView];
    
    UIBarButtonItem *spacer = [[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil] autorelease];
    UILabel *label = [[[UILabel alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 100.0f, 25.0f)] autorelease];
    label.text = @"PayPal";
    label.textAlignment = UITextAlignmentCenter;
    label.font = [UIFont fontWithName:@"Helvetica-Bold" size:14.0f];
    label.textColor = [UIColor whiteColor];
    label.backgroundColor = [UIColor clearColor];
    
    _toolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 320.0f, 44.0f)];
    _toolbar.tintColor = [[PCDataController sharedDataController] applicationTintColor];
    [_toolbar setItems:[NSArray arrayWithObjects:
                        [[[UIBarButtonItem alloc] initWithTitle:@"Back" style:UIBarButtonItemStyleDone target:self action:@selector(cancel:)] autorelease],
                        spacer,
                        [[[UIBarButtonItem alloc] initWithCustomView:label] autorelease],
                        spacer,
                        nil]
            animated:NO];
    
    [self.view addSubview:_toolbar];
    
	_webView = [[UIWebView alloc] initWithFrame:CGRectMake(0.0f, 44.0f, 320.0f, 416.0f)];
	_webView.delegate = self;
	[_webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:_startURL]]];
    
	[self.view addSubview:_webView];
}

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void) viewDidLoad {
    [super viewDidLoad];
    
	self.navigationItem.hidesBackButton = TRUE;
}


#define LOADING_TAG 6543

- (UIActivityIndicatorView *) loadingView {
	UIActivityIndicatorView *lv = (UIActivityIndicatorView *)[self.view viewWithTag:LOADING_TAG];
    
	if(!lv){
		lv = [[[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray] autorelease];
		[lv setHidesWhenStopped:TRUE];
		
        CGRect frame = lv.frame;
		frame.origin.x = round((self.view.frame.size.width - frame.size.width) / 2.);
		frame.origin.y = round((self.view.frame.size.height - frame.size.height) / 2.);
		
        lv.frame = frame;
		lv.tag = LOADING_TAG;
		
        [self.view addSubview:lv];
	}
    
	return lv;
}

- (void) viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
    
//	self.loadingView;
	
    [self.navigationController setNavigationBarHidden:TRUE animated:TRUE];
}

- (void) viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
    
	[self.navigationController setNavigationBarHidden:FALSE animated:TRUE];
}

- (void) didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

- (void) viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void) dealloc {
	self.startURL = nil;
	self.endURL = nil;
    
	((UIWebView *)_webView).delegate = nil;
    
    [_webView release];
    [_toolbar release];
    
    [super dealloc];
}


#pragma mark UIWebViewDelegate methods

//In webView:shouldStartLoadWithRequest:navigationType: we intercept attempts to redirect to a certain URL
//and use that to go back to the application launch screen to discard the current order and place a new order.
- (BOOL) webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
	NSString *urlString = [[request.URL absoluteString] lowercaseString];
    
	if(urlString.length > 0){
		//80 is the default HTTP port.
		//The PayPal server may add the default port to the URL.
		//This will break our string comparisons.
		if([request.URL.port intValue] == 80){
			urlString = [urlString stringByReplacingOccurrencesOfString:@":80" withString:@""];
		}
		
		if([urlString rangeOfString:@"_flow"].location != NSNotFound){
			_step++;
		}
		
		if([urlString rangeOfString:[_endURL lowercaseString]].location != NSNotFound){
//			[self.navigationController popToRootViewControllerAnimated:TRUE];
            [self dismissModalViewControllerAnimated:YES];
            
			return FALSE;
		}
	}
    
	return TRUE;
}

- (void) webViewDidStartLoad:(UIWebView *)webView {
	self.title = @"Connecting to PayPal...";
    
	[self.loadingView startAnimating];
}

- (void) webViewDidFinishLoad:(UIWebView *)webView {
	self.title = [NSString stringWithFormat:@"Step %d", _step];
    
	[self.loadingView stopAnimating];
}

- (void) webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error {
	self.title = @"Connection failed";
    
	[self.loadingView stopAnimating];
}

@end

