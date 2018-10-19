/*
  File: triangle.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/8/18
  Synopsis: This program takes one input (number of desired rows, n) and outputs a right triangle that outputs n
            row of digits, that resets back to 1 after n = 10 (Goes from 9, to 0, then back to one and repeats).
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    int row(1), numRows(0), col(1); // i = columns(inner), n = rows(outer)

    cout << "Number of rows (n): ";
    cin >> numRows;

    while(row <= numRows){
        col = 1;
        while(col <= row - 1){
            cout << (col % 10);
            col++;
        }
        cout << (row % 10) << endl;
        row++;
    }
    return 0;
}