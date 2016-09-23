#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "MenuState.h"

class MainMenuState : public MenuState
{
public:
    MainMenuState();

    virtual void update();
    virtual void render();

    virtual void onEnter();
    virtual void onExit();

    virtual std::string getStateID() const;
private:
    virtual void setCallbacks(const std::vector<Callback> &callbacks);

    static void exit();
    static void play();

    static const std::string s_stateID;

    std::vector<GameObjectInterface *> m_gameOjects;
    std::vector<std::string> m_textureIDs;
};

#endif // MAINMENUSTATE_H
