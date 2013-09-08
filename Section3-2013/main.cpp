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
const int MIN_WORD_SIZE = 3;
const string LEXICON_FILE_NAME = "EnglishWords.dat";


/* Function prototypes */
bool findAnagram(string letters, Lexicon &english, Vector<string> &words);
string scrubInput(string line);
bool findAnagramWithPrefix(string prefix, string rest,
						   Lexicon &english, Vector<string> &words);

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
				cout << word << " ";
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
	return findAnagramWithPrefix("", letters, english, words);
}


/*
 * Function: findAnagramWithPrefix
 * Usage: findAnagramWithPrefix("", letters, english, words);
 * ----------------------------------------------------------
 * Finds a multiword anagram for a set of letter, where the current word
 * must begin with the specified prefix.
 */

bool findAnagramWithPrefix(string prefix, string rest,
						   Lexicon &english, Vector<string> &words) {
	if (!english.containsPrefix(prefix)) return false;
	if (english.contains(prefix) && prefix.length() >= MIN_WORD_SIZE) {
		if (rest == "" || findAnagram(rest, english, words)) {
			words.add(prefix);
			return true;
		}
	}
	for (int i = 0; i < rest.size(); i++) {
		string otherLetters = rest.substr(0, i) + rest.substr(i+1);
		if (findAnagramWithPrefix(prefix + rest[i], otherLetters, english, words)) {
			return true;
		}
	}
	return false;
}






