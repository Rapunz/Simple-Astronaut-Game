#include "Player.h"
#include "Game.h"
#include "System.h"
#include "Bullet.h"

using namespace std;
using namespace engine;

std::shared_ptr<Player> Player::create(int x, int y, int w, int h, std::string file_path)
{
    return std::shared_ptr<Player>(new Player(x, y, w, h, file_path));
}

void Player::keyDown(const SDL_Event &event, Game &game)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
        if (getRectangle().y > 0)
            moveUp(10);
        break;
    case SDLK_DOWN:
        if (getRectangle().y < (sys.getWindowHeight() - getRectangle().h))
            moveDown(10);
        break;
    case SDLK_SPACE:
        game.add(Bullet::create(getRectangle().x + getRectangle().w / 2, getRectangle().y + getRectangle().h / 2, 20, 20, "media/bullet.png"));
        break;
    }
}

Player::Player(int x, int y, int w, int h, std::string file_path) : Image_Sprite(x, y, w, h, file_path) {}
