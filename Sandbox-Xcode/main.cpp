/*
 * File: main.cpp
 * --------------
 * Playing with file reading, searching, and collective nouns.
 * Created: 2013-08-16
 */

#include <iostream>
#include <string>
#include <fstream>
#include "simpio.h"
#include "console.h"
#include "strlib.h"

using namespace std;

/* Constants */

const string DEFAULT_FILE_NAME = "CollectiveNouns.txt";

/* Function prototypes */

string askUserForFile(ifstream &infile, string prompt = "");

/* Main program */

int main() {
    cout << "This program teaches you about collective nouns!" << endl;
    cout << "Do you have a special file? (Y/N) ";
    string ans = getLine();
    ifstream infile;
    if (ans.find('y') != string::npos || ans.find('Y') != string::npos) {
        string filename = askUserForFile(infile, "Enter file name: ");
        infile.open(filename.c_str());
    } else {
        cout << "Reading from default file..." << endl;
        cout << "Source: http://www.npwrc.usgs.gov/about/faqs/animals/names.htm" << endl;
        infile.open(DEFAULT_FILE_NAME.c_str());
    }
//    while (true) {
//        cout << "What would you call a group of... (Press RETURN to quit) ";
//        string entry = getLine();
//        if (entry == "") break;
//        string collective = toLowerCase(lookUpCollective(entry));
//        cout << "A group of " << entry << " is " << collective << "." << endl;
//    }

    infile.close();
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

