//
//  MainRenderer.hpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/27/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#pragma once

#include <GowEngine/GowEngine.hpp>

class MainRenderer
{
public:
    static void render(Renderer& r);
    
private:
    MainRenderer() {}
    ~MainRenderer() {}
    MainRenderer(const MainRenderer&);
    MainRenderer& operator=(const MainRenderer&);
};
