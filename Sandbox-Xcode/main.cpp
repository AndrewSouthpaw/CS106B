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
#include "lexicon.h"
using namespace std;



/* Quicksort! */

int partition(Vector<int> &arr, int start, int stop) {
	int lh = start + 1, rh = stop, pivot;
	
	pivot = arr[start];
	while (true) {
		while (lh < rh && arr[rh] >= pivot) rh--;
		// find something that is not greater than pivot
		while (lh < rh && arr[lh] < pivot) lh++;
		// find something that doesn't belong on lh
		if (lh == rh) break;
		swap(arr[lh], arr[rh]);
		// exchange those two! problems go away.
		// invariant: arr[start+1..lh] < pivot && arr[rh..stop] >= pivot
	}
	if (arr[lh] >= pivot) return start;
	swap(arr[start], arr[lh]);
	// swap pivot into place where lh and rh markers cross
	return lh;
}

void quicksort(Vector<int> &arr, int start, int stop) {
	if (stop > start) {
		int pivot = partition(arr, start, stop);
		quicksort(arr, start, pivot - 1);
		quicksort(arr, pivot + 1, stop);
	}
}














