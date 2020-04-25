#ifndef WALL_H
#define WALL_H

#include "SDL.h"
#include <vector>

// define call Wall here

class Wall
{
    public:
      Wall(std::size_t grid_width, std::size_t grid_height);
      std::vector<SDL_Point> GetWallBodies() const {return wall_bodies;}
      void AddWall();
      void AddWall(SDL_Point &point);
      void RemoveWall();
      bool WallCell(int x, int y);
      bool WallCell(SDL_Point &point);
    private:
      SDL_Point upperLeftCorner;
      SDL_Point upperRightCorner;
      SDL_Point lowerLeftCorner;
      SDL_Point lowerRightCorner;
      std::size_t grid_width;
      std::size_t grid_height;
      std::vector<int> growingDirection{1,0};
      SDL_Point currentWallHead{0,0};
      std::vector<SDL_Point> wall_bodies{};
};

#endif