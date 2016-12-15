//
//  Singleton.hpp
//  OpenGL_billiards
//
//  Created by ShirakawaYoshimaru on 2016/12/14.
//  Copyright © 2016年 ShirakawaYoshimaru. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>
template<class T>
class Singleton
{
public:
    static inline T& GetInstance()
    {
        static T instance;
        return instance;
    }

protected:
    Singleton() {}
    virtual ~Singleton() {}

private:
    void operator=(const Singleton& obj) {}
    Singleton(const Singleton &obj) {}
};
#endif /* Singleton_hpp */
