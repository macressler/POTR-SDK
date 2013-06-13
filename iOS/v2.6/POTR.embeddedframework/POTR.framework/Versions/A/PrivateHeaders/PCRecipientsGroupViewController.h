//
//  PCRecipientsGroupViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/26/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <UIKit/UIKit.h>


@protocol PCRecipientsGroupViewControllerDelegate;

@interface PCRecipientsGroupViewController : UITableViewController 
{
    id<PCRecipientsGroupViewControllerDelegate> _delegate;
}

@property(assign, nonatomic) __weak id<PCRecipientsGroupViewControllerDelegate> delegate;

- (IBAction)cancel:(id)sender;
- (IBAction)addGroup:(id)sender;

@end

@protocol PCRecipientsGroupViewControllerDelegate <NSObject>

- (void)recipientsGroupController:(PCRecipientsGroupViewController *)controller didFinishWithContacts:(NSArray *)contacts;
- (void)recipientsGroupControllerDidCancel:(PCRecipientsGroupViewController *)controller;

@end