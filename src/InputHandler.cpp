#include "InputHandler.h"

#include "Engine.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>

InputHandler *InputHandler::m_Instance = 0;

InputHandler::InputHandler()
{
    for (int i = 0; i < 3; i++) {
        m_MouseButtonStates.push_back(false);
    }
}

InputHandler *InputHandler::Instance()
{
    if (!m_Instance) {
        m_Instance = new InputHandler;
    }

    return m_Instance;
}

void InputHandler::clear()
{
}

void InputHandler::update()
{
    m_KeyboardState = SDL_GetKeyboardState(NULL);

    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            Engine::Instance()->quit();
            break;

        case SDL_KEYDOWN:
            onKeyDown(event);
            break;

        case SDL_KEYUP:
            onKeyUp(event);
            break;

        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;

        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
            break;

        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;

        default:
            break;
        }
    }
}

void InputHandler::reset()
{
    for (size_t i = 0; i < m_MouseButtonStates.size(); i++) {
        m_MouseButtonStates[i] = false;
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    return m_KeyboardState[key];
}

bool InputHandler::getMouseButtonState(InputHandler::MouseButton btn)
{
    return m_MouseButtonStates[btn];
}

Vector2D InputHandler::getMousePosition() const
{
    return m_MousePosition;
}

void InputHandler::onKeyDown(SDL_Event &event)
{
}

void InputHandler::onKeyUp(SDL_Event &event)
{
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if (event.button.button == SDL_BUTTON_LEFT) {
        m_MouseButtonStates[MouseButtonLeft] = true;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE) {
        m_MouseButtonStates[MouseButtonMiddle] = true;
    }
    if (event.button.button == SDL_BUTTON_RIGHT) {
        m_MouseButtonStates[MouseButtonRight] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
    if (event.button.button == SDL_BUTTON_LEFT) {
        m_MouseButtonStates[MouseButtonLeft] = false;
    }
    if (event.button.button == SDL_BUTTON_MIDDLE) {
        m_MouseButtonStates[MouseButtonMiddle] = false;
    }
    if (event.button.button == SDL_BUTTON_RIGHT) {
        m_MouseButtonStates[MouseButtonRight] = false;
    }
}

void InputHandler::onMouseMove(SDL_Event &event)
{
    m_MousePosition.setX(event.motion.x);
    m_MousePosition.setY(event.motion.y);
}
