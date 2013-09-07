/*
 * File: MultiWordAnagrams.cpp
 * -------------------------------------
 * Generates multi-word anagrams from an input by user. If no anagram exists,
 * the program states as such.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include "lexicon.h"

using namespace std;


/* Constants */
const int MIN_WORD_SIZE = 2;
const string LEXICON_FILE_NAME = "EnglishWords.dat";


/* Function prototypes */
bool findAnagram(string letters, Lexicon &english, Vector<string> &words);
string scrubInput(string line);

/* Main program */

int main() {

	Lexicon english(LEXICON_FILE_NAME);
	
	cout << "This program produces multi-word anagrams." << endl;
	cout << "Minimum word length: " << MIN_WORD_SIZE << endl;
	
	while (true) {
		string line = getLine("Enter a line: (ENTER to exit) ");
		if (line == "") break;
		Vector<string> words;
		if (findAnagram(scrubInput(line), english, words)) {
			cout << "An anagram exists." << endl;
			for (string word : words) {
				cout << word;
			}
			cout << endl;
		} else {
			cout << "Sorry, an anagram does not exist." << endl;
		}
	}
	
	return 0;
}


/*
 * Function: scrubInput
 * Usage: string clean = scrubInput(line);
 * ---------------------------------------
 * Scrubs the line of spaces and punctuation.
 */

string scrubInput(string line) {
	string result;
	for (char ch : line) {
		if (isalpha(ch)) {
			result += tolower(ch);
		}
	}
	return result;
}


/*
 * Function: findAnagram
 * Usage: findAnagram(letters, english, words);
 * --------------------------------------------
 * Checks for existence of multi-word anagram composed of the letters, using
 * a lexicon for reference. Passes back a Vector<string> of the words.
 * Returns true if an anagram is found, false otherwise.
 */

/*
 * Recursive strategy
 * ------------------
 
 This is a permutation problem. Pick a letter, pick another letter, etc.,
 until you run out of letters. Check if it is an anagram. If it's not,
 back up one step and try another letter.
 
 */

bool findAnagram(string letters, Lexicon &english, Vector<string> &words) {
	
	/* Base case: no letters remaining */
	if (letters == "") {
		string result = words[0];
		words.remove(0);
		if (isAllWords(result, english, words)) return true;
		return false;
	} else {
		for (int i = 0; i < letters.size(); i++) {
			words[0] += letters[i];
			string remaining = letters.substr(0, i) + letters.substr(i+1);
			if (findAnagram(remaining, english, words)) return true;
		}
	}
}


/*
 * Function: isAllWords
 * Usage: if (isAllWords(string, english, words);
 * ----------------------------------------------
 * Returns whether the string contains all words recognized in the Lexicon. 
 * The string is all letters with no spaces or punctuation. The string is
 * separated into words and passed back into the vector "words."
 */

bool isAllWords(string letters, Lexicon &english, Vector<string> &words) {
	
	/* Base case: no letters remaining */
	if (letters == "") {
		
	}
}













