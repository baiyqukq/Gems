#include "PlayPlayState.h"

#include "SoundManager.h"
#include "InputHandler.h"

#include "Objects/Gems.h"
#include "Objects/Gem.h"
#include "PlayState.h"

PlayPlayState::PlayPlayState(PlayState *parent)
    : m_parent(parent)
{
}

void PlayPlayState::render()
{

}

void PlayPlayState::update()
{
    if (TheInputHandler::Instance()->getMouseButtonState(InputHandler::MouseButtonLeft))
    {
        // play the click sound
        TheSoundManager::Instance()->playSound("click", 0);

        Vector2D pos = TheInputHandler::Instance()->getMousePosition();
        int row = pos.getY() / Gem::getNormalHeight();
        int col = pos.getX() / Gem::getNormalWidth();

        Gem *gem = TheGems::Instance()->getGem(row, col);

        if (TheGems::Instance()->hasSelected())
        {
            Gem *selectedGem = TheGems::Instance()->getSelected();

            int distance = gem->getRow() - selectedGem->getRow()
                    + gem->getCol() - selectedGem->getCol();

            if (distance == 1 || distance == -1)
            {
                TheGems::Instance()->clearSelection();
                m_parent->enterSwapState(gem, selectedGem);
            }
        } else {
            TheGems::Instance()->select(gem);
        }
    }
}

void PlayPlayState::onEnter()
{

}

void PlayPlayState::onExit()
{

}

std::string PlayPlayState::getStateID() const
{
    return "PlayPlayState";
}

void PlayPlayState::swapGem(Gem *first, Gem *second)
{
}
