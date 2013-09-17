/*
 * File: Problem8_2009_ListMnemonics.cpp
 * -------------------------------------
 * A Touch-Tone phone has letters mapped to numbers for a phone dial.
 * A business can use a mnemonic of their numbers that spell out a memorable
 * word or set of words.
 * 1 - 
 * 2 - ABC
 * 3 - DEF
 * 4 - GHI
 * 5 - JKL
 * 6 - MNO
 * 7 - PQR
 * 8 - TUV
 * 9 - WXY
 * This file lists all the mnemonics possible given a number combination.
 * Used help from solutions.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include "lexicon.h"
#include "strlib.h"

using namespace std;


/* Constants */


/* Function prototypes */
void listMnemonics(string nums);
void recurMnemonics(string prefix, string rest);
string dialpadNumToLetters(char ch);


/* Main program */

int main() {

	while (true) {
		string nums = getLine("Enter number combination: ");
		if (nums == "") break;
		listMnemonics(nums);
	}
	return 0;
}


/*
 * Function: listMnemonics
 * Usage: listMnemonics(nums);
 * ---------------------------
 * Lists all the mnemonics possible on a Touch-Tone phone mapping given
 * a string of numbers.
 */

void listMnemonics(string nums) {
	
	recurMnemonics("", nums);
	
}


/*
 * Function: recurMnemonics
 * Usage: recurMnemonics("", nums);
 * --------------------------------
 * Recursively lists the mnemonics possible giving a set of numbers.
 */

void recurMnemonics(string prefix, string rest) {
	
	if (rest.length() == 0) {
		cout << prefix << endl;
	}
	else {
		string options = dialpadNumToLetters(rest[0]);
		for(int i = 0; i < options.length(); i++) {
			recurMnemonics(prefix + options[i], rest.substr(1));
		}
	}
}


/*
 * Function: dialpadNumToLetters
 * Usage: string options = dialpadNumToLetters(number);
 * ----------------------------------------------------
 * Translates a dialpad number into the set of characters it could represent.
 */

string dialpadNumToLetters(char ch) {
	switch (ch) {
			case '0': return "0";
			case '1': return "1";
			case '2': return "ABC";
			case '3': return "DEF";
			case '4': return "GHI";
			case '5': return "JKL";
			case '6': return "MNO";
			case '7': return "PQRS";
			case '8': return "TUV";
			case '9': return "WXYZ";
		default: error("Invalid number");
	}
}
