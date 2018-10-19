/*
  File: rootTable.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/13/18
  Synopsis: This program takes in three values (Number of roots the user desires to print, the number increment between
            the number of roots, and the precision of the numbers) and prints them into a neatly organized table.
*/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    // Non-Constant Variable Initializations/Declarations
    int numRoots(0), valIncrement(0), precision(0), counter(2);

    // User-Inputs
    cout << "Enter number of roots: ";
    cin >> numRoots;
    cout << "Enter value increment (integer): ";
    cin >> valIncrement;
    cout << "Enter precision: ";
    cin >> precision;

    // Logic Statements
    cout << "Value";
    for(int x = 2; x <= numRoots + 1; x++){                             // This for loop prints the header row for the table, thee loop starts at 2 in order to avoid printing "x^1/1".
        if(x > 9){                                                      // This if statement checks to see if the root is a double digit, and reduces the amount of space accordingly.
            cout << setw(precision - 1) << " " << "x^1/" << x;
        }else{
            cout << setw(precision) << " " << "x^1/" << x;
        }
    }

    for(int i = valIncrement; i <= 100; i = valIncrement + i){          // This for loop starts making the table, if i == 100
        cout << endl << setw(5) << i;                                   // then the first value needs to only have 2 spaces instead of 3,
        if(i == 100){
            for(int j = 2; j <= numRoots + 1; j++){                     // The line below prints out the root table.
                cout << setw(counter) << " " << setprecision(precision) << fixed << pow(double(i), (1 / double(j)));
                if(j <= 2){                                             // This if statement makes it work. Counter is initialized to 2
                    counter++;                                          // and will only increase by one, once, for the duration of the program.
                }
            }
        }else{                                                          // This else statement behaves exactly like the statement above
            for(int j = 2; j <= numRoots + 1; j++){                     // except that the amount of whitespace doesn't need to change.
                cout << setw(3) << " " << setprecision(precision) << fixed << pow(double(i), (1 / double(j)));
            }
        }
    }
    cout << endl;
    return 0;
}