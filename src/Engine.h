#ifndef ENGINE_H
#define ENGINE_H

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
class GameStateMachine;

#include <SDL2/SDL_rect.h>

#include <list>
#include <string>

/* The singleton class */

class Engine
{
public:
    int exec();

    bool init();
    SDL_Renderer *getRenderer() const { return m_Renderer; }
    GameStateMachine *getGameStateMachine() const { return m_GameStateMachine; }

    static Engine *Instance();
    void quit();
private:
    Engine();
    void clear();
    void handleEvents();
    void update();
    void render();
private:
    static Engine *m_Instance;

    GameStateMachine* m_GameStateMachine;

    SDL_Window *m_Window;
    SDL_Renderer *m_Renderer;

    std::string m_Title;

    bool m_Running;
    int m_Width;
    int m_Height;
};

typedef Engine TheEngine;

#endif // ENGINE_H
