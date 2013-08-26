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
	Lexicon words("EnglishWords.dat");
	test();
}


void test() {
	string testWord = "people";
	if (words.contains(testWord)) {
		cout << testWord << " is a word." << endl;
	} else {
		cout << testWord << " is not a word." << endl;
	}
}