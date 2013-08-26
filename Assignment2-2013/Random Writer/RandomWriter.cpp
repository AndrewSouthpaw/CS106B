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
#include "error.h"
using namespace std;

/* Constants */

const int TEXT_LENGTH = 2000;	// Length of the random writer output

/* Function prototypes */

string askUserForFile(ifstream &infile, string prompt);
Map<string, Vector<char> > analyzeSourceText(ifstream &infile, int order);




/* Main program */

int main() {
	cout << "This program generates random text." << endl;
	
	/* Prompt user for source file and Markov order */
	ifstream infile;
	askUserForFile(infile, "Enter sample text file: ");
	int order;
	while (true) {
		order = getInteger("Enter Markov order [1-10]: ");
		if (order >= 1 && order <= 10) break;
		cout << "Please enter an order between 1 and 10." << endl;
	}

	/* Analyze source text for seed frequencies */
	cout << "Analyzing file..." << endl;
	Map<string, Vector<char> > seeds = analyzeSourceText(infile, order);
	
//	/* Print out source file analysis */
//	for (string seed : seeds) {
//		string str;
//		str += seed + ": ";
//		Vector<char> letters = seeds.get(seed);
//		for (char ch : letters) {
//			str += ch;
//		}
//		cout << str << endl;
//	}

	cout << "Writing random text..." << endl;
	writeRandomText(seeds, TEXT_LENGTH);
	
    return 0;
}



/*
 * Function: askUserForFile
 * Usage: string file = askUserForFile(infile, "Enter name: ");
 * ------------------------------------------------------------
 * Asks a user for file and opens it. Tests whether the file is valid. If it is not,
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



/*
 * Function: analyzeSourceText
 * Usage: Map<string, Vector<char> > freq = analyzeSourceText(infile, order);
 * --------------------------------------------------------------------------
 * Analyzes the source text for frequencies of a character given a seed string
 * of Markov order length "order". Returns a Map containing all the found
 * seeds with a Vector of all the occurrences of a character following that
 * seed.
 */
 

Map<string, Vector<char> > analyzeSourceText(ifstream &infile, int order) {
	
	Map<string, Vector<char> > seeds;
	
	/* Build the first seed; error if source not large enough for a seed */
	string seed = "";
	for (int i = 0; i < order; i++) {
		int ch = infile.get();
		if (ch == EOF) error("File not long enough for desired order.");
		seed += ch;
	}
	
	/* Analyze the file one character at a time */
	char ch;
	while (infile.get(ch)) {
		Vector<char> letters;

		/* Pull existing letters if it exists in the Map of seeds */
		if (seeds.containsKey(seed)) letters = seeds.get(seed);
		
		/* Add the new letter and add it to the Map of seeds */
		letters.add(ch);
		seeds.put(seed, letters);
		
		/* Update the seed to include the new char and drop the first */
		seed = seed.substr(1) + ch;
	}
	return seeds;
}



/*
 * Function: writeRandomText
 * Usage: writeRandomText(seeds, textLength);
 * ------------------------------------------
 * Writes random text based off a Markov model using a sample file that provides
 * seeds (and associated probabilities of characters) for random character 
 * generation.
 */


/* Pseudocode
 
 Pull the most commonly occurring seed
 Print the seed
 while (printout < textLength) {
	randomly select a char based on the seed
	print the char
	update the textLength count
	update the seed
 
 */


void writeRandomText(Map<string, Vector<char> > seeds, int textLength) {
	
}

















