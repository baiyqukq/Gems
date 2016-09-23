#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H


#include <string>

class LoaderParams
{
public:
    LoaderParams(int x, int y,
                 int width, int height,
                 const std::string &textureID,
                 int frameCount = 1,
                 int callbackID = 0,
                 int animateSpeed = 0);

    int getX() const;
    int getY() const;

    int getWidth() const;
    int getHeight() const;

    std::string getTextureID() const;
    int getCallbackID() const;

    int getFrameCount() const;
private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    int m_frameCount;
    int m_callbackID;
    int m_animateSpeed;

    std::string m_textureID;
};

#endif // LOADERPARAMS_H
