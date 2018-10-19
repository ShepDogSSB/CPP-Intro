/*
  File: bodes_law_template.cpp
  Created by: ??
  Creation Date: ??
  Synopsis:
	Computes the distances of planets Earth, Saturn, and Neptune from the sun in
	astronomical units, miles, and meters
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main()
{
	const double AU_TO_MILES(93000000);
	const double MILES_TO_METERS(1609.344);

	double dist_au_earth(0.0), dist_au_saturn(0.0), dist_au_neptune(0.0);
	double dist_miles_earth(0.0), dist_miles_saturn(0.0), dist_miles_neptune(0.0);
	double dist_meters_earth(0.0), dist_meters_saturn(0.0), dist_meters_neptune(0.0);
	
	 dist_au_earth = (4 + 3 * pow(2.0,(3-2)))/10;
	 dist_au_saturn = (4 + 3 * pow(2.0,(6-2)))/10;
	 dist_au_neptune = (4 + 3 * pow(2.0,(8-2)))/10;
	
	 dist_miles_earth = dist_au_earth * AU_TO_MILES;
	 dist_miles_saturn = dist_au_saturn * AU_TO_MILES;
	 dist_miles_neptune = dist_au_neptune * AU_TO_MILES;

	 dist_meters_earth = dist_miles_earth * MILES_TO_METERS;
	 dist_meters_saturn =  dist_miles_saturn * MILES_TO_METERS;
	 dist_meters_neptune =  dist_miles_neptune * MILES_TO_METERS;	
	
	cout << endl << "Planet  Astro Units (est.)  Miles (est.)  Meters (est.)" << endl ;
	cout << "-------------------------------------------------------" << endl;
	cout << left << setw(8) << "Earth" << setprecision(3) << fixed << right << setw(11) << dist_au_earth << scientific << setprecision(2) << setw(21) << dist_miles_earth << setprecision(3) << setw(15) << dist_meters_earth << fixed << endl;
	cout << left << setw(8) << "Saturn" << setprecision(3) << fixed << right << setw(11) << dist_au_saturn << scientific << setprecision(2) << setw(21) << dist_miles_saturn << setprecision(3) << setw(15) << dist_meters_saturn << fixed << endl;
	cout << left << setw(8) << "Neptune" << setprecision(3) << fixed << right << setw(11) << dist_au_neptune << scientific << setprecision(2) << setw(21) << dist_miles_neptune <<  setprecision(3) << setw(15) << dist_meters_neptune << fixed << endl;
	
	return 0;
}  
