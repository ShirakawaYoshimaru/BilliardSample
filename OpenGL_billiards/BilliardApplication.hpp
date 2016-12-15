//
//  BilliardApplication.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef BilliardApplication_hpp
#define BilliardApplication_hpp

#include <stdio.h>
#include "Application.hpp"
#include "Window.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
class BilliardApplication : public Application {
public:
    Window* window;
    BilliardApplication(Window* window);
    void Start();
private:
    void CreateWall();
    void CreateSphere();
};

#endif /* BilliardApplication_hpp */
