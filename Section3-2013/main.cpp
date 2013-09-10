/*
 * File: Problem6_2009_GCD.cpp
 * -------------------------------------
 * Computes the greatest common denominator using Euclid's method:
 * If x is evenly divisible by y, then y is the greatest common divisor. 
 * Otherwise, the greatest common divisor of x and y is always equal to the 
 * greatest common divisor of y and the remainder of x divided by y.
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
int gcd(int x, int y);


/* Main program */

int main() {

	while (true) {
		int x = getInteger("x = ");
		int y = getInteger("y = ");
		int num = gcd(x, y);
		cout << "GCD: " << num << endl;
	}
	return 0;
}


/*
 * Function: gcd
 * Usage: int num = gcd(x, y);
 * ---------------------------
 * Recursively computes the greatest common denominator using Euclid's method.
 * 
 */

int gcd(int x, int y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);
}



