#ifndef ANIMATEDGRAPHICS_H
#define ANIMATEDGRAPHICS_H

#include "StandardGameObject.h"

class AnimatedGraphics : public StandardGameObject
{
public:
    AnimatedGraphics();

    void setSpeed(int speed);
    int getSpeed() const;

    void update();
private:
    int m_iAnimateSpeed;
};

#include "CreatorInterface.h"

class AnimatedGraphicsCreator: public CreatorInterface
{
    GameObjectInterface *createGameObject() const;
};

#endif // ANIMATEDGRAPHICS_H
