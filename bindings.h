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

int main() {
    mapping testMap = mappings[0];
    char arr[5] = {'b','w','w','w','w'};

    //loop here, check map, call function here.

    char *tst = &(testMap.map[0]);

    int l_speed = testMap.l_speed;
    int r_speed = testMap.r_speed;


    if (equals(tst, arr)) {
        std::cout << "EQUAL" << "\n";
    }

    for (int i = 1; i < 5; i++) {
        mapping testMap = mappings[i];
        char *tst = &(testMap.map[i]);

        if (equals(tst, arr)) {
            int l_speed = testMap.l_speed;
            int r_speed = testMap.r_speed;

            (*testMap.func_ptr)(l_speed, r_speed);
        }
    }

    std::cout << equals(tst, arr) << "\n";
    
    std::cout << l_speed << "\n";
    std::cout << r_speed << "\n";

    std::cout << *tst << "\n";
    std::cout << (*testMap.func_ptr)(200,200) << "\n";
    std::cout << tst << "\n";

    return 0;
}


//    {1, 2, "b","b","w","w","w"}; // left
//    {1, 2, "b","b","b","w","w"}; // left
//    {1, 2, "b","b","b","b","w"}; // left
//    {1, 2, "w","w","b","w","w"}; // front

