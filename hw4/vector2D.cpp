/*
  File: vector2D.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/2/18
  Synopsis: This program takes in two vectors, and a scalar multiplier, then outputs various data using the information given by the user.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPSILON(1e-12);

// function prototypes

// ENTER FUNCTION PROTOTYPE FOR read_vector HERE.
void read_vector(const string& text, double& x, double& y); // This function takes in the user input for the program, except for scalar multiplier.
// ENTER FUNCTION PROTOTYPE FOR vector_length HERE.
double vector_length(double x, double y); // This function calculates the length between two vectors.
// ENTER FUNCTION PROTOTYPE FOR write_vector HERE.
void write_vector(const string& text, double x, double y); // This function writes to the screen a string, a vector and the length of the vector.
// ENTER FUNCTION PROTOTYPE FOR vector_add HERE.
void vector_add(double x1, double y1, double x2, double y2, double& x3, double& y3); // This function adds two vectors together and outputs the resulting vector.
// ENTER FUNCTION PROTOTYPE FOR vector_subtract HERE.
void vector_subtract(double x1, double y1, double x2, double y2, double& x3, double& y3); // This function subtracts two vectors together and outputs the resulting vector.
// ENTER FUNCTION PROTOTYPE FOR scalar_mult HERE.
void scalar_mult(double x1, double y1, double s, double& x2, double& y2); // This function multiplies a vector by a scalar multiplier and outputs the resulting vector.
// ENTER FUNCTION PROTOTYPE FOR normalize HERE.
void normalize(double& x, double& y); // This function normalizes the vector given to be used in the following function.
// ENTER FUNCTION PROTOTYPE FOR perpendicular HERE.
void perpendicular(double x1, double y1, double x2, double y2); // This function checks to see whether or not the two vectors given by the user are perpendicular or not.
// *** DO NOT CHANGE ANY CODE IN THE MAIN FUNCTION.
int main()
{
  double u1, v1;	// coordinates of first vector
  double u2, v2;	// coordinates of second vector
  double u3, v3;
  double scalar;

  read_vector("Enter first vector (2 floats): ", u1, v1);
  read_vector("Enter second vector (2 floats): ", u2, v2);
  
  cout << "Enter scalar multiplier: ";
  cin >> scalar;
  cout << endl;

  write_vector("First vector: ", u1, v1);
  write_vector("Second vector: ", u2, v2);

  cout << endl;
  
  vector_add(u1, v1, u2, v2, u3, v3);
  write_vector("Vector add: ", u3, v3);

  vector_subtract(u1, v1, u2, v2, u3, v3);
  write_vector("Vector subtract: ", u3, v3);

  scalar_mult(u1, v1, scalar, u3, v3);
  write_vector("Scalar multiplier: ", u3, v3);

  cout << endl;
  
  write_vector("First vector: ", u1, v1);
  write_vector("Second vector: ", u2, v2);
  perpendicular(u1, v1, u2, v2);
  
  return(0);
}

// DEFINE FUNCTION read_vector HERE.
void read_vector(const string& text, double& x, double& y){
    cout << text;
    cin >> x >> y;
}
// DEFINE FUNCTION vector_length HERE.
double vector_length(double x, double y){
    double output_length(0.0);
    output_length = sqrt(pow(x, 2.0) + pow(y, 2.0));
    return output_length;
}
// DEFINE FUNCTION write_vector HERE.
void write_vector(const string& text, double x, double y){
    cout << text << "(" << x << ", " << y << ") has length " << vector_length(x, y) << endl;
}
// DEFINE FUNCTION vector_add HERE.
void vector_add(double x1, double y1, double x2, double y2, double& x3, double& y3){
    x3 = x1 + x2;
    y3 = y1 + y2;
}
// DEFINE FUNCTION vector_subtract HERE.
void vector_subtract(double x1, double y1, double x2, double y2, double& x3, double& y3){
    x3 = x1 - x2;
    y3 = y1 - y2;
}
// DEFINE FUNCTION scalar_mult HERE.
void scalar_mult(double x1, double y1, double s, double& x2, double& y2){
    x2 = s * x1;
    y2 = s * y1;
}
// DEFINE FUNCTION normalize HERE.
void normalize(double& x, double& y){
    double a = vector_length(x, y);
    if(abs(a - 0) < EPSILON){
        x = 0;
        y = 0;
    }else{
        x = x/a;
        y = y/a;
    }
}
// DEFINE FUNCTION perpendicular HERE.
void perpendicular(double x1, double y1, double x2, double y2){
    normalize(x1, y1); // v1
    normalize(x2, y2); // v2

    double px1(-y1), py1(x1); // p1
    double px2(-px1), py2(-py1); // p2

    if((abs(x2 - px1) < EPSILON && abs(y2 - py1) < EPSILON) || (abs(x2 - px2) < EPSILON && abs(y2 - py2) < EPSILON)){
        cout << "Vectors are PERPENDICULAR." << endl;
    }else{
        cout << "Vectors are NOT PERPENDICULAR." << endl;
    }
}