#ifndef BOARD_H
#define BOARD_H

#include "GameObjectInterface.h"

#include <string>

class Board : public GameObjectInterface
{
public:
    Board();

    void draw();
    void update();
    void load(const LoaderParams *params);
    void clear();

    void setUnitSize(int w, int h);
    void setCols(int w);
    void setRows(int h);
private:
    std::string m_EvenTileTextureID;
    std::string m_OddTileTextureID;

    int m_UnitWidth;
    int m_UnitHeight;
    int m_Width;
    int m_Height;
};

#endif // BOARD_H
