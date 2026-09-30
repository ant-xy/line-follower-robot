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
    Serial.println("For");
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, HIGH);
    digitalWrite(rf, HIGH);

    digitalWrite(lb, LOW);
    digitalWrite(rb, LOW);
}

void backwards(int l_speed, int r_speed = 255) {
    Serial.println("Back");
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, LOW);
    digitalWrite(rf, LOW);

    digitalWrite(lb, HIGH);
    digitalWrite(rb, HIGH);
}

void rightSharp(int l_speed, int r_speed = 255) {
    Serial.println("Right");
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, HIGH);
    digitalWrite(rf, LOW);

    digitalWrite(lb, LOW);
    digitalWrite(rb, HIGH);
}

void leftSharp(int l_speed, int r_speed = 255) {
    Serial.println("Left");
    changeSpeed(l_speed, r_speed);

    digitalWrite(lf, LOW);
    digitalWrite(rf, HIGH);

    digitalWrite(lb, HIGH);
    digitalWrite(rb, LOW);
}
int del = 40;

void right90(int l_speed, int r_speed = 255) {
    Serial.println("right 90 PLZZ");
    rightSharp(255, 0);
    delay(del);
}
void left90(int l_speed, int r_speed = 255) {
    Serial.println("left 90 PLZZ");
    leftSharp(0, 255);
    delay(del);
}



void turnUntilMiddleTrips(lfr lfrArray) {
    int x = 0;
    while (!lfrArray.middleSensorTripOnly() && x != 100 && !lfrArray.edgeMost()) {
        x++;
        int arr[5];
        int* result = lfrArray.sensor(arr);
    }
}

void turnUntilMiddleThreeTrips(lfr lfrArray) {
    delay(300);
    while (!lfrArray.middleThreeSensorTrip()) {
        int arr[5];
        int* result = lfrArray.sensor(arr);
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
