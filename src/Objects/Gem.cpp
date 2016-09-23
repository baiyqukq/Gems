#include "Gem.h"

#include "Engine.h"
#include "InputHandler.h"
#include "TextureManager.h"

#include <SDL2/SDL_rect.h>
#include <stdlib.h>

std::string Gem::s_CursorTextureID = "cursor";

#include <sstream>

int Gem::s_normalWidth = 48;
int Gem::s_normalHeight = 48;
int Gem::s_intervalTime = 2000;

Gem::Gem()
{
    m_width = s_normalWidth;
    m_height = s_normalHeight;

    m_IsSelected = false;
    m_Type = GemType(rand() % GemTypeCount);

    std::stringstream ss;
    ss << "gem0" << m_Type + 1;

    m_textureID = ss.str();
}

void Gem::load(const LoaderParams *params)
{

}

void Gem::clear()
{

}

void Gem::update()
{
    if (m_position == m_destPosition)
    {
        m_velocity = Vector2D(0, 0);
    }

    StandardGameObject::update();
}

void Gem::draw()
{
    SDL_Rect rect;
    rect.x = m_position.getX();
    rect.y = m_position.getY();
    rect.w = m_width;
    rect.h = m_height;

    TheTextureManager::Instance()->draw(m_textureID, rect, TheEngine::Instance()->getRenderer());

    // draw cursor
    if (m_IsSelected) {
        TheTextureManager::Instance()->draw(s_CursorTextureID, rect, TheEngine::Instance()->getRenderer());
    }
}

bool Gem::isSelected() const
{
    return m_IsSelected;
}

void Gem::setIsSelected(bool selected)
{
    m_IsSelected = selected;
}

GemType Gem::getType() const
{
    return m_Type;
}

int Gem::getRow() const
{
    return m_position.getY() / s_normalHeight;
}

void Gem::setRow(int row)
{
    m_position.setY(row * s_normalHeight);
}

int Gem::getCol() const
{
    return m_position.getX() / s_normalWidth;
}

void Gem::setCol(int col)
{
    m_position.setX(col * s_normalWidth);
}

void Gem::setDestRow(int row)
{
    m_destPosition.setY(row * s_normalHeight);
}

void Gem::setDestCol(int col)
{
    m_destPosition.setX(col * s_normalWidth);
}

void Gem::moveToDest()
{
    m_velocity = (m_destPosition - m_position) / 8;
}

int Gem::getDestRow() const
{
    return m_destPosition.getY() / s_normalHeight;
}

int Gem::getDestCol() const
{
    return m_destPosition.getX() / s_normalWidth;
}

Vector2D Gem::getDestPos() const
{
    return m_destPosition;
}

int Gem::getNormalWidth()
{
    return s_normalWidth;
}

int Gem::getNormalHeight()
{
    return s_normalHeight;
}

void Gem::setDestPos(float x, float y)
{
    m_destPosition.setX(x);
    m_destPosition.setY(y);
}

void Gem::setDestPos(const Vector2D &pos)
{
    m_destPosition = pos;
}
