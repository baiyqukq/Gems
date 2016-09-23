#include "LoaderParams.h"

LoaderParams::LoaderParams(int x, int y, int width, int height, const std::string &textureID, int frameCount, int callbackID, int animateSpeed)
    : m_x(x),
      m_y(y),
      m_width(width),
      m_height(height),
      m_frameCount(frameCount),
      m_callbackID(callbackID),
      m_animateSpeed(animateSpeed),
      m_textureID(textureID)
{
}

int LoaderParams::getX() const
{
    return m_x;
}

int LoaderParams::getY() const
{
    return m_y;
}

int LoaderParams::getWidth() const
{
    return m_width;
}

int LoaderParams::getHeight() const
{
    return m_height;
}

std::string LoaderParams::getTextureID() const
{
    return m_textureID;
}

int LoaderParams::getCallbackID() const
{
    return m_callbackID;
}

int LoaderParams::getFrameCount() const
{
    return m_frameCount;
}

