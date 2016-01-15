//
//  SIDCameraPreviewView.h
//  NewCameraModule
//
//  Created by XU JUNJIE on 5/1/2016.
//  Copyright © 2016 ISNC. All rights reserved.
//

@import UIKit;

@class AVCaptureSession;

@interface SIDCameraPreviewView : UIView

@property (nonatomic) AVCaptureSession *session;

@end
