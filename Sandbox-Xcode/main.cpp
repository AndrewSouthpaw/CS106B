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

/* Constants */



/* Function prototypes */



/* Main program */

/* Tower of Brahma solution */

void moveTower(int n, char src, char dst, char tmp) {
	if (n > 0) {
		moveTower(n-1, src, tmp, dst);
		moveSingleDisc(src, dst);
		moveTower(n-1, tmp, dst, src);
	}
}