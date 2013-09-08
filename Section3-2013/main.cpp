/*
 * File: Problem4_2009_Cannonballs.cpp
 * -------------------------------------
 * Cannonballs are stacked in a pyramid shade: one cannonball sits on top of
 * a square of 4, on top of a square of 9, and so on.
 * Takes the number of layers in the pyramid from a user and reports the
 * cannonballs in the pyramid.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
#include "lexicon.h"

using namespace std;


/* Constants */


/* Function prototypes */
int cannonball(int height);

/* Main program */

int main() {

	while (true) {
		int height = getInteger("Number of layers in the cannonball pyramid: ");
		if (height == 0) break;
		int balls = cannonball(height);
		cout << "Number of balls: " << balls << endl;
	}
	return 0;
}


/*
 * Function: cannonball
 * Usage: numBalls = cannonball(height);
 * -------------------------------------
 * Returns the number of balls in a pyramid based on the number of layers.
 */

int cannonball(int height) {
	if (height < 1) {
		return 0;
	}
	if (height == 1) {
		return 1;
	}
	return height * height + cannonball(height - 1);
	
}



