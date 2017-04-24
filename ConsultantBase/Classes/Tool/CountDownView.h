//
//  CountDownView.h
//  Consultant997
//
//  Created by Kenvin on 2017/4/11.
//  Copyright © 2017年 上海房产. All rights reserved.
//


@interface CountDownView : UIView

@property(assign,nonatomic) BOOL isShowHour;

-(void)setTimeSecond:(NSInteger)second;

-(void)setLabelBackgroundColor:(UIColor *)color;

@end
