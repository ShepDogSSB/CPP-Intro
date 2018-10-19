// File: fallDist.cpp
// Created by: Nicholas Shepard
// Created on: 5/18/18

/* Compute the distance an object falls */

#include <iostream>
using namespace std;

int main()
{
    double g = 9.81;        // 9.81 meters per second^2
    double t;               // time (in seconds)
    double velocity;        // velocity after time t
    double distance;        // distance after time t

    cout << "Enter the time: ";
    cin >> t;

    // Compute the velocity and distance
    velocity = g * t;
    distance = velocity * 0.5 * t;

    cout << "After " << t << " seconds, the velocity is " << velocity << " meters per second." << endl;
    cout << "After " << t << " seconds, the falling distance is " << distance << " meters." << endl;
    return 0;
}