#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "food.h"
#include "snake.h"
#include "wall.h"
// #include <unistd.h>
// #include <Windows.h>
// #include <conio.h>
#include <ctime>

int main() {

    //添加随机种子
    srand((unsigned int)time(NULL));

    //是否死亡标示
    bool isDead = false;

    char preKey = NULL;

    Wall wall;
    wall.initWall();

    Food food(wall);
    food.setFood();

    Snake snake(wall, food);
    snake.initSnake();

    // snake.move('w');
    // snake.move('w');
    // snake.move('a');

    wall.drawWall();

    //接受用户输入

    while (!isDead) {
        char key = getchar();

        //判断 如果是第一次按了 左键 才不能激活游戏
        // 判断 上一次 移动方向
        if (preKey == NULL && key == snake.LEFT) {
            continue;
        }

        do {
            if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
                //判断本次按键 是否与上次冲突
                if ((key == snake.LEFT && preKey == snake.RIGHT) || (key == snake.RIGHT && preKey == snake.LEFT) ||
                    (key == snake.UP && preKey == snake.DOWN) || (key == snake.DOWN && preKey == snake.UP)) {
                    key = preKey;
                } else {
                    preKey = key; //不是冲突按键  可以更新按键
                }

                if (snake.move(key) == true) {
                    //移动成功 代码
                    system("cls");
                    wall.drawWall();
                    usleep(100);
                } else {
                    isDead = true;
                    break;
                }
            } else {
                key = preKey; //强制将错误按键变为 上一次移动的方向
            }
        } while (!_kbhit()); //当没有键盘输入的时候 返回0
    }

    ////测试
    // wall.setWall(5, 4, '=');
    // wall.setWall(5, 5, '=');
    // wall.setWall(5, 6, '@');

    //

    // cout << wall.getWall(0, 0) << endl;
    // cout << wall.getWall(5, 4) << endl;
    // cout << wall.getWall(5, 6) << endl;
    // cout << wall.getWall(1, 1) << endl;

    // system("pause");
    return EXIT_SUCCESS;
}