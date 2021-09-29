//
//  NSEngine.mm
//  GowEngineMount
//
//  Created by Stephen Gowen on 4/23/20.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#import "NSEngine.hpp"

#include "MainEngineState.hpp"

@implementation NSEngine
{
@private
    EngineConfig* _config;
    Engine* _engine;
}

- (NSEngine*)init
{
    _config = new EngineConfig("data/json/config.json");
    _engine = new Engine(*_config, MainEngineState::getInstance());
    return self;
}

- (void)dealloc
{
    delete _engine;
    delete _config;
}

- (void)createDeviceDependentResources
{
    // TODO, implement ClipboardHandler
    // see https://developer.apple.com/documentation/uikit/uipasteboard
    _engine->createDeviceDependentResources();
}

- (void)onWindowSizeChanged:(int)screenWidth :(int)screenHeight :(int)cursorWidth :(int)cursorHeight
{
    _engine->onWindowSizeChanged(screenWidth, screenHeight, cursorWidth, cursorHeight);
}

- (void)destroyDeviceDependentResources
{
    _engine->destroyDeviceDependentResources();
}

- (void)onResume
{
    _engine->onResume();
}

- (void)onPause
{
    _engine->onPause();
}

- (int)update:(double)deltaTime
{
    return _engine->update(deltaTime);
}

- (void)render
{
    _engine->render();
}

- (void)onCursorDown:(float)x :(float)y
{
    _engine->onCursorDown(x, y);
}

- (void)onCursorDragged:(float)x :(float)y
{
    _engine->onCursorDragged(x, y);
}

- (void)onCursorUp:(float)x :(float)y
{
    _engine->onCursorUp(x, y);
}

@end
