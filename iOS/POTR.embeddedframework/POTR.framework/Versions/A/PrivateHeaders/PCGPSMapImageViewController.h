//
//  PCGPSMapImageViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/20/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCBaseViewController.h>

@interface PCGPSMapImageViewController : PCBaseViewController {
    UIAlertView *_alertView;
    
    UIView *_gpsView;
    UIView *_photoView;
    UIView *_instructionsView;
    
    UISwitch *_gpsSwitch;
    UISwitch *_photoSwitch;
    
    UIImageView *_gpsImageView;
    UIImageView *_photoImageView;
}

@end
