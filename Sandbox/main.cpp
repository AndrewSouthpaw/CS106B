/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"


using namespace std;

/* Prototypes */


string promptUserForFile(ifstream& infile, string prompt) {
	while (true) {
		cout << prompt;
		string filename;
		getline(cin, filename);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		infile.clear();
		cout << "Unable to open file. Try again." << endl;
		if (prompt == "") prompt = "Input file: ";
	}
}


void copyStream(istream& is, ostream& os) {
	char ch;
	while (is.get(ch)) {
		os.put(ch);
	}
}

/*
 * Another possible form of using get, from days of C:
 * int get();
 * so...
 while (true) {
 int ch = infile.get();
 if (ch == EOF) break;
 ...
 }
 
 or...
 int ch;
 while ((ch = infile.get()) != EOF) {
 ...
 }
 
 */


int main() {
	
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	//	char ch;
	//	while (infile.get(ch)) {
	//		cout.put(ch);
	//	}
	copyStream(infile, cout);
	infile.close();
	
	
	return 0;
}














