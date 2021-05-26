#ifndef IMAGE_SPRITE_H
#define IMAGE_SPRITE_H

#include <SDL.h>
#include <string>

#include "Sprite.h"

namespace engine
{
    class Image_Sprite : public Sprite
    {
    public:
        ~Image_Sprite();
        void draw() const;
        
    protected:
        Image_Sprite(int x, int y, int w, int h, const std::string &file_path);

    private:
        SDL_Texture * texture;
        
    };
} // namespace engine

#endif