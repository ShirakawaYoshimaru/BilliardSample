//
//  RendererManager.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "RendererManager.hpp"


RendererManager::RendererManager() {

}
RendererManager::~RendererManager() {

}

void RendererManager::RegisterRenderTarget(GameObjectRenderer* renderer){
    rendererTargets.push_back(renderer);
}

void RendererManager::RegisterRenderCamera(CameraRenderer *camera) {
    this->camera = camera;
}

void RendererManager::Update(){
    camera->Render();

    for (auto rendererTarget: rendererTargets) {
        rendererTarget->Render();
    }
}


void RendererManager::Reshape(int width,int height) {
    this->camera->Reshape(width, height);
}
