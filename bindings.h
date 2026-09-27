struct mapping {
    int (*func_ptr)(int, int);
    int l_speed;
    int r_speed;
    char map[5];
    void (*callback)();
};

const int inputs {9};

mapping mappings[inputs] = {
    {&forward, 200, 255, {'w','w','b','w','w'}}, // forwards
    
    {&leftSharp, 200, 255, {'b','w','x','w','w'}, &turnUntilMiddleTrips}, // left
    {&leftSharp, 200, 255, {'b','b','x','w','w'}, &turnUntilMiddleTrips}, // left
    {&leftSharp, 200, 255, {'b','b','x','b','w'}, &turnUntilMiddleTrips}, // left
    
    {&rightSharp, 200, 255, {'w','w','x','w','b'}, &turnUntilMiddleTrips}, // right
    {&rightSharp, 200, 255, {'w','w','x','b','b'}, &turnUntilMiddleTrips}, // right
    {&rightSharp, 200, 255, {'w','b','x','b','b'}, &turnUntilMiddleTrips}, // right
};

int equals(char* a, char* b) {
    for (int i = 0; i < 5; i++) {
        if (a[i] != b[i] && a[i] != 'x') {
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

int move(char* newArr) {
    //mapping testMap = mappings[0];
    //loop here, check map, call function here.
    //TODO REPEAT UNTIL MIDDLE
    //TODO JUNCTION COUNTING

    //char *tst = &(testMap.map[0]);
    //int l_speed = testMap.l_speed;
    //int r_speed = testMap.r_speed;

    //char newArr[5] = {0,0,0,0,1}; // sensor input array here.
    convertToWords(newArr);

    //std::cout << newArr << "\n";

    for (int i = 0; i <= inputs; i++) {
        mapping testMap = mappings[i];
        char *tst = &(testMap.map[0]);

        if (equals(tst, newArr)) {

            //std::cout << "EQUAL," << " CONDITION: "<< i << "\n";
            int l_speed = testMap.l_speed;
            int r_speed = testMap.r_speed;

            (*testMap.func_ptr)(l_speed, r_speed);

            if (testMap.callback) {
                (*testMap.callback)();
            }
        }
    }

    return 0;
}

