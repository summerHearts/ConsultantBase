//
//  CommonDefines.h
//  Pods
//
//  Created by Kenvin on 2017/4/13.
//
//

#ifndef CommonDefines_h
#define CommonDefines_h

#import <UIKit/UIKit.h>
#import <objc/runtime.h>

//系统版本
#define SYS_VISION   ([[[UIDevice currentDevice] systemVersion] floatValue])
#define IOS10_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define IOS9_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)
#define IOS8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)

//APP版本
#define APP_VERSION  ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])

#define ScreenScale  ([[UIScreen mainScreen] scale])
//屏幕宽高
#define SCREEN_WIDTH                  ([UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT                 ([UIScreen mainScreen].bounds.size.height)
#define SCREEN_MAX_LENGTH             (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH             (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

//比例适配
#define SH_H_5s(h)   (SCREEN_HEIGHT * (h / 960.0))
#define SH_W_5s(w)   (SCREEN_WIDTH  * (w / 640.0))

#define SH_H(h)      (SCREEN_HEIGHT * (h / 1334.0))
#define SH_W(w)      (SCREEN_WIDTH  * (w / 750.0))

#define DEVICE_IS_IPAD ([[UIDevice currentDevice]userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPHONE_4  (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5  (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6  (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

//主window
#define APP_KEY_WINDOW                [UIApplication sharedApplication].keyWindow

#define UIImageMake(imgName)          [UIImage imageNamed:imgName]
#define UIImageOriginal(imgName)      [UIImageMake(imgName) imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal]

// 获取一个像素
#define PixelOne                      [ViewTool pixelOne]


#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif




#if __has_feature(objc_arc)
//ARC
#else
//MRC
#endif


/**
 *  调试日志输出
 */
//#ifdef DEBUG
#ifndef __OPTIMIZE__
//调试状态
#define Log_fileName [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
#define NSLog(...) printf("➡️ 执行文件 %s:第%d行: \n调用方法: %s\nlog信息:\n%s\n\n",[Log_fileName UTF8String],__LINE__,__func__,[[NSString stringWithFormat:__VA_ARGS__] UTF8String]);
#else
//发布状态
#define NSLog(...) {}
#endif


#pragma mark - 方法-C对象、结构操作
/**
 *  像素向上取整,传进来2.1pt -> 2.5(2x) ->2.333(3x) ->5px像素
 */
CG_INLINE float
floorUpPixel(float floatValue) {
    CGFloat flattedValue = ceilf(floatValue * ScreenScale) / ScreenScale;
    return flattedValue;
}

/**
 *  像素向下取整,传进来2.2pt -> 2(2x) ->2(3x) ->4px像素
 */
CG_INLINE float
floorDownPixel(float floatValue) {
    CGFloat resultValue = floorf(floatValue * ScreenScale) / ScreenScale;
    return resultValue;
}

/**
 *  像素四舍五入取整,传进来2.2pt -> 2(2x) ->4px像素 ->2.333(3x) ->5px像素,先不要使用
 */
CG_INLINE float
floorRoundPixel(float floatValue) {
    CGFloat resultValue = round(floatValue * ScreenScale) / ScreenScale;
    return resultValue;
}


#pragma mark - CGSize
/// 判断一个size是否为空（宽或高为0）
CG_INLINE BOOL
CGSizeIsEmpty(CGSize size) {
    return size.width <= 0 || size.height <= 0;
}

/// 传入size，返回一个x/y为0的CGRect
CG_INLINE CGRect
CGRectMakeWithSize(CGSize size) {
    return CGRectMake(0, 0, size.width, size.height);
}

/// 将一个CGSize像素对齐
CG_INLINE CGSize
CGSizeFlatted(CGSize size) {
    return CGSizeMake(floorUpPixel(size.width), floorUpPixel(size.height));
}

/// 将一个 CGSize 以 pt 为单位向上取整
CG_INLINE CGSize
CGSizeCeil(CGSize size) {
    return CGSizeMake(ceilf(size.width), ceilf(size.height));
}

/// 将一个 CGSize 以 pt 为单位向下取整
CG_INLINE CGSize
CGSizeFloor(CGSize size) {
    return CGSizeMake(floorf(size.width), floorf(size.height));
}

#pragma mark - CGPoint-
/// 获取rect的center，包括rect本身的x/y偏移
CG_INLINE CGPoint
CGPointGetCenterWithRect(CGRect rect) {
    return CGPointMake(floorUpPixel(CGRectGetMidX(rect)), floorUpPixel(CGRectGetMidY(rect)));
}

CG_INLINE CGPoint
CGPointGetCenterWithSize(CGSize size) {
    return CGPointMake(floorUpPixel(size.width / 2.0), floorUpPixel(size.height / 2.0));
}

#pragma mark - CGRect-像素对齐
CG_INLINE CGRect
CGRectFlatMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height) {
    return CGRectMake(floorUpPixel(x), floorUpPixel(y), floorUpPixel(width), floorUpPixel(height));
}

CG_INLINE CGRect
CGRectSetXY(CGRect rect, CGFloat x, CGFloat y) {
    rect.origin.x = floorUpPixel(x);
    rect.origin.y = floorUpPixel(y);
    return rect;
}

#pragma mark - CGFloat
//用于居中运算
CG_INLINE CGFloat
CGFloatGetCenter(CGFloat parent, CGFloat child) {
    return floorUpPixel((parent - child) / 2.0);
}


#pragma mark - swizz工具
CG_INLINE void
ReplaceMethod(Class _class, SEL _originSelector, SEL _newSelector) {
    Method oriMethod = class_getInstanceMethod(_class, _originSelector);
    Method newMethod = class_getInstanceMethod(_class, _newSelector);
    BOOL isAddedMethod = class_addMethod(_class, _originSelector, method_getImplementation(newMethod), method_getTypeEncoding(newMethod));
    if (isAddedMethod) {
        class_replaceMethod(_class, _newSelector, method_getImplementation(oriMethod), method_getTypeEncoding(oriMethod));
    } else {
        method_exchangeImplementations(oriMethod, newMethod);
    }
}

CG_INLINE void
AopMethod(Class _originClass, Class _hackClass, SEL _originSelector, SEL _newSelector) {
    Method oriMethod = class_getInstanceMethod(_originClass, _originSelector);
    Method newMethod = class_getInstanceMethod(_hackClass, _newSelector);
    BOOL isAddedMethod = class_addMethod(_originClass, _originSelector, method_getImplementation(newMethod), method_getTypeEncoding(newMethod));
    if (isAddedMethod) {
        class_replaceMethod(_originClass, _newSelector, method_getImplementation(oriMethod), method_getTypeEncoding(oriMethod));
    } else {
        method_exchangeImplementations(oriMethod, newMethod);
    }
}


#endif /* CommonDefines_h */
