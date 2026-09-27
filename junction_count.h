//#include ""

void apply_case(int* junction) {
    switch (*junction) {
        case 1: rightSharp(200,255); break;
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

    if (!true) {
      prevBlack = false;
    }
 
    apply_case(&junction);
}

