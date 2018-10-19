/*
  File: diag.cpp
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

  int numRows(0), row(1), col(1);
  
  cout << "Enter number of table rows: ";
  cin >> numRows;

  while (row <= numRows){
      while (col <= numRows - 1){
        cout << "#";
        col++;
    }
    cout << "x" << endl;
    row++;
    col = row;
  }
  return 0;
}
