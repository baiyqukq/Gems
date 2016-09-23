#include "PauseState.h"

#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "StateParser.h"

#include "Objects/MenuButton.h"

#include "TextureManager.h"
#include "InputHandler.h"
#include "Engine.h"
#include "LoaderParams.h"

using namespace std;

const std::string PauseState::s_stateID = "PauseState";

PauseState::PauseState()
{
}

void PauseState::render()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}


std::string PauseState::getStateID() const
{
    return s_stateID;
}

void PauseState::setCallbacks(const std::vector<MenuState::Callback> &callbacks)
{
    MenuButton *menuBtn;

    for(size_t i = 0; i < m_gameObjects.size(); i++)
    {
        // if they are of type MenuButton then assign a callback based on the id passed in from the file
        menuBtn = dynamic_cast<MenuButton*>(m_gameObjects[i]);
        if (menuBtn)
        {
            menuBtn->setCallback(callbacks[menuBtn->getCallbackID()]);
        }
    }
}

void PauseState::s_pauseToMain()
{
    TheEngine::Instance()->getGameStateMachine()->changeState(new MainMenuState);
}

void PauseState::s_resumePlay()
{
    TheEngine::Instance()->getGameStateMachine()->popState();
}


void PauseState::update()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void PauseState::onEnter()
{
    StateParser parser;
    parser.parseState("xml/states.xml", "STATE_PAUSE", &m_gameObjects, &m_textureIDs);

    m_callbacks.push_back(s_pauseToMain);
    m_callbacks.push_back(s_resumePlay);

    setCallbacks(m_callbacks);
}

void PauseState::onExit()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clear();
    }
    m_gameObjects.clear();

    for (size_t i = 0; i < m_textureIDs.size(); i++) {
        TextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
    }
    m_textureIDs.clear();

    // reset the mouse button states to false
    InputHandler::Instance()->reset();
}
