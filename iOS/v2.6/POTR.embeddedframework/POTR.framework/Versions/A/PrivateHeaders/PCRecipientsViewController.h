//
//  PCRecipientsViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/26/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <AddressBook/AddressBook.h>
#import <AddressBookUI/AddressBookUI.h>
#import <POTR/PCBaseViewController.h>
#import <POTR/PCPeoplePickerController.h>
#import <POTR/PCRecipientsGroupViewController.h>
#import <POTR/PCCustomRecipientViewController.h>
#import "RegexKitLite.h"

// We're not using a cancel button, back button or the usual background, so 
// don't inherit from PCBaseViewController.

@interface PCRecipientsViewController : PCBaseViewController <PCPeoplePickerControllerDelegate, PCRecipientsGroupViewControllerDelegate, PCCustomRecipientViewControllerDelegate, UITableViewDelegate, UITableViewDataSource> {
    NSMutableArray *_international;
    NSMutableArray *_purgatory;
    NSMutableArray *_people;
    UITableView *_tableView;
}

@property(retain, nonatomic) NSMutableArray *international;
@property(retain, nonatomic) NSMutableArray *purgatory;
@property(retain, nonatomic) NSMutableArray *people;
@property(retain, nonatomic) IBOutlet UITableView *tableView;

- (IBAction)addRecipient:(id)sender;

@end
