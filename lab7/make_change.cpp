/*
  File: make_change.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/27/18
  Synopsis: This program reads in an amount of money, then returns the amount of quarters, nickels, dimes and pennies
            that make up the amount of money given.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

// FUNCTION PROTOTYPE FOR read_change
double read_change(); // This function reads in the user input for the program to use.
// FUNCTION PROTOTYPE FOR convert2cents
int convert2cents(double dollars); // This function converts the dollar amount given (dollars) to change.
// FUNCTION PROTOTYPE FOR change_quarters
int change_quarters(int& cents); // This functions takes the cents given and calculates how many quarters you have.
// FUNCTION PROTOTYPE FOR change_dimes
int change_dimes(int& cents); // This function takes in the cents given and calculates how many dimes you have after calculating quarters.
// FUNCTION PROTOTYPE FOR change_nickels
int change_nickels(int& cents); // This function takes in the cents given and calculates how many nickels you have after calculating quarters & dimes.
// FUNCTION PROTOTYPE FOR write_change
void write_change(int quarters, int dimes, int nickels, int pennies); // This functions writes the output, formatted appropriately, to the screen

int main()
{
  double dollars(0.0);
  int cents(0), quarters(0), dimes(0), nickels(0), pennies(0);

  dollars = read_change();
  cents = convert2cents(dollars);

  cout << endl << "Making change for " << cents << " cents" << endl;

  quarters = change_quarters(cents);
  dimes = change_dimes(cents);
  nickels = change_nickels(cents);
  pennies = cents;
 
  write_change(quarters, dimes, nickels, pennies);

  return 0;
}

// DEFINE FUNCTION read_change HERE:
double read_change(){
    double dollars(0.0);
    cout << "Enter change in dollars ($): ";
    cin >> dollars;
    if(dollars < 0){
        cout << "Illegal negative value " << dollars << " for dollars." << endl;
        exit(0);
    }
    return dollars;
}
// DEFINE FUNCTION convert2cents HERE:
int convert2cents(double dollars){
    int cents(0), counter(0);
    while(counter < 2){
        cents = dollars *= 10;
        counter++;
    }
    return cents;
}
// DEFINE FUNCTION change_quarters HERE:
int change_quarters(int& cents){
    int numQuarters(0);
    numQuarters = cents/25;
    cents %= 25;
    return numQuarters;
}
// DEFINE FUNCTION change_dimes HERE:
int change_dimes(int& cents){
    int numDimes(0);
    numDimes = cents/10;
    cents %= 10;
    return numDimes;
}
// DEFINE FUNCTION change_nickels HERE:
int change_nickels(int& cents){
    int numNickels(0);
    numNickels = cents/5;
    cents %= 5;
    return numNickels;
}
// DEFINE FUNCTION write_change HERE:
void write_change(int quarters, int dimes, int nickels, int pennies){
    if(quarters > 0){
        cout << "Quarters: " << quarters << endl;
    }
    if(dimes > 0){
        cout << "Dimes: " << dimes << endl;
    }
    if(nickels > 0){
        cout << "Nickels: " << nickels << endl;
    }
    if(pennies > 0){
        cout << "Pennies: " << pennies << endl;
    }
}