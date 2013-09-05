/*
 * File: fillRegion.cpp
 * -------------------------------------
 * Fills a region of white pixels bounded by black pixels with black pixels.
 * In this simulation, pixels are bools; white is FALSE, black is TRUE.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"

using namespace std;


void fillRegion(Grid<bool> &pixels, int row, int col) {
	/* Base case: Row or column is off the grid */
	if (row >= pixels.numRows() || col >= pixels.numCols()) {
		return;
	}
	
	/* Base case 2: A black pixel is reached */
	if (pixels[row][col] == true) {
		return;
	}
	
	pixels[row][col] = true;
	fillRegion(pixels, row + 1, col);
	fillRegion(pixels, row - 1, col);
	fillRegion(pixels, row, col + 1);
	fillRegion(pixels, row, col - 1);
}















