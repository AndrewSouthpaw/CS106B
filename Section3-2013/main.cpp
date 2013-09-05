/*
 * File: Problem1-WeightsandBalances.cpp
 * -------------------------------------
 * Simulates a simple two-pan balance and set of weights.  User enters the set of
 * weights available.  User then can find out whether a certain weight can be
 * measured using the set of weights.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"

using namespace std;


/* Constants */
const int SENTINEL = 0;

/* Function prototypes */
bool isMeasureable(int wt, Vector<int> weights);


int main() {
	
	/* Get set of weights from user */
	Vector<int> weights;
	cout << "Enter the set of weights. (Enter " << SENTINEL << " to exit)" << endl;
	while (true) {
		int wt = getInteger("?: ");
		if (wt == SENTINEL) break;
		if (wt < 1) {
			cout << "Invalid weight. Please try again." << endl;
		} else {
			weights.add(wt);
		}
	}
	
	/* TEST FOR 0 WEIGHT CONDITION */
	
	/* Allow user to test if weights are measurable until SENTINEL entered */
	cout << "Enter weights you want to test if they are measurable." << endl;
	while (true) {
		int wt = getInteger("?: ");
		if (wt == SENTINEL) break;
		if (wt < 0) {
			cout << "Invalid weight. Please try again." << endl;
		} else {
			cout << "A weight of " << wt << ((isMeasureable(wt, weights)) ? " is " : " is not ");
			cout << "measurable." << endl;
		}
	}
	
    return 0;
}

/*
 * Function: isMeasureable
 * Usage: isMeasureable(wt, weights);
 * ----------------------------------
 * Recursively tests if a weight is measureable using a two-pan balance given
 * a set of weights.
 */

bool isMeasureable(int wt, Vector<int> weights) {
	
	/* Base case: weight to be measured equals remaining weights in set */
	int sum = 0;
	for (int n : weights) {
		sum += n;
	}
	
	if (wt == sum) return true;
	if (sum == 0) {
		return false;
	} else {
		for (int i = 0; i < weights.size();) {
			int next = weights[i];
			weights.remove(i);
			if (isMeasureable(wt + next, weights) || isMeasureable(wt, weights)) return true;
		}
	}
	return false;
	
	
}
















