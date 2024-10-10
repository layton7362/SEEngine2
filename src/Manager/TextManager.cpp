
#include <Core/Log.hpp>
#include <glad/glad.h>
#include <Manager/TextManager.hpp>

TextManager::TextManager()
{
    init();
}

TextManager::~TextManager()
{
}

int TextManager::init()
{

    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        Log::error("ERROR::FREETYPE: Could not init FreeType Library");
        return -1;
    }

    FT_Face face;
    if (FT_New_Face(ft, "_res/fonts/arial.ttf", 0, &face))
    {
        Log::error("ERROR::FREETYPE: Failed to load font");
        return -1;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);
    if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
    {
        Log::error("ERROR::FREETYTPE: Failed to load Glyph");
        return -1;
    }
    loadCharacters(face);
    return 0;
}

int TextManager::loadCharacters(FT_Face face)
{

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

    for (unsigned char c = 0; c < 128; c++)
    {
        // load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        // generate texture
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer);
        // set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // now store character for later use
        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x};
        Characters.insert(std::pair<char, Character>(c, character));
    }
    return 0;
}
