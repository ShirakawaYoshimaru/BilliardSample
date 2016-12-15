//
//  GroundRenderer.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "GroundRenderer.hpp"
GroundRenderer::GroundRenderer(Transform* transform) : GameObjectRenderer(transform) {
}


void GroundRenderer::Render(){
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    double ground_max_x = 300.0;
    double ground_max_y = 300.0;
    glColor3d(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    for(double ly = -ground_max_y ;ly <= ground_max_y; ly+=5.0){
        glVertex3d(-ground_max_x,0,ly);
        glVertex3d(ground_max_x,0,ly);
    }
    for(double lx = -ground_max_x ;lx <= ground_max_x; lx+=5.0){
        glVertex3d(lx, 0,ground_max_y);
        glVertex3d(lx,0,-ground_max_y);
    }
    glEnd();

    glPopMatrix();
}
