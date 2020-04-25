#ifndef WALL_H
#define WALL_H

#include "SDL.h"
#include <vector>

// add this SDL Point Wrapper class so that we can use == operator on SDL_Point object

class SDL_Point_Wrapper
{
    public:
      // define constructor
      SDL_Point_Wrapper(SDL_Point const &obj);
      SDL_Point_Wrapper(int x, int y);

      // define operator==
      bool operator==(SDL_Point const &obj) const;

    private:
      SDL_Point obj;
};

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
      SDL_Point_Wrapper upperLeftCorner;
      SDL_Point_Wrapper upperRightCorner;
      SDL_Point_Wrapper lowerLeftCorner;
      SDL_Point_Wrapper lowerRightCorner;
      std::size_t grid_width;
      std::size_t grid_height;
      std::vector<int> growingDirection{1,0};
      SDL_Point currentWallHead{0,0};
      std::vector<SDL_Point> wall_bodies{};
};

#endif