#include "StandardGameObject.h"

#include "LoaderParams.h"
#include "TextureManager.h"
#include "Engine.h"

using namespace std;

StandardGameObject::StandardGameObject()
{
    m_frameCount = 1;
    m_currentFrame = 0;
    m_acceleration = Vector2D(0, 0);
    m_velocity = Vector2D(0, 0);
}


void StandardGameObject::draw()
{
    SDL_Rect rect;
    rect.x = m_position.getX();
    rect.y = m_position.getY();
    rect.w = m_width;
    rect.h = m_height;

    TheTextureManager::Instance()->drawFrame(m_textureID,
                                             m_currentFrame,
                                             rect,
                                             TheEngine::Instance()->getRenderer());
}

void StandardGameObject::update()
{
    m_velocity += m_acceleration;
    m_position += m_velocity;
}

void StandardGameObject::clear()
{
}

void StandardGameObject::load(const LoaderParams *params)
{
    m_position.setX(params->getX());
    m_position.setY(params->getY());

    m_width = params->getWidth();
    m_height = params->getHeight();

    m_textureID = params->getTextureID();

    m_currentFrame = 0;
    m_frameCount = params->getFrameCount();

    m_velocity.setX(0);
    m_velocity.setY(0);

    m_acceleration.setX(0);
    m_acceleration.setY(0);
}


//void StandardGameObject::setPos(int x, int y)
//{
//    m_Position.setX(x);
//    m_Position.setY(y);
//}

//void StandardGameObject::setSize(int w, int h)
//{
//    m_Width = w;
//    m_Height = h;
//}

//void StandardGameObject::setFrameCount(int count)
//{
//    m_numFrames = count;
//}

Vector2D StandardGameObject::getPos() const
{
    return m_position;
}

void StandardGameObject::setPos(const Vector2D &pos)
{
    m_position = pos;
}

int StandardGameObject::getY() const
{
    return m_position.getY();
}

int StandardGameObject::getWidth() const
{
    return m_width;
}

int StandardGameObject::getHeight() const
{
    return m_height;
}

void StandardGameObject::setVelocity(const Vector2D &v)
{
    m_velocity = v;
}


