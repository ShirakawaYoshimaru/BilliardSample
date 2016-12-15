//
//  CubeRenderer.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef CubeRenderer_hpp
#define CubeRenderer_hpp

#include <stdio.h>
#include "GameObjectRenderer.hpp"

class CubeRenderer : public GameObjectRenderer{
public:
    CubeRenderer(const AABB* cube,Transform* transform);
    void Render();
private:
    const AABB* cube;
};


#endif /* CubeRenderer_hpp */
