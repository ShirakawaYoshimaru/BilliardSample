//
//  GameObjectRenderer.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef GameObjectRenderer_hpp
#define GameObjectRenderer_hpp

#include <stdio.h>
#include "BaseRenderer.hpp"
class GameObjectRenderer : public BaseRenderer {
public:
    GameObjectRenderer(Transform* transform);
    void Render();
};
#endif /* GameObjectRenderer_hpp */
