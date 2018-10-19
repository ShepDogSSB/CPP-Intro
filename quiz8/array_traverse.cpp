/*
  File: array_traverse.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/6/18
  Synopsis: This program reads in an array of ints from the user, displays it to the screen, and calculates the average of all the elements and the even values at or below the average.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE(10);
  
// Function prototypes
void read_list(int a[], int & num_elements); // This function reads in the array.
void print_array(const int a[], const int num_elements); // This function displays the array to the screen.
double compute_average(const int a[], const int num_elements); // This function computes the average from all the elements in the array.
void print_evens_below(const int a[], const int num_elements, const double val); // This function displays the even numbers below the average in the array.

int main()
{
  int num_elements(0);
  double avg(0.0);
  int array[SIZE];

  read_list(array, num_elements);
	
  if (num_elements > 0)
  {
	// Display original list
	cout << endl << "You entered the list:" << endl;
	print_array(array, num_elements);
	
	// Compute average
       	avg = compute_average(array, num_elements);
       	cout << "Average = " << avg << endl;
	
	// Display list values less than the average
       	cout << endl << "Even values at or below the average:" << endl; 
       	print_evens_below(array, num_elements, avg);
  }
  else {
	cout << "The list is empty." << endl;
  }
  
  return 0;
}

// INSERT FUNCTIONS HERE
void read_list(int a[], int& num_elements){
  int counter(0);
   cout << "Enter up to 10 positive numbers (ints) terminated by 0" << endl;
  while(counter < SIZE){
    cin >> a[counter];
    if(a[counter] == 0){
      break;
    }
    counter++;
    num_elements = counter;
  }
}

void print_array(const int a[], const int num_elements){
  for(int i = 0; i < num_elements; i++){
        if(i < num_elements){
	  cout << a[i] << " ";
	}
  }
  cout << endl;
}

double compute_average(const int a[], const int num_elements){
  double output_average(0.0), sum(0.0);
  for(int i = 0; i < num_elements; i++){
    sum += a[i];
  }
  output_average = double (sum/num_elements);
  return output_average;
}

void print_evens_below(const int a[], const int num_elements, const double val){
  for(int i = 0; i < num_elements; i++){
    if(a[i] % 2 == 0 && a[i] < val){
      cout << a[i] << " ";
    }
  }
  cout << endl;
}
