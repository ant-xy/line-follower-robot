#include <iostream>
#include <string>
#include <cstring>

// using flags, where you can turn each 

int leftSharp(int x, int y) {
    std::cout << x << " | " << y;
    return x + y;
}

int rightSharp(int x, int y) {
    return 1;
}

int calc(int x[5]) {
    int sum = 0;
    if (x[0] == 1) {
        sum += 1;
    }
    if (x[1] == 1) {
        sum += 1;
    }
    // 0 is zero
    if (x[3] == 1) {
        sum -= 1;
    }
    if (x[4] == 1) {
        sum -= 1;
    }
    return sum;
}

//void move(char x[5]) {
//    std::cout << x;
//    if (strcmp(x, {'b','w','w','w','w'})) { leftSharp(200,255); };
//}

//mapping mappings[5] = {
    //{leftSharp, 200, 255, {'b','w','w','w','w'}}, // left
    //{leftSharp, 200, 255, {'b','b','w','w','w'}}, // left
    //{leftSharp, 200, 255, {'b','b','b','w','w'}}, // left
    //{leftSharp, 200, 255, {'b','b','b','b','w'}}, // left
    //{leftSharp, 200, 255, {'w','w','b','w','w'}}, // front
//};


//    {1, 2, "b","b","w","w","w"}; // left
//    {1, 2, "b","b","b","w","w"}; // left
//    {1, 2, "b","b","b","b","w"}; // left
//    {1, 2, "w","w","b","w","w"}; // front

