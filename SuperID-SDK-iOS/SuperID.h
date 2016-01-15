//
//  SuperID.h
//  包含SDK接口和对象数据定义
//
//  Created by XU JUNJIE on 24/12/14.
//  Copyright (c) 2015年 ISNC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SuperIDDelegate.h"



@interface SuperID : NSObject



/** SDK 委托对象 */
@property(weak,nonatomic) id<SuperIDDelegate> delegate;



/**
 *  SuperID 单例生成类方法
 *
 *  @return SuperID单例对象
 */
+ (SuperID *)sharedInstance;



/**
 *  SuperID的实例方法，向SDK注册第三方应用。
 *  需要在每次启动第三方应用程序时调用。
 *  @param appID     开发者创建应用的应用ID
 *  @param appSecret 开发者创建应用的应用Secret
 *
 *  @return SuperID单例对象
 */
- (void)registerAppWithAppID:(NSString *)appID withAppSecret:(NSString *)appSecret;


/**
 *  SuperID的类方法，用于获取当前SDK的版本信息
 */
+ (NSDictionary *)getSDKVersion;
/**
 *  SuperID的类方法，用于设置SDK在开发者应用中的语言模式，分自动模式、英文模式、简体中文模式、繁体中文模式。
 *
 *  @param type 语言类型详见枚举参数SIDLanguageMode解析
 */
+ (void)setLanguageMode:(SIDLanguageMode)type;



/**
 *  SuperID的实例方法，用于设置SDK的调试模式。
 *  建议开发者在Debug模式下开启调试模式，在Release前关闭该模式。
 *  @param flag 当该值为"YES",SDK将打印对应的调试Log用于提示开发者。当该值为“NO”,关闭SDK内部的Log输出。
 */
+ (void)setDebugMode:(BOOL)flag;


/**
 *  SuperID的实例方法，获取一登登录VC。开发者使用present/show方法调用Super的登录界面
 *  用户登录操作结果可通过实现SuperID的协议方法获取。
 *  @param error 主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *  @return SuperID登录VC的实例
 */
- (instancetype)obtainLoginViewControllerWithError:(NSError **)error;


/**
 *  SuperID的实例方法，获取一登人脸验证VC。开发者使用present/show方法调用Super的登录界面，常用于1比1的人脸验证、人脸签到场景
 *
 *  @param count 用户可尝试重复刷脸验证次数，传入nil值为默认值1次 error 主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *  @return 一登人脸验证VC的实例
 */
- (instancetype)obtainFaceVerifyViewControllerWithRetryCount:(NSNumber *)count error:(NSError **)error;


/**
 *  SuperID的实例方法，获取一登登录VC。开发者使用present/show方法调用Super的登录界面
 *  用户登录操作结果可通过实现SuperID的协议方法获取。
 *  @param phoneNumber 当前用户的手机号码，当开发者在用户登录应用时已知用户手机号码情况下调用该接口。
 *  @param error       主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *  @param userInfo    当前用户的应用账号信息，传入后可加快授权绑定过程。具体用法参考开发文档。如无，可置为nil。
 *  @return SuperID登录VC的实例
 */
- (instancetype)obtainLoginViewControllerWithPhoneNumber:(NSString *)phoneNumber appUserInfo:(NSDictionary *)userInfo error:(NSError **)error;


/**
 *  SuperID的实例方法，查询当前用户OpenID的授权状态
 *  查询结果可通过实现SuperID的协议方法获取。
 *  @param openId 开发者应用中用户的openId
 */
- (void)queryCurrentUserAuthorizationStateWithOpenId:(NSString *)openId;




/**
 *  SuperID的实例方法,获取一登人脸信息VC,开发者使用present/show方法调用Super的授权界面
 *  用户人脸信息结果可通过实现SuperID的协议方法获取。
 *  @param error 主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *  @return 一登人脸信息VC的实例
 */
- (instancetype)obtainFaceFeatureViewControllerWithError:(NSError **)error;


/**
 *  用户取消当前应用账号与一登账号的授权接口
 */
- (void)userCancelAuthorization;


/**
 *  开发者应用退出登录时，调用该接口，用户清除SuperID账号的Token信息。
 */
- (void)appUserLogoutCurrentAccount;



/**
 *  当用户的应用账户信息发生变更时，可调用该接口将新的用户账户信息更新到一登账号。详细使用参考开发者文档。
 *
 *  @param userInfo 当前用户的应用账户信息字典。
 */
- (void)updateAppUserInfo:(NSDictionary *)userInfo;


/**
 *  判断当前用户与一登账号的授权情况。仅用于SDK的Demo
 *  开发者应调用接口：- (void)queryCurrentUserAuthorizationStateWithUid:(NSString *)uid;
 *  @return 授权返回YES, 未授权返回NO.
 */
- (BOOL)isAppAuth;


/**
 *  当应用启动处于无网络状态下启动时，重新连接网络时可调用改接口重新初始化SuperID的SDK。
 */
- (void)retryInitialSuperIDSDK;



/**
 *  用户的行为数据上传接口，针对部分开发者使用，正常情况不调用。
 *
 *  @param aTag       行为事件的类型：如“ListenMusic”
 *  @param attributes 该事件的属性字典：如歌曲名称、歌手信息等。
 *  @param actions    该事件的用户操作字典：如：收藏、分享、删除等操作记录。
 */
- (void)uploadUserBehaviourEventDataWithActionTag:(NSString *)aTag attributes:(NSDictionary *)attributes actions:(NSDictionary *)actions;


/**
 *  SuperID的实例方法，查询当前用户Uid的授权状态
 *  查询结果可通过实现SuperID的协议方法获取。
 *  @param uid 开发者应用中用户的Uid
 */
- (void)queryCurrentUserAuthorizationStateWithUid:(NSString *)uid NS_DEPRECATED_IOS(2_0, 6_0, "Please use OpenID Account instead of uid");


/**
 *  SuperID的实例方法，获取一登授权VC.开发者使用present/show方法调用Super的授权界面
 *  用户授权操作结果可通过实现SuperID的协议方法获取。
 *  @param uid         用于与用户SuperID账号授权绑定的用户Uid
 *  @param phoneNumber 当前用户的手机号码，传入后可加快授权绑定过程。如无，可置为nil。
 *  @param userInfo    当前用户的应用账号信息，传入后可加快授权绑定过程。具体用法参考开发文档。如无，可置为nil。
 *  @param error       主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *  @return SuperID授权VC的实例
 */

- (instancetype)obtainAuthViewControllerWithUid:(NSString *)uid phoneNumber:(NSString *)phoneNumber appUserInfo:(NSDictionary *)userInfo error:(NSError **)error NS_DEPRECATED_IOS(2_0, 6_0, "Please use OpenID Account instead of uid");



/**
 *  当用户首次直接使用一登账号登录时，SuperID将返回关联的随机应用id。
 *  开发者获取当前用户的正式账号id后，调用该接口进行id更新。
 *  @param uid 当前用户的应用id。
 */
- (void)updateAppUid:(NSString *)uid NS_DEPRECATED_IOS(2_0, 6_0, "Please use OpenID Account instead of uid");

@end
