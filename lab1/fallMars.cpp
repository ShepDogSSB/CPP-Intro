// File: fallMars.cpp
// Created by: Nicholas Shepard
// Created on: 5/16/18

/*
 * This program takes one input (in this case, time in seconds) and outputs two values, distance in meters (m) and
 * velocity in meters per second (m/s).
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Variable Initialization/Declaration
    const double g(3.73); // Gravitational Acceleration of Mars (m/s^2)
    double t(0.0), velocity(0.0), distance(0.0);

    // User-Defined Inputs
    cout << "Enter Time (t): ";
    cin >> t;

    // Calculations
    velocity = g * t;
    distance = (1.0 / 2.0) * velocity * t;

    // Outputs
    cout << "After " << t << " seconds, the velocity on mars is " << velocity << " meters per second." << endl;
    cout << "After " << t << " seconds, the falling distance on mars is " << distance << " meters." << endl;
    return 0;
}