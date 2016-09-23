#ifndef GEM_H
#define GEM_H

#include "StandardGameObject.h"

#include <string>

enum GemType
{
    Gem1 = 0,
    Gem2,
    Gem3,
    Gem4,
    Gem5,
    Gem6,
    Gem7,
    GemTypeCount
};

class Gem : public StandardGameObject
{
public:
    Gem();

    virtual void load(const LoaderParams *params);
    virtual void clear();
    virtual void update();
    virtual void draw();

    bool isSelected() const;
    void setIsSelected(bool selected);

    GemType getType() const;

    int getRow() const;
    void setRow(int row);

    int getCol() const;
    void setCol(int col);

    void setDestRow(int row);
    void setDestCol(int col);
    void moveToDest();

    int getDestRow() const;
    int getDestCol() const;

    Vector2D getDestPos() const;

    static int getNormalWidth();
    static int getNormalHeight();

    void setDestPos(float x, float y);
    void setDestPos(const Vector2D &pos);
protected:
    static std::string s_CursorTextureID;

    static int s_normalWidth;
    static int s_normalHeight;
    static int s_intervalTime;

    bool m_IsSelected;
    Vector2D m_destPosition;
    GemType m_Type;
};

#endif // GEM_H
