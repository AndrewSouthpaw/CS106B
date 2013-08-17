/*
 * File: Problem5Histogram.cpp
 * ---------------------------
 * Processes test scores from a text file and places them into a text-based
 * histogram.
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "vector.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

/* Function prototypes */
string askUserForFile(ifstream &infile, string prompt = "");
Vector<int> readScoresFromFile(ifstream &infile);
Vector<string> createHistogram(Vector<int> scores);
void displayHistogram(Vector<string> &histogram);

/* Main program */

int main() {
    cout << "This program produces a histogram from exam scores." << endl;
	ifstream infile;
	askUserForFile(infile, "Enter file name: ");
	Vector<int> scores = readScoresFromFile(infile);
	Vector<string> histogram = createHistogram(scores);
	displayHistogram(histogram);
	infile.close();
	return 0;
}



/*
 * Function: askUserForFile
 * Usage: askUserForFile(infile, prompt);
 * -------------------------------------------
 * Opens a file by prompting the user for filename. If a file by that name
 * does not exist, the user is given extra opportunities to enter a different
 * file name. The optional prompt argument is used to give the user additional
 * information about the desired input file. The valid file name is returned
 * by the function.
 */

string askUserForFile(ifstream &infile, string prompt) {
	while (true) {
		if (prompt == "") prompt = "Input file: ";
		cout << prompt;
		string str = getLine();
		infile.open(str.c_str());
		if (!infile.fail()) return str;
		infile.clear();
		cout << "Invalid file name. Please try again." << endl;
	}
}


/*
 * Function: readScoresFromFile
 * Usage: readScoresFromFile(infile);
 * ------------------------------------------
 * Returns a vector of scores from a file of exam scores.
 */

Vector<int> readScoresFromFile(ifstream &infile) {
	Vector<int> scores;
	while (true) {
		string line;
		getline(infile, line);
		if (infile.fail()) break;	
		int num = stringToInteger(line);
		scores.add(num);
	}
	return scores;
}



/*
 * Function: createHistogram
 * Usage: Vector<string> hist = createHistogram(scores);
 * -----------------------------------------------------
 * Creates a histogram of equal sized buckets, 0 - 100, in ranges of 10,
 * i.e. 0-9, 10-19, 20-29, etc. Count is indicated with an 'x' mark.
 */

Vector<string> createHistogram(Vector<int> scores) {
	Vector<string> result;
	for (int i = 0; i < 10; i++) {
		result.add("");
		for (int j = 0; j < scores.size(); j++) {
			if (i == 0 && scores[j] < 10) {
				result[i] += 'x';
			} else if (scores[j] < (i + 1) * 10 &&
					   scores[j] >= i * 10) {
				result[i] += 'x';
			}
		}
	}
	return result;
}


/*
 * Function: displayHistogram
 * Usage: displayHistogram(hist);
 * -------------------------------
 * Displays a histogram in text base, using 'x' as an counter.
 */

void displayHistogram(Vector<string> &histogram) {
	cout << "Printing histogram..." << endl;
	for (int i = 0; i < histogram.size(); i++) {
		cout << " " << (i * 10) << " - " << ((i * 10) + 9) << ": " <<
			histogram[i] << endl;
	}
}


















