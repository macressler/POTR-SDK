//
//  PCSmellMailViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 8/31/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCBaseViewController.h>

@class PCSmell;

@interface PCSmellMailViewController : PCBaseViewController <UIPickerViewDelegate, UIPickerViewDataSource, UIAlertViewDelegate>
{
    PCSmell *_selectedSmell;
    UIPickerView *_smellPicker;
    UIImageView *_imageView;
    UIAlertView *_alertView;
}

@property(retain, nonatomic) PCSmell *selectedSmell;
@property(retain, nonatomic) IBOutlet UIPickerView *smellPicker;
@property(retain, nonatomic) IBOutlet UIImageView *imageView;
@property(retain, nonatomic) IBOutlet UIAlertView *alertView;

- (IBAction)next:(id)sender;

@end
