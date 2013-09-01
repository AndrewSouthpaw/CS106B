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



/* 
 * Function: numPathsHome
 * Usage: int paths = numPathsHome(street, avenue);
 * ------------------------------------------------
 * Given a street number and avenue number, which are 1-indexed,
 * returns the number of paths Karel can take back home that only
 * moves left or down.
 */


int numPathsHome(int street, int avenue) {
	
	/* Base case 1: invalid location, no paths to home */
	if (street < 1 || avenue < 1) return 0;
	
	/* Base case 2: at origin, path is complete */
	if (street == 1 && avenue == 1) return 1;
	
	/* Recur step: try both paths */
	return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);

	
}















