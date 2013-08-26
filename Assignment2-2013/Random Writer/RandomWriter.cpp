/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: Andrew Smith
 * Based off starter files in Stanford CS106B Summer 2013 class.
 *
 * This program randomly generates text based on a Markov model for character
 * analysis.
 */

#include <fstream>
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "map.h"
#include "vector.h"
using namespace std;

/* Constants */



/* Function prototypes */

string askUserForFile(ifstream &infile, string prompt);




/* Main program */

int main() {
	cout << "This program generates random text." << endl;
	ifstream infile;
	string file = askUserForFile(infile, "Enter sample text file: ");
	
	cout << "Analyzing file..." << endl;
	Map<string, Vector<char> > frequencies;
	
	
    return 0;
}



/*
 * Function: askUserForFile
 * Usage: string file = askUserForFile(infile, "Enter name: ");
 * ------------------------------------------------------------
 * Asks a user for file. Tests whether the file is valid. If it is not,
 * the user is informed and giving additional opportunities to enter a valid
 * file name. The function returns the name of the file.
 */

string askUserForFile(ifstream &infile, string prompt) {
    if (prompt == "") prompt = "Enter file: ";
    while (true) {
        cout << prompt;
        string filename = getLine();
        infile.open(filename.c_str());
        if (!infile.fail()) return filename;
        infile.clear();
        cout << "Invalid file. Please try again." << endl;
    }
}