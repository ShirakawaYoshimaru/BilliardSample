//
//  Transform.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "primitive.hpp"
class Transform {
public:
    Transform();
    Transform(Vec3* position,Vec3* rotation,Vec3* scale);
    Vec3* position;
    Vec3* rotation;
    Vec3* scale;
    void SetPosition(Vec3* position);
    void SetScale(Vec3* scale);
    void SetRotation(Vec3* rotation);
    void AddPosition(Vec3 value);
    void AddPositionX(float x);
    void AddPositionY(float y);
    void AddPositionZ(float z);

    void AddRotationX(float x);
    void AddRotationY(float y);
    void AddRotationZ(float z);

    void AddScaleX(float x);
    void AddScaleY(float y);
    void AddScaleZ(float z);
};
#endif /* Transform_hpp */
