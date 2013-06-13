//
//  PCMessageViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <QuartzCore/QuartzCore.h>
#import <POTR/PCBaseViewController.h>
#import <POTR/PCFlowButtonsView.h>

@interface PCMessageViewController : PCBaseViewController <UITextViewDelegate, UIPickerViewDataSource, UIPickerViewDelegate>
{
    UILabel *_charsRemainingLbl;
    UIImageView *_shadow;
    UITextView *_messageTxt;
    
    NSInteger _previousColorRow;
    NSInteger _previousFontRow;
    NSDictionary *_colors;
    NSDictionary *_fonts;
}

@property(retain, nonatomic) IBOutlet UITextView *messsageTxt;
@property(retain, nonatomic) IBOutlet UILabel *charsRemainingLbl;
@property(retain, nonatomic) IBOutlet UIImageView *shadow;

- (IBAction) style:(id) sender;

@end
