#ifndef BONUS_H
#define BONUS_H

#include "SDL.h"
#include <random>
#include <vector>

// This bonus class can place bonus object in the game and will remove some walls and slow down the snake

class Bonus
{
  public:
    Bonus(std::size_t _grid_width, std::size_t _grid_height);
    ~Bonus(){}
    void Spawn();
    void Kill();
    std::vector<SDL_Point> GetBonusPosition() const {return _position;}
    bool isBonusSpawned() const {return !_position.empty();}

  private:
    std::size_t _grid_width;
    std::size_t _grid_height;
    std::vector<SDL_Point> _position;
};
#endif