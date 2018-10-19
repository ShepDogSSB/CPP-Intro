// File: position.cpp
// Created by: Nicholas Shepard
// Created on: 5/30/18

/* Synopsis: This program reads in 4 double or integer values (The x/y position of point 1, and the x/y positions of point two)
 * and outputs a string based on the relative location of the points (Ex. if one point is at (0,0) and another point is
 * at (0, 1), the program will tell that point 1 is to the right of point two).
 * */

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
    // Variable Initialization/Declaration
    double x1, x2, y1, y2;

    // User Inputs
    cout << "Enter coordinates of the first point (2 values): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of the second point (2 values): ";
    cin >> x2 >> y2;

    // If Statements/Output
    if (x1 < x2 && y1 < y2){
        cout << "Point (" << x1 << ", " << y1 << ") is left and below point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 < x2 && y1 > y2){
        cout << "Point (" << x1 << ", " << y1 << ") is left and above point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 < x2 && y1 == y2){
        cout << "Point (" << x1 << ", " << y1 << ") is left of point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 > x2 && y1 < y2){
        cout << "Point (" << x1 << ", " << y1 << ") is right and below point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 > x2 && y1 > y2){
        cout << "Point (" << x1 << ", " << y1 << ") is right and above point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 > x2 && y1 == y2){
        cout << "Point (" << x1 << ", " << y1 << ") is right of point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 == x2 && y1 < y2){
        cout << "Point (" << x1 << ", " << y1 << ") is below point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 == x2 && y1 > y2){
        cout << "Point (" << x1 << ", " << y1 << ") is above point (" << x2 << ", " << y2 << ").";
    }
    else if (x1 == x2 && y1 == y2){
        cout << "Point (" << x1 << ", " << y1 << ") equals point (" << x2 << ", " << y2 << ").";
    }

    return 0;
}