#include "snak.h"

snak::snak(wall &mywall, food &myfood) : mywall(mywall), myfood(myfood) {
    this->head = NULL;
}
//初始化
void snak::initsnak() {
    destroysnak();
    addnode(5, 4);
    addnode(5, 5);
    addnode(5, 6);
}

//销毁
void snak::destroysnak() {
    point *pcur = NULL;
    while (head != NULL) {
        pcur = head->next;
        delete head;
        head = pcur;
    }
}

//添加节点
void snak::addnode(int x, int y) {
    point *newpoit = new point;
    newpoit->snakx = x;
    newpoit->snaky = y;
    newpoit->next = NULL;

    if (head != NULL) {
        mywall.getseat(head->snakx, head->snaky, '=');
    }

    newpoit->next = head;
    head = newpoit;
    mywall.getseat(head->snakx, head->snaky, '@');
}

//删除尾节点
void snak::delettepoint() {
    if (head != NULL && head->next != NULL) {
        point *pre = head;
        point *pcur = head->next;

        while (pcur->next != NULL) {
            pcur = pcur->next;
            pre = pre->next;
        }

        mywall.getseat(pcur->snakx, pcur->snaky, ' ');
        delete pcur;
        pcur = NULL;
        pre->next = NULL;
    }
}

bool snak::movesnake(char a) {
    int x = head->snakx;
    int y = head->snaky;
    switch (a) {
    case UP:
        x--;
        break;
    case DOWN:
        x++;
        break;
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    default:
        break;
    }
    //判断 如果是下一步碰到的是尾巴，不应该死亡
    point *pCur = head->next;
    point *pPre = head;

    while (pCur->next != NULL) {
        pPre = pPre->next;
        pCur = pCur->next;
    }
    if (pCur->snakx == x && pCur->snaky == y) {
        isRool = true;
    } else {
        //移动失败
        if (mywall.setplace(x, y) == '*' || mywall.setplace(x, y) == '=') {
            addnode(x, y);
            delettepoint();
            system("cls");
            mywall.showwall();
            cout << "GAME OVER!!" << endl;
            return false;
        }
    }

    //移动的两种情况
    //吃到事物
    if (mywall.setplace(x, y) == '#') {
        addnode(x, y);
        myfood.setFood();
    }
    //没有吃到食物
    else {
        addnode(x, y);
        delettepoint();
        if (isRool == true) {
            mywall.getseat(x, y, '@');
        }
    }

    return true;
}