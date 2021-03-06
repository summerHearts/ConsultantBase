//
//  UINavigationBar+SMK_NavigationShadow.h
//  SMKKit
//
//  Created by Kenvin on 16/11/28.
//  Copyright © 2016年 Kenvin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationBar (NavigationShadow)
- (void)dropShadowWithOffset:(CGSize)offset
                      radius:(CGFloat)radius
                       color:(UIColor *)color
                     opacity:(CGFloat)opacity;

@end
