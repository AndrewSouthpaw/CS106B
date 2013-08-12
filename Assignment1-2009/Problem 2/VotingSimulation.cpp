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


/*
 Simulates an election.
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


/*
 Checks if the election was invalid. Returns true if B is declared winner.
 */
bool isElectionInvalid(char winner) {
    if (winner == 'B') return true;
    return false;
}


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



int main() {
    cout << "This program simulates a race between two candidates where there" << endl;
    cout << "is an error with the voting machine." << endl;
    cout << endl;
    cout << "Enter number of voters: ";
    int voters = getInteger();
    cout << "Enter percentage spread between candidates: ";
    double spread = getReal();
    cout << "Enter voting error percentage: ";
    double error = getReal();
    int trials = 500;
    
    double invalidResult = calculateInvalidResult(voters, spread, error, trials);
    cout << "Chance of an invalid election result after " << trials << " trials: ";
    cout << invalidResult << "%" << endl;
    
    return 0;
}


