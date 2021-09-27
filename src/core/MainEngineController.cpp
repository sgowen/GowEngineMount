//
//  MainEngineController.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/27/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include "MainEngineController.hpp"
#include "MainEngineState.hpp"

MainEngineController::MainEngineController(void* data1, void* data2) : EngineController(data1, data2)
{
    // fixme
    ASSETS.registerAssets("global", AssetsLoader::initWithJSONFile("data/json/assets_global.json"));
}

State<Engine>& MainEngineController::getInitialState()
{
    return ENGINE_STATE_MAIN;
}

double MainEngineController::getFrameRate()
{
    // fixme
    return 1.0 / 60.0;
}
