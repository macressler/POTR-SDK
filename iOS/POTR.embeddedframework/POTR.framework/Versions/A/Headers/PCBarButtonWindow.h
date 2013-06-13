//
//  PCBarButtonWindow.h
//  POTR
//
//  Created by Anthony Osibov on 6/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface PCBarButtonWindow : UIBarButtonItem {
    UIImageView *_bg;
    UIView *_content;
    UIImageView *_gloss;
    UIView *_holder;
    
    BOOL _showGloss;
}

@property (nonatomic, assign) BOOL showGloss;
@property (nonatomic, readonly, copy) NSArray *subviews;

- (id) initWithFrame:(CGRect)frame;
- (id) initWithView:(UIView *)view;

- (void) addSubview:(UIView *)view;
- (void) bringSubviewToFront:(UIView *)view;
- (void) exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;
- (void) insertSubview:(UIView *)view aboveSubview:(UIView *)siblingSubview;
- (void) insertSubview:(UIView *)view atIndex:(NSInteger)index;
- (void) insertSubview:(UIView *)view belowSubview:(UIView *)siblingSubview;
- (void) sendSubviewToBack:(UIView *)view;
- (UIView *) viewWithTag:(NSInteger)tag;

@end
