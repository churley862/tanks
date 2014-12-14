#include "world.hpp"
#include "tank.hpp"

int main (int argc, char* args[])
{
    World world;
    world.addObject(new Tank);
    world.addObject(new Tank(50,50));
    world.run();

    return 0;
}

