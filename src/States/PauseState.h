#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "MenuState.h"

#include <vector>

class GameObjectInterface;

class PauseState : public MenuState
{
public:
    PauseState();

    virtual void render();
    virtual void update();
    virtual void onEnter();
    virtual void onExit();
    virtual std::string getStateID() const;

    virtual void setCallbacks(const std::vector<Callback> &callbacks);
private:
    static void s_pauseToMain();
    static void s_resumePlay();

    static const std::string s_stateID;

    std::vector<GameObjectInterface *> m_gameObjects;
    std::vector<std::string> m_textureIDs;
};

#endif // PAUSESTATE_H
