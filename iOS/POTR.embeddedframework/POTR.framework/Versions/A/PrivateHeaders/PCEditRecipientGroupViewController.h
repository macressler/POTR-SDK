//
//  PCEditRecipientGroupViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/26/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <AddressBook/AddressBook.h>
#import <AddressBookUI/AddressBookUI.h>

@class PCContactGroup;

@interface PCEditRecipientGroupViewController : UITableViewController <ABPeoplePickerNavigationControllerDelegate, UITextFieldDelegate> {
    PCContactGroup *_contactGroup;
}

@property(retain, nonatomic) PCContactGroup *contactGroup;

- (IBAction)done:(id)sender;

@end
