#define _CRT_SECURE_NO_WARNINGS
#include "food.h"
#include "wall.h"
#include <iostream>
using namespace std;

class snak {
  public:
    enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

    snak(wall &mywall, food &myfood);

    struct point {
        int snakx;
        int snaky;
        point *next;
    };

    //初始化
    void initsnak();

    //销毁
    void destroysnak();

    //添加节点
    void addnode(int x, int y);
    //删除尾节点
    void delettepoint();
    //移动
    bool movesnake(char a);

    wall &mywall;
    point *head;
    food &myfood;
    bool isRool; //判断循环指示
};
