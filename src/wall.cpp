#include "wall.h"
#include <iostream>

Wall::Wall(std::size_t grid_width, std::size_t grid_height)
    : grid_width(grid_width),
      grid_height(grid_height){}

void Wall::AddWall()
{
    if (wall_bodies.empty())
    {
        growingDirection[0] = 1;
        growingDirection[1] = 0;
        wall_bodies.emplace_back(currentWallHead);
        return;
    } else if (wall_bodies.size() == grid_width)
    {
        growingDirection[0] = 0;
        growingDirection[1] = 1;
    } else if (wall_bodies.size() == grid_width + grid_height - 1)
    {
        growingDirection[0] = -1;
        growingDirection[1] = 0;
    } else if (wall_bodies.size() == 2*grid_width + grid_height - 2){
        growingDirection[0] = 0;
        growingDirection[1] = -1;
    } else if (wall_bodies.size() >= 2*grid_width + 2* grid_height - 4){
        return;
    }
    currentWallHead.x += growingDirection[0];
    currentWallHead.y += growingDirection[1];
    wall_bodies.emplace_back(currentWallHead);

}

void Wall::AddWall(SDL_Point point){
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