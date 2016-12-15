#include "BaseRenderer.hpp"
#include <iostream>
using namespace std;

BaseRenderer::BaseRenderer(Transform* transform) {
    this->transform = transform;
}

void BaseRenderer::Render(){
}
