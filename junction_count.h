void apply_case(int* junction, lfr lfrArray) {
    switch (*junction) {
        case 1: {rightSharp(0,0); turnJunctionCrossRight(lfrArray);};
        case 2: {rightSharp(0,0); turnJunctionCrossRight(lfrArray);};
        case 3: {rightSharp(0,0); turnJunctionCrossRight(lfrArray);};
        case 4: {rightSharp(0,0); turnJunctionCrossRight(lfrArray);};
        case 5: {rightSharp(0,0); turnJunctionCrossRight(lfrArray);};
        case 6: {rightSharp(0,0); turnJunctionCrossRight(lfrArray);};
    }
}

int junction { 0 };
bool prevBlack { false };

bool junctionCount(lfr lfrArray, settings carSettings) {
    if (lfrArray.junctionDetected()) {
      if (prevBlack == false) {
        prevBlack = true;
        Serial.println("JUNCTION COUNTED!");
        carSettings.junction++;
        Serial.println("JUNCTION SETTING:", carSettings.junction);
        apply_case(&carSettings.junction, lfrArray);
        carSettings.dir = 1;
        Serial.println(junction);
        return true;
      }
    }


    if (lfrArray.L2 == 1 && lfrArray.R2 == 1) {
      prevBlack = false;
    }
    return false;
}

