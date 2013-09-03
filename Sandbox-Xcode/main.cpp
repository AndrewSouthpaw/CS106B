/*
 * File: main.cpp
 * --------------
 * General tinkering
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
#include "queue.h"
#include "filelib.h"
#include "lexicon.h"
#include "random.h"


using namespace std;




int main() {
	int num;
	int *p, *q;
	
	p = new int;
	*p = 10;
	
	q = new int;
	*q = *p;	// dereference p and copy value in p address
	
	q = p;	// take address in p and assign to q; now they are aliases
	for same location
		
	/* we do our own garbage collection */
		delete p;
	delete q;	// currently an error, because q is pointing to p
	
	q = NULL;
	
	/* the original value assigned to q is now orphaned, you can't get
	 to it in any way */
}