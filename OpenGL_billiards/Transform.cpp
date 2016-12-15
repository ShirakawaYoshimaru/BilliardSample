//
//  Transform.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "Transform.hpp"

    //UnityのTransformを真似てみた

Transform::Transform() {
    this->position = new Vec3(0,0,0);
    this->rotation = new Vec3(0,0,0);
    this->scale = new Vec3(1,1,1);
}

Transform::Transform(Vec3* position,Vec3* rotation,Vec3* scale) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

void Transform::SetPosition(Vec3 *position) {
    this->position = position;
}

void Transform::SetRotation(Vec3 *rotation) {
    this->rotation = rotation;
}
void Transform::SetScale(Vec3 *scale) {
    this->scale = scale;
}

void Transform::AddPosition(Vec3 value) {
    this->position->x += value.x;
    this->position->y += value.y;
    this->position->z += value.z;
}

void Transform::AddPositionX(float x) {
    this->position->x += x;
}
void Transform::AddPositionY(float y) {
    this->position->y += y;
}
void Transform::AddPositionZ(float z) {
    this->position->z += z;
}

void Transform::AddRotationX(float x) {
    this->rotation->x += x;
}
void Transform::AddRotationY(float y) {
    this->rotation->y += y;
}
void Transform::AddRotationZ(float z) {
    this->rotation->z += z;
}

void Transform::AddScaleX(float x) {
    this->scale->x += x;
}
void Transform::AddScaleY(float y) {
    this->scale->y += y;
}
void Transform::AddScaleZ(float z) {
    this->scale->z += z;
}

