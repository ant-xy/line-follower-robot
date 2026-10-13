#define r_en 3
#define l_en 5

#define lf 2
#define lb 4

#define rf 7
#define rb 6

void changeSpeed(int l_speed, int r_speed = 255) {
    analogWrite(r_en, r_speed);
    analogWrite(l_en, l_speed);
}

void stop() {
  changeSpeed(0, 0);
  digitalWrite(lf, LOW);
  digitalWrite(rf, LOW);

  digitalWrite(lb, LOW);
  digitalWrite(rb, LOW);
}

void forward(int l_speed, int r_speed = 255) {
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, HIGH);
    digitalWrite(rf, HIGH);

    digitalWrite(lb, LOW);
    digitalWrite(rb, LOW);
}

void backwards(int l_speed, int r_speed = 255) {
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, LOW);
    digitalWrite(rf, LOW);

    digitalWrite(lb, HIGH);
    digitalWrite(rb, HIGH);
}

void rightSharp(int l_speed, int r_speed = 255) {
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, HIGH);
    digitalWrite(rf, LOW);

    digitalWrite(lb, LOW);
    digitalWrite(rb, HIGH);
}

void leftSharp(int l_speed, int r_speed = 255) {
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, LOW);
    digitalWrite(rf, HIGH);

    digitalWrite(lb, HIGH);
    digitalWrite(rb, LOW);
}

void turnUntilMiddleTrips(lfr lfrArray) {
    int x = 0;
    Serial.println("Turn: Waiting for exclusively middle sensor trip");
    while (!lfrArray.middleSensorTripOnly()) {
        if (!lfrArray.L2 == 0 && !lfrArray.R2 == 0) {
            break;
        }
        lfrArray.refreshSensors();
    }
}

void turnJunctionCrossRight(lfr lfrArray) {
    Serial.println("Junction detected");
    while (lfrArray.junctionDetected()) {
        lfrArray.refreshSensors();
        forward(140,130);
    }
    int _R1 = 1;
    int _R2 = 1;
    lfrArray.refreshSensors();
    while (_R2 == 1) {
        Serial.println("R2 NOT BLACK!");
        _R2 = lfrArray.R2;
        rightSharp(150, 165);
        lfrArray.refreshSensors();
    }
    while (_R1 == 1) {
        Serial.println("R1 NOT BLACK!");
        _R1 = lfrArray.R1;
        rightSharp(150, 165);
        lfrArray.refreshSensors();
    }
    Serial.println("JUNCTION FINISHED");
}

void test_movement() {
    forward(230, 255);
    delay(1000);
    backwards(255);
    delay(1000);
    leftSharp(255);
    delay(1360);
    rightSharp(255);
    delay(1360);
}
