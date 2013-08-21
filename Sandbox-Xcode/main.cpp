/*
 * File: main.cpp
 * --------------
 * Learning about Maps and Sets.
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
#include "filelib.h"


using namespace std;

/* Constants */


/* Function prototypes */

bool isAnagram(string w1, string w2);
string sortLetters(string s);

/* Main program */

int main() {

    cout << "This program checks if two words are anagrams." << endl;
    cout << "Enter first word: ";
    string w1 = getLine();
    cout << "Enter second word: ";
    string w2 = getLine();
    bool b = isAnagram(w1, w2);
    cout << "These words " << (b ? "are" : "are not") << " anagrams." << endl;
    return 0;
    
}


/*
 * Function: isAnagram
 * Usage: bool b = isAnagram(w1, w2);
 * -------------------------------------
 * Checks if two words are anagrams.
 */
 

bool isAnagram(string w1, string w2) {
    string s1 = sortLetters(w1);
    string s2 = sortLetters(w2);
    if (s1 == s2) {
        return true;
    } else {
        return false;
    }
}


/*
 * Function: sortLetters
 * Usage: string str = sortLetters(string word);
 * ------------------------------------------------
 * Returns a string with the letters of the word sorted.
 */

string sortLetters(string s) {
    Map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (m.containsKey(ch)) {
            m[ch]++;
        } else {
            m[ch] = 1;
        }
    }
    string result = "";
    foreach(char ch in m) {
        int num = m.get(ch);
        result += string(num, ch);
    }
    return result;
}











