//
//  CameraRenderer.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "CameraRenderer.hpp"
#include "RendererManager.hpp"
#include "InputManager.hpp"
#include <iostream>
using namespace std;
CameraRenderer::CameraRenderer(Transform* transform) : BaseRenderer(transform){
    RendererManager::GetInstance().RegisterRenderCamera(this);
    InputManager::OnKeyInputCallback moveCamera = [&] (unsigned char key){
        cout << key << endl;
        if(key == 'e'){
                //MoveForward();
            float moveSpeed = 5;
            this->transform->AddRotationX(moveSpeed);
        } else if(key == 'q'){
            float moveSpeed = 5;
            this->transform->AddRotationX(moveSpeed * -1);
        } else if(key == 'w'){
            float moveSpeed = 5;
            this->transform->AddPositionZ(moveSpeed * -1);
        } else if(key == 'a'){
            float moveSpeed = 5;
            this->transform->AddPositionX(moveSpeed * -1);
        } else if(key == 's'){
            float moveSpeed = 5;
            this->transform->AddPositionZ(moveSpeed);
        } else if(key == 'd'){
            float moveSpeed = 5;
            this->transform->AddPositionX(moveSpeed);
        }

    };

    InputManager::GetInstance().RegisterKeyInputCallback(moveCamera);

}
void CameraRenderer::Render() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
        gluPerspective(30.0, (double)500/500, 1.0, 1000.0);
        gluLookAt(this->transform->position->x, this->transform->position->y, this->transform->position->z,
            this->transform->rotation->x, this->transform->rotation->y, this->transform->rotation->z, 0, 0, 1);

}

void CameraRenderer::Reshape(int width, int height){
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION); //投影変換モードへ
    glLoadIdentity(); //投影変換の変換行列を単位行列で初期化
    gluPerspective(30.0, (double)width/height, 1.0, 100.0);
    gluLookAt(this->transform->position->x, this->transform->position->y, this->transform->position->z,
              this->transform->rotation->x, this->transform->rotation->y, this->transform->rotation->z, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
