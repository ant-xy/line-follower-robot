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

int dir;
void loop() {
    int arr[5];
    int* result = lfrArray.sensor(arr);
    int sum = 0;


    int res;
    res = move(result);
    //Serial.println(res + " HIIII");

    if (res) {
      return 0;
    }


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

    if (result[0] == 1 && result[1] == 1 && result[2] == 1 && result[3] == 1 && result[4] == 1) {
      if (dir == -1) {
        sum = -1;
      }

      if (dir == 1) {
        sum = 1;
      }
    }
    Serial.println(sum);

    int ls = 140;
    int rs = 145;

    Serial.println(dir + " hiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii");


    
    if (sum > 0) {
      Serial.println("turn right");
      rightSharp(ls,rs);
      
      dir = 1;

      turnUntilMiddleTrips(lfrArray);
    }

    if (sum < 0) {
      Serial.println("turn left");

      dir = -1;
      leftSharp(ls,rs);
      turnUntilMiddleTrips(lfrArray);
    }
    if (sum == 0) {
      forward(ls,rs);
      Serial.println("forwards");
    }


}
