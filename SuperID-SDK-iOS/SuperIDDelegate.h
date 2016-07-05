//
//  SuperIDSuperIDDelegate.h
//  包含SuperID的所有委托方法和对应枚举参数
//
//  Created by XU JUNJIE on 24/12/14.
//  Copyright (c) 2015年 ISNC. All rights reserved.
//

/**
 *  SuperID 语言模式类型
 */
typedef NS_ENUM(NSInteger, SIDLanguageMode){
    /**
     *  自动模式，根据iOS系统当前的语言自动切换。
     */
    SIDAutoMode,
    /**
     *  简体中文
     */
    SIDSimplifiedChineseMode,
    /**
     *  英文
     */
    SIDEnglishMode,
    /**
     *  繁体中文
     */
    SIDTraditionChineseMode,
};


/**
 *  SuperID 更新应用用户Uid或者用户账号信息回调的结果状态类型
 */
typedef NS_ENUM(NSInteger, SIDUserUpdateResponseState){
    /**
     *  更新用户的账户信息成功
     */
    SIDUpdateUserInfoSucceed,
    /**
     *  更新用户的账户信息失败，一般情况下不会发生。
     */
    SIDUpdateAppUserInfoFail,
    /**
     *  更新用户的Uid成功
     */
    SIDUpdateAppUidSucceed,
    /**
     *  当前用户Uid已经存在，即开发者上传应用Uid已经和某个SuperID账户关联。
     */
    SIDUidHasExist,
    /**
     *  更新用户Uid失败，一般情况下不会发生。
     */
    SIDUpdateAppUidFail,
    /**
     *  当应用用户尚未授权SuperID时或者解除绑定授权，更新用户账户信息或者Uid会失败。
     *  开发者接受到该状态类型时，可在应用中通知用户先绑定SuperID.
     */
    SIDUserNoAuthToSuperID,
    /**
     *  当应用用户长时间不操作应用时，授权将过期失效，更新用户账户信息或者Uid会失败。
     *  开发者接受到该状态类型时，可在应用中提醒用户重新使用SuperID登录。
     */
    SIDUserAccessExpired,
};


/**
 *  查询当前用户Uid的授权状态类型
 */
typedef NS_ENUM(NSInteger, SIDUserAuthorizationState){
    /**
     *  用户Uid与SuperID已授权关联
     */
    SIDUserHasAuth,
    /**
     *  用户Uid与SuperID未授权关联
     */
    SIDUserNoAuth,
    /**
     *  查询失败，一般情况下不会发生
     */
    SIDQueryUserAuthorizationFail,
};



/**
 *  用户人脸验证回调状态
 */
typedef NS_ENUM(NSInteger, SIDFACEVerifyState) {
    /**
     *  人脸验证成功
     */
    SIDFaceVerifySucceed,
    /**
     *  人脸验证失败
     */
    SIDFaceVerifyFail,
};


#pragma mark - SuperIDDelegate
#import <Foundation/Foundation.h>

@class SuperID;

@protocol SuperIDDelegate<NSObject>

@optional


/**
 *  应用用户使用SuperID登录应用操作完成调用的协议方法，开发者可通过继承该协议方法获取用户信息。
 *
 *  @param userInfo 当前一登用户的账户信息
 *  @param openId   针对当前应用中，用户的openId
 *  @param error    登录成功为nil，登录失败不为nil。开发者可根据该错误信息描述进行对应处理，详见开发者文档和Demo
 */
- (void)superID:(SuperID *)sender userDidFinishLoginWithUserInfo:(NSDictionary *)userInfo withOpenId:(NSString *)openId error:(NSError *)error;




/**
 *  应用用户取消当前应用账号与一登账号的授权关联成功协议方法
 *
 *  @param error  解除授权成功为nil，解除授权失败不为nil。
 */
- (void)superID:(SuperID *)sender userDidFinishCancelAuthorization:(NSError *)error;



/**
 *  用户在授权状态下使用一登人脸信息获取成功的协议方法
 *
 *  @param featureInfo 用户的人脸信息内容
 *  @param error       获取成功为nil， 获取不成功不为nil。错误信息通知，开发者可根据错误描述判断错误情况。详见Demo或开发者文档
 */
- (void)superID:(SuperID *)sender userDidFinishGetFaceFeatureWithFeatureInfo:(NSDictionary *) featureInfo error:(NSError *)error;



/**
 *  查询用户与一登账号授权关联状态的协议方法
 *
 *  @param state  SIDUserAuthorizationState的类型参数，用于状态进行定位
 */
- (void)superID:(SuperID *)sender queryCurrentUserAuthorizationStateResponse:(SIDUserAuthorizationState)state;



/**
 *  用户验证结果回调
 *
 *  @param state  SIDFACEVerifyState类型参数，用于成功或失败的判断
 */
- (void)superID:(SuperID *)sender faceVerifyResponse:(SIDFACEVerifyState)state;






//已弃用接口


/**
 *  应用用户使用SuperID登录应用操作完成调用的协议方法，开发者可通过继承该协议方法获取用户信息。
 */
- (void)superID:(SuperID *)sender userDidFinishLoginWithUserInfo:(NSDictionary *)userInfo withAppUid:(NSString *)uid error:(NSError *)error NS_DEPRECATED_IOS(2_0, 6_0, "Please use:- (void)superID: userDidFinishLoginWithUserInfo: withOpenId: error:");



@end
