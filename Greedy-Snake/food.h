#pragma once
#include "wall.h"
#include <iostream>
using namespace std;

class Food {
  public:
    Food(Wall &tempWall);

    //设置食物
    void setFood();

    int foodX;
    int foodY;

    Wall &wall;
};
