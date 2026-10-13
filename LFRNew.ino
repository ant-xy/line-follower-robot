#include "setting.h"
#include "line_sensor.h"
#include "movement.h"
#include "junction_count.h"

lfr lfrArray;
settings carSettings;

void setup() {
    Serial.begin(9600);
    lfrArray.setup_sensors();
}

// slight adjustments
int checkSum(int _l2, int _l1, int _m, int _r1, int _r2) {
  int sum = 0;
  if (_l2 == 0) {
    sum--;
  }
  if (_l1 == 0) {
    sum--;
  }
  if (_r1 == 0) {
    sum++;
  }
  if (_r2 == 0) {
    sum++;
  }
  return sum;
}

int ls = 120;
int rs = 155;

void loop() {
    lfrArray.refreshSensors();
    int L2 = lfrArray.L2;
    int L1 = lfrArray.L1;
    int M = lfrArray.M;
    int R1 = lfrArray.R1;
    int R2 = lfrArray.R2;

    // Junction Count: L2 and R2.
    Serial.println(String(L2)+String(L1)+String(M)+String(R1)+String(R2));
    int isJunction;
    isJunction = junctionCount(lfrArray, carSettings);
    
    if (L2 == 0 && L1 == 0) { // left 90
      carSettings.dir = -1;
      leftSharp(ls, rs);
      turnUntilMiddleTrips(lfrArray);
    }

    if (R1 == 0 && R2 == 0) { // right 90
      carSettings.dir = 1;
      rightSharp(ls, rs);
      turnUntilMiddleTrips(lfrArray);
    }

    int sum;

    if (L2 == 1 && L1 == 1 && M == 1 && R1 == 1 && R2 == 1) {
      sum = carSettings.dir;
    }
    else {
      sum = checkSum(L2, L1, M, R1, R2);
    }

    if (sum > 0) {
      carSettings.dir = 1;
      rightSharp(ls, rs);
      turnUntilMiddleTrips(lfrArray);
      return 0;
    }

    if (sum < 0) {
      carSettings.dir = -1;
      leftSharp(ls, rs);
      turnUntilMiddleTrips(lfrArray);
      return 0;
    }

    if (sum == 0) {
      forward(ls, rs);
    }
}
