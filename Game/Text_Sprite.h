#ifndef TEXT_SPRITE_H
#define TEXT_SPRITE_H

#include <SDL.h>
#include <string>

#include "Sprite.h"

namespace engine
{
    class Text_Sprite : public Sprite
    {
    public:
        ~Text_Sprite();
        void draw() const;
        std::string getText() const;
        void setText(const std::string &text);
        
    protected:
        Text_Sprite(int x, int y, int w, int h, const std::string &file_path, const SDL_Color &color);

    private:
        SDL_Texture * texture;
        std::string content;
        SDL_Color textColor;
        
    };
} // namespace engine

#endif