//
//  GameObject.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "GameObject.hpp"
#include <iostream>
using namespace std;

    //GameObjectクラス。UnityのGameObjectを真似てみた

GameObject::GameObject(PrimitiveType primitiveType) {
    this->primitiveType = primitiveType;
    this->transform = new Transform();
    Init();
}
GameObject::GameObject(PrimitiveType primitiveType,Transform* transform) {
    this->transform = transform;
    Init();
}

void GameObject::Init() {
    switch (primitiveType) {
        case SphereType: {
            sphere = new Sphere();
            sphere->r = 1;
            sphere->color = Color(1,0,0,1);
            this->renderer = new SphereRenderer(sphere,transform);
            this->rigidBody = new RigidBody(this);
        }

            break;
        case CubeType: {
            cube = new AABB();
            cube->color = Color(0,0,1,1);
            this->renderer = new CubeRenderer(cube,transform);
            this->rigidBody = new RigidBody(this);
        }

            break;
        case GroundType: {
               this->renderer = new GroundRenderer(transform);
        }
            break;
    }


}
