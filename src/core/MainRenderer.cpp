//
//  MainRenderer.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 1/27/21.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include "MainRenderer.hpp"

void MainRenderer::render(Renderer& r)
{
    r.bindFramebuffer();
    
    r.clearFramebuffer(Color::BLACK);

    r.renderTextViews();
    
    r.renderToScreen();
}
