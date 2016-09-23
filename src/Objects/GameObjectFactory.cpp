#include "GameObjectFactory.h"

#include "GameObjectInterface.h"
#include "CreatorInterface.h"

#include <iostream>

using namespace std;

GameObjectFactory *GameObjectFactory::m_instance = NULL;

GameObjectFactory *GameObjectFactory::Instance()
{
    if (!m_instance) {
        m_instance = new GameObjectFactory;
    }

    return m_instance;
}

bool GameObjectFactory::registerType(const string &typeID, CreatorInterface *creator)
{
    map<string, CreatorInterface*>::iterator i = m_creators.find(typeID);

    if (i != m_creators.end()) {
        delete creator;
        return false;
    }

    m_creators[typeID] = creator;

    return true;
}

GameObjectInterface *GameObjectFactory::create(const std::string &typeID)
{
    map<string, CreatorInterface *>::iterator i = m_creators.find(typeID);

    if (i == m_creators.end()) {
        cout << "Could not find type:" << typeID << endl;
        return NULL;
    }

    CreatorInterface *creator = (*i).second;
    return creator->createGameObject();
}

GameObjectFactory::GameObjectFactory()
{
}
