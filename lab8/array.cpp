/*
  File: array.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/5/18
  Synopsis: This program reads in an array, prints it to the screen, finds the maximum value in the array and adds it to every element in the array, then prints the array back to the screen.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

void read_list(int array[], int& arraySize, const int ARRAY_SIZE_MAX); // This function reads in the array from the user.
void print_array(const int array[], const int arraySize); // This function prints the array to the screen.
int find_max(const int array[], const int arraySize); // This function finds the highest value in the array.
void array_add(int counter, int array[], int arraySize); // This function adds the maximum value to the array.

int main(){
    // Constant Variable Initializations/Declarations.
    const int ARRAY_SIZE_MAX(20);

    // Non-Constant Variable Initializations/Declarations.
    int numStorage[ARRAY_SIZE_MAX];
    int arraySize(0), counter(0);

    // User Input.
    read_list(numStorage, arraySize, ARRAY_SIZE_MAX);

    // Function Calls/Output.
    cout << "Original list (" << arraySize << " Values): " << endl;
    print_array(numStorage, arraySize);

    counter = find_max(numStorage, arraySize);
    array_add(counter, numStorage, arraySize);

    cout << "Modified list (" << arraySize << " Values): " << endl;
    print_array(numStorage, arraySize);
    return 0;
}

void read_list(int array[], int& arraySize, const int ARRAY_SIZE_MAX){
    int counter(0);
    cout << "Enter non-negative numbers (ints) terminated by -99" << endl;
    while(counter < ARRAY_SIZE_MAX){
        cin >> array[counter];
        if(counter == 0 && array[counter] == -99){
	  cout << endl << "The list is empty." << endl;
            exit(0);
        }
        else if(array[counter] == -99){
            break;
        }
        if(array[counter] < 0){
            array[counter] = 0;
            counter--;
        }
        counter++;
        arraySize = counter;
    }
}
void print_array(const int array[], const int arraySize){
    for(int i = 0; i < arraySize; i++){
        if(i < arraySize - 1){
            cout << array[i] << ", ";
        }else{
            cout << array[i] << ".";
        }
    }
    cout << endl;
}
int find_max(const int array[], const int arraySize){
    int max(0);
    for(int i = 0; i < arraySize; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    cout << endl << "The maximum value is " << max << "." << endl << endl;
    return max;
}
void array_add(int counter, int array[], int arraySize){
    for(int i = 0; i < arraySize; i++){
        array[i] += counter;
    }
}
