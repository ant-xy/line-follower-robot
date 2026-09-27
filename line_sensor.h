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

        int sensor() {
            L2 =  digitalRead(l2);
            L1 =  digitalRead(l1);
            M =   digitalRead(m);
            R1 =  digitalRead(r1);
            R2 =  digitalRead(r2);
            String a = String(L2) + " | " + String(L1) + " | " + String(M) + " | " + String(R1) + " | " + String(R2);
            int result[5] = {L2, L1, M, R1, R2};
            return result;
        }
            
        bool allSensorsTripped() {
            return (L2 == 0 && L1 == 0 && M == 0 && R1 == 0 && R2 == 0);
        }         
};

