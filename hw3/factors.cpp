/*
  File: factors.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/11/18
  Synopsis: This program reads in an positive integer (throws an error if it is 0 or negative) and outputs
            all the factors for that number.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

    // Variable Initialization & Declaration
    int x(0);

    // User-input
    while (x <= 0){ // While loop + if-statement check to see if integer is positive
        cout << "Enter integer: ";
        cin >> x;
        if (x <= 0){
            cout << "Number must be positive." << endl;
        }
    }

    // Output
    for(int row = 1; row <= x; row++){
        cout << row << ": 1"; // 1 is factor for everything, so it gets included in the first cout statement for simplicity
        for(int col = 2; col <= row; col++){ // Runs through the factors of x from 2 to row (skips 1 because 1 is always a factor)
            if(row % col == 0) { // Calculates factors using logic given in hw3 pdf.
                cout << ", " << col;
            }
        }
        cout << endl;
    }
    return 0;
}