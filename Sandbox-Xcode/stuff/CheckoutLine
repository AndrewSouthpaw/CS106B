/*
 * File: CheckoutLine.cpp
 * --------------
 * Learning about models and simulations. Code lifted from "Programming
 * Abstractions in C++" by Eric Roberts, 2012, p. 222-4.
 *
 * Simulates a checkout line. Customers arrive at stand and get in line. Wait
 * until cashier is free, at which point they are served and take some period
 * of time. After service time completes, cashier is free to serve next customer
 * in line.
 *
 * In each unit of time, up to constant SIMULATION_TIME, each are performed:
 *
 * 1. Determine whether new customer arrives, with probability determined by
 *    constant ARRIVAL_PROBABILITY, using Poisson distribution.
 * 
 * 2. If cashier is busy, note cashier has spent another unit of time with that
 *    customer.
 *
 * 3. If cashier is free, serve next customer in line. Service time is random
 *    period between MIN_SERVICE_TIME and MAX_SERVICE_TIME.
 *
 * At end, report:
 * o The number of customers served
 * o The average time spent in line
 * o The average number of people in line
 */

#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <iomanip>
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "strlib.h"
#include "map.h"
#include "vector.h"
#include "queue.h"
#include "filelib.h"
#include "lexicon.h"
#include "random.h"


using namespace std;

/* Constants */

const double ARRIVAL_PROBABILITY = 0.10;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
const int SIMULATION_TIME = 2000;


/* Function prototypes */

void runSimulation(int &nServed, int &totalWait, int &totalLength);
void printReport(int nServed, int totalWait, int totalLength);

/* Main program */

int main() {
	int nServed;
	int totalWait;
	int totalLength;
	runSimulation(nServed, totalWait, totalLength);
	printReport(nServed, totalWait, totalLength);
	return 0;
}



/*
 * Function: runSimulation
 * Usage: runSimulation(nServed, totalWait, totalLength);
 * -------------------------
 * Runs simulation.
 */

void runSimulation(int &nServed, int &totalWait, int &totalLength) {
	Queue<int> queue;
	int timeRemaining = 0;
	nServed = 0;
	totalWait = 0;
	totalLength = 0;
	for (int t = 0; t < SIMULATION_TIME; t++) {
		if (randomChance(ARRIVAL_PROBABILITY)) {
			queue.enqueue(t);
		}
		if (timeRemaining > 0) {
			timeRemaining--;
		} else if (!queue.isEmpty()) {
			totalWait += t - queue.dequeue();
			nServed++;
			timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
		}
		totalLength += queue.size();
	}
}


/*
 * Function: printReport
 * Usage: printReport(nServed, totalWait, totalLength);
 * ---------------------------------------------------
 * This function reports the results of the simulation.
 */

void printReport(int nServed, int totalWait, int totalLength) {
	cout << "Simulation results given the following constants:" << endl;
	cout << fixed << setprecision(2);
	cout << "SIMULATION_TIME: " << SIMULATION_TIME << endl;
	cout << "ARRIVAL_PROBABILITY: " << ARRIVAL_PROBABILITY << endl;
	cout << "MIN_SERVICE_TIME: " << MIN_SERVICE_TIME << endl;
	cout << "MAX_SERVICE_TIME: " << MAX_SERVICE_TIME << endl;
	cout << endl;
	cout << "Customers served: " << nServed << endl;
	cout << "Average waiting time: " << double(totalWait) / nServed << endl;
	cout << "Average queue length: " << double(totalLength) / SIMULATION_TIME << endl;
	
}



















