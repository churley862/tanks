#ifndef TANK_HPP__
#define TANK_HPP__

#include "world.hpp"

class Tank : public WorldObject
{
public:
    Tank(int x=0, int y=0);
    virtual ~Tank();

    virtual bool run(World& world);

private:
    SDL_Surface* tank;
    SDL_Rect loc;
};

#endif
