#include "System.h"

#include <stdexcept>

using namespace std;

namespace engine
{
    System::System()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            throw runtime_error(string("Failure initializing SDL: ") + SDL_GetError());

        win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 700, SDL_WINDOW_SHOWN);
        if (win == nullptr)
            throw runtime_error(string("Failure creating window: ") + SDL_GetError());

        ren = SDL_CreateRenderer(win, -1, 0);
        if (ren == nullptr)
            throw runtime_error(string("Failure creating renderer: ") + SDL_GetError());
        if (TTF_Init() != 0)
            throw runtime_error(string("Failure initializing TTF: ") + SDL_GetError());
        font = TTF_OpenFont("media/DejaVuSans-Bold.ttf", 18);
        if(!font)
            throw runtime_error(string("Failure opening font: ") + SDL_GetError());
    }

    System::~System()
    {
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    void System::setWindowTitel(const std::string& title)
    {
        SDL_SetWindowTitle(win, title.c_str());

    }

    SDL_Renderer *System::getRenderer() const
    {
        return ren;
    }

    int System::getWindowWidth() const
    {
        int w, h;
        SDL_GetWindowSize(win, &w, &h);
        return w;
    }
    int System::getWindowHeight() const
    {
        int w, h;
        SDL_GetWindowSize(win, &w, &h);
        return h;
    }

    TTF_Font *System::get_font() const
    {
        return font;
    }

    System sys;
} // namespace engine