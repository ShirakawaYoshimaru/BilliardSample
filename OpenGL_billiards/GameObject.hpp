//
//  GameObject.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Transform.hpp"
#include "SphereRenderer.hpp"
#include "GroundRenderer.hpp"
#include "CubeRenderer.hpp"
#include "PrimitiveType.hpp"
#include "RigidBody.hpp"
class GameObject {
public:
    GameObject(const PrimitiveType primitiveType);
    GameObject(const PrimitiveType primitiveType,Transform* transform);
    Transform* transform;
    PrimitiveType primitiveType;
    IRigidBody* rigidBody;
    Sphere* sphere;
    AABB* cube;
private:
    void Init();
    IRenderer* renderer;
};

#endif /* GameObject_hpp */
