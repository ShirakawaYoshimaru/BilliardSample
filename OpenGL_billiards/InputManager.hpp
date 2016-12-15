//
//  InputManager.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <stdio.h>
#include "Singleton.hpp"
#include <vector>
#include <functional>
using namespace std;

class InputManager : public Singleton<InputManager> {
public:
    friend class Singleton<InputManager>;
    void Input(unsigned char key);
    typedef function<void(unsigned char key)> OnKeyInputCallback;
    void RegisterKeyInputCallback(OnKeyInputCallback callback);
    vector<OnKeyInputCallback> OnKeyInputCallbacks;
};
#endif /* InputManager_hpp */
