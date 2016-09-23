#include "Board.h"

#include "Gem.h"
#include "TextureManager.h"
#include "Engine.h"

Board::Board()
{
    m_EvenTileTextureID = "tile_even";
    m_OddTileTextureID = "tile_odd";
}

void Board::setCols(int w)
{
    m_Width = w;
}

void Board::setRows(int h)
{
    m_Height = h;
}

void Board::draw()
{
    for (int row = 0; row < m_Height; row++)
    {
        for (int col = 0; col < m_Width; ++col)
        {
            SDL_Rect rect;
            rect.x = col * m_UnitWidth;
            rect.y = row * m_UnitHeight;
            rect.w = m_UnitWidth;
            rect.h = m_UnitHeight;

            if ((row + col) % 2)
            {
                TheTextureManager::Instance()->draw(m_EvenTileTextureID,
                                                    rect,
                                                    TheEngine::Instance()->getRenderer());
            } else {
                TheTextureManager::Instance()->draw(m_OddTileTextureID,
                                                    rect,
                                                    TheEngine::Instance()->getRenderer());
            }
        }
    }
}

void Board::update()
{

}

void Board::load(const LoaderParams *params)
{

}

void Board::clear()
{

}

void Board::setUnitSize(int w, int h)
{
    m_UnitWidth = w;
    m_UnitHeight = h;
}
