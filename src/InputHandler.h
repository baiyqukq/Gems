#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>
#include "Vector2D.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_scancode.h>

/* The singleton class */

class InputHandler
{
public:
    enum MouseButton {
        MouseButtonLeft,
        MouseButtonMiddle,
        MouseButtonRight
    };

    static InputHandler *Instance();

    void clear();
    void update();
    void reset();
    bool isKeyDown(SDL_Scancode key);
    bool getMouseButtonState(MouseButton btn);
    Vector2D getMousePosition() const;
protected:
    void onKeyDown(SDL_Event &event);
    void onKeyUp(SDL_Event &event);

    void onMouseButtonDown(SDL_Event &event);
    void onMouseButtonUp(SDL_Event &event);
    void onMouseMove(SDL_Event &event);
private:
    InputHandler();
    static InputHandler *m_Instance;

    Vector2D m_MousePosition;

    std::vector<bool> m_MouseButtonStates;

    const Uint8* m_KeyboardState;
};

typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H
