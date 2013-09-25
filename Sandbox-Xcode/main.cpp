/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include "console.h"
#include "gwindow.h"
#include "random.h"
#include "simpio.h"
#include "vector.h"
#include "queue.h"
using namespace std;

/* Constants */


/* Function prototypes */

// This one is for Queues... write one for Vectors.
void merge(Queue<int> &one, Queue<int> &two, Queue<int> &result) {
	while (!one.isEmpty() && !two.isEmpty()) {
		if (one.peek() < two.peek()) {
			result.enqueue(one.dequeue());
		} else {
			result.enqueue(two.dequeue());
		}
	}
	
	while (!one.isEmpty()) {
		result.enqueue(one.dequeue());
	}
	while (!two.isEmpty()) {
		result.enqueue(two.dequeue());
	}
}

void merge(Vector<int> &one, Vector<int> &two, Vector<int> &result) {
	int p, p1, p2;
	p = p1 = p2 = 0;
	while (p1 < one.size() && p2 < two.size()) {
		if (one[p1] < two[p2])
			result[p++] = one[p1++];
		else
			result[p++] = two[p2++];
	}
	while (p1 < one.size()) result[p++] = one[p1++];
	while (p2 < two.size()) result[p++] = two[p2++];
}

void mergeSort(Vector<int> &v) {
	if (v.size() > 1) {
		int n1 = v.size()/2;
		int n2 = v.size() - n1;
		Vector<int> left = copy(v, 0, n1);		// O(N)
		Vector<int> right = copy(v, n1, n2);	// O(N)
		mergeSort(left);
		mergeSort(right);
		merge(v, left, right);					// O(N)
	}
}

