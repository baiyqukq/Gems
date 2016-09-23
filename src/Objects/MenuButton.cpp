#include "MenuButton.h"

#include "InputHandler.h"
#include <iostream>
#include "LoaderParams.h"

using namespace std;

MenuButton::MenuButton()
    : StandardGameObject()
{
    m_currentFrame = Button_Mouse_Out;
    m_bRelease = true;
}

void MenuButton::draw()
{
    StandardGameObject::draw();
}

void MenuButton::update()
{
    Vector2D pos = InputHandler::Instance()->getMousePosition();

    if ((pos.getX() > m_position.getX())
            && (pos.getX() < (m_position.getX() + m_width))
            && (pos.getY() > m_position.getY())
            && (pos.getY() < (m_position.getY() + m_height))) {

        if (InputHandler::Instance()->getMouseButtonState(InputHandler::MouseButtonLeft) && m_bRelease) {
            m_currentFrame = Button_Clicked;
            m_bRelease = false;
            m_callback();       // -------------------------------- //
        } else if (!InputHandler::Instance()->getMouseButtonState(InputHandler::MouseButtonLeft)) {
            m_currentFrame = Button_Mouse_Over;
            m_bRelease = true;
        }

    } else {
        m_currentFrame = Button_Mouse_Out;
    }
}

void MenuButton::clear()
{
    StandardGameObject::clear();
}

void MenuButton::load(const LoaderParams *params)
{
    StandardGameObject::load(params);

    m_callbackID = params->getCallbackID();
    m_currentFrame = Button_Mouse_Out;
}

void MenuButton::setCallback(void (*callback)())
{
    m_callback = callback;
}

int MenuButton::getCallbackID() const
{
    return m_callbackID;
}


GameObjectInterface *MenuButtonCreator::createGameObject() const
{
    return new MenuButton();
}
