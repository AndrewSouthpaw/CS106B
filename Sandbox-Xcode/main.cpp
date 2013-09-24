/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include "console.h"
#include "gwindow.h"
#include "random.h"
#include "simpio.h"
using namespace std;

/* Constants */


/* Function prototypes */



struct Entry {
	string name, phone;
	Entry *next;
};

void printEntry(Entry *e) {
	cout << e->name << " " << e->phone << endl;
}

Entry *getNewEntry() {
	cout << "Enter name (ENTER to quit): ";
	string name = getLine();
	if (name == "") return NULL;
	
	Entry *newOne = new Entry;
	// *newOne.name doesn't work: dot (.) has higher precedence than *
	// (*newOne).name works. Thus the -> operator simplifies it.
	newOne->name = name;
	cout << "Enter phone: ";
	newOne->phone = getLine();
	newOne->next = NULL; // no one follows
	return newOne;
}

int main() {
	Entry *n = getNewEntry();
	printEntry(n);
	return 42;
}