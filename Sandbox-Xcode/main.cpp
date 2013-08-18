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
#include "error.h"

using namespace std;

/* Constants */

const string DEFAULT_FILE_NAME = "CollectiveNouns.txt";
const string ANIMAL_NOT_LISTED_TEXT = "Sorry, this animal is not listed.";

/* Function prototypes */

string askUserForFile(ifstream &infile, string prompt = "");
string lookUpCollective(ifstream &infile, string animal);

/* Main program */

int main() {
    cout << "This program teaches you about collective nouns!" << endl;
    cout << "Do you have a special file? (Y/N) ";
    string ans = getLine();
    ifstream infile;
    string filename;
    if (ans.find('y') != string::npos || ans.find('Y') != string::npos) {
        filename = askUserForFile(infile, "Enter file name: ");
    } else {
        cout << "Reading from default file..." << endl;
        cout << "Source: http://www.npwrc.usgs.gov/about/faqs/animals/names.htm" << endl;
        filename = DEFAULT_FILE_NAME;
    }
    while (true) {
        infile.open(filename.c_str());
        if(infile.fail())
            error("Failed to open the file.");
        cout << "What would you call a group of... (Press RETURN to quit) ";
        string entry = getLine();
        if (entry == "") break;
        string collective = lookUpCollective(infile, entry);
        if (collective == ANIMAL_NOT_LISTED_TEXT) {
            cout << collective << endl;
        } else {
            cout << "A group of " << toLowerCase(entry) << " is ";
            cout << toLowerCase(collective) << "." << endl;
        }
        infile.close();
    }

    infile.close();
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



/*
 * Function: lookUpCollective
 * Usage: string collective = lookUpCollective(infile, animal);
 * -------------------------------------------------------------
 * Returns a collective noun for an animal from a file. File is formatted
 * so that the collective noun is listed on the next line after the name
 * of the animal.
 */

string lookUpCollective(ifstream &infile, string animal) {
    animal = toLowerCase(animal);
    while (true) {
        string str;
        getline(infile, str);
        str = toLowerCase(str);
        if (infile.fail()) break;
        if (str == animal) {
            getline(infile, str);
            return str;
        }
    }
    return ANIMAL_NOT_LISTED_TEXT;
    
}

















