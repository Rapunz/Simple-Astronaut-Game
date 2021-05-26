#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <memory>
#include "Image_Sprite.h"

class Explosion : public engine::Image_Sprite, public std::enable_shared_from_this<Explosion>
{
public:
    static std::shared_ptr<Explosion> create(int x, int y, int w, int h, std::string file_path);

    void tick(engine::Game &game);

private:
    Explosion(int x, int y, int w, int h, std::string file_path);
    int count;
};

#endif