//
//  SIDMutilpleCameraManagerViewController.h
//  NewCameraModule
//
//  Created by XU JUNJIE on 5/1/2016.
//  Copyright © 2016 ISNC. All rights reserved.
//


/**
 *  设置开启优选设备摄像头
 */
typedef NS_ENUM(NSInteger, SIDPreferCameraDevicePosition) {
    /**
     *  后置摄像头
     */
    SIDPreferCameraDeviceBack = 1,
    /**
     *  前置摄像头
     */
    SIDPreferCameraDeviceFront,
};

@import UIKit;
#import "SIDCameraPreviewView.h"


@protocol SIDMutipleCameraManagerProtocol <NSObject>

@required
/**
 *  1比N结果回调
 *
 *  @param isSucceed  在人脸群组中找到对应用户为成功，返回YES,其他情况为失败，返回NO
 *  @param usersArray 根据人脸群组的检索出的对应用户组，并根据得分进行排序
 */
- (void)groupCompareResult:(BOOL)isSucceed usersArray:(NSArray *)usersArray;


/**
 *  摄像头成功捕获人脸，开始进行人脸检索
 */
- (void)hasGetTheUserFace;

@end

@interface SIDMutilpleCameraManagerViewController : UIViewController

/**
 *  初始化摄像头配置以及人脸检测配置，该方法在ViewDidLoad中执行
 *
 *  @param previewView 摄像头的preview指针
 *  @param positon     打开界面时的优先摄像头，为 SIDPreferCameraDeviceFront 开启前置摄像头，为 SIDPreferCameraDeviceBack 开启后置摄像头
 */
- (void)setupMutipleCameraManagerWithPreview:(SIDCameraPreviewView *)previewView preferDevicePosition:(SIDPreferCameraDevicePosition)positon;


/**
 *  调用该方法可切换当前使用的摄像头
 */
- (void)switchCamera;


/**
 *  开启人脸检测和比对方法
 *
 *  @param sourceId 用户组对应的source_app_id
 *  @param groupId  用户组ID，多个用户组使用逗号分隔，如：group_1,group_2
 */
- (void)startDetectFaceWithSourceId:(NSString *)sourceId GroupId:(NSString *)groupId;




@end
