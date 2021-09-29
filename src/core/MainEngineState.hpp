//
//  MainEngineState.hpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/27/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#pragma once

#include <GowEngine/GowEngine.hpp>

#define ENGINE_STATE_MAIN MainEngineState::getInstance()

class MainEngineState : public EngineState
{
public:
    static MainEngineState& getInstance()
    {
        static MainEngineState ret = MainEngineState();
        return ret;
    }
    
    virtual void onEnter(Engine* e);
    virtual void onExit(Engine* e);
    virtual void onUpdate(Engine* e);
    
private:
    static void render(Renderer& r);
    
    MainEngineState();
    virtual ~MainEngineState() {}
    MainEngineState(const MainEngineState&);
    MainEngineState& operator=(const MainEngineState&);
};
