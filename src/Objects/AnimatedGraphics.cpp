#include "AnimatedGraphics.h"

#include <SDL2/SDL_timer.h>

AnimatedGraphics::AnimatedGraphics()
    : StandardGameObject()
{
    m_iAnimateSpeed = 1;
}

void AnimatedGraphics::setSpeed(int speed)
{
    m_iAnimateSpeed = speed;
}

int AnimatedGraphics::getSpeed() const
{
    return m_iAnimateSpeed;
}

void AnimatedGraphics::update()
{
    m_currentFrame = SDL_GetTicks() / 1000 / m_iAnimateSpeed % m_frameCount;
}


GameObjectInterface *AnimatedGraphicsCreator::createGameObject() const
{
    return new AnimatedGraphics;
}
