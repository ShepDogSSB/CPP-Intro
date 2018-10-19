/*
  File: convert2seconds.cpp
  Created by: Nicholas Shepard
  Creation Date: 6/29/18
  Synopsis: This program reads Miliatry Time in hours, minutes, and seconds, and converts to total seconds.
*/

#include <cstdlib>
#include <iostream>

using namespace std;

const int SECONDS_AT_NOON(43200);

// FUNCTION PROTOTYPE FOR read_military_time
void read_military_time(int & hours, int & minutes, int & seconds);

// FUNCTION PROTOTYPE FOR convert2total_seconds
int convert2total_seconds(int hours, int minutes, int seconds);

// FUNCTION PROTOTYPE FOR write_ampm
void write_ampm(const int total_seconds);

int main()
{
  int hours, minutes, seconds;  // military time
  int total_seconds;           	// total seconds

  read_military_time(hours, minutes, seconds);
  total_seconds = convert2total_seconds(hours, minutes, seconds);
  write_ampm(total_seconds);

  return 0;
}

// DEFINE FUNCTION read_military_second HERE:
void read_military_time(int & hours, int & minutes, int & seconds) // This function reads in the MIlitary Time & checks if the value given is legal or not.
{
  cout << "Enter number of hours: ";
  cin >> hours;
  if(hours > 23){
    cout << "Illegal value " << hours << " for hours." << endl;
    exit(0);
  }
  cout << "Enter number of minutes: ";
  cin >> minutes;
    if(minutes > 59){
      cout << "Illegal value " << minutes << " for minutes." << endl;
    exit(0);
  }
  cout << "Enter number of seconds: ";
  cin >> seconds;
    if(hours > 59){
      cout << "Illegal value " << seconds << " for seconds." << endl;
    exit(0);
  }
}

// DEFINE FUNCTION convert2total_seconds HERE:
int convert2total_seconds(int hours, int minutes, int seconds) // This function takes the three values (hours, minutes, seconds) given above, converts them all to seconds and calculates the total number of seconds.
{
  int output_totalSeconds(0);
  output_totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
  return output_totalSeconds;
}

// DEFINE FUNCTION write_ampm HERE:
void write_ampm(const int total_seconds) // This function takes in the total amount of seconds (total_seconds), determines whether or not the time is in AM or PM.
{
  if(total_seconds < SECONDS_AT_NOON){
    cout << total_seconds << " seconds is AM" << endl;
  }else{
    cout << total_seconds <<  " seconds is PM" << endl;
  }
}
