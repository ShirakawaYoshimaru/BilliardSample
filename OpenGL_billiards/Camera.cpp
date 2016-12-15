//
//  Camera.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "Camera.hpp"
#include <iostream>
#include <vector>
using namespace std;

    //カメラの設定・描画を行うクラス

Camera::Camera() {
    Vec3* position = new Vec3(0,-100, -70);
    Vec3* rotation = new Vec3(0,0,-10);
    Vec3* scale = new Vec3(1,1,1);
    Camera(new Transform(position,rotation,scale));
}

Camera::Camera(Transform* transform){
    this->transform = transform;
    this->renderer = new CameraRenderer(this->transform);
    Init();
}

void Camera::Init(){
        //ここでInputコールバックを呼ぶとCameraRendererがNULLになるので使わない。よく分からない・・・;;
}


