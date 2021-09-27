//
//  GlfwMain.hpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 11/16/17.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include <GowEngine/BuildMacros.hpp>
#if IS_DESKTOP

#include <GowEngine/GowEngine.hpp>

class EngineController;

class GlfwMain
{
public:
    static void exec(EngineController& engineController, const char* windowTitle);

private:
    GlfwMain();
    ~GlfwMain();
    GlfwMain(const GlfwMain&);
    GlfwMain& operator=(const GlfwMain&);
};

#endif /* IS_DESKTOP */
