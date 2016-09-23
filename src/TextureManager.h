#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>

#include <SDL2/SDL_render.h>

using namespace std;

class SDL_Rect;
class SDL_Renderer;
class SDL_Texture;

/* The singleton class */

class TextureManager
{
public:
    bool load(const string &fileName, const string &id);

    // draw the whole texture
    void draw(const string &id,
              const SDL_Rect &destRect,
              SDL_Renderer *renderer,
              SDL_RendererFlip flip = SDL_FLIP_NONE);
    // draw some frame in the texture
    void drawFrame(const string &id,
                   int frameNum,
                   const SDL_Rect &destRect,
                   SDL_Renderer *renderder,
                   SDL_RendererFlip flip = SDL_FLIP_NONE);
    void setRenderer(SDL_Renderer *renderer);

    void clearFromTextureMap(const std::string &textureID);

    static TextureManager *Instance();
private:
    TextureManager();
private:
    static TextureManager *m_Instance;
    SDL_Renderer *m_Renderer;
    map<string, SDL_Texture *> m_TextureMap;
};

typedef TextureManager TheTextureManager;

#endif // TEXTUREMANAGER_H
