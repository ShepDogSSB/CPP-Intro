// File: power.cpp
// Created by:
// Modified by: ShepDog
// Modified on: 5/14/18

// Grade: 100%

/* A program to read in a floating point number x
   and compute sqrt(x), x^2, and x^3
   and output the solutions on separate lines.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double x, y;

  // Reads in variable x.
  cout << "Enter x (float): ";
  cin >> x;

  // Compute the sqrt of the input variable
  y = sqrt(x);

  // Output
  cout << "sqrt(x) = " << y << endl;
  cout << "x^2 = " << (pow(x, 2.0)) << endl;
  cout << "x^3 = " << (pow(x, 3.0)) << endl;

  return 0;
}
