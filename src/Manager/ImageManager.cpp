#include <Manager/ImageManager.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}

void ImageManager::load(const char *path)
{
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

    
}

template <typename T>
ResultInt<T> ImageManager::detectImage(void *Image)
{
    return {T(), ImageCode::NONE};
}
