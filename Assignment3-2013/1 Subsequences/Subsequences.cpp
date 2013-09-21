/*
 * File: Subsequences.cpp
 * ----------------------
 * Name: Andrew Smith
 *
 * Tests if one string is a subsequence of another string.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
using namespace std;

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subsequence);

int main() {
    string str1 = getLine("Enter the first string: ");
    string str2 = getLine("Enter the second string: ");
    cout << str1 << (isSubsequence(str1, str2) ? " is " : " is not ") <<
        "a subsequence of " << str2 << "." << endl;
    return 0;
}



/*
 * Function: isSubsequence
 * Usage: isSubsequence(str1, str2);
 * ---------------------------------
 * Returns if the first string is a subsequence of the second.
 */

bool isSubsequence(string s1, string s2) {
    
    /* Base case 1: no characters left in first string, thus it is substring */
    if (s1.length() == 0) return true;
    
    /* Base case 2: chars remain in first string but not second */
    if (s1.length() != 0 && s2.length() == 0) return false;
    
    /* Recursive step:
     * 1. If first characters of strings match, remove first char of first string
     * 2. Recur on first string and the second string with first char removed
     */
    if (s1[0] == s2[0]) s1.erase(0);
    s2.erase(0);
    return isSubsequence(s1, s2);
}
