#include "line_sensor.h"
#include "movement.h"
#include "bindings.h"
#include "junction_count.h"

lfr lfrArray;

void setup() {
    Serial.begin(9600);
    lfrArray.setup_sensors();

    int arr[5];
    int* result = lfrArray.sensor(arr);

    //while (!(result[0] == 1 && result[1] == 1 && result[2] == 0 && result[3] == 1 && result[4] == 1)) { // old lfr
      //  delay(100);
     //   Serial.println("Waiting for line");
    //}
}

void loop() {
    int arr[5];
    int* result = lfrArray.sensor(arr);
    int sum = 0;
    move(result);

    //junctionCount(lfrArray);

    //test_movement();
    if (result[0] == 0) {
      sum--;
    }

    if (result[1] == 0) {
      sum--;
    }
    if (result[3] == 0) {
      sum++;
    }
    if (result[4] == 0) {
      sum++;
    }

    Serial.println(sum);

    if (sum > 0) {
      Serial.println("turn right");
      rightSharp(190,225);
      turnUntilMiddleTrips(lfrArray);
    }

    if (sum < 0) {
      Serial.println("turn left");
      leftSharp(190,225);
      turnUntilMiddleTrips(lfrArray);
    }
    if (sum == 0) {
      forward(175,200);
      Serial.println("forwards");
    }


}
