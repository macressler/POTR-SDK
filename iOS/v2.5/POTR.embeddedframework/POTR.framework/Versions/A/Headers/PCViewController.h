//
//  PCViewController.h
//  POTR
//
//  Created by Anthony Osibov on 6/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "DejalActivityView.h"

@interface PCViewController : UIViewController {
    
    DejalActivityView *_activityView;
    UIActionSheet *_actionSheet;
    
}

- (DejalActivityView *) showActivityView:(UIView *)view label:(NSString *)label showNetworkActivityIndicator:(BOOL)showNetworkActivityIndicator;
- (void) removeActivityView:(BOOL)animated;

- (void) showActionSheetWithView:(UIView *)view title:(NSString *)title;
- (void) dismissActionSheet;
- (void) dismissActionSheet:(id)sender;

@end
