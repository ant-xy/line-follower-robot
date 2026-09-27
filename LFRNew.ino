#include "line_sensor.h"
#include "movement.h"
#include "bindings.h"
#include "junction_count.h"

lfr lfrArray;

int main() {
    junctionCount(lfrArray);
    move(lfrArray.sensor());
}
