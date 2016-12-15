//
//  PhysicsManager.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "PhysicsManager.hpp"
#include <cmath>

    //物理演算全体を管理するクラス

PhysicsManager::PhysicsManager() {

}
PhysicsManager::~PhysicsManager() {

}

void PhysicsManager::RegisterPhysicsTarget(RigidBody *rigidBody){
    physicsTargets.push_back(rigidBody);
}

void PhysicsManager::Update(){
    //衝突判定
    for (auto ownBody: physicsTargets) {
        if(ownBody->GetColliderType() == PrimitiveType::CubeType) {
            //Cubeから見た衝突判定はとりあえずスキップ
            continue;
        }

        for (auto otherBody: physicsTargets) {
            if(ownBody == otherBody) {
                //自分自身とはぶつからないのでスキップ
                continue;
            }
            if(ownBody->GetColliderType() == PrimitiveType::SphereType && otherBody->GetColliderType() == PrimitiveType::SphereType) {
                    //SphereとSphereの衝突判定
                if(IsSphereToShereHit(ownBody, otherBody)) {
                    //衝突していたら反発させる
                    ReflectSphereToSphere(ownBody,otherBody);
                }
            } else {
                   //SphereとCubeの衝突判定
                if(IsSphereToCube(ownBody, otherBody)) {
                    ReflectSphereToCube(ownBody, otherBody);
                }

            }
        }
    }

    //加速度による移動
    for (auto physicsTarget: physicsTargets) {
        physicsTarget->Update();
    }
}

bool PhysicsManager::IsSphereToShereHit(RigidBody* ownBody, RigidBody* otherBody) {
    Vec3* ownCenter = ownBody->transform->position;
    float ownR = ownBody->gameObject->sphere->r;
    Vec3* otherCenter = otherBody->transform->position;
    float otherR = ownBody->gameObject->sphere->r;
    bool result = false;
    result = std::pow(otherCenter->x - ownCenter->x,2) + std::pow(otherCenter->y - ownCenter->y,2) + std::pow(otherCenter->z - ownCenter->z,2)
                <= std::pow(ownR+ otherR,2);
    return result;
}

void PhysicsManager::ReflectSphereToSphere(RigidBody* ownBody,RigidBody* otherBody) {
        //反射係数
    float refRate = (otherBody->GetRefRate() + ownBody->GetRefRate()) / 2.0;
        //総重量
    float totalWeight = ownBody->GetWight() + otherBody->GetWight();
        //向きを求める
    Vec3 normalizedDirection = *otherBody->transform->position - *ownBody->transform->position;
    normalizedDirection = normalizedDirection.getNorm();

        //相対加速度を求める
    Vec3 relativeAcceleration = otherBody->velocity - ownBody->velocity;
    float dot = relativeAcceleration.x*normalizedDirection.x + relativeAcceleration.y*normalizedDirection.y + relativeAcceleration.z*normalizedDirection.z;
    relativeAcceleration = (refRate*dot/totalWeight)*normalizedDirection;

        //衝突後の加速度を更新
    otherBody->AddVelocity(-1 * relativeAcceleration);
    ownBody->AddVelocity(1 * relativeAcceleration);

        //中心点からの重なった距離を算出
    float overlapX = ownBody->transform->position->x - otherBody->transform->position->x;
    float overlapZ = ownBody->transform->position->z-otherBody->transform->position->z;
    float overlapDistance = sqrt(std::pow(overlapX,2) + std::pow(overlapZ,2));
        //Sphereの半径を考慮した重なった距離
    float overlapSpherDistance = (ownBody->gameObject->sphere->r + otherBody->gameObject->sphere->r) - overlapDistance;

        //重なった距離だけ均等に反発させる
    ownBody->transform->AddPositionX(overlapX*overlapSpherDistance/2.0);
    otherBody->transform->AddPositionX(-overlapX*overlapSpherDistance/2.0);
    ownBody->transform->AddPositionZ(-overlapZ*overlapSpherDistance/2.0);
    otherBody->transform->AddPositionZ(overlapZ*overlapSpherDistance/2.0);

}


bool PhysicsManager::IsSphereToCube(RigidBody* ownBody,RigidBody* otherBody) {
    if(otherBody->gameObject->cube->wallNumber == 3) {
        //右の壁の場合
        Transform* wallTransform = otherBody->transform;
        float borderWallPosition = wallTransform->position->x - (wallTransform->scale->x / 0.5);
        if(ownBody->transform->position->x >= borderWallPosition) {
            return true;
        }
    } else if(otherBody->gameObject->cube->wallNumber == 2) {
        //左の壁の場合
        Transform* wallTransform = otherBody->transform;
        float borderWallPosition = wallTransform->position->x + (wallTransform->scale->x / 0.5);
        if(ownBody->transform->position->x <= borderWallPosition) {
            return true;
        }
    } else if(otherBody->gameObject->cube->wallNumber == 1) {
        //手前の壁の場合
        Transform* wallTransform = otherBody->transform;
        float borderWallPosition = wallTransform->position->z + (wallTransform->scale->z / 0.5);
        if(ownBody->transform->position->z <= borderWallPosition) {
            return true;
        }
    } else if(otherBody->gameObject->cube->wallNumber == 0) {
            //奥の壁の場合
        Transform* wallTransform = otherBody->transform;
        float borderWallPosition = wallTransform->position->z - (wallTransform->scale->z / 0.5);
        if(ownBody->transform->position->z >= borderWallPosition) {
            return true;
        }
    }


    return false;
}

void PhysicsManager::ReflectSphereToCube(RigidBody* ownBody,RigidBody* otherBody) {
    Vec3 inNormal = Vec3();
    Vec3 inDirection = ownBody->velocity;
    if(otherBody->gameObject->cube->wallNumber == 3) {
            //右の壁の場合
        inNormal = Vec3(-1,0,0);
    } else if(otherBody->gameObject->cube->wallNumber == 2) {
            //左の壁の場合
        inNormal = Vec3(1,0,0);
    } else if(otherBody->gameObject->cube->wallNumber == 1) {
            //手前の壁の場合
        inNormal = Vec3(0,0,1);
    } else if(otherBody->gameObject->cube->wallNumber == 0) {
            //奥の壁の場合
        inNormal = Vec3(0,0,-1);
    }
    Vec3 reflection =  -2.0f * inNormal.dot(inDirection) * inNormal + inDirection;
    ownBody->SetVelocity(reflection);
}
