#include "tank.hpp"

Tank::Tank(int x, int y)
{
    tank = SDL_LoadBMP( "assets/small_tank.bmp" );
    if (!tank)
    {
        throw "Unable to load tank asset";
    }

    loc.x = x;
    loc.y = y;
}

Tank::~Tank()
{
    SDL_FreeSurface(tank);
}

bool Tank::run(World& world)
{
    if (loc.x < 1000)
    {
      loc.x++;
      loc.y++;
      world.blit(tank, &loc);

      return true;
    }

    return false;
}

