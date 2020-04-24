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
      grid_height(grid_height){}

void Wall::AddWall()
{
    if (wall_bodies.empty())
    {
        growingDirection = {1,0};
        wall_bodies.emplace_back(currentWallHead);
        return;
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

void Wall::AddWall(SDL_Point &point){
    wall_bodies.emplace_back(point);
}

bool Wall::WallCell(int x, int y){
    for (SDL_Point &point : wall_bodies){
        if (point.x == x && point.y == y){
            return true;
        }
    }
    return false;
}