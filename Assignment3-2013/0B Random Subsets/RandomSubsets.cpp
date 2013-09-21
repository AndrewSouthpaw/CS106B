/*
 * File: RandomSubsets.cpp
 * ----------------------
 * Name: Andrew Smith
 *
 * Produces a uniformly-random subset of a given set.
 */

#include <iostream>
#include "set.h"
#include "random.h"
#include "console.h"
using namespace std;


const int SENTINEL = 0;

/* Given a set of integers, returns a uniformly-random subset of that
 * set.
 */
Set<int> randomSubsetOf(Set<int>& s);

int main() {
	Set<int> nums;
	cout << "Enter a set of numbers: (" << SENTINEL << " to exit.)" << endl;
	while (true) {
		int n = getInteger("?: ");
		if (n == SENTINEL) break;
		nums.add(n);
	}
	Set<int> subset = randomSubsetOf(nums);
	for (int num : subset) {
		cout << num << endl;
	}
    return 0;
}


/*
 * Function: randomSubsetOf
 * Usage: set = randomSubsetOf(masterSet);
 * ---------------------------------------
 * Returns a uniformly-random subset of the master set.
 */

Set<int> randomSubsetOf(Set<int> &s) {
	
}