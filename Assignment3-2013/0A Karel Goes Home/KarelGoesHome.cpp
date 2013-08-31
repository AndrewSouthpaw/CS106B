/*
 * File: KarelGoesHome.cpp
 * ----------------------
 * Name: Andrew Smith
 * This file is the starter project for the Karel Goes Home
 * warmup problem for Assignment #3.
 * 
 * Karel the Robot lives in a regular rectangular grid composed of indexed
 * streets (running E-W) and avenues (running N-S). This program reports the
 * number of shortest paths possible to return to the origin at 1st Street &
 * 1st Avenue given an inputted location.
 */
 

#include <iostream>
#include "console.h"
using namespace std;

int numPathsHome(int street, int avenue);

int main() {
	int street = getInteger("Enter street: ");
	int avenue = getInteger("Enter avenue: ");
	int paths = numPathsHome(street, avenue);
	cout << "Number of paths home: " << paths << endl;
    return 0;
}



/* Function: numPathsHome
 * Usage: int paths = numPathsHome(street, avenue);
 * ------------------------------------------------
 * Given a street number and avenue number, which are 1-indexed,
 * returns the number of paths Karel can take back home that only
 * moves left or down.
 */

/*
 * Reasoning through the recursive formula
 
 At each junction, choose to go down or left if it is clear
 It is clear if street > 1 || avenue > 1
 Base case: street == 1 && avenue == 1
 Have a counter to track the number of different paths taken
 
 How to set up the counter?
 If only one option is available, it is not a new path (should have been
 counted previously). If both are available, then one "new" path is created.
 
 Could do it with a series of if / else ifs. But is that the most elegant?
 Well, give it a shot and see where it takes you.
 */

int numPathsHome(int street, int avenue) {
	int paths = 0;
	
	return paths;
}