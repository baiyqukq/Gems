#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    Vector2D(){}
    Vector2D(float x, float y);

    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    float length() const;
    void normalize();

    // operator overload
    bool operator==(const Vector2D &v2) const;
    Vector2D operator+(const Vector2D &v2) const;
    Vector2D operator-(const Vector2D &v2) const;
    Vector2D operator*(float scalar) const;
    Vector2D operator/(float scalar) const;
    Vector2D &operator*=(float scalar);
    Vector2D &operator/=(float scalar);
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);

private:
    float m_X;
    float m_Y;
};

#endif // VECTOR2D_H
