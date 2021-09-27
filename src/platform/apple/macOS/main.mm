//
//  main.mm
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/18/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include <GowEngine/AppleMacros.hpp>

#include "MainEngineController.hpp"
#include "glfw/GlfwMain.hpp"

int main(void)
{
    APPLE_INIT_BUNDLE_ROOT_FILE_PATH;
    MainEngineController controller(APPLE_BUNDLE_ROOT_FILE_PATH);
    GlfwMain::exec(controller, "GowEngineMount");
    
    return 0;
}
