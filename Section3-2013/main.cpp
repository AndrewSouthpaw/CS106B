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


/* Function prototypes */


/* Main program */

int main() {

	Lexicon english("EnglishWords.dat");
	
	cout << "This program produces multi-word anagrams." << endl;
	cout << "Minimum word length: " << MIN_WORD_SIZE << endl;
	
	return 0;
}




