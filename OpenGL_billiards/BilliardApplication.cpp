//
//  BilliardApplication.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "BilliardApplication.hpp"
#include "SphereRenderer.hpp"
#include <iostream>
using namespace std;

    //ビリヤードアプリを構築するクラス

BilliardApplication::BilliardApplication(Window* window) : Application(){
    this->window = window;
}

void BilliardApplication::Start() {
    cout << "start" << endl;

    GameObject* ground = new GameObject(PrimitiveType::GroundType);
    CreateSphere();
    CreateWall();

    Camera* camera = new Camera();
    
    this->window->Launch();
}

void BilliardApplication::CreateSphere() {
        //9個の球体を並べる
    for (int i=0; i < 9; i++) {
        GameObject* sphere = new GameObject(PrimitiveType::SphereType);
        sphere->transform->AddPositionX(i * 0.5);
    }

        //力を持った球体を１つ用意してぶつける
    GameObject* sphere1 = new GameObject(PrimitiveType::SphereType);
    sphere1->transform->AddPositionX(6);
    sphere1->rigidBody->AddVelocity(Vec3(3,0,3));
        //こいつだけ空気抵抗を限りなく減らす
    sphere1->rigidBody->SetAirResistance(0.9999);
}

void BilliardApplication::CreateWall(){
    GameObject* fowardWall = new GameObject(PrimitiveType::CubeType);
    fowardWall->transform->AddScaleX(100);
    fowardWall->transform->SetPosition(new Vec3(0,0,10));
    fowardWall->cube->wallNumber = 0; //奥の壁

    GameObject* backWall = new GameObject(PrimitiveType::CubeType);
    backWall->transform->AddScaleX(100);
    backWall->transform->SetPosition(new Vec3(0,0,-20));
    backWall->cube->wallNumber = 1; //手前の壁

    GameObject* leftWall = new GameObject(PrimitiveType::CubeType);
    leftWall->transform->AddScaleZ(100);
    leftWall->transform->SetPosition(new Vec3(-20,0,0));
    leftWall->cube->wallNumber = 2; //左の壁

    GameObject* rightWall = new GameObject(PrimitiveType::CubeType);
    rightWall->transform->AddScaleZ(100);
    rightWall->transform->SetPosition(new Vec3(20,0,0));
    rightWall->cube->wallNumber = 3; //右の壁
}
