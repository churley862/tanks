#include <list>
#include "SDL/SDL.h"

using namespace std;

class WorldObject
{
public:
    WorldObject() {}
    virtual ~WorldObject() {}

    virtual void run(SDL_Surface* screen) {}
};

class Tank : public WorldObject
{
public:
    Tank();
    virtual ~Tank();

    virtual void run(SDL_Surface* screen);

private:
    SDL_Surface* tank;
};

Tank::Tank()
{

}

Tank::~Tank()
{

}

void Tank::run(SDL_Surface* screen)
{

}

class World
{
    public:

    World();
    virtual ~World();
    void run();

    private:

    SDL_Surface* screen;
};

World::World()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen =  SDL_SetVideoMode( 1024, 768, 32, SDL_SWSURFACE );
}

World::~World()
{
    SDL_Quit();
}

void World::run()
{
    SDL_Rect loc;
    loc.h = 32;
    loc.w = 50;
    loc.x = 0;
    loc.y = 0;

    SDL_Surface* tank = SDL_LoadBMP( "small_tank.bmp" );
    if (!tank)
    {
        throw "Unable to load tank asset";
    }

    for (int p = 0; p < 100; ++p)
    {
      loc.x = p;
      loc.y = p;
      SDL_BlitSurface(tank,NULL,screen,&loc);
      SDL_Flip(screen);
      SDL_Delay(0);
    }

    SDL_FreeSurface(tank);

}

int main (int argc, char* args[])
{
    World world;
    world.run();

    return 0;
}

