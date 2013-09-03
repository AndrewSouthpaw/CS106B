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
	
    return 0;
}
