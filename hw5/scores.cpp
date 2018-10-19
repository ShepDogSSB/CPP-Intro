/*
  File: scores.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/12/18
  Synopsis: This program takes in the # of students and their scores on exams 1, 2 and 3. The program then outputs a
            neatly organized table that displays the # of students, the scores from their exams & the combined total of
            their scores, the average, maximum and minimum combined score, the amount of total scores above or at the
            average & which students are above, exactly at, or below the average.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// FUNCTION PROTOTYPES GO HERE:
int read_students(const string prompt); // This function reads in the number of students.
void read_scores(int * scores1, int * scores2, int * scores3, const int students); // This function reads in their 3 exam scores.
void compute_sum(int * scores1, int * scores2, int * scores3, int * totals, const int students); // This function computes the total score for one student using their 3 exam scores
double compute_avg(int * totals, const int students); // This function computes the average score from the total scores.
int find_minimum(int * totals, const int students); // This function finds the lowest value in totals.
int find_maximum(int * totals, const int students); // This function finds the highest value in totals.
int good_scores(int * totals, const int students, const double avg); // This function finds the amount of scores that are greater than or equal to the average.
void print_table(int * scores1, int * scores2, int * scores3, int * totals, const int students, const double avg, const int min, const int max, const int above); // This function manages the printing of the table.
void print_top(); // This function prints the header of the table.
void print_scores(const int studentNum, int * scores1, int * scores2, int * scores3, int * totals, const double average); // This function prints the table that shows the number of students, their scores, their total and if they are at, above or below the average.
void print_bottom(const int students, const double avg, const int min, const int max, const int above); // This function prints the number of students, the average rounded score, the maximum & minimum score & the total scores at or above the average.

int main()
{
	int * scores1;
	int * scores2;
	int * scores3;
	int * totals;
	int students(0);
	double avg(0.0);
	int min, max, above;
	
	// Prompt for the number of students
	students = read_students("Enter number of students: ");
	// Allocate arrays to hold exam scores and totals
	scores1 = new int[students];
	scores2 = new int[students];
	scores3 = new int[students];
	totals = new int[students];
	// Prompt and read exams for each student
	read_scores(scores1, scores2, scores3, students);
	// Compute exam totals for each student
	compute_sum(scores1, scores2, scores3, totals, students);
	// Compute the average of the total scores
	avg = compute_avg(totals, students);
	// Find the minimum total score
	min = find_minimum(totals, students);
	// Find the maximum total score
	max = find_maximum(totals, students);
	// Compute the number of students with total scores at or average of the total scores
	above = good_scores(totals, students, avg);
	// Display table
	print_table(scores1, scores2, scores3, totals, students, avg, min, max, above);
	// De-allocate arrays
	delete [] scores1;
	delete [] scores2;
	delete [] scores3;
	delete [] totals;
	return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
int read_students(const string prompt){
    int numStudents(0);
    cout << prompt;
    cin >> numStudents;
    while (numStudents <= 0){
        cout << "Sorry, you must enter a positive value." << endl << prompt;
        cin >> numStudents;
    }
    return numStudents;
}
void read_scores(int * scores1, int * scores2, int * scores3, const int students){
    for(int counter = 0; counter < students; counter++){
        cout << "Enter the three exam scores for student #" << counter + 1 << ": ";
        cin >> scores1[counter] >> scores2[counter] >> scores3[counter];
    }
}
void compute_sum(int * scores1, int * scores2, int * scores3, int * totals, const int students){
    for(int counter = 0; counter < students; counter++){
        totals[counter] = scores1[counter] + scores2[counter] + scores3[counter];
    }
}
double compute_avg(int * totals, const int students){
    double sum(0.0), avg(0.0);
    for(int counter = 0; counter < students; counter++){
        sum += totals[counter];
    }
    avg = sum/students;
    return avg;
}
int find_minimum(int * totals, const int students){
    int min(totals[0]);
    for(int counter = 0; counter < students; counter++){
        if(min > totals[counter]){
            min = totals[counter];
        }
    }
    return min;
}
int find_maximum(int * totals, const int students){
    int max(totals[0]);
    for(int counter = 0; counter < students; counter++){
        if(max < totals[counter]){
            max = totals[counter];
        }
    }
    return max;
}
int good_scores(int * totals, const int students, const double avg){
    int scoresAbove(0);
    for(int counter = 0; counter < students; counter++){
        if(totals[counter] >= avg){
            scoresAbove++;
        }
    }
    return scoresAbove;
}
void print_table(int * scores1, int * scores2, int * scores3, int * totals, const int students, const double avg, const int min, const int max, const int above){
    print_top();
    for(int counter = 0; counter < students; counter++){
        print_scores(counter, scores1, scores2, scores3, totals, avg);
    }
    print_bottom(students, avg, min, max, above);
}
void print_top(){
    int numDashes(47);
    for(int counter = 0; counter < numDashes; counter++){
        cout << "-";
    }
    cout << endl << "Student" << setw(3) << " " << "Score 1" << setw(3) << " " << "Score 2" << setw(3) << " " << "Score 3" << setw(3) << " " << "Total" << endl;
    for(int counter = 0; counter < numDashes; counter++){
        cout << "-";
    }
    cout << endl;
}
void print_scores(const int studentNum, int * scores1, int * scores2, int * scores3, int * totals, const double average){
    cout << right << setw(7) << studentNum+ 1 << setw(3) << " ";
    cout << left << setw(10) << scores1[studentNum] << setw(10) <<scores2[studentNum] << setw(10) << scores3[studentNum] << setw(6) << totals[studentNum];
    if(totals[studentNum] == average){
        cout << "=" << endl;
    }
    else if(totals[studentNum] > average){
        cout << "+" << endl;
    }
    else{
        cout << "-" << endl;
    }
}
void print_bottom(const int students, const double avg, const int min, const int max, const int above){
    int numDashes(47);
    for(int counter = 0; counter < numDashes; counter++){
        cout << "-";
    }
    cout << endl;

    cout << "The number of students is: " << setw(13) << " " << students << endl;
    cout << "The avg total score (rounded) is: " << setw(6) << " " << round(avg) << endl;
    cout << "The maximum score is: " << setw(18) << " " << max << endl;
    cout << "The minimum score is: " << setw(18) << " " << min << endl;
    cout << "Total scores at or above the avg is: " << setw(3) << " " << above << endl;

    for(int counter = 0; counter < numDashes; counter++){
        cout << "-";
    }
    cout << endl;
}
