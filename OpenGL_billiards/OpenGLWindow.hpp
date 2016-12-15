//
//  OpenGLWindow.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef OpenGLWindow_hpp
#define OpenGLWindow_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
#include "Window.hpp"
#include "RendererManager.hpp"
#include "PhysicsManager.hpp"
#include "InputManager.hpp"
#include "Application.hpp"

class OpenGLWindow : public Window {
public:
    OpenGLWindow(int argc, char *argv[]);
    void Init(int argc, char *argv[]);
    void Launch();
private:
    static void Display();
    static void Reshape(int width,int height);
    static void Timer(int millisecond);
    static void Idle();
    static void InputKeyboard(unsigned char key, int x, int y);

};
#endif /* OpenGLWindow_hpp */
