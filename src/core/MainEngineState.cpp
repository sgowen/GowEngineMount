//
//  main.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 9/29/21.
//  Copyright © 2020 Stephen Gowen. All rights reserved.
//

#include "MainEngineState.hpp"

void MainEngineState::render(Renderer& r)
{
    r.bindFramebuffer();
    r.clearFramebuffer(Color::BLACK);
    r.renderTextViews();
    r.renderToScreen();
}

MainEngineState::MainEngineState() : EngineState("data/json/assets_main.json", "data/json/renderer_main.json", MainEngineState::render)
{
    // Empty
}

#if IS_DESKTOP
int main(void)
{
    EngineConfig config("data/json/config.json");
    GlfwMain::exec(config, MainEngineState::getInstance());

    return 0;
}
#endif /* IS_DESKTOP */
