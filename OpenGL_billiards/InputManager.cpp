//
//  InputManager.cpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/15.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#include "InputManager.hpp"
#include <iostream>

    //ユーザーインプットを管理するクラス

void InputManager::Input(unsigned char key) {
    for (auto callback: InputManager::OnKeyInputCallbacks) {
        callback(key);
    }
}

void InputManager::RegisterKeyInputCallback(OnKeyInputCallback callback){
    InputManager::OnKeyInputCallbacks.push_back(callback);
}
