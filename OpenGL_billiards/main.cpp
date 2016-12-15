#include "main.hpp"
#include <iostream>

    //メイン関数ではApplicationを立ち上げているだけ。以降の処理はBilliardApplicationおよびWindowが担当する

int main(int argc, char *argv[]){
    Window* window = new OpenGLWindow(argc,argv);
    Application* app = new BilliardApplication(window);
    app->Start();
    return 0;
}
