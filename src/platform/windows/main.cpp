//
//  main.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/18/21.
//  Copyright © 2020 Stephen Gowen. All rights reserved.
//

#include "MainEngineController.hpp"

int main(void)
{
    MainEngineController controller;
    GlfwMain::exec(controller, "GowEngineMount");

    return 0;
}
