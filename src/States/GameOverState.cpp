#include "GameOverState.h"

#include "GameStateMachine.h"
#include "MainMenuState.h"
#include "StateParser.h"
#include "PlayState/PlayState.h"

#include "TextureManager.h"
#include "LoaderParams.h"
#include "Engine.h"

#include "Objects/AnimatedGraphics.h"
#include "Objects/MenuButton.h"


const std::string GameOverState::s_gameOverID = "STATE_GAMEOVER";

GameOverState::GameOverState()
{
}

void GameOverState::onEnter()
{
    StateParser parser;
    parser.parseState("xml/states.xml", "STATE_GAMEOVER", &m_gameObjects, &m_textureIDs);

    m_callbacks.push_back(s_gameOverToMain);
    m_callbacks.push_back(s_restartPlay);

    setCallbacks(m_callbacks);

}

void GameOverState::setCallbacks(const std::vector<MenuState::Callback> &callbacks)
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

void GameOverState::onExit()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clear();
    }

    m_gameObjects.clear();

    for (size_t i = 0; i < m_textureIDs.size(); ++i) {
        TextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
    }
    m_textureIDs.clear();

}

void GameOverState::update()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->update();
    }
}

void GameOverState::render()
{
    for (size_t i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
}

void GameOverState::s_gameOverToMain()
{
    TheEngine::Instance()->getGameStateMachine()->changeState(new MainMenuState);
}

void GameOverState::s_restartPlay()
{
    TheEngine::Instance()->getGameStateMachine()->changeState(new PlayState);
}

string GameOverState::getStateID() const
{
    return s_gameOverID;
}
