#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <string>
#include <map>

class CreatorInterface;

class GameObjectInterface;

class GameObjectFactory
{
public:
    static GameObjectFactory *Instance();

    bool registerType(const std::string &typeID, CreatorInterface *creator);
    GameObjectInterface *create(const std::string &typeID);
private:
    GameObjectFactory();
    static GameObjectFactory *m_instance;
    std::map<std::string, CreatorInterface *> m_creators;
};

#endif // GAMEOBJECTFACTORY_H
