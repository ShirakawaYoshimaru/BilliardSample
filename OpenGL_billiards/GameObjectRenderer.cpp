//
//  GameObjectRenderer.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "GameObjectRenderer.hpp"
#include "RendererManager.hpp"

GameObjectRenderer::GameObjectRenderer(Transform* transform) : BaseRenderer(transform) {
    RendererManager::GetInstance().RegisterRenderTarget(this);
}

void GameObjectRenderer::Render() {

}
