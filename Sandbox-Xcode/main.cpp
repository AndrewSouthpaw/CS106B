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

/* because it's a chain, it's easier to get to the front of the list
 than the back. So we pre-pend when building a list.
 Two things get modified: the next pointer going to the (now second)
 element in the list, and the pointer from the list to the new first
 entry */

Entry *buildList() {
	Entry *list = NULL;
	while (true) {
		Entry *newOne = getNewEntry();
		if (newOne == NULL) break;
		newOne->next = list;
		list = newOne;
	}
	return list;
}

void printList(Entry *list) {
	for (Entry *cur = list; cur != NULL; cur = cur->next)
		printEntry(cur);
}

int main() {
	Entry *n = getNewEntry();
	printList(n);
	return 42;
}

