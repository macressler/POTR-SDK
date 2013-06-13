//
//  PCPeoplePickerController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 11/22/11.
//  Copyright (c) 2011 ELC Technologies. All rights reserved.
//
#import <AddressBook/AddressBook.h>
#import <AddressBookUI/AddressBookUI.h>
#import <POTR/PCCustomRecipientViewController.h>

@interface PCPeoplePickerController : UITableViewController <UISearchBarDelegate, UISearchDisplayDelegate, ABPersonViewControllerDelegate, PCCustomRecipientViewControllerDelegate> {
    ABAddressBookRef _addressBook;
    NSDictionary *_dataSource;
    NSArray *_keys;
    NSMutableArray *_searchResults;
    UILabel *_selectionCountLabel;
    NSArray *_selected;
    NSMutableArray *_people;
    id _delegate;
    UISearchDisplayController *_searchController;
}

@property(assign, nonatomic) ABAddressBookRef addressBook;
@property(retain, nonatomic) NSDictionary *dataSource;
@property(retain, nonatomic) NSArray *keys;
@property(retain, nonatomic) NSMutableArray *searchResults;
@property(retain, nonatomic) IBOutlet UILabel *selectionCountLabel;
@property(retain, nonatomic) NSMutableArray *people;
@property(assign, nonatomic) id delegate;
@property(retain, nonatomic) UISearchDisplayController *searchController;

- (id) initWithStyle:(UITableViewStyle)style andSelected:(NSMutableArray *)people andDelegate:(id)delegate;
- (NSInteger) getSelectedIndex:(ABRecordRef)person;
- (IBAction) cancel:(id)sender;
- (IBAction) done:(id)sender;

@end

@protocol PCPeoplePickerControllerDelegate <NSObject>

- (void) peoplePickerController:(PCPeoplePickerController *)controller didFinishWithContacts:(NSArray *)contacts;
- (void) peoplePickerControllerDidCancel:(PCPeoplePickerController *)controller;

@end
