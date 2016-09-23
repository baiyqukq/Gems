#include "PlayAddState.h"

#include "PlayState.h"

#include "Objects/Gem.h"
#include "Objects/Gems.h"

std::string PlayAddState::s_StateID = "PlayAddState";

#include <iostream>

PlayAddState::PlayAddState(PlayState *parent)
    : m_parent(parent)
{
}

void PlayAddState::render()
{
    // the gems have rendered in play state
}

void PlayAddState::update()
{
    // the gems is not belong to the class
    // hence, the gems donot update here

    bool isFinished = true;

    std::vector<Gem *> *gems = TheGems::Instance()->getGems();

    for (size_t i = 0; i < gems->size(); i++)
    {
        Gem *gem = gems->at(i);

        if (gem->getY() < gem->getDestPos().getY())
        {
            isFinished = false;
        } else {
            gem->setRow(gem->getDestRow());
            gem->setVelocity(Vector2D(0, 0));
        }
    }

    if (isFinished)
    {
        m_parent->enterDestoryState();
    }
}

void PlayAddState::onEnter()
{
    std::vector<Gem *> *gems = TheGems::Instance()->getGems();

    // the first, creating lacking gems
    // put the new gems onto the top of board
    for (int col = 0; col < TheGems::getCols(); col++)
    {
        std::vector<Gem *> newGems;
        for (int row = 0; row < TheGems::getRows(); row++)
        {
            if (!TheGems::Instance()->exists(row, col))
            {
                Gem *gem = new Gem;
                newGems.push_back(gem);
            }

        }

        for (size_t i = 0; i < newGems.size(); i++)
        {
            Gem *gem = newGems.at(i);
            gem->setRow(-1 - i);
            gem->setCol(col);
            gem->setDestRow(-1 - i);
            gem->setDestCol(col);
        }

        // push the new gems backto the gems of Play State
        for (size_t i = 0; i < newGems.size(); i++) {
            gems->push_back(newGems.at(i));
        }
    }

    // the second, put down the gems in sky
    // moving the gems to corresponding position
    for (int col = 0; col < TheGems::getCols(); col++)
    {
        for (int row = 0; row < TheGems::getRows(); row++)
        {
            if (!TheGems::Instance()->exists(row, col))
            {
                for (size_t i = 0; i < gems->size(); i++)
                {
                    Gem *gem = gems->at(i);
                    if ((gem->getDestCol() == col ) && (gem->getDestRow() < row))
                    {
                        gem->setDestRow(gem->getDestRow() + 1);
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < gems->size(); i++)
    {
        Gem *gem = gems->at(i);
        gem->setVelocity(Vector2D(0, 5));
    }
}

void PlayAddState::onExit()
{
    // do nothing
}

std::string PlayAddState::getStateID() const
{
    return s_StateID;
}
