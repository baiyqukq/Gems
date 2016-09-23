#ifndef STANDARDGAMEOBJECT_H
#define STANDARDGAMEOBJECT_H

#include "GameObjectInterface.h"

class StandardGameObject : public GameObjectInterface
{
public:
    StandardGameObject();

    virtual void draw();
    virtual void update();
    virtual void clear();
    virtual void load(const LoaderParams *params);

    Vector2D getPos() const;
    void setPos(const Vector2D &pos);

    int getX() const;
    int getY() const;

    int getWidth() const;
    int getHeight() const;

    void setVelocity(const Vector2D &v);
protected:

    Vector2D m_acceleration;
    Vector2D m_velocity;
    Vector2D m_position;

    int m_width;
    int m_height;

    int m_currentFrame;
    int m_frameCount;

    std::string m_textureID;
};

#endif // STANDARDGAMEOBJECT_H
