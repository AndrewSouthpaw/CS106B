/*
 * File: main.cpp
 * --------------
 * Reading on material from Chapter 3.
 */

#include <string>
#include <iostream>
#include "console.h"
#include "simpio.h"

using namespace std;

/* Constants */


/* Function prototypes */
string reverseWord(string str);

/* Main program */

int main() {
    string str = "desserts";
    string rev = reverseWord(str);
    cout << "Your word: " << rev << endl;
    return 0;
}

string reverseWord(string str) {
    string result = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        result += str[i];
    }
    return result;
}









