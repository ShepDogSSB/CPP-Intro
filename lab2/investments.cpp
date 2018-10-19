// File: investments.cpp
// Created by: Nicholas Shepard
// Created on: 5/16/18

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // Variable Initialization/Declaration
    double investment(0.0), rateInterest(0.0) ,timeMonths(0.0), investmentFinal(0.0), profit(0.0), investmentCompound(0.0), profitCompound(0.0), profitDiff(0.0);
    const double E = 2.71828;

    // User-Input
    cout << "Enter initial investment (dollars):  ";
    cin >> investment;
    cout << "Enter the interest rate: ";
    cin >> rateInterest;
    cout << "Enter the time invested (in months): ";
    cin >> timeMonths;

    // Calculations
    investmentFinal = investment * pow(1 + (rateInterest/100),(timeMonths/12.0)); // Calculates final investment from annual interest
    profit = investmentFinal - investment; // Profit from investment from annual interest
    investmentCompound = investment * pow(E, ((rateInterest/100) * (timeMonths/12.0))); // Final value of investment compounded continuously.
    profitCompound = investmentCompound - investment; // Calculates profit from compound interest formula.
    profitDiff = abs(profitCompound - profit); // Calculates the difference in profit from annual and compound interest formulas.

    // Output
    cout << "Value of your investment compounded annually after " << (timeMonths/12.0) << " year(s) is " <<
         investmentFinal << " dollars." << endl << "Profit from your investment after " << (timeMonths/12.0) <<
         " year(s) is " << profit << " dollars." << endl << endl;
    cout << "Value of your investment continuously compounded after " << (timeMonths/12.0) << " year(s) is " <<
         investmentCompound << " dollars." << endl << "Profit from your investment after " << (timeMonths/12.0) <<
         " year(s) is " << profitCompound << " dollars." << endl << endl;
    cout << "The difference between both investments types is " << profitDiff << " dollars." << endl;
    return 0;
}