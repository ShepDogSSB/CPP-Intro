/*
  File: isprime.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/21/18
  Synopsis: This program takes in a range of numbers and outputs all prime numbers within the given range.
*/

#include <iostream>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPE FOR read_range
int read_range(int& imin, int& imax);

// FUNCTION PROTOTYPE FOR is_prime
int is_prime(int& j);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main()
{
  int imin(0), imax(0);

  // Read in range
  read_range(imin, imax);

  // Print prime numbers
  cout << "Primes:";
  for (int j = imin; j <= imax; j++) {
    if (is_prime(j)) 
      { 
        cout << "  " << j; 
      }
  }
  cout << endl;

  return 0;
}

// DEFINE FUNCTION read_range() HERE:
int read_range(int& imin, int& imax){
    cout << "Enter minimum and maximum: ";
    cin >> imin >> imax;
    while((imin < 2 || imax < 2) || (imin > imax)){
        cout << "Error. Minimum and maximum must be at least 2";
        cout << "Enter minimum and maximum: ";
        cin >> imin >> imax;
    }
}

// DEFINE FUNCTION is_prime() HERE:
int is_prime(int& j){
    int b;
    for(b = 2; b <= j - 1; b++){
        if(j % b == 0){
            return 0;
        }
    }
    return 1;
}