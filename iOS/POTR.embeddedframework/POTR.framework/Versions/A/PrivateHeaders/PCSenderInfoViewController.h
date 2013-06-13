//
//  PCSenderInfoViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCBaseViewController.h>


@interface PCSenderInfoViewController : PCBaseViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, UIAlertViewDelegate, UIPickerViewDelegate, UIPickerViewDataSource> {
    UITableView *_tableView;
    UIView *_footerView;
    UIView *_headerView;
    UITextField *_editor;
    
    BOOL _hasPartner;
}

@property(retain, nonatomic) IBOutlet UITableView *tableView;
@property(retain, nonatomic) IBOutlet UIView *footerView;
@property(retain, nonatomic) IBOutlet UIView *headerView;
@property(retain, nonatomic) IBOutlet UITextField *editor;

- (IBAction)next:(id)sender;

@end
