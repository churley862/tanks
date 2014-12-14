#include "world.hpp"

using namespace std;

World::World()
{
    SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow( "Tanks!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN );
    screen = SDL_GetWindowSurface(window);
    //screen =  SDL_SetVideoMode( 1024, 768, 32, SDL_SWSURFACE );
}

World::~World()
{
    SDL_Quit();
}

void World::run()
{
    bool running = true;

    while (running && stuff.size()) 
    {
        for (auto& thing : stuff) 
        {
          running &= thing->run(*this);
        }
        SDL_UpdateWindowSurface(window);
    }
}

