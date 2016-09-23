#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <SDL2/SDL_rect.h>

#include "Vector2D.h"

class LoaderParams;

class GameObjectInterface
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clear() = 0;
    virtual void load(const LoaderParams* pParams) = 0;
protected:
    virtual ~GameObjectInterface() {}

};

#endif // GAMEOBJECT_H
