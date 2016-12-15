//
//  IRigidBody.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef IRigidBody_hpp
#define IRigidBody_hpp

#include <stdio.h>
#include "primitive.hpp"
#include "PrimitiveType.hpp"
class IRigidBody {
public:
        //PhysicsManagerから呼ばれる物理演算処理実行関数
    virtual void Update() = 0;
        //加速度を加える
    virtual void AddVelocity(Vec3 power) = 0;
        //加速度を設定する
    virtual void SetVelocity(Vec3 velocity) = 0;
        //Colliderのタイプを返す
    virtual PrimitiveType GetColliderType() = 0;
        //空気抵抗を加える
    virtual void SetAirResistance(float value) = 0;
};
#endif /* IRigidBody_hpp */
