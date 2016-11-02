//
//  SIDCoreLoginKit.h
//  SuperIDSDK
//
//  Created by lzn on 16/9/14.
//  Copyright © 2016年 ISNC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "SIDAppUserInfoModel.h"
#import "SuperIDDelegate.h"

@interface SIDCoreLoginKit : NSObject

/**
 一登刷脸登录功能:弹出一登刷脸VC

 @param userInfoModel 当前用户的应用账号信息，传入后可加快授权绑定过程。具体用法参考开发文档。如无，可置为nil
 @param responseBlock 刷脸成功,返回用户数据,error为nil;其他任何情况失败,error都不为nil
 */
+ (void)showLoginViewControllerWithAppUserInfoModel:(SIDAppUserInfoModel *)userInfoModel
                                      responseBlock:(void(^)(NSDictionary *result, NSError *error))responseBlock;


/**
 一登刷脸验证功能:用户必须先刷脸登录成功,才能调用刷脸验证功能,否则是不会弹出刷脸验证VC

 @param count         用户可尝试重复刷脸验证次数，传入nil值为默认值1次
 @param responseBlock 刷脸验证成功,返回枚举值:SIDFaceVerifySucceed,error为nil;其他任何情况失败,error都不为nil
 */
+ (void)showFaceVerifyViewControllerWithRetryCount:(NSNumber *)count
                                     responseBlock:(void(^)(SIDFACEVerifyState result, NSError *error))responseBlock;


/**
 一登刷脸获取用户人脸信息功能

 @param responseBlock 获取人脸信息成功,返回用户数据,error为nil;其他任何情况失败,error都不为nil
 */
+ (void)showFaceFeatureViewControllerWithResponseBlock:(void(^)(NSDictionary *result, NSError *error))responseBlock;


@end
