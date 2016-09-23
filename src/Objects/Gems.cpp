#include "Gems.h"

#include "Gem.h"

#include <algorithm>

uint8_t Gems::s_rows = 12;
uint8_t Gems::s_cols = 12;
Gems* Gems::s_instance = NULL;

Gems *Gems::Instance()
{
    if (!s_instance)
    {
        s_instance = new Gems;
    }

    return s_instance;
}

Gem *Gems::getGem(int row, int col)
{
    for (size_t i = 0; i < m_gems.size(); i++)
    {
        Gem *gem = m_gems.at(i);
        if ((gem->getCol() == col) && (gem->getRow() == row))
            return gem;
    }

    return NULL;
}

void Gems::update()
{
    for (size_t i = 0; i < m_gems.size(); i++)
    {
        Gem *gem = m_gems.at(i);
        gem->update();
    }
}

void Gems::draw()
{
    for (size_t i = 0; i < m_gems.size(); i++)
    {
        Gem *gem = m_gems.at(i);
        gem->draw();
    }
}

void Gems::clear()
{
    for (size_t i = 0; i < m_gems.size(); i++)
    {
        Gem *gem = m_gems.at(i);
        gem->clear();
    }
}

void Gems::load(const LoaderParams *params)
{

}

bool Gems::isComplete() const
{
    if (m_gems.size() == (s_rows * s_cols))
        return true;
    else
        return false;
}

bool Gems::exists(int row, int col)
{
    Gem *gem = getGem(row, col);

    if (gem == NULL)
        return false;
    else
        return true;
}

void Gems::remove(std::vector<Gem *> gems)
{
    for (size_t i = 0; i < gems.size(); i++)
    {
        Gem *gem = gems.at(i);

        remove(gem);
    }
}

void Gems::remove(Gem *gem)
{
    for (std::vector<Gem *>::iterator i = m_gems.begin();
         i != m_gems.end();
         i++)
    {
        if (gem == *i)
        {
            m_gems.erase(i);

            // it is important
            return;
        }
    }
}

std::vector<Gem *> *Gems::getGems()
{
    return &m_gems;
}

Gem *Gems::getSelected() const
{
    for (size_t i = 0; i < m_gems.size(); i++)
    {
        Gem *gem = m_gems.at(i);

        if (gem->isSelected())
            return gem;
    }

    return NULL;
}

void Gems::clearSelection()
{
    for (size_t i = 0; i < m_gems.size(); i++)
    {
        Gem *gem = m_gems.at(i);
        gem->setIsSelected(false);
    }
}

bool Gems::hasSelected() const
{
    if (getSelected() != NULL)
        return true;
    else
        return false;
}

void Gems::select(Gem *gem)
{
    Gem *selectGem = getSelected();

    if (selectGem)
    {
        selectGem->setIsSelected(false);
    }

    gem->setIsSelected(true);
}

int Gems::getCols()
{
    return s_cols;
}

int Gems::getRows()
{
    return s_rows;
}

Gems::Gems()
{
}
