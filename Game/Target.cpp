#include "Target.h"
#include "System.h"

using namespace std;
using namespace engine;

    shared_ptr<Target> Target::create(int x, int y, int w, int h, string file_path)
    {
        return shared_ptr<Target>(new Target(x, y, w, h, file_path));
    }

    void Target::tick(Game &game)
    {
        SDL_Rect rect = getRectangle();
        if (rect.y < 0 || rect.y > (sys.getWindowHeight() - rect.h))
        {
            up = !up;
        }

        up ? moveUp(1) : moveDown(1);
    }

    Target::Target(int x, int y, int w, int h, string file_path) : 
        Image_Sprite(x, y, w, h, file_path), up(false) {}
