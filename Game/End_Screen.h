#ifndef END_SCREEN_H
#define END_SCREEN_H

#include <memory>
#include "Text_Sprite.h"

class End_Screen : public engine::Text_Sprite
{
public:
    static std::shared_ptr<End_Screen> create(int x, int y, int w, int h, int score);
    void tick(engine::Game &game);

private:
    End_Screen(int x, int y, int w, int h, int score);
};

#endif