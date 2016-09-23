#include "MainMenuState.h"
#include "StateParser.h"

#include "Objects/MenuButton.h"

#include "Engine.h"
#include "GameStateMachine.h"
#include "TextureManager.h"
#include "PlayState/PlayState.h"

const std::string MainMenuState::s_stateID = "MainMenuState";

MainMenuState::MainMenuState()
{
}


void MainMenuState::update()
{
    for (size_t i = 0; i < m_gameOjects.size(); i++) {
        m_gameOjects[i]->update();
    }
}


void MainMenuState::render()
{
    for (size_t i = 0; i < m_gameOjects.size(); i++) {
        m_gameOjects[i]->draw();
    }
}


std::string MainMenuState::getStateID() const
{
    return s_stateID;
}

void MainMenuState::exit()
{
    Engine::Instance()->quit();
}

void MainMenuState::play()
{
    PlayState *state = new PlayState;
    TheEngine::Instance()->getGameStateMachine()->changeState(state);
}

void MainMenuState::onExit()
{
    for (size_t i = 0; i < m_gameOjects.size(); i++) {
        m_gameOjects[i]->clear();
    }

    m_gameOjects.clear();

    for (size_t i = 0; i < m_textureIDs.size(); i++) {
        TheTextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
    }

    m_textureIDs.clear();
}


void MainMenuState::onEnter()
{
    StateParser parser;
    parser.parseState("xml/states.xml", s_stateID, &m_gameOjects, &m_textureIDs);

    m_callbacks.push_back(play);
    m_callbacks.push_back(exit);
    setCallbacks(m_callbacks);
}

void MainMenuState::setCallbacks(const std::vector<MenuState::Callback> &callbacks)
{
    for (size_t i = 0; i < m_gameOjects.size(); ++i) {
        MenuButton *btn = dynamic_cast<MenuButton *>(m_gameOjects[i]);

        if (!btn)
            continue;

        btn->setCallback(callbacks[btn->getCallbackID()]);
    }
}
