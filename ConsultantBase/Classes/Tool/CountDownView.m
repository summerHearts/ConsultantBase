//
//  CountDownView.m
//  Consultant997
//
//  Created by Kenvin on 2017/4/11.
//  Copyright © 2017年 上海房产. All rights reserved.
//

#import "CountDownView.h"
#import "UIColor+Hex.h"

#define FONT(F) [UIFont systemFontOfSize:F]

@interface CountDownView()

@property(strong,nonatomic) UILabel *hourLabel;

@property(strong,nonatomic) UILabel *minuteLabel;

@property(strong,nonatomic) UILabel *secondeLabel;

@property(strong,nonatomic) UILabel *divideLabelOne;

@property(strong,nonatomic) UILabel *divideLabelTwo;

@end

@implementation CountDownView


-(instancetype)init{
    self = [super init];
    if (self) {
        [self initViews];
    }
    return self;
}

-(instancetype)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self) {
        [self initViews];
    }
    return self;
}

-(void)awakeFromNib{
    [super awakeFromNib];
    [self initViews];
}

#pragma mark - SubViews UI

-(void)initViews{
    self.backgroundColor = [UIColor colorWithHexString:@"F0F0F0"];
    _hourLabel=[[UILabel alloc]init];
    _hourLabel.textColor=[UIColor colorWithHexString:@"969696"];
    _hourLabel.font=FONT(10);
    _hourLabel.textAlignment=NSTextAlignmentCenter;
    _hourLabel.backgroundColor=[UIColor clearColor];
    _minuteLabel=[[UILabel alloc]init];
    _minuteLabel.textColor=[UIColor colorWithHexString:@"969696"];
    _minuteLabel.font=FONT(10);
    _minuteLabel.textAlignment=NSTextAlignmentCenter;
    _minuteLabel.backgroundColor=[UIColor clearColor];
    _secondeLabel=[[UILabel alloc]init];
    _secondeLabel.textColor=[UIColor colorWithHexString:@"969696"];
    _secondeLabel.font=FONT(10);
    _secondeLabel.textAlignment=NSTextAlignmentCenter;
    _secondeLabel.backgroundColor=[UIColor clearColor];
    _divideLabelOne=[[UILabel alloc]init];
    _divideLabelOne.text=@":";
    _divideLabelOne.textColor=[UIColor colorWithHexString:@"969696"];
    _divideLabelOne.font=FONT(10);
    _divideLabelOne.backgroundColor = [UIColor clearColor];
    _divideLabelOne.textAlignment=NSTextAlignmentCenter;
    _divideLabelTwo=[[UILabel alloc]init];
    _divideLabelTwo.text=@":";
    _divideLabelTwo.textColor = [UIColor colorWithHexString:@"969696"];
    _divideLabelTwo.font=FONT(10);
    _divideLabelTwo.textAlignment=NSTextAlignmentCenter;
    _divideLabelTwo.backgroundColor = [UIColor clearColor];
    [self addSubview:_hourLabel];
    [self addSubview:_minuteLabel];
    [self addSubview:_secondeLabel];
    [self addSubview:_divideLabelOne];
    [self addSubview:_divideLabelTwo];
    _hourLabel.text=[NSString stringWithFormat:@"%02d",0];
    _minuteLabel.text=[NSString stringWithFormat:@"%02d",0];
    _secondeLabel.text=[NSString stringWithFormat:@"%02d",0];
    _hourLabel.frame=CGRectMake(0, 0, self.frame.size.width/4, self.frame.size.height);
    _minuteLabel.frame=CGRectMake(self.frame.size.width/8*3, 0, self.frame.size.width/4, self.frame.size.height);
    _secondeLabel.frame=CGRectMake(self.frame.size.width/4*3, 0, self.frame.size.width/4, self.frame.size.height);
    _divideLabelOne.frame=CGRectMake(self.frame.size.width/4, 0, self.frame.size.width/8, self.frame.size.height);
    _divideLabelTwo.frame=CGRectMake(self.frame.size.width/8*5, 0, self.frame.size.width/8, self.frame.size.height);
    
}


-(void)setTimeSecond:(NSInteger)second{
    _hourLabel.text=[NSString stringWithFormat:@"%02ld",(long)second/3600];
    _minuteLabel.text=[NSString stringWithFormat:@"%02ld",(long)(second/60)%60];
    _secondeLabel.text=[NSString stringWithFormat:@"%02ld",(long)second%60];
}

-(void)setLabelBackgroundColor:(UIColor *)color{

}

@end
