#include "Game.h"

#include <stdexcept>

#include "System.h"

using namespace std;

namespace engine
{
    Game *Game::game = nullptr;

    Game::Game(const string &name, int f) : gameName(name), fps(f)
    {
        sys.setWindowTitel(name);
    }

    Game::~Game()
    {
        if (background)
            SDL_DestroyTexture(background);
    }

    Game *Game::create(const string &name, int fps)
    {
        if (game)
            throw runtime_error("You can only create one game at a time");
        else
            game = new Game(name, fps);
        return game;
    }

    void Game::destroy()
    {
        delete game;
        game = nullptr;
    }

    void Game::setBackground(const string &file_path)
    {
        background = IMG_LoadTexture(sys.getRenderer(), file_path.c_str());
        if (!background)
            throw runtime_error(string("Failure creating texture: ") + SDL_GetError());
    }

        void Game::removeBackground()
    {
        if (background)
        {
            SDL_DestroyTexture(background);
            background=nullptr;
        }
    }

    void Game::run()
    {

        Uint32 tickInterval = 1000 / fps;
        while (running)
        {
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                running = handleEvent(event);
            }

            updateSprites();

            render();

            int delay = nextTick - SDL_GetTicks();
            if (delay > 0)
            {
                SDL_Delay(delay);
            }
        }
    }

    bool Game::handleEvent(SDL_Event &event)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            return false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            for (auto s : sprites)
            {
                s->mouseDown(event, *this);
            }
            break;
        case SDL_MOUSEBUTTONUP:
            for (auto s : sprites)
            {
                s->mouseUp(event, *this);
            }
            break;
        case SDL_KEYDOWN:
            for (auto s : sprites)
            {
                s->keyDown(event, *this);
            }
            break;
        case SDL_KEYUP:
            for (auto s : sprites)
            {
                s->keyUp(event, *this);
            }
            break;
        }
        return true;
    }

    void Game::updateSprites()
    {
        for (shared_ptr<Sprite> s : sprites)
            s->tick(*this);

        for (shared_ptr<Sprite> s : added)
            sprites.push_back(s);
        added.clear();

        for (shared_ptr<Sprite> s : removed)
            for (auto iter = sprites.begin(); iter != sprites.end();)
                if (*iter == s)
                {
                    iter = sprites.erase(iter);
                }
                else
                    iter++;
        removed.clear();
    }

    void Game::render()
    {
        SDL_RenderClear(sys.getRenderer());
        if(background)
        {
            SDL_RenderCopy(sys.getRenderer(), background, NULL, NULL);
        }
        
        for (shared_ptr<Sprite> s : sprites)
        {
            s->draw();
        }
        SDL_RenderPresent(sys.getRenderer());
    }

    void Game::add(shared_ptr<Sprite> sprite)
    {
        added.push_back(sprite);
    }

    void Game::remove(shared_ptr<Sprite> sprite)
    {
        removed.push_back(sprite);
    }

    vector<shared_ptr<Sprite>> Game::getCollisionsFor(shared_ptr<Sprite> sprite) const
    {
        vector<shared_ptr<Sprite>> collisions;
        for (auto other : sprites)
        {
            if (sprite != other && SDL_HasIntersection(&(sprite->getRectangle()), &(other->getRectangle())))
                collisions.push_back(other);
        }
        return collisions;
    }

    int Game::getScore() const
    {
        return score;
    }
    int Game::getMaxScore() const
    {
        return maxScore;
    }
    void Game::increaseScore(int i)
    {
        score += i;
        if (score > maxScore)
            maxScore = score;
    }
    void Game::decreaseScore(int i)
    {
        score -= i;
    }

    void Game::quit()
    {
        running = false;
    }

    void Game::clear()
    {
        removed = sprites;
    }
} // namespace engine