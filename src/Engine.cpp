#include "Engine.h"

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_scancode.h>

#include "TextureManager.h"
#include "InputHandler.h"

#include "States/GameStateMachine.h"
#include "States/MainMenuState.h"
#include "States/PlayState/PlayState.h"

#include "Objects/GameObjectInterface.h"
#include "Objects/GameObjectFactory.h"
#include "Objects/MenuButton.h"
#include "Objects/AnimatedGraphics.h"

using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;

Engine *Engine::m_Instance = NULL;

Engine::Engine()
{
    m_Width = 576;
    m_Height = 576;

    m_Running = false;
    m_Title = "SDL Game";

    init();
}

int Engine::exec()
{
    int frameStart, frameTime;

    while (m_Running) {
        frameStart = SDL_GetTicks();

        handleEvents();
        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay(DELAY_TIME - frameTime);
        }
    }

    clear();

    cout << "Game is going to quit" << endl;

    return 0;
}

Engine *Engine::Instance()
{
    if (!m_Instance) {
        m_Instance = new Engine;
        return m_Instance;
    }

    return m_Instance;
}

void Engine::quit()
{
    m_Running = false;
}

void Engine::clear()
{
    InputHandler::Instance()->clear();

    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
}

bool Engine::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL can not initializes everything: " << SDL_GetError() << endl;
        return false;
    }
    
    cout << "SDL has initilized everything" << endl;

    m_Window = SDL_CreateWindow(m_Title.c_str(),
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                m_Width, m_Height,
                                SDL_WINDOW_SHOWN);

    if (!m_Window) {
        cout << "SDL can not create the window: " << SDL_GetError() << endl;
        return false;
    }

    cout << "SDL has created a new window" << endl;

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_TARGETTEXTURE);
    if (!m_Renderer) {
        cout << "SDL can not create renderer: " << SDL_GetError() << endl;
        return false;
    }

    cout << "SDL has created a new renderer" << endl;

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    cout << "SDL set the render draw color to black" << endl;

    TheTextureManager::Instance()->setRenderer(m_Renderer);

    GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator);
    GameObjectFactory::Instance()->registerType("AnimatedGraphics", new AnimatedGraphicsCreator);

    MainMenuState *state = new MainMenuState;

    m_GameStateMachine = new GameStateMachine;
    cout << "Game has create the main state machine" << endl;
    m_GameStateMachine->pushState(state);

    m_Running = true;
    return true;
}

void Engine::handleEvents()
{
    InputHandler *handler = InputHandler::Instance();
    handler->update();
}

void Engine::update()
{
    m_GameStateMachine->update();
}

void Engine::render()
{
    SDL_RenderClear(m_Renderer);

    //! [draw]
    m_GameStateMachine->render();
    //! []

    SDL_RenderPresent(m_Renderer);
}
