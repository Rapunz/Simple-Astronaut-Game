#ifndef TARGET_H
#define TARGET_H

#include <memory>
#include "Image_Sprite.h"

class Target : public engine::Image_Sprite
{
public:
    static std::shared_ptr<Target> create(int x, int y, int w, int h, std::string file_path);
    void tick(engine::Game &game);

private:
    Target(int x, int y, int w, int h, std::string file_path);
    bool up;
};

#endif