#ifndef STATEPARSER_H
#define STATEPARSER_H


#include <string>
#include <vector>

class GameObjectInterface;
class TiXmlElement;

class StateParser
{
public:
    StateParser();

    bool parseState(const std::string &fileName,
                    const std::string &stateID,
                    std::vector<GameObjectInterface *> *gameObjects,
                    std::vector<std::string> *textureIDs);

private:
    void parseObjects(const TiXmlElement *root, std::vector<GameObjectInterface *> *gameObjects);
    void parseTexture(const TiXmlElement *root, std::vector<std::string> *textureIDs);
};

#endif // STATEPARSER_H
