#include <iostream>

struct mapping {
    int (*func_ptr)(int, int);
    int l_speed;
    int r_speed;
    char map[5];
};

int leftSharp(int x, int y) {
    return x + y;
}

int rightSharp(int x, int y) {
    return 1;
}

mapping mappings[5] = {
    {&leftSharp, 200, 255, {'b','w','w','w','w'}}, // left
    {&leftSharp, 200, 255, {'b','b','w','w','w'}}, // left
    {&leftSharp, 200, 255, {'b','b','b','w','w'}}, // left
    {&leftSharp, 200, 255, {'b','b','b','b','w'}}, // left
    {&leftSharp, 200, 255, {'w','w','b','w','w'}}, // front
};

int equals(char* a, char* b) {
    for (int i = 1; i < 5; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void convertToWords(char* array) {
    for (int i = 0; i < 5; i++) {
        if (array[i] == 1) {
            array[i] = 'w';
        }
        else {
            array[i] = 'b';
        }
    }
}

int main() {
    mapping testMap = mappings[0];

    //loop here, check map, call function here.

    char *tst = &(testMap.map[0]);

    int l_speed = testMap.l_speed;
    int r_speed = testMap.r_speed;

    char newArr[5] = {1,1,0,1,1}; // sensor input array here.
    convertToWords(newArr);

    std::cout << newArr << "\n";

    for (int i = 0; i <= 5; i++) {
        mapping testMap = mappings[i];
        char *tst = &(testMap.map[0]);

        if (equals(tst, newArr)) {

            std::cout << "EQUAL," << " CONDITION: "<< i << "\n";
            int l_speed = testMap.l_speed;
            int r_speed = testMap.r_speed;

            (*testMap.func_ptr)(l_speed, r_speed);
        }
    }

    return 0;
}

