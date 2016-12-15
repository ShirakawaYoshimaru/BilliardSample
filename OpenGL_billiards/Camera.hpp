//
//  Camera.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Transform.hpp"
#include "CameraRenderer.hpp"
#include "InputManager.hpp"

class Camera{
public:
    Camera();
    Camera(Transform* transform);
    Transform* transform;
    CameraRenderer* renderer;
private:
    void Init();
};

#endif /* Camera_hpp */
