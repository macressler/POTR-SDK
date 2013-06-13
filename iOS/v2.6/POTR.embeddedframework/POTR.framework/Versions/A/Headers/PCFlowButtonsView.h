//
//  PCFlowButtonsView.h
//  POTR SDK
//
//  Created by Anthony Osibov on 3/1/12.
//  Copyright (c) 2011 Postcard On The Run. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PCButton.h"


@interface PCFlowButtonsView : UIView <UIAlertViewDelegate> {
    UIImageView *_bar;
    PCButton *_cancelBtn;
    PCButton *_nextBtn;
    id _delegate;
    BOOL _allowCancel;
    BOOL _allowSave;
    BOOL _isLast;
    BOOL _isFirst;
}

@property (nonatomic, assign) id delegate;
@property (nonatomic) BOOL allowCancel;
@property (nonatomic) BOOL allowSave;
@property (nonatomic) BOOL isLast;
@property (nonatomic) BOOL isFirst;

- (void)onNext:(id)sender;
- (void)onCancel:(id)sender;

@end