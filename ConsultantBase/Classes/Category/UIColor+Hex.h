//
//  UIColor+Hex.h
//  SMKKit
//
//  Created by Kenvin on 16/3/19.
//  Copyright © 2016年 Kenvin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface UIColor (Hex)
//十六进制颜色
+ (UIColor *) colorWithHexString: (NSString *)color;

//颜色转图片
+ (UIImage *)toImage:(UIColor *)color;

//颜色转图片
- (UIImage *)toImage;

@end
