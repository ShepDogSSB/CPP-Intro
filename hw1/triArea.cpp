// File: triArea.cpp
// Created by: Naeem Shareef
// Modified by: Nicholas Shepard
// Modified on: 5/14/18

// Grading: 100%

/* 
   A program to compute and output the area of three triangles:
   First triangle has base 1 and height 5; 
   Second triangle has base 4 and height 3; 
   Third triangle has base 3 and height 6.

   Each output should be on a separate line.
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double area;

  area = (1*5)/2.0;
  cout << "The area of a triangle with base 1 and height 5 is " << area << "." << endl;

  area = (4*3)/2.0;
  cout << "The area of a triangle with base 4 and height 3 is " << area << "." << endl;

  area = (3*6)/2.0;
  cout << "The area of a triangle with base 3 and height 6 is " << area << '.' << endl;

  return 0;
}
