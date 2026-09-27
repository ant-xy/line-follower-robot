//#include ""

void apply_case(int* junction) {
    switch (junction) {
        case 1: sharpRight() break;
        case 2: sharpRight() break;
        case 3: sharpRight() break;
        case 4: sharpRight() break;
        case 5: sharpRight() break;
    }
}

int junction { 0 };
bool prevBlack { false };

void junctionCount(int lfrArray) {
    //if (lfrArray.allSensorsTripped()) {
    if (true) {
      //Serial.println(junction);
        std::cout << junction << "\n";
      if (prevBlack == false) {
        prevBlack = true;
        junction++;
      }
    }

    if (!lfrArray.allSensorsTripped()) {
      prevBlack = false;
    }
 
    apply_case(junction);
}

