//
// Created by alex on 2/4/19.
//

#include "common.h"
#include <string>

#ifndef ASV_STATE_H
#define ASV_STATE_H

/**
 * Represents a singular state of the ASV.
 */
class state {
public:
    double x, y, heading, speed, time;
    double collisionProbability;

    /**
     * Returns the time in seconds until state other.
     */
    double timeUntil(state other);

    /**
     * Returns the Euclidean distance in two dimensions (x,y).
     */
    double distanceTo(state other);

    double distanceTo(double other[3]);

    /**
     * Returns the heading towards the other state.
     */
     double headingTo(state other);

    /**
     * True iff other is within in the x and y directions.
     */
    bool collides(state other);

    bool collides(double other[3]);

    /**
     * Tests whether the states have same (x, y).
     */
    bool isSamePosition(state other);

    /**
     * Convert this state to a 3D vector (for Dubins functions).
     */
    double* toArray();

    /**
     * Create a string representation of the state.
     * Angle is turned back into heading.
     * @return a string representation of the state
     */
    std::string toString();

    /**
     * Projects a state to a specified time assuming constant speed and heading.
     * Creates a new state.
     *
     * Meant to be used with future times but should work either way.
     */
     state* project(double time);



};

#endif //ASV_STATE_H
