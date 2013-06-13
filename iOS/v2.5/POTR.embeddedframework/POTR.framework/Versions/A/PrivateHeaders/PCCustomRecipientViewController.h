//
//  PCCustomRecipientViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/26/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <UIKit/UIKit.h>

@class PCContact;


@protocol PCCustomRecipientViewControllerDelegate;

@interface PCCustomRecipientViewController : UIViewController <UITextFieldDelegate> {
    UITableView *_tableView;
    UIView *_gopherMessageView;
    UITextField *_textField;
    PCContact *_contact;
    id<PCCustomRecipientViewControllerDelegate> _delegate;
}

@property(retain, nonatomic) IBOutlet UITableView *tableView;
@property(retain, nonatomic) IBOutlet UIView *gopherMessageView;
@property(retain, nonatomic) UITextField *textField;
@property(retain, nonatomic) PCContact *contact;
@property(assign, nonatomic) __weak id<PCCustomRecipientViewControllerDelegate>  delegate;

- (IBAction)cancel:(id)sender;
- (IBAction)done:(id)sender;

@end

@protocol PCCustomRecipientViewControllerDelegate <NSObject>

- (void)customRecipientController:(PCCustomRecipientViewController *)recipientController didFinishContact:(PCContact *)contact;
- (void)customRecipientControllerDidCancel:(PCCustomRecipientViewController *)recipientController;

@end
