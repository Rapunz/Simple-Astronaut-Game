#include "Score.h"
#include "Game.h"
#include "End_Screen.h"

using namespace std;
using namespace engine;

shared_ptr<Score> Score::create(int x, int y, int w, int h)
{
    return shared_ptr<Score>(new Score(x, y, w, h));
}

void Score::tick(Game &game)
{
    if (game.getScore() < 0)
    {
        game.removeBackground();
        game.clear();
        game.add(End_Screen::create(100, 100, 700, 300, game.getMaxScore()));
    }
    else
    {
        setText(to_string(game.getScore()));
    }
}

Score::Score(int x, int y, int w, int h) : Text_Sprite(x, y, w, h, "0", {255, 0, 0}) {}