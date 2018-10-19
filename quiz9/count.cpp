/*
  File: count.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/13/18
  Synopsis: This program counts the # of 0's and positive integers from an array. The elements in the array and the size of the array are specified by the user.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

// FUNCTION PROTOTYPES
void get_list(int list[], int size);
int count_pos(const int list[], int size);
int count_zeros(const int list[], int size);

int main()
{
  int length;
  int num_pos, num_zeros;
  int * list;

  // Prompt and read number of elements from the user into the variable length
  cout << "Enter number of elements: ";
  cin >> length;
  
  // Create a new array (dynamically allocate) of size length and assign it to variable list
  list = new int[length];

  // Prompt and read the elements from the user. Call the function get_list
  get_list(list, length);
  
  // Count the number of positive numbers in the list. Call the function count_pos. Use variable num_pos
  num_pos =  count_pos(list, length);
  
  // Count the number of zeros in the list. Call the function count_zeros. Use variable num_zeros
  num_zeros = count_zeros(list, length);
  
  // Display number of positive elements
  cout << "Number of positive element: " << num_pos << endl;
  
  // Display number of zeros
  cout << "Number of zero elements: " << num_zeros << endl;
  
  // De-allocate the list
    delete [] list;
  
  return 0;
}

// FUNCTION DEFINTIONS GO HERE
void get_list(int list[], int size){ // This function takes in the array (list) and the length of the array (size) and prompts the user to enter integers into the list from the list[0] to list[size - 1].
  cout << "Enter list: " << endl;
  for(int i = 0; i < size; i++){
    cin >> list[i];
  }
}

int count_pos(const int list[], int size){ // This function takes in the array (list) and the length of the array (size) and counts/outputs the amount of positive integers in the list (output_posCount). 
  int output_posCount(0);
  for(int i = 0; i < size; i++){
    if(list[i] > 0){
      output_posCount++;
    }
  }
  return output_posCount;
}

int count_zeros(const int list[], int size){ // This function takes in the array (list) and the length of the array (size) and counts/outputs the amount of zeros in the list (output_zeroCount). 
   int output_zeroCount(0);
  for(int i = 0; i < size; i++){
    if(list[i] == 0){
      output_zeroCount++;
    }
  }
  return output_zeroCount;
}
