#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "MenuState.h"
#include <vector>

class GameObjectInterface;

class GameOverState : public MenuState
{
public:
    GameOverState();

    void onEnter();
    void onExit();
    void update();
    void render();
    std::string getStateID() const;
    virtual void setCallbacks(const std::vector<Callback>& callbacks);
private:
    static void s_gameOverToMain();
    static void s_restartPlay();

    static const std::string s_gameOverID;
private:
    std::vector<GameObjectInterface *> m_gameObjects;
    std::vector<std::string> m_textureIDs;
};

#endif // GAMEOVERSTATE_H
