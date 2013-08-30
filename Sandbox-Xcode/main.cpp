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





bool dumbSolve(puzzleT puzzle, string lettersToAssign) {
	if (lettersToAssign == "")
		return puzzleSolved(puzzle);
	
	for (int digit = 0; digit <= 9; digit++) {
		if(assignLetter(lettersToAssign[0], digit)) {
			if (dumbSolve(puzzle, lettersToAssign.substr(1))) return true;
			unassignLetter(lettersToAssign[0], digit);
		}
	}
	return false;
}