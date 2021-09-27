//
//  NSEngine.hpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 4/23/20.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSEngine : NSObject

- (instancetype)init;

- (void)createDeviceDependentResources;
- (void)onWindowSizeChanged:(int)screenWidth :(int)screenHeight :(int)cursorWidth :(int)cursorHeight;
- (void)destroyDeviceDependentResources;
- (void)onResume;
- (void)onPause;
- (int)update:(double)deltaTime;
- (void)render;
- (void)onCursorDown:(float)x :(float)y;
- (void)onCursorDragged:(float)x :(float)y;
- (void)onCursorUp:(float)x :(float)y;

@end
