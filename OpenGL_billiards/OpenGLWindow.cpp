//
//  OpenGLWindow.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "OpenGLWindow.hpp"
#include <iostream>
using namespace std;

static float fps;

    //OpenGL/GLUTを使ったWindow描画を行うクラス

OpenGLWindow::OpenGLWindow(int argc, char *argv[]) : Window(argc,argv){
    fps = 1;
    Init(argc,argv);
}

void OpenGLWindow::Init(int argc, char *argv[]) {
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("ビリヤード");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0,Timer,1.0/fps);
    glutIdleFunc(Idle);
    glutKeyboardFunc(InputKeyboard);
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1);
}

void OpenGLWindow::Launch() {
    glutMainLoop();
}

void OpenGLWindow::Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    RendererManager::GetInstance().Update();
    glFlush();
}

void OpenGLWindow::Reshape(int width,int height){
    RendererManager::GetInstance().Reshape(width, height);
}

void OpenGLWindow::Timer(int millisecond) {
    PhysicsManager::GetInstance().Update();
    glutTimerFunc(0,Timer,1.0/fps);
}

void OpenGLWindow::Idle() {
    glutPostRedisplay();
}

void OpenGLWindow::InputKeyboard(unsigned char key, int x, int y) {
    InputManager::GetInstance().Input(key);
}
