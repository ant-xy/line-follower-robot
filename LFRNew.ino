#include "line_sensor.h"
#include "movement.h"
#include "bindings.h"
#include "junction_count.h"

lfr lfrArray;

void setup() {
    Serial.begin(9600);
    lfrArray.setup_sensors();
}

int dir;

void loop() {
   
    int isJunction;
    isJunction = junctionCount(lfrArray);

    if (isJunction) {
      Serial.println("Junction was detected.");
      return 0;
    }

    int arr[5];
    int* result = lfrArray.sensor(arr);

    int res;
    res = move(result);

    if (res == 1) {
      return 0;
    }

    int sum = 0;

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

    if (result[0] == 1 && result[1] == 1 && result[2] == 1 && result[3] == 1 && result[4] == 1) {
      if (dir == -1) {
        sum = -1;
      }

      if (dir == 1) {
        sum = 1;
      }
    }

    int ls = 140;
    int rs = 145;
    
    if (sum > 0) {
      Serial.println("Sum: Turn Right");
      dir = 1;
      rightSharp(ls,rs);
      turnUntilMiddleTrips(lfrArray);
    }

    if (sum < 0) {
      Serial.println("Sum: Turn Left");
      dir = -1;
      leftSharp(ls,rs);
      turnUntilMiddleTrips(lfrArray);
    }

    if (sum == 0) {
      Serial.println("Sum: Forwards");
      forward(ls,rs);
    }
}
