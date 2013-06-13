//
//  PCPINViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 9/27/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCBaseViewController.h>

@interface PCPINViewController : PCBaseViewController <UITextFieldDelegate>
{
    id _delegate;
    BOOL _createMode;
    UITextField *_field1;
    UITextField *_field2;
    UITextField *_field3;
    UITextField *_field4;
    UITextField *_offScreenField;
    UILabel *_titleLabel;
    UITextView *_instructions;
}

@property(assign, nonatomic) __weak id delegate;
@property(assign, nonatomic) BOOL createMode;
@property(retain, nonatomic) IBOutlet UITextField *field1;
@property(retain, nonatomic) IBOutlet UITextField *field2;
@property(retain, nonatomic) IBOutlet UITextField *field3;
@property(retain, nonatomic) IBOutlet UITextField *field4;
@property(retain, nonatomic) IBOutlet UITextField *offScreenField;
@property(retain, nonatomic) IBOutlet UILabel *titleLabel;
@property(retain, nonatomic) IBOutlet UITextView *instructions;

@end

@protocol PCPINViewControllerDelegate <NSObject>

- (void)controller:(PCPINViewController *)controller finishedWithPin:(NSString *)PIN;

@end
