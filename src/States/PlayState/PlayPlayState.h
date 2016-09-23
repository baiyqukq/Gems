#ifndef PLAYPLAYSTATE_H
#define PLAYPLAYSTATE_H

#include "States/GameState.h"


class Gem;
class PlayState;

class PlayPlayState : public GameState
{
public:
    PlayPlayState(PlayState *parent = NULL);

    virtual void render();
    virtual void update();
    virtual void onEnter();
    virtual void onExit();
    virtual std::string getStateID() const;

    void swapGem(Gem *first, Gem *second);
private:
    PlayState *m_parent;
};

#endif // PLAYPLAYSTATE_H
