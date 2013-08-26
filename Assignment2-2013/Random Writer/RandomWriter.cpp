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
#include "random.h"
using namespace std;

/* Constants */

const int TEXT_LENGTH = 2000;	// Length of the random writer output

/* Function prototypes */

string askUserForFile(ifstream &infile, string prompt);
Map<string, Vector<char> > analyzeSourceText(ifstream &infile, int order);
void writeRandomText(Map<string, Vector<char> > &seeds, int textLength);
string mostFrequentSeed(Map<string, Vector<char> > &seeds);



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
		break;
		cout << "Please enter an order between 1 and 10." << endl;
	}

	/* Analyze source text for seed frequencies */
	cout << "Analyzing file..." << endl;
	Map<string, Vector<char> > seeds = analyzeSourceText(infile, order);
	
	/* Print out random text based on seed analysis */
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
 * generation. If it reaches a situation where there are no characters to pull
 * from, it stops writing early.
 */


void writeRandomText(Map<string, Vector<char> > &seeds, int textLength) {
	
	int count = 0;
	/* Find the most commonly occurring seed and print it */
	string seed = mostFrequentSeed(seeds);
	count += seed.length();
	cout << seed;
	
	while (count < textLength) {
		Vector<char> letters = seeds.get(seed); // Pull letters for the seed
		if (letters.size() == 0) break; // Stop if no chars to choose from

		/* Randomly select character to print, update count and seed */
		int num = randomInteger(0, letters.size() - 1);
		cout.put(letters[num]);
		count++;
		seed = seed.substr(1) + letters[num];
	}
	
	/* Print out the results */
	cout << endl;

}





/*
 * Function: mostFrequentSeed
 * Usage: string seed = mostFrequentSeed(seeds);
 * ---------------------------------------------
 * Returns the most commonly occurring seed in a Map of seeds containing the
 * Vector of chars that followed the seed. If there are multiple seeds of
 * equal maximum occurrence, one is chosen randomly.
 */

string mostFrequentSeed(Map<string, Vector<char> > &seeds) {
	Vector<string> mostFrequentSeeds;
	int freq = 0;

	/* Extract the most frequent seeds */
	for (string seed : seeds) {
		Vector<char> letters = seeds.get(seed);
		if (letters.size() > freq) {
			mostFrequentSeeds.clear();
			mostFrequentSeeds.add(seed);
			freq = letters.size();
		} else if (letters.size() == freq) {
			mostFrequentSeeds.add(seed);
		}
	}
	
	/* Return one of the most frequent seeds with equal probability */
	int num = randomInteger(0, mostFrequentSeeds.size() - 1);
	return mostFrequentSeeds[num];
}

















