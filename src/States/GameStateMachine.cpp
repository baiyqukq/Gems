#include "GameStateMachine.h"

#include "GameState.h"

#include <iostream>

using namespace std;

GameStateMachine::GameStateMachine()
{
}

void GameStateMachine::update()
{
    if (m_GameStates.empty())
        return;

    m_GameStates.back()->update();
}

void GameStateMachine::render()
{
    if (m_GameStates.empty())
        return;

    m_GameStates.back()->render();
}

void GameStateMachine::changeState(GameState *state)
{
    if (m_GameStates.empty())
        return;

    if (m_GameStates.back()->getStateID() == state->getStateID())
        return;

    popState();

    pushState(state);
}

void GameStateMachine::pushState(GameState *s)
{
    cout << "Game State Machine enters the state:" << s->getStateID() << endl;

    m_GameStates.push_back(s);

    // it must after push_back
    s->onEnter();
}

void GameStateMachine::popState()
{
    if (m_GameStates.empty())
        return;

    cout << "Game State Machine exits the state:" << m_GameStates.back()->getStateID() << endl;

    m_GameStates.back()->onExit();
    m_GameStates.pop_back();    // This destroys the removed element.
}
