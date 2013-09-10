/*
 * File: Problem5_2009_ReverseString.cpp
 * -------------------------------------
 * Recursively reverses a string.
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
string reverseString(string str);


/* Main program */

int main() {

	while (true) {
		string str = getLine("?: ");
		if (str == "") break;
		string rev = reverseString(str);
		cout << rev << endl;
	}
	return 0;
}


/*
 * Function: reverseString
 * Usage: string rev = reverseString(str);
 * ---------------------------------------
 * Recursively reverses a string.
 */

string reverseString(string str) {
	if (str == "") return "";
	return reverseString(str.substr(1)) + str[0];
}



