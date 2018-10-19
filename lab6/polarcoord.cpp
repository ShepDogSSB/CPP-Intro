/*
  File: polarcoord.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/20/18
  Synopsis: This program takes in the polar angle and the radius of a point in a circle, and converts the info into
  Cartesian coordinates (x, y).
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR degrees2radians
double degrees2radians(double angle_degrees);

// FUNCTION PROTOTYPE FOR compute_coord
double compute_coord(double radius, double angle_radians, double& coord_x, double& coord_y);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
  double angle_degrees(0.0), angle_radians(0.0), radius(0.0);
  double coord_x(0.0), coord_y(0.0);

  // Read in polar coordinates
  cout << "Enter radius: ";
  cin >> radius;

  cout << "Enter polar angle (degrees): ";
  cin >> angle_degrees;

  // Convert degrees to radians
  angle_radians = degrees2radians(angle_degrees);

  // Compute Cartesian (x,y) coordinates
  compute_coord(radius, angle_radians, coord_x, coord_y);

  // Output Cartesian coordinates
  cout << "Cartesian coordinates: ";
  cout << "(" << coord_x << "," << coord_y << ")" << endl;

  return 0;
}

// DEFINE FUNCTION degrees2radians here:
double degrees2radians(double angle_degrees){
    double radian_output(0.0);
    radian_output = (angle_degrees * M_PI)/180.0;
    return radian_output;
}

// DEFINE FUNCTION compute_coord here:
double compute_coord(double radius, double angle_radians, double& coord_x, double& coord_y){
    coord_x = radius * cos(angle_radians);
    coord_y = radius * sin(angle_radians);
    return 0;
}

