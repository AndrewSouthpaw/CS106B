/*
 * File: main.cpp
 * --------------
 * Learning Strings, reading Ch 3.
 * Created: 2013-08-13
 */

#include <iostream>
#include <string>

using namespace std;

/* Function prototypes */


/* Main program */

int main() {
    string name;
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;
    return 0;
}

/* This is interesting, because getline takes a stream. That stream
 * could be the cin stream, or the fstream!
 */

