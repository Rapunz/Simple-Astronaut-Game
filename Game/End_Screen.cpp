#include "End_Screen.h"
#include "Game.h"

using namespace std;
using namespace engine;

shared_ptr<End_Screen> End_Screen::create(int x, int y, int w, int h, int score)
    {
        return shared_ptr<End_Screen>(new End_Screen(x, y, w, h, score));
    }

    void End_Screen::tick(Game &game)
    {
        bool quit = false;
        while (!quit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT || event.type == SDL_MOUSEBUTTONDOWN)
                {
                    quit = true;
                    game.quit();
                }
            }
        }
    }


    End_Screen::End_Screen(int x, int y, int w, int h, int score) : Text_Sprite(x, y, w, h, "Sorry you lost\nYour max score was " + to_string(score) + "\nThank you for playing\nPress anywhere to quit", {255, 0, 0}) {}
