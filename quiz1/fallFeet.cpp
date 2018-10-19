// File: fallFeet.cpp
// Created by: Nicholas Shepard
// Created on: 5/18/18

/* Compute the distance an object falls */

#include <iostream>
using namespace std;

int main() {
    double ratio = 3.28084; // Ratio of meters to feet
    double g = 9.81; // Gravitational Acceleration of Earth (9.81 meters per second^2)
    double distance, velocity, t; // velocity after time t, distance after time t, and t

    cout << "Enter the time: ";
    cin >> t;

    velocity = g * t * ratio;
    distance = (1.0/2.0) * velocity * t;

    cout << "After " << t << " seconds, the velocity is " << velocity << " feet per second." << endl;
    cout << "After " << t << " seconds, the falling distance is " << distance << " feet." << endl;
}