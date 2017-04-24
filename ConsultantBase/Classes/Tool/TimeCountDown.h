//
//  TimeCountDownView.h
//  Mike
//
//  Created by 佐毅 on 15/10/19.
//  Copyright © 2015年 上海乐住信息技术有限公司. All rights reserved.
//

@class TimeCountDown;
@protocol TimeCountDownDelegate <NSObject>

@optional
- (void)timeCountDownPerSecond;

@end

@interface TimeCountDown : NSObject

//Delegate
@property(assign,nonatomic) id<TimeCountDownDelegate> delegate;

//倒计时时间
@property(assign,nonatomic) NSInteger timeInterval;

//开始时间
-(void)startTimer:(NSInteger)timeInterval;

//停止时间
-(void)stopTimer;

@end
