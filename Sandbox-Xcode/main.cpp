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
	int stringToInteger(string str) {
		istringstream stream(str);
		int value;
		stream >> value >> ws;
		if (stream.fail() || !stream.eof()) {
			error("stringToInteger: Illegal integer format");
		}
		return value;
	}
	
	
	string integerToString(int n) {
		ostringstream stream;
		stream << n;
		return stream.str();
	}
	
	int getInteger(string prompt) {
		int value;
		string line;
		while (true) {
			cout << prompt;
			getline(cin, line);
			istringstream stream(line);
			stream >> value >> ws;
			if (!stream.fail() && stream.eof()) break;
			cout << "Illegal integer format. Try again." << endl;
		}
		return value;
	}
}


