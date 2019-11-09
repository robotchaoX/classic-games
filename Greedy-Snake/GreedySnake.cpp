#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "food.h"
#include "snak.h"
#include "wall.h"
// #include <Windows.h>
// #include <conio.h>
#include <ctime>

int main() {
    srand(unsigned int(time(NULL)));
    wall p1;
    food f1(p1);
    p1.init();
    snak s1(p1, f1);
    bool isDeath = false;
    char preKey = NULL;
    s1.initsnak();
    f1.setFood();
    p1.showwall();

    while (!isDeath) {
        char key = getchar();
        if (preKey == NULL && key == s1.LEFT && key) {
            continue;
        }
        do { //限制用户只能输入wsad四建
            if (key == s1.LEFT || key == s1.RIGHT || key == s1.UP || key == s1.DOWN) {
                if ((key == s1.LEFT && preKey == s1.RIGHT) || (key == s1.RIGHT && preKey == s1.LEFT) ||
                    (key == s1.DOWN && preKey == s1.UP) || (key == s1.UP && preKey == s1.DOWN)) {
                    key = preKey;
                } else {
                    preKey = key; //不是冲突按键
                }
                if (s1.movesnake(key)) {
                    system("cls");
                    p1.showwall();
                    sleep(100);
                } else {
                    isDeath = true;
                    break;
                }
            } else {
                key = preKey;
            }
        } while (!_kbhit()); //没有键盘输入的时候就返回零
    }

    // system("pause");
    return EXIT_SUCCESS;
}