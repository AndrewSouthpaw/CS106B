/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include "console.h"
#include "vector.h"
#include "simpio.h"


using namespace std;




int main() {
	Vector<int> v;
	v += 1, 2, 3;
	cout << "Sum is: " << sum(v) << endl;
}