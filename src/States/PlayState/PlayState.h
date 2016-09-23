#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "States/GameState.h"
#include <vector>

class StandardGameObject;
class GameObjectInterface;
class GameStateMachine;
class Gem;
class Gems;
class Board;

class PlayState : public GameState
{
public:
    PlayState();
    ~PlayState();

    std::string getStateID() const;

    void update();
    void render();

    void onEnter();
    void onExit();

    // this game donot need to check collision
//    bool checkCollision(StandardGameObject *go_A, StandardGameObject *go_B);

    void enterSwapState(Gem *first, Gem *second);
    void enterAddState();
    void enterDestoryState();
    void enterPlayState();
private:
    int m_UnitWidth;
    int m_UnitHeight;

    static const std::string s_stateID;

    GameStateMachine* m_GameStateMachine;
    Board *m_Board;
    Gems *m_gems; // the class is singleton, but it is considered to be belong to this class
    std::vector<std::string> m_textureIDs;
};

#endif // PLAYSTATE_H
