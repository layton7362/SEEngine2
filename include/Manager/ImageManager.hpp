#pragma once


#include <Structs.hpp>

using ImageResultCode = int;

class ImageExt
{
    inline static const char *JPEG = "jpeg";
    inline static const char *JPG = "jpg";
    inline static const char *BMP = "bmp";
    inline static const char *PNG = "png";
};

class ImageCode
{
    enum Type
    {
        NONE = 0,
        JPEG = 1,
        BMP = 2,
        PNG = 3,

    }
};

class ImageManager
{

public:
    ImageManager();
    virtual ~ImageManager() noexcept;

    void load(const char *path);

    template <typename T>
    ResultInt<T> detectImage(void *Image);
};
