#include "bonus.h"

Bonus::Bonus(std::size_t grid_width, std::size_t grid_height) : 
                _grid_width(grid_width),_grid_height(grid_height){}

void Bonus::Spawn()
{
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> random_w(0,static_cast<int>(_grid_width-1));
    std::uniform_int_distribution<int> random_h(0,static_cast<int>(_grid_height-1));
    int random_x = random_w(engine);
    int random_y = random_h(engine);
    SDL_Point position{random_x,random_y};
    _position.clear();
    _position.emplace_back(std::move(position));
    return;
}

void Bonus::Kill()
{
    _position.clear();
    return;
}

SDL_Point Bonus::GetBonusPosition() const
{
    SDL_Point point;
    point.x =_position.front().x;
    point.y = _position.front().y;
    return point;
}