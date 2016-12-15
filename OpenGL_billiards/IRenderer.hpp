//
//  IRenderer.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef IRenderer_hpp
#define IRenderer_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
class IRenderer {
public:
    virtual void Render() = 0;
};

#endif /* IRenderer_hpp */
