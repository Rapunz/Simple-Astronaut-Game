#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "Image_Sprite.h"

class Player : public engine::Image_Sprite
{
public:
    static std::shared_ptr<Player> create(int x, int y, int w, int h, std::string file_path);

    void keyDown(const SDL_Event &event, engine::Game &game);

private:
    Player(int x, int y, int w, int h, std::string file_path);
};

#endif