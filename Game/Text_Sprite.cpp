#include "Text_Sprite.h"
#include "System.h"

#include <SDL_ttf.h>
#include <stdexcept>

using namespace std;

namespace engine
{
    Text_Sprite::~Text_Sprite()
    {
        SDL_DestroyTexture(texture);
    }

    Text_Sprite::Text_Sprite(int x, int y, int w, int h, const string &text, const SDL_Color &color) : Sprite(x, y, w, h), content(text), textColor(color)
    {
        SDL_Surface *surf = TTF_RenderText_Blended_Wrapped(sys.get_font(), text.c_str(), color, w);
        if (!surf)
            throw runtime_error(string("Failure creating textsurface: ") + SDL_GetError());

        texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
        SDL_FreeSurface(surf);
        if (!texture)
            throw runtime_error(string("Failure creating texture: ") + SDL_GetError());
    }

    void Text_Sprite::draw() const
    {
        SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRectangle());
    }

    string Text_Sprite::getText() const
    {
        return content;
    }

    void Text_Sprite::setText(const string &text)
    {
        if (text != content)
        {
            content = text;
            SDL_DestroyTexture(texture);
            SDL_Surface *surf = TTF_RenderText_Blended_Wrapped(sys.get_font(), text.c_str(), textColor, getRectangle().w);
            if (!surf)
                throw runtime_error(string("Failure creating textsurface: ") + SDL_GetError());

            texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
            SDL_FreeSurface(surf);
            if (!texture)
                throw runtime_error(string("Failure creating texture: ") + SDL_GetError());
        }
    }

} // namespace engine