#include "Sprite.h"

namespace engine
{
    Sprite::Sprite(int x, int y, int w, int h) : rect{x, y, w, h} {}

    Sprite::~Sprite() {}

    void Sprite::tick(Game &game) {}

    void Sprite::draw() const {}

    const SDL_Rect &Sprite::getRectangle() const { return rect; }

    void Sprite::mouseDown(const SDL_Event &, Game &game){};
    void Sprite::mouseUp(const SDL_Event &, Game &game){};
    void Sprite::keyDown(const SDL_Event &, Game &game){};
    void Sprite::keyUp(const SDL_Event &, Game &game){};

    void Sprite::moveUp(int pixels) { rect.y -= pixels; }
    void Sprite::moveDown(int pixels) { rect.y += pixels; }
    void Sprite::moveRight(int pixels) { rect.x += pixels; }
    void Sprite::moveLeft(int pixels) { rect.x -= pixels; }

    void Sprite::setX(int pixels) { rect.x = pixels; }
    void Sprite::setY(int pixels) { rect.y = pixels; }

    void Sprite::increaseWidth(int pixels){rect.w += pixels;}
    void Sprite::increaseHeight(int pixels) {rect.h += pixels;}

    void Sprite::decreaseWidth(int pixels){rect.w -= pixels;}
    void Sprite::decreaseHeight(int pixels) {rect.h -= pixels;}

} // namespace engine