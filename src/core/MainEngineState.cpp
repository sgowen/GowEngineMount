//
//  MainEngineState.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/27/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include "MainEngineState.hpp"

void MainEngineState::onEnter(Engine* e)
{
    // Empty
}

void MainEngineState::onExit(Engine* e)
{
    // Empty
}

void MainEngineState::onUpdate(Engine* e)
{
    // Empty
}

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
