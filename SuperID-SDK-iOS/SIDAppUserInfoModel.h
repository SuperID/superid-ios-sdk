//
//  SIDAppUserInfoModel.h
//  SuperIDSDK
//
//  Created by XU JUNJIE on 2/7/2016.
//  Copyright © 2016 ISNC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SIDAppUserInfoModel : NSObject

@property (retain, nonatomic) NSString                            *phone;
@property (retain, nonatomic) NSString                            *name;
@property (retain, nonatomic) NSString                            *email;
@property (retain, nonatomic) NSString                            *avatar;
@property (retain, nonatomic) NSString                            *appUid;
@property (retain, nonatomic) NSDictionary                        *otherInfo;

@end
