#include "StateParser.h"

#include <tinyxml.h>
#include <iostream>

#include "Objects/GameObjectInterface.h"
#include "Objects/CreatorInterface.h"
#include "Objects/GameObjectFactory.h"
#include "LoaderParams.h"
#include "TextureManager.h"

using namespace std;

StateParser::StateParser()
{
}

bool StateParser::parseState(const std::string &fileName, const std::string &stateID, std::vector<GameObjectInterface *> *gameObjects, std::vector<string> *textureIDs)
{
    cout << "Game State Parser begins to parse the state:" + stateID << endl;

    TiXmlDocument doc;

    if (!doc.LoadFile(fileName)) {
        cout << "Could not load file:" << fileName << endl;
        cout << doc.ErrorDesc() << endl;

        return false;
    }

    TiXmlElement *root = doc.RootElement();


    TiXmlElement *e_state = NULL;

    for (TiXmlElement* e = root->FirstChildElement();
         e != NULL;
         e = e->NextSiblingElement())
    {
        if (e->Attribute("name") == stateID) {
            e_state = e;
        }
    }

    if (!e_state)
        return false;

    const TiXmlElement *e_objects = NULL;

    for (TiXmlElement *e = e_state->FirstChildElement();
         e != NULL;
         e = e->NextSiblingElement())
    {
        if (e->Value() == string("objects"))
        {
            e_objects = e;
        }
    }

    const TiXmlElement *e_textures = NULL;
    for (TiXmlElement *e = e_state->FirstChildElement();
         e != NULL;
         e = e->NextSiblingElement())
    {
        if (e->Value() == string("textures"))
        {
            e_textures = e;
        }
    }

    if (e_objects) {
        parseObjects(e_objects, gameObjects);
    }

    if (e_textures) {
        parseTexture(e_textures, textureIDs);
    }

    return true;
}

void StateParser::parseObjects(const TiXmlElement *root, std::vector<GameObjectInterface *> *gameObjects)
{
    const TiXmlElement *e = root->FirstChildElement();

    while (e) {
        if (e->Value() == string("object")) {
            int x, y, width, height, frameCount, callbackID, animateSpeed;
            string textureID;

            e->Attribute("x", &x);
            e->Attribute("y", &y);
            e->Attribute("width", &width);
            e->Attribute("height", &height);
            textureID = e->Attribute("textureID");
            e->Attribute("frameCount", &frameCount);
            e->Attribute("callbackID", &callbackID);
            e->Attribute("animateSpeed", &animateSpeed);

            LoaderParams *params = new LoaderParams(x, y,
                                                    width, height,
                                                    textureID, frameCount,
                                                    callbackID,
                                                    animateSpeed);

            GameObjectInterface *gameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));

            if (gameObject) {
                gameObject->load(params);
                gameObjects->push_back(gameObject);
            }

        }

        e = e->NextSiblingElement();
    }
}

void StateParser::parseTexture(const TiXmlElement *root, std::vector<std::string> *textureIDs)
{
    const TiXmlElement *e = root->FirstChildElement();

    while (e) {
        if (e->Value() == string("texture")) {
            string href = e->Attribute("href");
            string id = e->Attribute("id");
            TheTextureManager::Instance()->load(href, id);
            textureIDs->push_back(id);
        }
        e = e->NextSiblingElement();
    }

}
