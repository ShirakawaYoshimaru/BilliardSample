//
//  PhysicsManager.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include "GameObject.hpp"
#include <vector>
using namespace std;

class PhysicsManager : public Singleton<PhysicsManager>
{
public:
    friend class Singleton<PhysicsManager>;
public:
    void RegisterPhysicsTarget(RigidBody* rigidBody);
    void Update();
protected:
    PhysicsManager();
    virtual ~PhysicsManager();
    vector<RigidBody*> physicsTargets;
private:
    bool IsSphereToShereHit(RigidBody* ownBody,RigidBody* otherBody);
    void ReflectSphereToSphere(RigidBody* ownBody,RigidBody* otherBody);
    bool IsSphereToCube(RigidBody* ownBody,RigidBody* otherBody);
    void ReflectSphereToCube(RigidBody* ownBody,RigidBody* otherBody);
};

#endif /* PhysicsManager_hpp */
