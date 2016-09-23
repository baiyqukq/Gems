#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "StandardGameObject.h"
#include "CreatorInterface.h"

class MenuButton : public StandardGameObject
{
public:
    MenuButton();

    enum ButtonState {
        Button_Mouse_Out,
        Button_Mouse_Over,
        Button_Clicked
    };

    virtual void draw();
    virtual void update();
    virtual void clear();
    virtual void load(const LoaderParams *params);

    void setCallback(void (*callback)());
    int getCallbackID() const;
private:
    void (*m_callback)();
    int m_callbackID;
    bool m_bRelease;
};

class MenuButtonCreator : public CreatorInterface
{
    GameObjectInterface *createGameObject() const;
};

#endif // MENUBUTTON_H
