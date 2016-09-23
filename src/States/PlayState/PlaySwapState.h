#ifndef PLAYSWAPSTATE_H
#define PLAYSWAPSTATE_H

#include "States/GameState.h"

class PlayState;
class Gem;

class PlaySwapState : public GameState
{
public:
    PlaySwapState(PlayState *parent = NULL);
    void swap(Gem *first, Gem *second);
    virtual void render();
    virtual void update();

    virtual void onEnter();
    virtual void onExit();

    virtual std::string getStateID() const;

private:
    Gem *m_firstGem;
    Gem *m_secondGem;
    PlayState *m_parent;
    static std::string s_stateID;
};

#endif // PLAYSWAPSTATE_H
