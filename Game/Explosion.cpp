#include "Explosion.h"
#include "Game.h"

using namespace std;
using namespace engine;

shared_ptr<Explosion> Explosion::create(int x, int y, int w, int h, string file_path)
{
    return shared_ptr<Explosion>(new Explosion(x, y, w, h, file_path));
}

void Explosion::tick(Game &game)
{
    if (count++ > 10)
    {
        game.remove(shared_from_this());
    }
    else
    {
        increaseHeight(10);
        increaseWidth(10);
    }
}

Explosion::Explosion(int x, int y, int w, int h, string file_path) : Image_Sprite(x, y, w, h, file_path), count(0) {}