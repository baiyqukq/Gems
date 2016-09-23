#ifndef CREATORINTERFACE_H
#define CREATORINTERFACE_H

class GameObjectInterface;

class CreatorInterface
{
public:
    virtual ~CreatorInterface(){}
    virtual GameObjectInterface *createGameObject() const = 0;
};

#endif // CREATORINTERFACE_H
