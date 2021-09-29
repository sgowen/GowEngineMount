//
//  MainEngineState.hpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 9/29/21.
//  Copyright © 2020 Stephen Gowen. All rights reserved.
//

#include <GowEngine/GowEngine.hpp>

class MainEngineState : public EngineState
{
public:
    static MainEngineState& getInstance()
    {
        static MainEngineState ret = MainEngineState();
        return ret;
    }
    
    virtual void onEnter(Engine* e) {}
    virtual void onExit(Engine* e) {}
    virtual void onUpdate(Engine* e) {}
    virtual void onRender(Renderer& r);
    
private:    
    MainEngineState();
    virtual ~MainEngineState() {}
    MainEngineState(const MainEngineState&);
    MainEngineState& operator=(const MainEngineState&);
};
