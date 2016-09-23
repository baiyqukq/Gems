#include "TextureManager.h"

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>

#include <iostream>

using namespace std;

TextureManager *TextureManager::m_Instance = NULL;

TextureManager::TextureManager()
{
    m_Renderer = NULL;
}

bool TextureManager::load(const string &fileName, const string &id)
{
    SDL_Surface *surface = IMG_Load(fileName.c_str());

    if (!surface) {
        cout << "Can not load image:" << fileName << endl;
        cout << SDL_GetError() <<  endl;
        return false;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        cout << "Can not create texture from surface" << endl;
        cout <<  SDL_GetError() << endl;
        return false;
    }

    m_TextureMap[id] = texture;
    return true;
}

void TextureManager::draw(const string &id, const SDL_Rect &destRect, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    if (m_TextureMap.count(id) <= 0) {
        cout << "Can find the texture with the id:" << id << endl;
        return;
    }

    SDL_Texture *texture = m_TextureMap[id];

    SDL_Rect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;

    SDL_QueryTexture(texture, NULL, NULL, &(srcRect.w), &(srcRect.h));

    SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(const string &id, int frameNum, const SDL_Rect &destRect, SDL_Renderer *renderder, SDL_RendererFlip flip)
{
    if (m_TextureMap.count(id) <= 0) {
        cout << "Can find the texture with the id:" << id << endl;
        return;
    }

    int textureWidth, textureHeight;

    SDL_QueryTexture(m_TextureMap[id], NULL, NULL, &textureWidth, &textureHeight);

    SDL_Rect srcRect;
    srcRect.x = destRect.w * frameNum;
    srcRect.y = 0;
    srcRect.w = destRect.w;
    srcRect.h = destRect.h;


    SDL_RenderCopyEx(m_Renderer,
                     m_TextureMap[id],
                     &srcRect,
                     &destRect,
                     0,
                     0,
                     flip);
}


void TextureManager::setRenderer(SDL_Renderer *renderer)
{
    m_Renderer = renderer;
}

void TextureManager::clearFromTextureMap(const string &textureID)
{
    /* This function enables us to clear only the textures from the current state,
     * not the entire texture map. */

    m_TextureMap.erase(textureID);
}

TextureManager *TextureManager::Instance()
{
    if (!m_Instance) {
        m_Instance = new TextureManager;
        return m_Instance;
    }

    return m_Instance;
}
