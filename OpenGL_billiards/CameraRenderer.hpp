//
//  CameraRenderer.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef CameraRenderer_hpp
#define CameraRenderer_hpp

#include <stdio.h>
#include "BaseRenderer.hpp"
#include "Transform.hpp"
class CameraRenderer : public BaseRenderer {
public:
    CameraRenderer(Transform* transform);
    void Render();
    void Reshape(int width,int height);
};
#endif /* CameraRenderer_hpp */
