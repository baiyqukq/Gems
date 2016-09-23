#include "SoundManager.h"

#include <SDL2/SDL_mixer.h>

#include <iostream>

using namespace std;

SoundManager *SoundManager::m_instance = NULL;

SoundManager::SoundManager()
{
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{
    Mix_CloseAudio();
}

bool SoundManager::load(std::string fileName, std::string id, SoundType type)
{
    if(type == SoundMusic)
    {
        Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
        if(pMusic == 0)
        {
            std::cout << "Could not load music: ERROR - "
                      << Mix_GetError() << std::endl;
            return false;
        }
        m_musicMap[id] = pMusic;
        return true;
    }
    else if(type == SoundSFX)
    {
        Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
        if(pChunk == 0)
        {
            std::cout << "Could not load SFX: ERROR - "
                      << Mix_GetError() << std::endl;
            return false;
        }
        m_sfxMap[id] = pChunk;
        return true;
    }
    return false;
}

void SoundManager::playSound(std::string id, int loop)
{
    Mix_PlayChannel(-1, m_sfxMap[id], loop);
}

void SoundManager::playMusic(std::string id, int loop)
{
    Mix_PlayMusic(m_musicMap[id], loop);
}

SoundManager *SoundManager::Instance()
{
    if (m_instance == NULL)
    {
        m_instance = new SoundManager();
    }

    return m_instance;
}

