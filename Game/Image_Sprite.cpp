#include "Image_Sprite.h"
#include "System.h"

#include <SDL_image.h>
#include <stdexcept>

using namespace std;

namespace engine
{
        Image_Sprite::~Image_Sprite()
        {
            SDL_DestroyTexture(texture);

        }

        Image_Sprite::Image_Sprite(int x, int y, int w, int h, const string &file_path) : Sprite (x,y,w,h), texture(IMG_LoadTexture(sys.getRenderer(), file_path.c_str()))
        {
            if (!texture)
                throw runtime_error(string("Failure creating texture: ") + SDL_GetError());
        }

        void Image_Sprite::draw() const
        {
            SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRectangle());
        }

} // namespace engine