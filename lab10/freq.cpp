/*
  File: freq.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/18/18
  Synopsis: This program takes in a string and outputs the number of each vowel that appears in a table, and prints the number of consonants in a string.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// FUNCTION PROTOTYPES GO HERE:
void init_vectors(vector<char> & vowels, vector<int> & frequencies);
string read_text(const string & prompt);
bool is_alphabetic(const char character);
void create_list(const string & str_text, vector<char> & vec_text);
bool is_member(const vector<char> & list, char character);
int find_index(const vector<char> & list, char character);
int compute_vowel_freqs(const vector<char> & text, const vector<char> & vowels, vector<int> & freqs);
void display_characters(const vector<char> & characters, const int colwidth);
void display_freqs(const vector<int> & freqs, const int colwidth);

int main()
{
	// Define local variables and constants
	vector<char> vowels;
	vector<int> freqs;
	string input;
	vector<char> text;
	int consonants(0);
	
	const int COLUMNWIDTH = 2;

	// Initialize the list of vowels and vowel frequencies.
	// Call function init_vectors with variables vowels and freqs
	init_vectors(vowels, freqs);

	// Prompt the user for the input text by calling function read_text	
	input = read_text("Enter your text: ");
	
	// Copy the characters (ignoring non-alphabetic characters) in the input string to the vector of characters in variable text
	// Call function create_list to do this
	create_list(input, text);
	
	// Compute the frequencies of vowels and consonants from the input text containing only alphabetic letters
	// Call function compute_vowel_freqs to do this
	consonants = compute_vowel_freqs(text, vowels, freqs);
	
	// Display the vowels and their frequencies
	// Call functions display_characters and display_freqs
	display_characters(vowels, COLUMNWIDTH);
	display_freqs(freqs, COLUMNWIDTH);

	// Display the number of consonants. No function calls here.
	cout << endl << "There are " << consonants << " consonants." << endl;
  return 0;
}
		 
// FUNCTION DEFINITIONS GO HERE:
void init_vectors(vector<char> & vowels, vector<int> & frequencies){
    vowels.push_back('a');
    vowels.push_back('e');
    vowels.push_back('i');
    vowels.push_back('o');
    vowels.push_back('u');
    vowels.push_back('y');

    for(int i = 0; i < 6; i++){
        frequencies.push_back(0);
    }
}
string read_text(const string & prompt){
    string user_input;

    cout << prompt;
    getline(cin, user_input);

    return user_input;
}
bool is_alphabetic(const char character){
    if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
        return true;
    }
    return false;
}
void create_list(const string & str_text, vector<char> & vec_text){
    for(int i = 0; i < str_text.length(); i++){
        if(is_alphabetic(str_text[i])){
            vec_text.push_back(str_text[i]);
        }
    }
}
bool is_member(const vector<char> & list, char character){
    for(int i = 0; i < list.size(); i++){
        if(list.at(i) == character){
            return true;
        }
    }
    return false;
}
int find_index(const vector<char> & list, char character){
    for(int i = 0; i < list.size(); i++){
        if(list.at(i) == character){
            return i;
        }
    }
    return -1;
}
int compute_vowel_freqs(const vector<char> & text, const vector<char> & vowels, vector<int> & freqs){
    int consonant_count(0), vowel_index(0);
    for(int i = 0; i < text.size(); i++){
        if(is_member(vowels, tolower(text.at(i)))){
            freqs.at(find_index(vowels, tolower(text.at(i)))) += 1;
        }else{
            consonant_count++;
        }
}
    return consonant_count;
}
void display_characters(const vector<char> & characters, const int colwidth){
    for(int i = 0; i < characters.size(); i++){
        if(i == characters.size() - 1){
            cout << setw(colwidth) << characters.at(i);
        }else{
            cout << setw(colwidth) << characters.at(i) << ", " << setw(colwidth);
        }
    }
    cout << endl;
}
void display_freqs(const vector<int> & freqs, const int colwidth){
    for(int i = 0; i < freqs.size(); i++){
        if(i == freqs.size() - 1){
            cout << setw(colwidth) << freqs.at(i);
        }else{
            cout << setw(colwidth) << freqs.at(i) << ", " << setw(colwidth);
        }
    }
}
