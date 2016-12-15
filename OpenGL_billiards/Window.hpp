//
//  Window.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>

class Window {
public:
    virtual ~Window();
    virtual void Launch() = 0;
protected:
    Window(int argc,char *argv[]);
};

#endif /* Window_hpp */
