#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include <vector>

class GameState;

class GameStateMachine
{
public:
    GameStateMachine();

    void update();
    void render();

    void changeState(GameState *state);
    void pushState(GameState *s);
    void popState();
private:
    std::vector<GameState *> m_GameStates;
};

#endif // GAMESTATEMACHINE_H
