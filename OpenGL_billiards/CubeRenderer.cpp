//
//  CubeRenderer.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "CubeRenderer.hpp"
CubeRenderer::CubeRenderer(const AABB* cube,Transform* transform) : GameObjectRenderer(transform) {
    this->cube = cube;
}


void CubeRenderer::Render(){
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(this->cube->color.r,this->cube->color.g,this->cube->color.b);
    glScalef(this->transform->scale->x,this->transform->scale->y,this->transform->scale->z);
    glTranslated(this->transform->position->x,this->transform->position->y,this->transform->position->z);
    glutWireCube(1);
    glPopMatrix();
}
