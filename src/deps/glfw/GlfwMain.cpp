//
//  GlfwMain.cpp
//  GowEngineMount
//
//  Created by Stephen Gowen on 11/16/17.
//  Copyright © 2021 Stephen Gowen. All rights reserved.
//

#include "GlfwMain.hpp"

#if IS_DESKTOP

#if IS_LINUX
    #include <GL/glew.h>
#elif IS_WINDOWS
    #define GLAD_GL_IMPLEMENTATION
    #include <glad/gl.h>
#endif

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

Engine* _engine = nullptr;
int joysticks[GLFW_JOYSTICK_LAST + 1];
int joystick_count = 0;
bool isDown = false;
bool isAlt = false;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
    int screenWidth = 0;
    int screenHeight = 0;
    glfwGetWindowSize(window, &screenWidth, &screenHeight);
    
    _engine->onWindowSizeChanged(w, h, screenWidth, screenHeight);
}

void window_iconify_callback(GLFWwindow* window, int iconified)
{
    if (iconified)
    {
        _engine->onPause();
    }
    else
    {
        _engine->onResume();
    }
}

void joystick_callback(int jid, int event)
{
    if (event == GLFW_CONNECTED)
    {
        joysticks[joystick_count++] = jid;
    }
    else if (event == GLFW_DISCONNECTED)
    {
        int i;

        for (i = 0; i < joystick_count; ++i)
        {
            if (joysticks[i] == jid)
            {
                break;
            }
        }

        for (i = i + 1; i < joystick_count; ++i)
        {
            joysticks[i - 1] = joysticks[i];
        }

        joystick_count--;
    }
}

void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    _engine->onCursorScrolled((float)yoffset);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    double x;
    double y;
    glfwGetCursorPos(window, &x, &y);
    
    isAlt = button == GLFW_MOUSE_BUTTON_2;
    
    switch (action)
    {
        case GLFW_PRESS:
            _engine->onCursorDown((float)x, (float)y, isAlt);
            isDown = true;
            break;
        case GLFW_RELEASE:
            _engine->onCursorUp((float)x, (float)y, isAlt);
            isDown = false;
            break;
        default:
            break;
    }
}

void mouse_cursor_pos_callback(GLFWwindow* window, double x, double y)
{
    if (isDown)
    {
        _engine->onCursorDragged((float)x, (float)y, isAlt);
    }
    else
    {
        _engine->onCursorMoved((float)x, (float)y);
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    _engine->onKeyboardInput(key, action == GLFW_RELEASE);
}

void GlfwMain::exec(EngineController& engineController, const char* windowTitle)
{
    memset(joysticks, 0, sizeof(joysticks));

    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWmonitor* monitor = nullptr;

    int width = 800;
    int height = 480;

#if IS_RELEASE
    monitor = glfwGetPrimaryMonitor();
    if (monitor)
    {
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);

        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        width = mode->width;
        height = mode->height;
    }
#endif

    window = glfwCreateWindow(width, height, windowTitle, monitor, nullptr);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    for (int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid)
    {
        if (glfwJoystickPresent(jid))
        {
            joysticks[joystick_count++] = jid;
        }
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowIconifyCallback(window, window_iconify_callback);
    glfwSetJoystickCallback(joystick_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, mouse_cursor_pos_callback);
    glfwSetScrollCallback(window, mouse_scroll_callback);
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
#if IS_WINDOWS
    gladLoadGL(glfwGetProcAddress);
#elif IS_LINUX
    glewInit();
#endif
    
    glfwSwapInterval(1);
    
    _engine = new Engine(engineController);
    _engine->createDeviceDependentResources(window);
    
    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);
    
    glfwSetTime(0.0);

    double lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        double deltaTime = glfwGetTime() - lastTime;
        lastTime = glfwGetTime();
        
        glfwPollEvents();

        for (int i = 0; i < joystick_count; ++i)
        {
            int j, axis_count, button_count;
            const float* axes;
            const uint8_t* buttons;

            axes = glfwGetJoystickAxes(joysticks[i], &axis_count);
            buttons = glfwGetJoystickButtons(joysticks[i], &button_count);

            float stickLeftX = 0;
            float stickLeftY = 0;
            float stickRightX = 0;
            float stickRightY = 0;
            float triggerLeft = 0;
            float triggerRight = 0;

            for (j = 0; j < axis_count; ++j)
            {
                switch (j)
                {
                    case 0:
                        stickLeftX = axes[j];
                        break;
                    case 1:
                        stickLeftY = axes[j];
                        break;
                    case 2:
                        stickRightX = axes[j];
                        break;
                    case 3:
                        triggerLeft = axes[j];
                        break;
                    case 4:
                        triggerRight = axes[j];
                        break;
                    case 5:
                        stickRightY = axes[j];
                    default:
                        break;
                }
            }

            _engine->onGamepadInputStickLeft(i, stickLeftX, stickLeftY);
            _engine->onGamepadInputStickRight(i, stickRightX, stickRightY);
            _engine->onGamepadInputTrigger(i, triggerLeft, triggerRight);

            for (j = 0; j < button_count; ++j)
            {
                _engine->onGamepadInputButton(i, j, buttons[j]);
            }
        }

        EngineRequestedHostAction requestedAction = _engine->update(deltaTime);
        switch (requestedAction)
        {
            case ERHA_EXIT:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
            case ERHA_DEFAULT:
            default:
                break;
        }

        _engine->render();

        glfwSwapBuffers(window);
    }

    _engine->destroyDeviceDependentResources();
    
    delete _engine;
    _engine = nullptr;

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

#endif /* IS_DESKTOP */
