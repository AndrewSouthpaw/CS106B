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

using namespace std;

double calculateInvalidResult(int voters, double spread, double error, int trials);

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
    cout << invalidResult;
    
    return 0;
}


double calculateInvalidResult(int voters, double spread, double error, int trials)
{
    
}
