//
//  PCBaseViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 9/19/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//

#import <POTR/PCFlowButtonsView.h>
#import <POTR/PCViewController.h>

@class PCCoachnote;


@protocol PCBaseViewDelegate
    
    @required 
    - (void) dismissCoachnote;
    - (IBAction) next:(id)sender;

@end


@interface PCBaseViewController : PCViewController <UIAlertViewDelegate, PCBaseViewDelegate> {
    NSString *_backButtonTitle;
    
    PCFlowButtonsView *_flow_buttons_view;
    
    NSString *_coachnoteKey;
    NSString *_coachnoteImage;
    PCCoachnote *_coachnoteView;
}

@property(retain, nonatomic) NSString *backButtonTitle;
@property(retain, nonatomic) PCFlowButtonsView *flowButtonsView;

- (CGRect) makeFlowButtonsFrame;
- (CGPoint) makeCoachnoteOrigin;
- (void) dismissCoachnote;

- (void) next:(id)sender;
- (BOOL) cancel:(id)sender;

@end
