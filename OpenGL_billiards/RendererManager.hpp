//
//  RendererManager.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef RendererManager_hpp
#define RendererManager_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include "GameObjectRenderer.hpp"
#include "CameraRenderer.hpp"
#include <vector>
using namespace std;

class RendererManager : public Singleton<RendererManager>
{
public:
    friend class Singleton<RendererManager>;

public:
    void RegisterRenderTarget(GameObjectRenderer* renderer);
    void RegisterRenderCamera(CameraRenderer* camera);
    void Update();
    void Reshape(int width,int height);
protected:
    RendererManager();
    virtual ~RendererManager();
    vector<GameObjectRenderer*> rendererTargets;
    CameraRenderer* camera;
};
#endif /* RendererManager_hpp */
