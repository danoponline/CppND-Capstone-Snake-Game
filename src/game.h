#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "wall.h"
#include "bonus.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  bool isSnakeRunIntoWall(int x, int y);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Wall wall;
  SDL_Point food;
  Bonus bonus;
  std::size_t grid_width;
  std::size_t grid_height;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif