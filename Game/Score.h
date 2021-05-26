#ifndef SCORE_H
#define SCORE_H

#include <memory>
#include "Text_Sprite.h"

class Score : public engine::Text_Sprite
{
public:
    static std::shared_ptr<Score> create(int x, int y, int w, int h);
    void tick(engine::Game &game);

private:
    Score(int x, int y, int w, int h);
};

#endif