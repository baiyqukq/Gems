#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <map>
#include <string>
#include <SDL2/SDL_mixer.h>

enum SoundType
{
    SoundMusic = 0,
    SoundSFX = 1
};

/* The singleton class */

class SoundManager
{
public:
    bool load(std::string fileName, std::string id, SoundType type = SoundSFX);
    void playSound(std::string id, int loop);
    void playMusic(std::string id, int loop);
    static SoundManager* Instance();
private:
    SoundManager();
    SoundManager(const SoundManager&);
    SoundManager &operator=(const SoundManager&);
    ~SoundManager();
    static SoundManager* m_instance;
    std::map<std::string, Mix_Chunk*> m_sfxMap;
    std::map<std::string, Mix_Music*> m_musicMap;
};

typedef SoundManager TheSoundManager;

#endif // SOUNDMANAGER_H
