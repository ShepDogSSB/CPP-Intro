/*
  File: harmonic.cpp
  Created by: ??
  Creation Date: ??
  Synopsis:
	??
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long sum(0);
  int n(0);

  cout << "Enter number of terms in the summation: ";
  cin >> n;
  
  int i(1);
  while (i <= n) 
  {
	sum += i * i * i;
	i++;
  }

  cout << "1^3 + 2^3 + 3^3 + ... + " 
       << n << "^3 = " << sum << endl;

  return 0;
}
