//
//  GroundRenderer.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef GroundRenderer_hpp
#define GroundRenderer_hpp

#include <stdio.h>
#include "GameObjectRenderer.hpp"
class GroundRenderer : public GameObjectRenderer{
public:
    GroundRenderer(Transform* transform);
    void Render();
};

#endif /* GroundRenderer_hpp */
