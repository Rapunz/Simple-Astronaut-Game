#include "Planet.h"
using namespace engine;
using namespace std;
shared_ptr<Planet> Planet::create(int x, int y, int w, int h, int r, string file_path)
{
    return shared_ptr<Planet>(new Planet(x, y, w, h, r, file_path));
}

void Planet::tick(Game &game)
{

    angle += speed * 0.001;
    count++;
    if (count % 1000 == 0)
        speed++;
    setX(centerX + radius * cos(angle) - getRectangle().w / 2);
    setY(centerY + radius * sin(angle) - getRectangle().h / 2);
}

Planet::Planet(int centX, int centY, int w, int h, int r, string file_path) : Image_Sprite(0, 0, w, h, file_path), radius(r), centerX(centX), centerY(centY),
                                                                                   angle((rand() % 628) / 100.0), speed((rand() % 9) + 1), count(0)
{
    setX(centerX + radius * cos(angle) - getRectangle().w / 2);
    setY(centerY + radius * sin(angle) - getRectangle().h / 2);
}