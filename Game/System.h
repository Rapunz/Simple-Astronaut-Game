#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

namespace engine
{
    class System
    {
    public:
        System();
        ~System();
        void setWindowTitel(const std::string&);
        SDL_Renderer *getRenderer() const;
        int getWindowWidth() const;
        int getWindowHeight() const;
        TTF_Font *get_font() const;
    private:
        SDL_Window *win;
        SDL_Renderer *ren;
        TTF_Font *font;
    };

    extern System sys;

} // namespace engine

#endif