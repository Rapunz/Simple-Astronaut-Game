#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

namespace engine
{
    class Game;
    class Sprite
    {
    public:
        virtual ~Sprite();
        virtual void tick(Game &game);
        virtual void draw() const;
        const SDL_Rect &getRectangle() const;
        virtual void mouseDown(const SDL_Event &, Game &game);
        virtual void mouseUp(const SDL_Event &, Game &game);
        virtual void keyDown(const SDL_Event &, Game &game);
        virtual void keyUp(const SDL_Event &, Game &game);
        void moveUp(int pixels);
        void moveDown(int pixels);
        void moveRight(int pixels);
        void moveLeft(int pixels);
        void setX(int pixels);
        void setY(int pixels);
        void increaseWidth(int pixels);
        void increaseHeight(int pixels);
        void decreaseWidth(int pixels);
        void decreaseHeight(int pixels);

    protected:
        Sprite(int x, int y, int w, int h);

    private:
        Sprite(const Sprite &) = delete;
        const Sprite &operator=(const Sprite &) = delete;

        SDL_Rect rect;
    };
} // namespace engine

#endif