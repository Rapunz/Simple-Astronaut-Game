#include "Game.h"
#include "System.h"

#include "Target.h"
#include "Planet.h"
#include "Player.h"
#include "Score.h"

using namespace engine;

int main(int argc, char *argv[])
{
    Game *game = Game::create("Astronaut", 100);
    game->setBackground("media/stars.jpg");
    game->add(Target::create(sys.getWindowWidth() - 80, 0, 70, 120, "media/spaceship.png"));
    game->add(Score::create(sys.getWindowWidth() / 2 - 50, 0, 100, 70));
    game->add(Player::create(70, sys.getWindowHeight() / 2, 120, 120, "media/astronout.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 90, 90, 450, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 80, 80, 350, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 70, 70, 450, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 70, 70, 550, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 90, 90, 350, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 80, 80, 550, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 70, 70, 450, "media/pluto.png"));
    game->add(Planet::create(sys.getWindowWidth(), sys.getWindowHeight() / 2, 70, 70, 550, "media/pluto.png"));


    game->run();

    Game::destroy();
    return 5;
}