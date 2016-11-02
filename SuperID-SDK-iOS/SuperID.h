//
//  SuperID.h
//  包含SDK接口和对象数据定义
//
//  Created by XU JUNJIE on 24/12/14.
//  Copyright (c) 2015年 ISNC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SuperIDDelegate.h"
#import "SIDAppUserInfoModel.h"


#define SIDCURRENTUSERINFODATA @"SIDCurrentUserInfoData"


@interface SuperID : NSObject



/**
 *  获取 SuperID 单例对象
 *
 *  @return SuperID 单例对象
 */
+ (SuperID *)sharedInstance;


/**
 *  SuperID 设置单例委托对象
 *
 */
+ (void)setupSuperIDDelegate:(id<SuperIDDelegate>)delegate;




/**
 *  设置SDK主题颜色
 *
 *  @param color UIColor对象
 */
+ (void)setThemeColor:(UIColor *)color;



/**
 *  移除SDK主题颜色，恢复SDK默认主题颜色
 *
 */
+ (void)removeThemeColor;



/**
 *  SuperID的注册方法，向SDK注册第三方应用。
 *  需要在每次启动第三方应用程序时调用。
 *  @param appID     开发者创建应用的应用ID
 *  @param appSecret 开发者创建应用的应用Secret
 *
 */
+ (void)registerAppWithAppID:(NSString *)appID withAppSecret:(NSString *)appSecret;




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
    SuperID的实例方法，获取一登登录VC。开发者使用present/show方法调用Super的登录界面
 *  用户登录操作结果可通过实现SuperID的协议方法获取。

 *   @param userInfoModel 当前用户的应用账号信息，传入后可加快授权绑定过程。具体用法参考开发文档。如无，可置为nil。
 *   @param error         主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *   @return SuperID登录VC的实例
 */
+ (UINavigationController *)obtainLoginViewControllerWithAppUserInfoModel:(SIDAppUserInfoModel *)userInfoModel error:(NSError **)error;




/**
 *  SuperID的实例方法，获取一登人脸验证VC。开发者使用present/show方法调用Super的登录界面，常用于1比1的人脸验证、人脸签到场景
 *
 *  @param count 用户可尝试重复刷脸验证次数，传入nil值为默认值1次 error 主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *  @return 一登人脸验证VC的实例
 */
+ (UINavigationController *)obtainFaceVerifyViewControllerWithRetryCount:(NSNumber *)count error:(NSError **)error;




/**
 *  SuperID的实例方法，获取乐视专用一登登录VC。开发者使用present/show方法调用Super的登录界面
 *  用户登录操作结果可通过实现SuperID的协议方法获取。
 *  @param error       主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *  @return SuperID登录VC的实例
 */
+ (UINavigationController *)obtainLELoginViewControllerWithError:(NSError **)error;



/**
 *  SuperID的实例方法，查询当前用户Uid的授权状态
 *  查询结果可通过实现SuperID的协议方法获取。
 *
 *   @param openId 开发者应用中用户的Uid
 */
+ (void)queryCurrentUserAuthorizationStateWithOpenId:(NSString *)openId;




/**
 *  SuperID的实例方法,获取一登人脸信息VC,开发者使用present/show方法调用Super的授权界面
 *  用户人脸信息结果可通过实现SuperID的协议方法获取。
 *  @param error 主调用方传入NSError的指针的指针，来获取错误信息。开发者可根据错误描述判断错误情况。
 *
 *  @return 一登人脸信息VC的实例
 */
+ (UINavigationController *)obtainFaceFeatureViewControllerWithError:(NSError **)error;




/**
 *  用户取消当前应用账号与一登账号的授权接口
 */
+ (void)userCancelAuthorization;



/**
 *  开发者应用退出登录时，调用该接口，用户清除SuperID账号的Token信息。
 */
+ (void)appUserLogoutCurrentAccount;




/**
 *  基于三方有效sso Token 创建一登账号
 *
 *  @param ssoToken 三方tk
 */
+ (void)SIDCreatUserWithLESSOToken:(NSString *)ssoToken;




/**
 *  获取未注册一登用户的待验证手机号信息
 *
 *  @return 手机号信息：包括地区号和手机号
 */
+ (NSDictionary *)getPreSignUpUserPhoneInfo;




/**
 *  获取一登用户的用户画像
 *
 *  @return 字典：一登用户画像
 */
+ (NSDictionary *)getSIDUserInfoData;





/**
 *  当用户的应用账户信息发生变更时，可调用该接口将新的用户账户信息更新到一登账号。详细使用参考开发者文档。
 *
 *  @param userInfo 当前用户的应用账户信息字典。
 */
+ (void)updateAppUserInfo:(NSDictionary *)userInfo;




/**
 *  判断当前用户与一登账号的授权情况。仅用于SDK的Demo
 *  开发者应调用接口：+ (void)queryCurrentUserAuthorizationStateWithUid:(NSString *)uid;
 *  @return 授权返回YES, 未授权返回NO.
 */
+ (BOOL)isAppAuth;





/**
 *  当应用启动处于无网络状态下启动时，重新连接网络时可调用改接口重新初始化SuperID的SDK。
 */
+ (void)retryInitialSuperIDSDK;




/**
 *  当开发者应用兼容多方向适配时，如果开发者当前 VC 继承了
 *  - (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator
 *  该委托方法，需要在该方法中添加如下接口调用，已将屏幕旋转事件传递给 SuperID 的 UI 界面作为界面变换判断
 *
 *  @param size                 委托方法回调的size
 *  @param coordinator          委托方法回到的coodinator
 *  @param sourceViewController 当前 VC 指针，一直传入 self
 */
+ (void)SIDViewControllerWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator fromSourceViewController:(UIViewController *)sourceViewController;




/**
 *  用户的行为数据上传接口，针对部分开发者使用，正常情况不调用。
 *
 *  @param aTag       行为事件的类型：如“ListenMusic”
 *  @param attributes 该事件的属性字典：如歌曲名称、歌手信息等。
 *  @param actions    该事件的用户操作字典：如：收藏、分享、删除等操作记录。
 */
+ (void)uploadUserBehaviourEventDataWithActionTag:(NSString *)aTag attributes:(NSDictionary *)attributes actions:(NSDictionary *)actions;

@end
