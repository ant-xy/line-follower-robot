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
    {leftSharp, 200, 255, {'b','w','w','w','w'}}, // left
    {leftSharp, 200, 255, {'b','b','w','w','w'}}, // left
    {leftSharp, 200, 255, {'b','b','b','w','w'}}, // left
    {leftSharp, 200, 255, {'b','b','b','b','w'}}, // left
    {leftSharp, 200, 255, {'w','w','b','w','w'}}, // front
};


//    {1, 2, "b","b","w","w","w"}; // left
//    {1, 2, "b","b","b","w","w"}; // left
//    {1, 2, "b","b","b","b","w"}; // left
//    {1, 2, "w","w","b","w","w"}; // front

