//
//  SIDScanFaceViewController.h
//  SuperIDSDK
//
//  Created by lzn on 16/10/19.
//  Copyright © 2016年 ISNC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SIDCameraManagerViewController.h"
#import "SIDCameraPreviewView.h"

@protocol SIDSearchFaceProtocol <NSObject>

@required
/**
 *  1比N结果回调
 *
 *  @param isSucceed  在人脸群组中找到对应用户为成功，返回YES,其他情况为失败，返回NO
 *  @param usersArray 根据人脸群组的检索出的对应用户组，并根据得分进行排序
 */
- (void)groupCompareResult:(BOOL)isSucceed usersArray:(NSArray *)usersArray;


/**
 *  输入图像无法通过活体检测回调方法
 *
 *  当输入源为图像或者视频时，将通过该回调方法通知三方，1比N结果不在回调，三方可作为统一失败处理，可以要求用户重新刷脸
 *
 */
- (void)userCannotPassLivenessDetect;


/**
 *  摄像头成功捕获人脸，开始进行人脸检索
 */
- (void)hasGetTheUserFace;

@end

@interface SIDSearchFaceViewController : SIDCameraManagerViewController

/**
 *  初始化摄像头配置以及人脸检测配置，该方法在ViewDidLoad中执行
 *
 *  @param previewView 摄像头的preview指针
 */
- (void)setupSearchFaceManagerWithPreview:(SIDCameraPreviewView *)previewView;



/**
 *  开启人脸检测和比对方法
 *
 *  @param sourceId 用户组对应的source_app_id
 *  @param groupId  用户组ID，多个用户组使用逗号分隔，如：group_1,group_2
 */
- (void)startDetectFaceWithSourceId:(NSString *)sourceId GroupId:(NSString *)groupId;

@end
