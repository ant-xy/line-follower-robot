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
    while (!lfrArray.middleSensorTrip()) {
        lfrArray.sensor();
    }
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
