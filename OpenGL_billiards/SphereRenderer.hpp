//
//  SphereRenderer.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef SphereRenderer_hpp
#define SphereRenderer_hpp

#include <stdio.h>
#include "GameObjectRenderer.hpp"

class SphereRenderer : public GameObjectRenderer{
public:
    SphereRenderer(const Sphere* sphere,Transform* transform);
    void Render();
private:
    const Sphere* sphere;
};

#endif /* SphereRenderer_hpp */
