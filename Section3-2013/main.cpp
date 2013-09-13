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
 * 7 - PQRS
 * 8 - TUV
 * 9 - WXYZ
 * This file lists all the mnemonics possible given a number combination.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include "lexicon.h"

using namespace std;


/* Constants */


/* Function prototypes */
void listMnemonics(string nums);


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
	
	// use enums??
	// still struggling with this one...
}








