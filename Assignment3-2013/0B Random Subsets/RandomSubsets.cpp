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
#include "simpio.h"
using namespace std;


const int SENTINEL = 0;

/* Given a set of integers, returns a uniformly-random subset of that
 * set.
 */
Set<int> randomSubsetOf(Set<int>& s);

int main() {
	while(true) {
		cout << "Run again?" << endl;
		string response = getLine();
		if (response == "n") break;
	Set<int> nums;
//	cout << "Enter a set of numbers: (" << SENTINEL << " to exit.)" << endl;
//	while (true) {
//		int n = getInteger("?: ");
//		if (n == SENTINEL) break;
//		nums.add(n);
//	}
		nums += 1, 2, 3, 4, 5, 6, 7, 8, 9;
		Set<int> subset = randomSubsetOf(nums);
		for (int num : subset) {
			cout << num << endl;
		}
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
	/* Base case: empty set; no more numbers left to consider. */
	if (s.isEmpty()) {
		Set<int> empty;
		return empty;
	}
	
	/* Recursion: take first element of set, randomly choose to add it
	 * to the subset, and recur of the remainder. */
	
	Set<int> subset;
	if (randomChance(0.5)) subset.add(s.first());
	s.remove(s.first());
	return subset + randomSubsetOf(s);
	
	
}