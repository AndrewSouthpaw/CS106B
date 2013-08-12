/*
 * File: main.cpp
 * --------------
 * Created: 2013-08-11.
 * Author: Andrew Smith
 *
 * Lists the perfect numbers (numbers equal to the sum of its proper
 * divisors) between 1 and 10,000.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"

using namespace std;

bool isPerfect(int n);

int main() {
    cout << "This program lists the perfect numbers between 1 and 10000." << endl;
    int n = 1;
    while (n < 10000) {
        if (isPerfect(n)) {
            cout << n << endl;
        }
        n++;
    }
    
    return 0;
}

bool isPerfect(int n)
{
    int divisor = 1;
    int sum = 0;
    while (divisor < n) {
        if (n % divisor == 0) sum += divisor;
        divisor++;
    }
    if (sum == n) return true;
    return false;
}
