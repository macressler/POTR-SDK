//
//  PCCropPhotoViewController.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 7/12/11.
//  Copyright 2011 Postcard On The Run. All rights reserved.
//
#import <POTR/PCBaseViewController.h>

@class PCCropGuideView;

//#import <MediaPlayer/MediaPlayer.h>
//#import <MobileCoreServices/UTCoreTypes.h>
//#import <AssetsLibrary/AssetsLibrary.h>

@interface PCEditPhotoViewController : PCBaseViewController <UIScrollViewDelegate, UIPickerViewDataSource, UIPickerViewDelegate> {
    UIView *_bgView;
    UIView *_frameView;
    UIImageView *_borderView;
    UIScrollView *_cropScrollView;
    UIImageView *_instructionsView;
    UISlider *_borderSizeSlider;
    UIButton *_borderStyleButton;
    
    PCCropGuideView *_cropGuideView;
    int _count;
    UIColor *_borderColor;
    UIImage *_borderImage;
    int _borderSize;
    NSDictionary *_borderColors;
    UIImage *_photo;
    //**//
   // UIImagePickerController *_cameraUI;
    //**//
}
//**//
//@property (nonatomic, retain) UIImagePickerController *cameraUI;
//**//
@property (retain, nonatomic) IBOutlet UIView *bgView;
@property (retain, nonatomic) IBOutlet UIScrollView *cropScrollView;
@property (retain, nonatomic) IBOutlet UIImageView *instructionsView;
@property (retain, nonatomic) IBOutlet PCCropGuideView *cropGuideView;

- (IBAction) rotate:(id)sender;
- (IBAction) onBorderSizeChange:(id)sender;

//**//
//- (void)video: (NSString *) videoPath didFinishSavingWithError: (NSError *) error contextInfo:(void*)contextInfo;
//**//

@end
