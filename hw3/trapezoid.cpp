/*
  File: trapezoid.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/11/18
  Synopsis: This program takes in two values (the number of symbols on the top row, and the number of rows), calculates
            the number of symbols on the bottom row and prints a neat inverted trapezoid.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Declare and initialize variables
  int ntop(0), nbottom(0);     // Top row size and bottom row size
  int nrows(0);				   // Total number of rows

  // Repeatedly prompt for top row size until valid value is entered
    while (ntop <= 0){ // While loop + if-statement check to see if integer is positive
        cout << "Enter size of top: ";
        cin >> ntop;
        if (ntop < 2){
            cout << "Size of top row must at least be two." << endl;
        }
    }
  
  // Prompt for total number of rows
    cout << "Enter number of rows: ";
    cin >> nrows;
  
  // Compute bottom row size
    nbottom = ntop/nrows;
  // Repeatedly prompt for total number of rows until valid value is entered
    while(nrows < 1 || nbottom < 2){
        cout << "Invalid number of rows." << endl;
        cout << "Enter number of rows: ";
        cin >> nrows;
        nbottom = ntop/nrows;
    }
    cout << endl;
  // Print the inverted trapezoid
  for(int i = 1; i <= nrows; i++){
      for(int blanks = 1; blanks < i; blanks++){
          cout << " ";
      }
      for(int at = 1; at <= ntop; at++){
          cout << "@";
      }
      ntop -= 2;
      cout << endl;
  }

  // end program
  return 0;
}
