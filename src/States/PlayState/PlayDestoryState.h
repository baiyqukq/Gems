#ifndef PLAYDESTORYSTATE_H
#define PLAYDESTORYSTATE_H

#include "States/GameState.h"

class Gem;
class PlayState;

enum Orientation
{
    Horizontial,
    Vertical
};

class PlayDestoryState : public GameState
{
public:
    PlayDestoryState(PlayState *parent);

    // interface functions
    virtual void update();
    virtual void render();
    virtual void onEnter();
    virtual void onExit();

    virtual std::string getStateID() const;
private:
    void destorySame(Gem *gem);
    void destoryVeriticalSame(Gem *gem);
private:
    static std::string s_StateID;
    PlayState *m_PlayState;
};

#endif // PLAYDESTORYSTATE_H
