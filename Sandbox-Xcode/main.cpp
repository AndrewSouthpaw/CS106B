/*
 * File: main.cpp
 * --------------
 * General tinkering
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
#include "queue.h"
#include "filelib.h"
#include "lexicon.h"
#include "random.h"


using namespace std;

/* Constants */



/* Function prototypes */



/* Main program */

int main() {
	ifstream infile;
	infile.open("sample.txt");
	ofstream outfile;
	char ch;
	while (infile.get(ch)) {
		outfile.put(ch);
	}
	cout << endl;
	infile.close();
	return 0;
}


