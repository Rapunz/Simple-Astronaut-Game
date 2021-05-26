#ifndef BULLET_H
#define BULLET_H

#include <memory>
#include "Image_Sprite.h"

class Bullet : public engine::Image_Sprite, public std::enable_shared_from_this<Bullet>
{
public:
    static std::shared_ptr<Bullet> create(int x, int y, int w, int h, std::string file_path);
    void tick(engine::Game &game);

private:
    Bullet(int x, int y, int w, int h, std::string file_path);
};

#endif