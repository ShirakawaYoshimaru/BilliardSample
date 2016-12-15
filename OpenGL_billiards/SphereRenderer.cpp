//
//  SphereRenderer.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "SphereRenderer.hpp"
#include <iostream>
using namespace std;

SphereRenderer::SphereRenderer(const Sphere* sphere,Transform* transform) : GameObjectRenderer(transform) {
    this->sphere = sphere;
}


void SphereRenderer::Render(){
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(this->sphere->color.r,this->sphere->color.g,this->sphere->color.b);
    glTranslated(this->transform->position->x,this->transform->position->y,this->transform->position->z);
    glutWireSphere(sphere->r,30,30);
    glPopMatrix();
}
