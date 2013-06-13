//
//  PCPreviewViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/20/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <QuartzCore/QuartzCore.h>
#import <POTR/PCBaseViewController.h>

@interface PCPreviewViewController : PCBaseViewController {
    UIImageView *_imageView;
    UILabel *_smellLabel;
    BOOL _flipped;    
}

@property(retain, nonatomic) IBOutlet UIImageView *imageView;
@property(retain, nonatomic) IBOutlet UILabel *smellLabel;

- (IBAction) flip:(id)sender;
- (IBAction) next:(id)sender;

@end
