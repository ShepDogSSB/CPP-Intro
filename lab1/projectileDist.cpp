// File: projectileDist.cpp
// Created by: Nicholas Shepard
// Created on: 5/16/18

/*
 * This program takes one user defined input ()
 */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // Variable Initialization/Declaration
    const double g(9.81); // Acceleration due to gravity on earth.
    double distance(0.0), velocity(0.0);

    // User-Defined Inputs
    cout << "Enter the initial velocity (meter/second): ";
    cin >> velocity;

    // Calculations/Output
    distance = (velocity * velocity)/g;
    cout << "Horizontal distance travelled is " << distance << " meters.";
    return 0;
}
