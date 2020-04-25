#include "wall.h"
#include <iostream>

// SDL Point Wrapper method implementation down here

SDL_Point_Wrapper::SDL_Point_Wrapper(SDL_Point const &obj){
    this->obj.x = obj.x;
    this->obj.y = obj.y;
}

SDL_Point_Wrapper::SDL_Point_Wrapper(int x, int y){
    obj.x = x;
    obj.y = y;
}

bool SDL_Point_Wrapper::operator==(SDL_Point const &obj) const
{
    return (obj.x == this->obj.x && obj.y == this->obj.y);
}

// Wall method implementation down here

Wall::Wall(std::size_t grid_width, std::size_t grid_height)
    : grid_width(grid_width),
      grid_height(grid_height),
      upperLeftCorner(0,0),
      upperRightCorner(static_cast<int>(grid_width-1),0),
      lowerLeftCorner(0,static_cast<int>(grid_height-1)),
      lowerRightCorner(static_cast<int>(grid_width-1),static_cast<int>(grid_height-1)){}

void Wall::AddWall()
{
    if (wall_bodies.empty())
    {
        //growingDirection = {1,0}; // by default this is set at the beginning of the game
        wall_bodies.emplace_back(currentWallHead);
        return;
    } else if (upperLeftCorner==wall_bodies.back())
    {
        growingDirection = {1,0};
    } else if (upperRightCorner==wall_bodies.back())
    {
        growingDirection = {0,1};
    } else if (lowerRightCorner==wall_bodies.back())
    {
        growingDirection = {-1,0};
    } else if (lowerLeftCorner==wall_bodies.back())
    {
        growingDirection = {0,-1};
    } else if (wall_bodies.size() >= 2*grid_width + 2* grid_height - 4){
        return;
    }
    currentWallHead.x += growingDirection[0];
    currentWallHead.y += growingDirection[1];
    wall_bodies.emplace_back(currentWallHead);

}

void Wall::AddWall(SDL_Point &point)
{
    wall_bodies.emplace_back(point);
}

void Wall::RemoveWall()
{
    wall_bodies.clear();
}

bool Wall::WallCell(int x, int y)
{
    for (SDL_Point &point : wall_bodies){
        if (point.x == x && point.y == y){
            return true;
        }
    }
    return false;
}

bool Wall::WallCell(SDL_Point &pt)
{
    for (SDL_Point &point : wall_bodies){
        if (point.x == pt.x && point.y == pt.y){
            return true;
        }
    }
    return false;
}