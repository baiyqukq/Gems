#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <vector>

class GameState
{
public:
    virtual ~GameState(){}
    virtual void render() = 0;
    virtual void update() = 0;

    virtual void onEnter() = 0;
    virtual void onExit() = 0;

    virtual std::string getStateID() const = 0;
protected:
    std::vector<std::string> m_textureIDs;    
};

#endif // GAMESTATE_H
