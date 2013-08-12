/*
 * File: main.cpp
 * --------------
 * This is an empty C++ source file.
 */

#include <iostream>
#include "console.h"
#include "random.h"
#include "vector.h"

using namespace std;


Vector<int> makeRandomVector(int sz)
{
	Vector<int> numbers;
	for (int i = 0; i < sz; i++)
		numbers.add(randomInteger(1, 100));
	return numbers;
}

void printVector(Vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
    cout << "" << endl;
}

int main()
{
	Vector<int> nums = makeRandomVector(10);
	printVector(nums);
	return 0;
}