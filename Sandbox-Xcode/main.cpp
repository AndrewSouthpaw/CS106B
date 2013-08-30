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





bool solveSudoku(Grid<int> &grid) {
	int row, col;
	
	if (!findUnassignedLocation(grid, row, col)) {
		return true; 	// all locations successfully assigned
	}
	for (int num = 1; num <= 9; num++) {
		if (noConflicts(grid, row, col, num)) {
			grid(row, col) = num;
			if (solveSudoku(grid)) return true;
			grid(row, col) = UNASSIGNED;
		}
	}
	return false;
}
