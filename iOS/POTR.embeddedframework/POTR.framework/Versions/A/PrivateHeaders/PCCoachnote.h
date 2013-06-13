//
//  PCCoachnote.h
//  POTR SDK
//
//  Created by Anthony Osibov on 3/22/12.
//  Copyright (c) 2011 Postcard On The Run. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <POTR/PCBaseViewController.h>

@interface PCCoachnote : UIImageView {
    NSString *_key;
    id <PCBaseViewDelegate> _delegate;
}

@property (nonatomic, retain) NSString *key;

- (id) initWithKey:(NSString *)key andImage:(NSString *)image andDelegate:(id)delegate;

@end
