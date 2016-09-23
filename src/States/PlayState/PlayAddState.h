#ifndef PLAYADDSTATE_H
#define PLAYADDSTATE_H

#include "States/GameState.h"

#include <vector>
#include <string>

class Gem;
class GameStateMachine;
class PlayState;

class PlayAddState : public GameState
{
public:
    PlayAddState(PlayState *parent = NULL);

    void setGems(std::vector<Gem *> *gems);

    virtual void render();
    virtual void update();

    virtual void onEnter();
    virtual void onExit();

    virtual std::string getStateID() const;
private:
    PlayState *m_parent;
    static std::string s_StateID;
};

#endif // PLAYADDSTATE_H
