//#include ""

void apply_case(int* junction) {
    switch (*junction) {
        case 1: rightSharp(200,255); break;
    }
}

int junction { 0 };
bool prevBlack { false };

void junctionCount(lfr lfrArray) {
    if (lfrArray.allSensorsTripped()) {
      Serial.println(junction);
      if (prevBlack == false) {
        prevBlack = true;
        junction++;
        apply_case(&junction);
      }
    }

    if (!lfrArray.allSensorsTripped()) {
      prevBlack = false;
    }
 
}

