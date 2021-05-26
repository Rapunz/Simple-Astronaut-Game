#ifndef PLANET_H
#define PLANET_H

#include <memory>
#include "Image_Sprite.h"

class Planet : public engine::Image_Sprite
{
public:
    static std::shared_ptr<Planet> create(int x, int y, int w, int h, int r, std::string file_path);

    void tick(engine::Game &game);

private:
    Planet(int centX, int centY, int w, int h, int r, std::string file_path);
    int radius, centerX, centerY;
    double angle;
    int speed;
    int count;
};

#endif