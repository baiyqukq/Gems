#include "PlayDestoryState.h"

#include "Objects/Gem.h"
#include "Objects/Gems.h"

#include "PlayState.h"

#include <iostream>

std::string PlayDestoryState::s_StateID = "PlayDestoryState";

PlayDestoryState::PlayDestoryState(PlayState *parent)
    : m_PlayState(parent)
{
}

void PlayDestoryState::update()
{

}

void PlayDestoryState::render()
{

}

void PlayDestoryState::onEnter()
{
    // check the same gems

    for (int row = 0; row < TheGems::getRows(); row++)
    {
        for (int col = 0; col < TheGems::getCols(); col++)
        {
            Gem *gem = TheGems::Instance()->getGem(row, col);
            destorySame(gem);
        }
    }

    if (!TheGems::Instance()->isComplete())
    {
        m_PlayState->enterAddState();
    } else {
        m_PlayState->enterPlayState();
    }
}

void PlayDestoryState::onExit()
{

}

std::string PlayDestoryState::getStateID() const
{
    return s_StateID;
}

void PlayDestoryState::destorySame(Gem *gem)
{
    if (gem == NULL)
        return;

    std::vector<Gem *> removingGems;
    const int row = gem->getRow();
    const int col = gem->getCol();


    const GemType gemType = gem->getType();


    // horizontial
    Gem *rightFirstGem = TheGems::Instance()->getGem(row, col + 1);
    Gem *rightSecondGem = TheGems::Instance()->getGem(row, col + 2);

    if (rightFirstGem && rightSecondGem)
    {
        if ((gemType == rightFirstGem->getType()) && (gemType == rightSecondGem->getType()))
        {
            removingGems.push_back(gem);
            removingGems.push_back(rightFirstGem);
            removingGems.push_back(rightSecondGem);

            int moreCol = col + 3;
            while (true)
            {
                Gem *moreGem = TheGems::Instance()->getGem(row, moreCol++);

                if (moreGem == NULL)
                    break;

                if (gemType == moreGem->getType())
                    removingGems.push_back(moreGem);
                else
                    break;
            }

            // veritical
            for (size_t i = 0; i < removingGems.size(); i++)
            {
                destoryVeriticalSame(gem);
            }
        }
    }

    // veritical
    destoryVeriticalSame(gem);

    TheGems::Instance()->remove(removingGems);
}

void PlayDestoryState::destoryVeriticalSame(Gem *gem)
{
    if (gem == NULL)
        return;

    std::vector<Gem *> removingGems;
    const int row = gem->getRow();
    const int col = gem->getCol();
    const GemType gemType = gem->getType();

    // veritical
    Gem *bottomFirstGem = TheGems::Instance()->getGem(row + 1, col);
    Gem *bottomSecondGem = TheGems::Instance()->getGem(row + 2, col);

    if (bottomFirstGem && bottomSecondGem)
    {
        if ((gemType == bottomFirstGem->getType()) && (gemType == bottomSecondGem->getType()))
        {
            removingGems.push_back(gem);
            removingGems.push_back(bottomFirstGem);
            removingGems.push_back(bottomSecondGem);

            int moreRow = row + 3;
            while (true)
            {
                Gem *moreGem = TheGems::Instance()->getGem(moreRow++, col);

                if (moreGem == NULL)
                    break;

                if (moreGem->getType() == gemType)
                    removingGems.push_back(moreGem);
                else
                    break;
            }
        }
    }

    TheGems::Instance()->remove(removingGems);
}
