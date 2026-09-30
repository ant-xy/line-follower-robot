#define l2  12
#define l1  11
#define m   10
#define r1  9
#define r2  8

// no sensor reading = 0_0_0_0_0

class lfr {
    public:
        int L2 =  digitalRead(l2);
        int L1 =  digitalRead(l1);
        int M =   digitalRead(m);
        int R1 =  digitalRead(r1);
        int R2 =  digitalRead(r2);

        void setup_sensors() {
            pinMode(l2, INPUT);
            pinMode(l1, INPUT);
            pinMode(m, INPUT);
            pinMode(r1, INPUT);
            pinMode(r2, INPUT);
        }

        int* sensor(int* arr) {
            L2 =  digitalRead(l2);
            L1 =  digitalRead(l1);
            M =   digitalRead(m);
            R1 =  digitalRead(r1);
            R2 =  digitalRead(r2);
            String a = String(L2) + " | " + String(L1) + " | " + String(M) + " | " + String(R1) + " | " + String(R2);
            arr[0] = L2;
            arr[1] = L1;
            arr[2] = M;
            arr[3] = R1;
            arr[4] = R2;
            return arr;
        }

        bool middleSensorTripOnly() {
            return (L2 == 1 && L1 == 1 && M == 0 && R1 == 1 && R2 == 1);
        }

        bool middleSensorTrip() {
            return (M == 0);
        }

        bool edgeMost() {
            return (R2 == 0 || L2 == 0);
        }

        bool middleThreeSensorTrip() {
            return (L1 == 0 || M == 0 || R1 == 0);
        }

        bool allSensorsTripped() {
            return (L2 == 0 && L1 == 0 && M == 0 && R1 == 0 && R2 == 0);
        }         
};

