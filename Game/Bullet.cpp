
#include "Bullet.h"
#include "Explosion.h"
#include "Planet.h"
#include "Target.h"
#include "System.h"
#include "Game.h"

using namespace std;
using namespace engine;

shared_ptr<Bullet> Bullet::create(int x, int y, int w, int h, string file_path)
{
    return shared_ptr<Bullet>(new Bullet(x, y, w, h, file_path));
}

void Bullet::tick(Game &game)
{
    SDL_Rect rect = getRectangle();
    if (rect.x >= sys.getWindowWidth())
    {
        game.remove(shared_from_this());
    }
    else
    {
        moveRight(10);

        vector<shared_ptr<Sprite>> collisions = game.getCollisionsFor(shared_from_this());
        for (auto s : collisions)
        {
            if (shared_ptr<Planet> p = dynamic_pointer_cast<Planet>(s))
            {
                game.decreaseScore(1);
                game.add(Explosion::create(getRectangle().x, getRectangle().y, getRectangle().w, getRectangle().h, "media/explosion.png"));
                game.remove(shared_from_this());
                return;
            }
            else if (shared_ptr<Target> p = dynamic_pointer_cast<Target>(s))
            {
                game.increaseScore(1);
                game.add(Explosion::create(getRectangle().x, getRectangle().y, getRectangle().w, getRectangle().h, "media/explosion.png"));
                game.remove(shared_from_this());
                return;
            }
        }
    }
}

Bullet::Bullet(int x, int y, int w, int h, string file_path) : Image_Sprite(x, y, w, h, file_path) {}