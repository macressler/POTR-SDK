//
//  PCCropGuideView.h
//  POTR SDK
//
//  Created by Marc Charbonneau on 5/10/11.
//  Copyright 2011 Post Card on the Run. All rights reserved.
//
#import <UIKit/UIKit.h>


@interface PCCropGuideView : UIView {
    CGRect _visibleRect;
}

@property(assign, nonatomic) CGRect visibleRect;
@property(readonly) UIEdgeInsets edgeWidths;

@end
