//
//  SIDCameraManagerViewController.h
//  SuperIDSDK
//
//  Created by XU JUNJIE on 23/6/15.
//  Copyright (c) 2015 ISNC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "SIDImageFilterCommon.h"
#import "SIDCameraPreviewView.h"


typedef NS_ENUM( NSInteger, SIDAVCamSetupResult ) {
    
    AVCamSetupResultSuccess,
    AVCamSetupResultCameraNotAuthorized,
    AVCamSetupResultSessionConfigurationFailed
};

@interface SIDCameraManagerViewController : UIViewController

//配置摄像头模块
- (BOOL)configureCameraManagerWithLivenessDetectFlag:(BOOL) flag SIDPreview:(SIDCameraPreviewView *)previewView cameraPositon:(SIDPreferCameraDevicePosition) positon;


//dealloc中调用
- (void)destoryCameraModule;

//开始活体检测
- (void)startLivenessDetect;

//停止活体检测
- (void)stopLivenssDetect;

//配置加亮模式
- (void)configNightModeInView:(UIView*)view;

//启动加亮模式
- (void)enableNightMode;


//查询是否允许加亮模式
- (BOOL)isNightModeEnable;


//启动自动通过用户照片生成头像
- (void)enableAutoSaveAvatar;


//用户不允许使用摄像头通知
- (void)cannotAccessCamera;

//查询是否有摄像头访问权限
- (SIDAVCamSetupResult)getCameraSetupResult;

//完成人脸检测，摄像头自动停止捕获，自动关闭双击操作
- (void)finishGetFaceWithLivenessScore:(float)score;

//超时未捕获人脸，摄像头自动停止捕获
- (void)overTimeGetFace;

//开启加亮模式，摄像头自动停止捕获
- (void)openNightMode;

//关闭加亮模式，摄像头自动停止捕获
- (void)closeNightMode;

//停止摄像头
- (void)stopCameraSession;


- (BOOL)isGetFace;


//当需要在特定界面开启双击手势时，使用该方法
- (void) openDoubleTapGesture;

- (void) enableDoubleTap;

- (void) disableDoubleTap;

- (void) startLivenessDetectUnderNightMode;

- (void) hideFaceLandmarks;

@end
