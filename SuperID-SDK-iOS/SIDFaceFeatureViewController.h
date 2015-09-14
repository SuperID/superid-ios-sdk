//
//  SIDFaceFeatureViewController.h
//  人脸信息深度整合VC 包含所有支持操作的方法
//
//  Created by XU JUNJIE on 24/12/14.
//  Copyright (c) 2014 ISNC. All rights reserved.
//


#import <UIKit/UIKit.h>

/**
 开发者通过继承SIDFaceFeatureViewController类进行深度整合
 */
@interface SIDFaceFeatureViewController : UIViewController

/**
 *  初始人脸信息VC,在元类的ViewDidLoad方法中调用
 *
 *  @param duration 单次识别人脸信息的持续时长
 *  @param width    获取摄像头实时视频流视窗的宽度（不大于480）
 *  @param hight    获取摄像头实时视频流视窗的高度（不大于640）
 *
 *  @return 初始化成功返回YES,失败返回NO
 */
- (BOOL)configureFaceFeatureViewWithDuration:(float)duration withFrameWidth:(float)width high:(float)high;


/**
 *  启动人脸信息识别
 */
- (void)startDetectFaceFeature;

- (void)startDetectAdvancedFaceFeature;

/**
 *  结束人脸信息识别
 */
- (void)stopDetectFaceFeature;


/**
 *  当摄像头成功检测到可用人脸时，通过该方法通知
 */
- (void)didFinishDetectFace;


/**
 *  成功完成人脸信息识别后，调用该方法通知
 *
 *  @param featureInfo  用户的人脸信息内容
 */
- (void)getFaceFeatureSucceedWithFeatureInfo:(NSDictionary *) featureInfo;


/**
 *  人脸信息识别失败，调用该方法通知
 *
 *  @param error  开发者可根据错误信息描述进行相应处理，详见Demo或开发者文档
 */
- (void)getFaceFeatureFail:(NSError *)error;


/**
 *  获取当前的摄像头视频Layer
 *
 *  @return AVCaptureVideoPreviewLayer
 */
- (id)getCurrentPreviewLayer;

@end
