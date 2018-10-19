/*
  File: quadrants.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/1/18
  Synopsis: This program takes in two int values (x-value of a point and y-value of a point) and outputs the location of
            that point using if and else-if statements.
*/

#include <iostream>
using namespace std;

int main()
{
  // Variable declarations
  int pt_x(0), pt_y(0); // Point to classify - (x, y)

  // Prompt and read in point to classify
  cout << "Enter x-coordinate of point to classify: ";
  cin >> pt_x;
  cout << "Enter y-coordinate of point to classify: ";
  cin >> pt_y;

  // Classify point in the Cartesian plane
    if (pt_x > 0 && pt_y == 0){
        cout << "Point is on the +X axis.";
    }
    else if (pt_x == 0 && pt_y > 0){
        cout << "Point is on the +Y axis.";
    }
    else if (pt_x < 0 && pt_y == 0){
        cout << "Point is on the -X axis.";
    }
    else if (pt_x == 0 && pt_y < 0){
        cout << "Point is on the -Y axis.";
    }
    else if (pt_x > 0 && pt_y > 0){
        cout << "Point is in Quadrant I.";
    }
    else if (pt_x < 0 && pt_y > 0){
        cout << "Point is in Quadrant II.";
    }
    else if (pt_x < 0 && pt_y < 0){
        cout << "Point is in Quadrant III.";
    }
    else if (pt_x > 0 && pt_y < 0){
        cout << "Point is in Quadrant IV.";
    }else{
        cout << "Point is the origin.";
    }
    return 0;
}
