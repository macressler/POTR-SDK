//
//  PCSignaturePadViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/20/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCBaseViewController.h>
#import <POTR/PCFlowButtonsView.h>

@interface PCSignaturePadViewController : PCBaseViewController {
    UIImageView *_signaturePad;
    PCFlowButtonsView *_flowBtns;
    
    CGRect _navBarFrame;
    CGRect _controllerFrame;
    
    CGPoint _lastPoint;    
}

@property(nonatomic, retain) IBOutlet UIImageView *signaturePad;
@property(readonly) UIImageView *signature;

- (IBAction)next:(id)sender;
- (IBAction)clear:(id)sender;

@end
