#include "main.h"
#include "autonSets.hpp"

void skillsRoute() {
    resetCoords(0, 0, 0);
    // waitCallibrate();
    intake(127);
    baseTurn(90);
    waitBase(100000);
}
