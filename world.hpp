#ifndef WORLD_HPP__
#define WORLD_HPP__

#include <list>
#include <SDL.h>

class World;

class WorldObject
{
public:
    WorldObject() {}
    virtual ~WorldObject() {}
    virtual bool run(World& world) { return true; }
};

class World
{
public:
    World();
    virtual ~World();
    void run();
    void addObject(WorldObject* obj) { stuff.push_back(obj); }

    void blit(SDL_Surface* s, SDL_Rect* loc) { SDL_BlitSurface(s, 0, screen, loc); } 

private:
    SDL_Window* window;
    SDL_Surface* screen;
    std::list<WorldObject*> stuff;
};

#endif
