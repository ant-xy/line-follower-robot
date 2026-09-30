struct mapping {
    int (*func_ptr)(int, int);
    int l_speed;
    int r_speed;
    char map[5];
    void (*callback)();
};

const int inputs {9};

int turn_low_l = 170;
int turn_low_r = 200;

int turn_med_l = 200;
int turn_med_r = 225;

int turn_hig_l = 225;
int turn_hig_r = 255;

mapping mappings[inputs] = {
    //{&forward, 150, 175, {'w','w','b','w','w'}}, // forwards
    
    //{&leftSharp,  turn_hig_l, turn_hig_r, {'b','w','w','w','w'}, &turnUntilMiddleThreeTrips}, // left, extreme turn
    //{&rightSharp, turn_hig_l, turn_hig_r, {'w','w','w','w','b'}, &turnUntilMiddleThreeTrips}, // right, extreme turn

    //{&leftSharp,  turn_med_l, turn_med_r, {'w','b','w','w','w'}, &turnUntilMiddleTrips}, // left, medium turn
    //{&rightSharp, turn_med_l, turn_med_r, {'w','w','w','b','w'}, &turnUntilMiddleTrips}, // right, medium turn
    
    {&left90,  turn_hig_l, turn_hig_r, {'b','b','b','w','w'}, &turnUntilMiddleTrips}, // left, high turn, till loose middle
    {&left90,  turn_hig_l, turn_hig_r, {'b','b','b','b','w'}, &turnUntilMiddleTrips}, // left, high turn, till loose middle
    {&right90, turn_hig_l, turn_hig_r, {'w','w','b','b','b'}, &turnUntilMiddleTrips}, // left, high turn, till loose middle
    {&right90, turn_hig_l, turn_hig_r, {'w','b','b','b','b'}, &turnUntilMiddleTrips}, // left, high turn, till loose middle
    //{&leftSharp, 150, 175, {'b','w','w','w','w'}, &turnUntilMiddleTrips}, // left
    //{&leftSharp, 150, 175, {'w','b','w','w','w'}, &turnUntilMiddleTrips}, // left
    //{&leftSharp, 150, 175, {'w','b','b','w','w'}, &turnUntilMiddleTrips}, // left
    
    //{&rightSharp, 150, 175, {'w','w','w','b','b'}, &turnUntilMiddleTrips}, // right
    //{&rightSharp, 150, 175, {'w','w','w','w','b'}, &turnUntilMiddleTrips}, // right
    //{&rightSharp, 150, 175, {'w','w','w','b','w'}, &turnUntilMiddleTrips}, // right
    //{&rightSharp, 150, 175, {'w','w','b','b','w'}, &turnUntilMiddleTrips}, // right
};

int equals(char* a, char* b) {
    for (int i = 0; i < 5; i++) {
        if (a[i] != b[i] && a[i] != 'x') {
            return false;
        }
    }
    return true;
}

char* convertToWords(int* array) {
    static char res[5];
    for (int i = 0; i < 5; i++) {
        if (array[i] == 1) {
            res[i] = 'w';
        }
        else {
            res[i] = 'b';
        }
    }
    return res;
}

int move(int* sensorData) {
    //mapping testMap = mappings[0];
    //loop here, check map, call function here.
    //TODO REPEAT UNTIL MIDDLE
    //TODO JUNCTION COUNTING

    //char *tst = &(testMap.map[0]);
    //int l_speed = testMap.l_speed;
    //int r_speed = testMap.r_speed;

    //char newArr[5] = {0,0,0,0,1}; // sensor input array here.
    char* result = convertToWords(sensorData);

    for (int i = 0; i<5; i++) {
        Serial.print(result[i]);
    }
    Serial.println("");

    

    //std::cout << newArr << "\n";

    for (int i = 0; i <= inputs; i++) {
        mapping testMap = mappings[i];
        char *tst = &(testMap.map[0]);

        if (equals(tst, result)) {

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

