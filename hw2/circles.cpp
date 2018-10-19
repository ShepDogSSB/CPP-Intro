/*
  File: circles.cpp
  Created by: Nicholas Shepard
  Created on: 5/30/18
  Synopsis: This program takes the X and Y positions of the center of circles A, B, C, and the radius of circles A, B,
            & C, and outputs the location of a given query point relative to the circles.
  Grade: 100%
*/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
    // Variable Initialization/Declaration
    double xA(0.0), xB(0.0), xC(0.0), yA(0.0), yB(0.0), yC(0.0);
    double radiusA(0.0), radiusB(0.0), radiusC(0.0), qX(0.0), qY(0.0), queryA(0.0), queryB(0.0), queryC(0.0);

    // User Inputs
    cout << "Enter the x and y coordinates of circle A (2 values): ";
    cin >> xA >> yA;
    cout << "Enter the radius of circle A: ";
    cin >> radiusA;

    cout << "Enter the x and y coordinates of circle B (2 values): ";
    cin >> xB >> yB;
    cout << "Enter the radius of circle B: ";
    cin >> radiusB;

    cout << "Enter the x and y coordinates of circle C (2 values): ";
    cin >> xC >> yC;
    cout << "Enter the radius of circle C: ";
    cin >> radiusC;

    cout << "Enter x and y coordinates of query point (2 values): ";
    cin >> qX >> qY;

    // Calculations
    queryA = sqrt(pow((qX - xA), 2.0) + pow((qY - yA), 2.0));
    queryB = sqrt(pow((qX - xB), 2.0) + pow((qY - yB), 2.0));
    queryC = sqrt(pow((qX - xC), 2.0) + pow((qY - yC), 2.0));

    // If statements/Output
    if (queryA <= radiusA && queryB <= radiusB && queryC <= radiusC)
    {
        cout << "Circles A, B, and C contain point (" << qX << ", " << qY << ").";
    }
    else if (queryA <= radiusA && queryB <= radiusB)
    {
        cout << "Circles A and B contain point (" << qX << ", " << qY << ").";
    }
    else if (queryA <= radiusA && queryC <= radiusC)
    {
        cout << "Circles A and C contain point (" << qX << ", " << qY << ").";
    }
    else if (queryB <= radiusB && queryC <= radiusC)
    {
        cout << "Circles B and C contain point (" << qX << ", " << qY << ").";
    }
    else if (queryA <= radiusA)
    {
        cout << "Circles A contains point (" << qX << ", " << qY << ").";
    }
    else if (queryB <= radiusB)
    {
        cout << "Circles B contains point (" << qX << ", " << qY << ").";
    }
    else if (queryC <= radiusC)
    {
        cout << "Circles C contains point (" << qX << ", " << qY << ").";
    }
    else
        {
        cout << "No circle contains point (" << qX << ", " << qY << ").";
    }

    return 0;
}