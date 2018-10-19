// File: triLength.cpp
// Created by: Nicholas Shepard
// Created on: 5/25/18

/* Synopsis: This program reads in 3 double values (Side A & B of a triangle and the angle between them)
 * and outputs one value (The length of Side C)
 * */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // Variable Initialization/Declaration
    double sideA, sideB, sideC, angleDegrees, angleRadians;

    // User-Input
    cout << "Enter length of Side A: ";
    cin >> sideA;
    cout << "Enter length of Side B: ";
    cin >> sideB;
    cout << "Enter angle between sides A and B (degrees): ";
    cin >> angleDegrees;

    // Calculations
    angleRadians = (angleDegrees * M_PI)/180.0; // Converts the angle from degrees to radians.
    sideC = sqrt((pow(sideA, 2.0) + pow(sideB, 2.0)) - (2 * sideA * sideB) * cos(angleRadians)); // Calculates the length of Side C, using Law of Cosines

    // Output
    cout << "Length of Side C is " << sideC << "." << endl;
    return 0;
}