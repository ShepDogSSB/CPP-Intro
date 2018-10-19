/*
  File: replace.cpp
  Created by: Nicholas Shepard
  Creation Date: 7/20/18
  Synopsis: This program takes a phrase, a letter to replace and a letter to replace it with, and replaces all letters within the phrase with the desired letter specified by the user.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text);
void display_phrase(const vector<char> & text);
 
int main()
{
  string phrase, letter, replacement;
  vector<char> text_vec;

  cout << "Enter phrase: ";
  getline(cin, phrase);

  if (phrase.length() > 0)
  {
	cout << "Enter letter to replace: ";
	getline(cin, letter);

	if (letter.length() == 1)
	{
		cout << "Enter replacement letter: ";
		getline(cin, replacement);
  
		if (replacement.length() == 1)
		{
			replace(phrase, letter, replacement, text_vec);
			cout << "String phrase: " << phrase << endl;
			cout << "Vector phrase: ";
		       	display_phrase(text_vec);
			cout << endl;
		}
		else
		{
			cout << "Replacement letter must be a single letter" << endl;
		}
	}
	else
	{
		cout << "Letter to replace must be a single letter" << endl;
	}
  }
  
  return 0;
}

// FUNCTION 
void replace(string & phrase, const string & letter, const string & replacement, vector<char> & text)
{
  for(int i = 0; i < phrase.length(); i++){
    if(phrase[i] == letter[0]){
      phrase.replace(i, 1, replacement);
    }
    text.push_back(phrase[i]);
  }
}

void display_phrase(const vector<char> & text)
{
  for(int i = 0; i < text.size(); i++){
    cout << text.at(i);
  }
}
