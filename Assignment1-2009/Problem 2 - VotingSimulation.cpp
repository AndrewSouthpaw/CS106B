/*
 * File: VotingSimulation.cpp
 * --------------
 * Created: 2013-08-11
 * Author: Andrew Smith
 *
 * Simulates a vote between two candidates with a voting machine that has
 * a prescribed error rate. Reports the percent of times the election would
 * be invalid due to error in the voting machine.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "random.h"

using namespace std;

/* Function prototypes */

bool isElectionInvalid(char winner);
double calculateInvalidResult(int voters, double spread, double error, int trials);
char simulateElection(int voters, double spread, double error);


/* Main program */

int main() {
    cout << "This program simulates a race between two candidates where there" << endl;
    cout << "is an error with the voting machine." << endl;
    cout << endl;
    int voters;
    while (true) {
        cout << "Enter number of voters: ";
        voters = getInteger();
        if (voters > 0) break;
        cout << "Please enter a positive number of voters." << endl;
    }
    double spread;
    while (true) {
        cout << "Enter percentage spread between candidates: ";
        spread = getReal();
        if (spread >= 0.0 && spread <= 1.0) break;
        cout << "Please enter a percentage between 0.0 and 1.0." << endl;
    }
    double error;
    while (true) {
        cout << "Enter voting error percentage: ";
        error = getReal();
        if (spread >= 0.0 && spread <= 1.0) break;
        cout << "Please enter a percentage between 0.0 and 1.0." << endl;
    }
    int trials = 500;
    
    double invalidResult = calculateInvalidResult(voters, spread, error, trials);
    cout << "Chance of an invalid election result after " << trials << " trials: ";
    cout << invalidResult << "%" << endl;
    
    return 0;
}



/*
 * Function: isElectionValid
 * Usage: bool valid = isElectionValid(winner);
 * -------------------------------------------
 * Checks if the election was invalid. Returns true if B is declared winner.
 */


bool isElectionInvalid(char winner) {
    if (winner == 'B') return true;
    return false;
}


/*
 * Function: calculateInvalidResult
 * Usage: double res = calculateInvalidResult(voters, spread, error, trails);
 * -------------------------------------------------------------------------
 * Calculates the % of invalid elections based on the number of voters,
 * spread between the candidates, voting machine error, and number of trials.
 */

double calculateInvalidResult(int voters, double spread, double error, int trials)
{
    int invalidTrials = 0;
    for (int i = 0; i < trials; i++) {
        char winner = simulateElection(voters, spread, error);
        if (isElectionInvalid(winner))
            invalidTrials++;
        
    }
    double result = (double)invalidTrials / trials * 100;
    return result;
}


/*
 * Function: simulateElection
 * Usage: char winner = simulateElection(voters, spread, error);
 * -------------------------------------------------------------
 * Simulates an election. Winner determined based on number of voters,
 * spread between the candidates, and voting machine error.
 */

char simulateElection(int voters, double spread, double error)
{
    int votersActuallyForA = (voters + voters * spread) / 2;
    int votersActuallyForB = voters - votersActuallyForA;
    int votesForA = 0;
    int votesForB = 0;
    for (int i = 0; i < votersActuallyForA; i++) {
        double rnd = randomReal(0.0, 1.0);
        if (rnd < error) {
            votesForB++;
        } else {
            votesForA++;
        }
    }
    for (int i = 0; i < votersActuallyForB; i++) {
        double rnd = randomReal(0.0, 1.0);
        if (rnd < error) {
            votesForA++;
        } else {
            votesForB++;
        }
    }
    if (votesForA > votesForB)
        return 'A';
    return 'B';
}


