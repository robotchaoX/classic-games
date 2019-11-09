#include "test.h"
#include <iostream>

int main(void) {
    add(1, 2);
    return 0;
}

void add(int a, int b) {
    cout << a + b << endl;
}