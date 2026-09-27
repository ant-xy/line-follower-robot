void apply_case(int* junction, lfr lfrArray) {
    switch (*junction) {
        case 1: rightSharp(200,255); turnUntilMiddleTrips(lfrArray); break;
        case 2: rightSharp(200,255); turnUntilMiddleTrips(lfrArray); break;
        case 3: rightSharp(200,255); turnUntilMiddleTrips(lfrArray); break;
        case 4: rightSharp(200,255); turnUntilMiddleTrips(lfrArray); break;
    }
}

int junction { 0 };
bool prevBlack { false };

void junctionCount(lfr lfrArray) {
    if (lfrArray.allSensorsTripped()) {
      if (prevBlack == false) {
        prevBlack = true;
        junction++;
        apply_case(&junction, lfrArray);
        Serial.println(junction);
      }
    }

    if (!lfrArray.allSensorsTripped()) {
      prevBlack = false;
    }
}

