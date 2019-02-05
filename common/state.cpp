//
// Created by alex on 2/4/19.
//

#include <math.h>
#include "state.h"

using namespace std;

double state::timeUntil(state other) {
    return other.time - time;
}

double state::distanceTo(state other) {
    return sqrt((this.x - other.x)*(this.x - other.x) + (this.y - other.y)*(this.y - other.y));
}

double state::distanceTo(double other[3]) {
    return sqrt((this.x - other[0])*(this.x - other[0]) + (this.y - other[1])*(this.y - other[1]));
}

double state::headingTo(state other) {
    double dx = other.x - this.x;
    double dy = other.y - this.y;
    double h = atan2(dy, dx);
    if (h < 0) {
        return h + (2 * M_PI);
    }
    return h;
}

// TODO


bool state::collides(state other) {
    return false;
}

state *state::project(double time) {
    return nullptr;
}

bool state::collides(double *other) {
    return false;
}

bool state::isSamePosition(state other) {
    return false;
}

double *state::toArray() {
    return nullptr;
}

string state::toString() {
    return string();
}
