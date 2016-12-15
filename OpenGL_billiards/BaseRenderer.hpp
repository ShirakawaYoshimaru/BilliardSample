#ifndef BaseRenderer_hpp
#define BaseRenderer_hpp

#include <stdio.h>
#include "IRenderer.hpp"
#include "Transform.hpp"

class BaseRenderer : public IRenderer{
    public:
    BaseRenderer(Transform* transform);
    virtual void Render();
    Transform* transform;
};
#endif /* BaseRenderer_hpp */
