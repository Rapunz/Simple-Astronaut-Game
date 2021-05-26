#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

#include "Sprite.h"

namespace engine
{
    class Game
    {
    public:
        static Game *create(const std::string &name, int fps);
        static void destroy();
        void setBackground(const std::string &file_path);
        void removeBackground();
        void run();
        void add(std::shared_ptr<Sprite> sprite);
        void remove(std::shared_ptr<Sprite> sprite);
        std::vector<std::shared_ptr<Sprite>> getCollisionsFor(std::shared_ptr<Sprite>) const;
        int getScore() const;
        int getMaxScore() const;
        void increaseScore(int i);
        void decreaseScore(int i);
        void quit();
        void clear();
    private:
        Game(const std::string &name, int fps);
        Game(const Game&) = delete;
        ~Game();
        const Game &operator=(const Game &) = delete;
        bool handleEvent(SDL_Event &event);
        void updateSprites();
        void render();

        static Game* game;

        std::string gameName;
        int fps;
        int score = 0;
        int maxScore = 0;
        bool running = true;
        SDL_Texture * background = nullptr;

        std::vector<std::shared_ptr<Sprite>> sprites;
        std::vector<std::shared_ptr<Sprite>> added;
        std::vector<std::shared_ptr<Sprite>> removed;
    };
} // namespace engine

#endif