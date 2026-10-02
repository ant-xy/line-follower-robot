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
    {&right90, turn_hig_l, turn_hig_r, {'w','w','b','b','b'}, &turnUntilMiddleTrips}, // left, high turn, till loose middle
    {&right90, turn_hig_l, turn_hig_r, {'w','b','b','b','b'}, &turnUntilMiddleTrips}, // left, high turn, till loose middle
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
    char* result = convertToWords(sensorData);

    for (int i = 0; i<5; i++) {
        Serial.print(result[i]);
    }

    for (int i = 0; i <= inputs; i++) {
        mapping testMap = mappings[i];
        char *tst = &(testMap.map[0]);

        if (equals(tst, result)) {

            int l_speed = testMap.l_speed;
            int r_speed = testMap.r_speed;

            Serial.println("Binding: Sequence matched!");

            (*testMap.func_ptr)(l_speed, r_speed);

            if (testMap.callback) {
                (*testMap.callback)();
            }
            return 1;
        }
    }

    return 0;
}

