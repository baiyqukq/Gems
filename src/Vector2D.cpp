#include "Vector2D.h"

#include <math.h>

Vector2D::Vector2D(float x, float y)
    : m_X(x), m_Y(y)
{
}

float Vector2D::getX() const
{
    return m_X;
}

float Vector2D::getY() const
{
    return m_Y;
}

void Vector2D::setX(float x)
{
    m_X = x;
}

void Vector2D::setY(float y)
{
    m_Y = y;
}

float Vector2D::length() const
{
    return sqrtf(m_X * m_X + m_Y * m_Y);
}

void Vector2D::normalize()
{

}

bool Vector2D::operator==(const Vector2D &v2) const
{
    if (this->getX() != v2.getX() || this->getY() != v2.getY())
        return false;
    else
        return true;
}

Vector2D Vector2D::operator +(const Vector2D &v2) const
{
    return Vector2D(m_X + v2.m_X, m_Y + v2.m_Y);
}

Vector2D Vector2D::operator -(const Vector2D &v2) const
{
    return Vector2D(m_X - v2.m_X, m_Y - v2.m_Y);
}

Vector2D Vector2D::operator /(float scalar) const
{
    return Vector2D(m_X / scalar, m_Y / scalar);
}

Vector2D &Vector2D::operator *=(float scalar)
{
    m_X *= scalar;
    m_Y *= scalar;

    return (*this);
}

Vector2D &Vector2D::operator /=(float scalar)
{
    m_X /= scalar;
    m_Y /= scalar;

    return (*this);
}

Vector2D & operator +=(Vector2D &v1, const Vector2D &v2)
{
    v1.m_X += v2.m_X;
    v1.m_Y += v2.m_Y;

    return v1;
}
