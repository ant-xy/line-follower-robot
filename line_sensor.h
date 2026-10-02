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

        void refreshSensors() {
            L2 =  digitalRead(l2);
            L1 =  digitalRead(l1);
            M =   digitalRead(m);
            R1 =  digitalRead(r1);
            R2 =  digitalRead(r2);
        }

        int* sensor(int* arr) {
            L2 =  digitalRead(l2);
            L1 =  digitalRead(l1);
            M =   digitalRead(m);
            R1 =  digitalRead(r1);
            R2 =  digitalRead(r2);

            arr[0] = L2;
            arr[1] = L1;
            arr[2] = M;
            arr[3] = R1;
            arr[4] = R2;
            return arr;
        }

        int sensorEquals(int _l2, int _l1, int _m, int _r1, int _r2) {
            if (_l2 != L2) { return false; };
            if (_l1 != L1) { return false; };
            if (_m  !=  M) { return false; };
            if (_r1 != R1) { return false; };
            if (_r2 != R2) { return false; };
            return true;
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

        bool junctionDetected() {
            return (L2 == 0 && L1 == 0 && M == 0 && R1 == 0 && R2 == 0);
        }

        bool allSensorsTripped() {
            return (L2 == 0 && L1 == 0 && M == 0 && R1 == 0 && R2 == 0);
        }         

        bool junctionLeftBlack() {
            return (L2 == 0 || L1 == 0);
        }

        bool junctionLeftWhite() {
            return (L2 == 1 || L1 == 1);
        }

        bool junctionRight() {
            return (L2 == 1 && L1 == 1 && M == 1 && (R1 == 0 || R2 == 0));
        }
};

