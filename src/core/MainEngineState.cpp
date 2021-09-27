//
//  MainEngineState.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/27/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include "MainEngineState.hpp"
#include "MainRenderer.hpp"

void MainEngineState::onEnter(Engine* e)
{
    // TODO
}

void MainEngineState::onExit(Engine* e)
{
    // TODO
}

void MainEngineState::onUpdate(Engine* e)
{
    // TODO
}

// fixme
MainEngineState::MainEngineState() : EngineState("data/json/assets_main.json", "data/json/renderer_main.json", MainRenderer::render)
{
    // Empty
}
