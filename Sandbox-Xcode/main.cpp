/*
 * File: main.cpp
 * --------------
 * Learning about Maps and Sets.
 */

#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include "filelib.h"
#include "lexicon.h"


using namespace std;

/* Constants */

static const int COLUMNS = 7;

/* Function prototypes */



/* Main program */

int main() {
	
	Vector<int> letterCounts(26);
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	char ch;
	while (infile.get(ch)) {
		if (isalpha(ch) ) {
			letterCounts[toupper(ch) - 'A']++;
		}
	}
	infile.close();
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		cout << setw(COLUMNS) << letterCounts[ch - 'A'] << " " << ch << endl;
	}
	return 0;
	
}







