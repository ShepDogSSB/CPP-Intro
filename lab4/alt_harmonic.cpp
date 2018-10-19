/*
  File: alt_harmonic.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/8/18
  Synopsis: This program takes in one value (n) and computes a alternating harmonic series that is designed to get
            as close as possible to the natural log of 2 as the input can. (Higher numbers of n = closer output to ln(2). )
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    int n(0);
    double sum(0.0);

    while (n <= 0){
        cout << "Enter n: ";
        cin >> n;
        if (n <= 0){
            cout << "Error! n must be greater than 1, please try again." << endl;
        }
    }
    for(int k = 1; k <= n; k++){
        sum += (pow(-1, k + 1))/k;
    }
    cout << "The alternating series converges to " << sum;
    return 0;
}