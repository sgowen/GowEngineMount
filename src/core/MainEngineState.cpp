//
//  main.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 9/29/21.
//  Copyright © 2020 Stephen Gowen. All rights reserved.
//

#include "MainEngineState.hpp"

void MainEngineState::onRender(Renderer& r)
{
    r.bindFramebuffer();
    r.clearFramebuffer(Color::BLACK);
    r.renderTextViews();
    r.renderToScreen();
}

MainEngineState::MainEngineState() : EngineState("data/json/MainEngineState_Config.json")
{
    // Empty
}

#if IS_DESKTOP
int main(void)
{
    EngineConfig config("data/json/Engine_Config.json");
    GlfwMain::exec(config, MainEngineState::getInstance());

    return 0;
}
#endif /* IS_DESKTOP */
