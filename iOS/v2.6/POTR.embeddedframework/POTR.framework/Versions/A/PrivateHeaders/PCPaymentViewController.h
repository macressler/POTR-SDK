//
//  PCPaymentViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/20/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCPINViewController.h>
#import "PayPal.h"
#import <POTR/PCBarButtonWindow.h>

@interface PCPaymentViewController : PCBaseViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, PCPINViewControllerDelegate, UIAlertViewDelegate, DeviceReferenceTokenDelegate> {
    UIButton *_doneButton;
    BOOL _hasPromoCode;
    BOOL _showPaymentOptions;
    UILabel *_orderSummaryLabel;
    UIView *_orderSummaryView;
    NSNumber *_origTotal;
    NSString *_paypalDevice;
    UIView *_paypalView;
    UILabel *_promoDiscountLabel;
    UITextField *_promoTextField;
    UIView *_purchaseOptionsView;
    UISwitch *_saveCCInfoSwitch;
    UITableView *_tableView;
    UITextField *_textField;
    UILabel *_totalLabel;
    PCBarButtonWindow *_totalWindow;
}

@property (nonatomic, retain) IBOutlet UIButton *doneButton;
@property (nonatomic, retain) IBOutlet UILabel *orderSummaryLabel;
@property (nonatomic, retain) IBOutlet UIView *orderSummaryView;
@property (nonatomic, retain) IBOutlet UILabel *orderTotalLabel;
@property (nonatomic, retain) IBOutlet UILabel *promoDiscountLabel;
@property (nonatomic, retain) IBOutlet UIView *promoFooterView;
@property (nonatomic, retain) IBOutlet UITextField *promoTextField;
@property (nonatomic, retain) IBOutlet UIView *purchaseOptionsView;
@property (nonatomic, retain) IBOutlet UISwitch *saveCCInfoSwitch;
@property (nonatomic, retain) IBOutlet UITableView *tableView;
@property (nonatomic, retain) IBOutlet UITextField *textField;

- (IBAction) next:(id)sender;
- (IBAction) returnButton:(id)sender;
- (IBAction) toggleSaveInfo:(id)sender;

@end
