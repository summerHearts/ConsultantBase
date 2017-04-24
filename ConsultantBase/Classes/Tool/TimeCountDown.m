//
//  TimeCountDownView.m
//  Consultant997
//
//  Created by Kenvin on 2017/4/11.
//  Copyright © 2017年 上海房产. All rights reserved.
//

#import "TimeCountDown.h"

@interface TimeCountDown(){
    
    dispatch_source_t _processingQueueSource;
}


@property (atomic, assign, getter=isRunning) BOOL running;

@end

@implementation TimeCountDown

-(void)stopTimer{
    [self pause];
}

-(void)startTimer:(NSInteger)timeInterval{
    if (timeInterval<=0) {
        return;
    }
    _timeInterval=timeInterval;

   
    if (_processingQueueSource) {
        _processingQueueSource  = nil;
    }
    
    NSInteger totalTime = self.timeInterval;

    __weak TimeCountDown *weakSelf = self;
    _processingQueueSource = dispatch_source_create(DISPATCH_SOURCE_TYPE_DATA_ADD, 0, 0,
                                                    dispatch_get_main_queue());
    dispatch_source_set_event_handler(_processingQueueSource, ^{
        if (weakSelf.timeInterval<=0) {
            _processingQueueSource = nil;
        }else{
            weakSelf.timeInterval--;
        }
        if (weakSelf.delegate && [weakSelf.delegate respondsToSelector:@selector(timeCountDownPerSecond)]) {
            [weakSelf.delegate timeCountDownPerSecond];
        }
        
    });
    
    [self resume];
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        
        for (NSUInteger index = 0; index <totalTime; index++) {
            dispatch_source_merge_data(_processingQueueSource, 1);
            usleep(1000000);//1秒
        }
    });

    
}

//获取分派源分派处理程序之前恢复
- (void)resume {
    if (self.running) {
        return;
    }
    self.running = YES;
    dispatch_resume(_processingQueueSource);
}

//暂停
- (void)pause {
    if (!self.running) {
        return;
    }
    self.running = NO;
    dispatch_suspend(_processingQueueSource);
}
@end
