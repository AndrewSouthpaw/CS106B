/*
 * File: main.cpp
 * --------------
 * Author: Andrew Smith
 * Created: 2013-08-14
 * 
 * Translates user-provided surnames into Soundex codes, a system for encoding
 * surnames based on their phonetic structure. All Soundex codes have the same
 * format: an uppercase letter followed by three digits. The Soundex algorithm
 * is shown below:
 * 1. Keep the first letter of the surname (convert to uppercase if needed)
 * 2. Convert all other letters to a digit using the table below, discarding
 * non-characters (dashes, spaces, etc.)
 *		0	A E I O U H W Y
 *		1	B F P V
 *		2	C G J K Q S X Z
 *		3	D T
 *		4	M N
 *		5	L
 *		6	R
 * 3. Remove consecutive duplicate digits
 * 4. Remove zeros
 * 5. Make code length 4 by truncating or padding with zeros
 */

#include <iostream>
#include "console.h"
#include "simpio.h"


using namespace std;



/* Constants */

const int SOUNDEX_CODE_LENGTH = 4;

/* Function prototypes */

string surnameToSoundexCode(string surname);
void scrubName(string &str);
string encodeSurname(string surname);
void removeDuplicateOccurrences(string &str, bool caseSensitive);
void removeAllOccurrences(string &str, char ch);
void forceLength(string &str, int n);

/* Main program */

int main() {
	while (true) {
		cout << "Enter surname (RETURN to quit): ";
		string str = getLine();
		if (str.empty()) break;
		string code = surnameToSoundexCode(str);
		cout << "Soundex code for " << str << " is " << code << endl;
	}
	return 0;
}


/*
 * Function: surnameToSoundexCode
 * Usage: surnameToSoundexCode(name);
 * ----------------------------------
 * Translates a surname into its corresponding Soundex code.
 */

string surnameToSoundexCode(string surname) {
	scrubName(surname);
	string result = encodeSurname(surname);
	removeDuplicateOccurrences(result, false);
	removeAllOccurrences(result, '0');
	forceLength(result, SOUNDEX_CODE_LENGTH);
	return result;
}


/*
 * Function: scrubName
 * Usage: scrubName(surname);
 * --------------------------
 * Scrubs name for spaces and non-letter characters.
 */

void scrubName(string &str) {
	string result;
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i]))
			result += str[i];
	}
	str = result;
}


/*
 * Function: encodeSurname
 * Usage: string code = encodeSurname(name);
 * -----------------------------------------
 * Converts the surname into Soundex numbers. Uses the first letter of
 * the surname, then subsequent letters are converted to numbers, using
 * this table:
 *		0	A E I O U H W Y
 *		1	B F P V
 *		2	C G J K Q S X Z
 *		3	D T
 *		4	M N
 *		5	L
 *		6	R
 */

string encodeSurname(string surname) {
	string result;
	result += toupper(surname[0]);
	for (int i = 1; i < surname.length(); i++) {
		char ch = toupper(surname[i]);
		switch (ch) {
				case 'A': case 'E': case 'I': case 'O': case 'U': case 'H':
				case 'W': case 'Y':
					result += '0';
					break;
				case 'B': case 'F': case 'P': case 'V':
					result += '1';
					break;
				case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S':
				case 'X': case 'Z':
					result += '2';
					break;
				case 'D': case 'T':
					result += '3';
					break;
				case 'M': case 'N':
					result += '4';
					break;
				case 'L':
					result += '5';
					break;
				case 'R':
					result += '6';
					break;
		}
	}
	return result;
}


/*
 * Function: removeDuplicateOccurrences
 * Usage: removeDuplicateOccurrences(str, false)
 * ---------------------------------------------
 * Removes duplicate occurrences of a char in a string. Case sensitivity is
 * set true or false.
 */

void removeDuplicateOccurrences(string &str, bool caseSensitive) {
	string result;
	for (int i = 0; i < str.length(); i++) {
		if (i < str.length() - 1) {
			if (caseSensitive) {
				if (str[i] != str[i + 1])
					result += str[i];
			} else {
				if (toupper(str[i]) != toupper(str[i + 1]))
					result += str[i];		
			}
		} else if (i == str.length() - 1) {
			result += str[i];
		}
	}
	str = result;
}


/*
 * Function: removeAllOccurrences
 * Usage: removeAllOccurrences(str, '0');
 * --------------------------------------
 * Removes all occurrences of a char from a string.
 */

void removeAllOccurrences(string &str, char ch) {
	int found = 0;
	while ((found = str.find(ch, found)) != string::npos)
		str.erase(found, 1);
}


/*
 * Function: forceLength
 * Usage: forceLength(str, 4);
 * -------------------------------
 * Forces string to be of specified length by truncation or adding zeros.
 */

void forceLength(string &str, int n) {
	if (str.length() < n) {
		while (str.length() < n)
			str += '0';
	} else if (str.length() > n) {
		str = str.substr(0, n-1);
	}
	
}





















