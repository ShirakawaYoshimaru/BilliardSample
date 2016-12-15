//
//  RigidBody.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <stdio.h>
#include "IRigidBody.hpp"
#include "PrimitiveType.hpp"
class GameObject;
class Transform;
class RigidBody : public IRigidBody {
public:
    RigidBody(GameObject* transform);
    Vec3 velocity;
    float airResistance;
    void SetAirResistance(float value);
    void Update();
    void AddVelocity(Vec3 power);
    void SetVelocity(Vec3 velocity);
    float GetRefRate();
    float GetWight();
    PrimitiveType GetColliderType();
    GameObject* gameObject;
    Transform* transform;

private:
    PrimitiveType primitiveType;
};

#endif /* RigidBody_hpp */
