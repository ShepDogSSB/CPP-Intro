/*
  File: split.cpp // FIXME: NEEDS TESTING
  Created by: Nicholas Shepard
  Creation Date: 7/12/18
  Synopsis: This program reads in an array of numbers, and splits them up into their own array's based on whether the
            number in the array is negative or not. The program then prints the two new array's to the screen.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void count(int array[], const int numElements, int& posCount, int& negCount); // This function takes an array and the number of elements in that array, and counts the positive and negative numbers.
void split(int array[], const int numElements, int arrayNeg[], const int negCount, int arrayPos[], const int posCount); // This function takes in the array and its length and copies the negative and non-negative values into their own array's
void print_array(int array[], const int numElements); // This function prints the array's to the screen.

int main(){
    // Non-Constant Variable Initializations/Declarations
    int numElements(0), posCount(0), negCount(0);
    // User-Input
    cout << "Enter number of elements: ";
    cin >> numElements;
    int * array;
    array = new int[numElements];
    cout << "Enter list: " << endl;
    for(int i = 0; i < numElements; i++){
        cin >> array[i];
    }
    // Function calls & Additional Array Declarations.
    count(array, numElements, posCount, negCount);
    int * arrayNeg = new int[negCount];
    int * arrayPos = new int[posCount];
    split(array, numElements, arrayNeg, negCount, arrayPos, posCount);

    // Output & Memory Cleanup.
    cout << "Negative elements: " << endl;
    print_array(arrayNeg, negCount);
    cout << endl;
    cout << "Non-negative elements: " << endl;
    print_array(arrayPos, posCount);
    cout << endl;
    delete [] array;
    delete [] arrayNeg;
    delete [] arrayPos;
    return 0;
}
void count(int array[], const int numElements, int& posCount, int& negCount){
    for(int i = 0; i < numElements; i++){
        if(array[i] < 0) {
            negCount++;
        }else{
            posCount++;
        }
    }
}
void split(int array[], const int numElements, int arrayNeg[], const int negCount, int arrayPos[], const int posCount){
    int j(0), k(0);
    for(int i = 0; i < numElements; i++){
        if(array[i] < 0){
           while(j < negCount){
               arrayNeg[j] = array[i];
               j++;
               break;
           }
        }

        else if(array[i] >= 0){
            while(k < posCount){
                arrayPos[k] = array[i];
                k++;
                break;
            }
        }
    }
    if(j != negCount || k != posCount){
        cerr << "Error: array sizes not equal." << endl;
        exit(10);
    }
}
void print_array(int array[], const int numElements){
    for(int i = 0; i < numElements; i++){
        cout << " " << array[i];
    }
}