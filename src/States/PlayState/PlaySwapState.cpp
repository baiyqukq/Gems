#include "PlaySwapState.h"

#include "Objects/Gem.h"
#include "PlayState.h"
#include "SoundManager.h"

std::string PlaySwapState::s_stateID = "PlaySwapState";

PlaySwapState::PlaySwapState(PlayState *parent)
    : m_parent(parent)
{
    m_firstGem = NULL;
    m_secondGem = NULL;
}

void PlaySwapState::swap(Gem *first, Gem *second)
{
    TheSoundManager::Instance()->playSound("swap", 0);

    m_firstGem = first;
    first->setDestRow(second->getRow());
    first->setDestCol(second->getCol());
    first->moveToDest();

    m_secondGem = second;
    second->setDestRow(first->getRow());
    second->setDestCol(first->getCol());
    second->moveToDest();
}

void PlaySwapState::render()
{

}

void PlaySwapState::update()
{
    if (m_firstGem->getPos() == m_firstGem->getDestPos())
    {
        m_parent->enterDestoryState();
    }
}

void PlaySwapState::onEnter()
{

}

void PlaySwapState::onExit()
{

}

std::string PlaySwapState::getStateID() const
{
    return s_stateID;
}

