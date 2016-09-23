#include "PlayState.h"

#include "States/StateParser.h"
#include "States/GameOverState.h"
#include "States/GameStateMachine.h"
#include "States/PauseState.h"

#include "PlayAddState.h"
#include "PlaySwapState.h"
#include "PlayDestoryState.h"
#include "PlayPlayState.h"

#include "Engine.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "SoundManager.h"

#include "Objects/Gem.h"
#include "Objects/Gems.h"
#include "Objects/Board.h"

#include <iostream>

using namespace std;

const std::string PlayState::s_stateID = "PlayState";

PlayState::PlayState()
{
    m_UnitWidth = 48;
    m_UnitHeight = 48;

    m_GameStateMachine = new GameStateMachine();
    cout << "Play state has created own game state machine" << endl;

    m_Board = new Board;
    m_Board->setCols(TheGems::getCols());
    m_Board->setRows(TheGems::getRows());
    m_Board->setUnitSize(m_UnitWidth, m_UnitHeight);

    m_gems =  TheGems::Instance();
}

PlayState::~PlayState()
{
}

std::string PlayState::getStateID() const
{
    return s_stateID;
}

void PlayState::update()
{
    // when put down esc key, into pause state
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        TheEngine::Instance()->getGameStateMachine()->pushState(new PauseState());
    }

    m_Board->update();
    m_gems->update();

    m_GameStateMachine->update();
}

void PlayState::render()
{
    m_Board->draw();
    m_gems->draw();

    m_GameStateMachine->render();
}

void PlayState::onEnter()
{
   StateParser parser;
   parser.parseState("xml/states.xml", s_stateID, NULL, &m_textureIDs);

   // template
   TheSoundManager::Instance()->load("sounds/click.wav", "click");
   TheSoundManager::Instance()->load("sounds/swap.wav", "swap");

   enterAddState();
}

void PlayState::onExit()
{
    m_Board->clear();
    m_gems->clear();

    // clear all textures
    for (size_t i = 0; i < m_textureIDs.size(); ++i) {
        TextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
    }
}

void PlayState::enterSwapState(Gem *first, Gem *second)
{
    m_GameStateMachine->popState();

    PlaySwapState *state = new PlaySwapState(this);
    state->swap(first, second);
    m_GameStateMachine->pushState(state);
}

void PlayState::enterAddState()
{
    m_GameStateMachine->popState();

    PlayAddState *playAddState = new PlayAddState(this);
    m_GameStateMachine->pushState(playAddState);
}

void PlayState::enterDestoryState()
{
    m_GameStateMachine->popState();

    PlayDestoryState *state = new PlayDestoryState(this);
    m_GameStateMachine->pushState(state);
}

void PlayState::enterPlayState()
{
    m_GameStateMachine->popState();

    PlayPlayState *state = new PlayPlayState(this);
    m_GameStateMachine->pushState(state);
}
