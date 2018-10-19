/*
  File: degrees2radians.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/22/18
  Synopsis: This program reads in polar coordinates of a circle and computes the arc length from 0/360 degrees to the point/angle on the circle.
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR degrees2radians
double degrees2radians(double angle_degrees); // Takes in the angle given in degrees (angle_degrees) and converts it to radians.
// FUNCTION PROTOTYPE FOR compute_arc_length
double compute_arc_length(double radius, double angle_radians); // Takes in the angle given in radians (angle_radians) and the radius of the circle (radius), and computes the arc length desired. 
int main()
{
  // Declare and initialize your variables
  double radius, angle_degrees(0.0), angle_radians(0.0), arc_length;

  // Read in polar coordinates
  cout << "Enter radius: ";
  cin >> radius;

  cout << "Enter polar angle (degrees): ";
  cin >> angle_degrees;

  // Convert degrees to radians
  angle_radians = degrees2radians(angle_degrees);

  // Compute arc length
  arc_length = compute_arc_length(radius, angle_radians);

  // Output arc length
  cout << "The arc length is " << arc_length << endl;

  return 0;
}

// DEFINE FUNCTION degrees2radians here:
double degrees2radians(double angle_degrees){
  double output_radians(0.0);
  output_radians = angle_degrees *(M_PI/180.0);
  return output_radians;
}
// DEFINE FUNCTION compute_arc_length here:
double compute_arc_length(double radius, double angle_radians){
  double output_arc_length(0.0);
  output_arc_length = radius * angle_radians;
  return output_arc_length;
}
