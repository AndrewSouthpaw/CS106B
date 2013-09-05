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
	
	/* Suppose the weight to be measured is always on the left pan.
	 * Each weight in the set can be included on the left pan, right pan,
	 * or neither.
	 * Base case reached when the weight on the left equals the set of weights
	 * remaining, or when there are no weights left to be considered.
	 * But how to store where the weight is located?!
	 * Do you add it to the wt and remove it from the weights set? Yes.
	 * So there are two branches? One where the setWt is added to wt and removed
	 * from set, and one where it's just removed?
	 * Almost, but there's an issue with ordering with that strategy. If it is
	 * either added to wt or removed, there's no time when the 1st and last
	 * setWt elements would be tested together.
	 * So that would be a permutation issue.
	 * I think that would do it, but it might get messy.
	 */
	
	/* Base case: weight to be measured equals remaining weights in set */
	int sum = 0;
	for (int n : weights) {
		sum += n;
	}
	
	if (wt == sum) return true;
	if (sum == 0) {
		return false;
	} else {
		for (int i = 0; i < weights.size(); i++) {
			int next = weights[i];
			isMeasureable(wt + next)
		}
	}
	
	
}
















