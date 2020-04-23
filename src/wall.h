#ifndef WALL_H
#define WALL_H

#include "SDL.h"
#include <vector>

class Wall
{
    public:
      Wall(std::size_t grid_width, std::size_t grid_height);
      std::vector<SDL_Point> GetWallBodies() const {return wall_bodies;}
      void AddWall();
      void AddWall(SDL_Point &point);
      bool WallCell(int x, int y);
    private:
      std::size_t grid_width;
      std::size_t grid_height;
      int growingDirection[2]{1,0};
      SDL_Point currentWallHead{0,0};
      std::vector<SDL_Point> wall_bodies{};

};

#endif