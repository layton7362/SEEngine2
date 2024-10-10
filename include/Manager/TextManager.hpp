#pragma once
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <Types.hpp>


struct Character {
    unsigned int TextureID;  // ID handle of the glyph texture
    ivec2   Size;       // Size of glyph
    ivec2   Bearing;    // Offset from baseline to left/top of glyph
    unsigned int Advance;    // Offset to advance to next glyph
};

std::map<char, Character> Characters;

class TextManager
{
    
public:
    TextManager();
    virtual ~TextManager() noexcept;

    int init();
    int loadCharacters(FT_Face face);
};
// TODO
// TextManager m;