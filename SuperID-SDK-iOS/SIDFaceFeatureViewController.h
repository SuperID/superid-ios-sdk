//
//  SIDFaceFeatureViewController.h
//  人脸信息深度整合VC 包含所有支持操作的方法
//
//  Created by XU JUNJIE on 24/12/14.
//  Copyright (c) 2014 ISNC. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "SIDCameraManagerViewController.h"

/**
 开发者通过继承SIDFaceFeatureViewController类进行深度整合
 */
@interface SIDFaceFeatureViewController : SIDCameraManagerViewController

/**
 *  初始化摄像头配置以及人脸检测配置，该方法在ViewDidLoad中执行
 *
 *  @param previewView 摄像头的preview指针
 */
- (void)setupFaceFeatureManagerWithPreview:(SIDCameraPreviewView *)previewView;

/**
 *  启动人脸信息识别
 */
- (void)startDetectFaceFeature;

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

@end
