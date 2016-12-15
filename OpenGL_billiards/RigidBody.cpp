//
//  RigidBody.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "RigidBody.hpp"
#include "PhysicsManager.hpp"
#include "GameObject.hpp"

    //実際に物理演算をするクラス

RigidBody::RigidBody(GameObject* gameObject) {
    this->gameObject = gameObject;
    this->transform = this->gameObject->transform;
    this->primitiveType = this->gameObject->primitiveType;
    this->velocity = Vec3(0, 0, 0);
    this->airResistance = 0.98;
    PhysicsManager::GetInstance().RegisterPhysicsTarget(this);
}

void RigidBody::Update() {
    this->transform->AddPosition(this->velocity);

    //空気抵抗によって加速度現象
    this->velocity.x *= airResistance;
    this->velocity.y *= airResistance;
    this->velocity.z *= airResistance;

    if(this->velocity.length() < 0.05){
        this->velocity = Vec3(0, 0, 0);
    }
}

void RigidBody::AddVelocity(Vec3 power) {
    this->velocity.x += power.x;
    this->velocity.y += power.y;
    this->velocity.z += power.z;
}

void RigidBody::SetVelocity(Vec3 velocity) {
    this->velocity = velocity;
}

PrimitiveType RigidBody::GetColliderType() {
    return this->primitiveType;
}

float RigidBody::GetRefRate() {
    return 0.5;
}

float RigidBody::GetWight() {
    return 1;
}

void RigidBody::SetAirResistance(float value) {
    this->airResistance = value;
}
