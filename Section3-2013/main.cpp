/*
 * File: Problem1_2009_SetCallbacks.cpp
 * -------------------------------------
 * Comparison callback for a data structure in an address book.
 * Set used to store data:
 * struct entryT {
 *		string firstName;
 *		string lastName;
 *		string phoneNumber;
 * }
 * Compares using last name and then first name.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include "lexicon.h"
#include "strlib.h"

using namespace std;


/* Constants */

/* Structures */
struct entryT {
	string firstName;
	string lastName;
	string phoneNumber;
};

/* Function prototypes */
int compareEntry(entryT a, entryT b);


/* Main program */

int main() {
	entryT test1;
	test1.firstName = "Andrew";
	test1.lastName = "Smith";
	entryT test2;
	test2.firstName = "Bob";
	test2.lastName = "Willens";
	entryT test3;
	test3.firstName = "Zach";
	test3.lastName = "Bingo";
	
	Set<entryT> people(compareEntry);
	people += test1, test2, test3;
	for (entryT person : people) {
		cout << person.firstName << person.lastName << endl;
	}
	
	return 0;
}


int compareEntry(entryT a, entryT b) {
	if (a.lastName < b.lastName) return -1;
	else if (a.lastName > b.lastName) return 1;
	else if (a.firstName < b.firstName) return -1;
	else if (a.firstName > b.firstName) return 1;
	else return 0;

}







