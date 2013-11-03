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


/* Selection sort */

void swap (int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort (Vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int minIndex = i;
		for (int j = i; j < arr.size() - 1; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}



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


void insertionSort(Vector<int> &v) {
	for (int i = 1; i < v.size(); i++) {
		int cur = v[i];
		for (int j = i - 1; j >= 0 && v[j] > cur; j--) {
			v[j+1] = v[j];
			v[j] = cur;
		}
	}
}



int main() {
	
	Vector<int> randnumbers;
	randnumbers += 1, 4, 2, 3, 7, 5, 8;

	insertionSort(randnumbers);
	for (int num : randnumbers) {
		cout << num << " ";
	}
	cout << endl;
	return 42;
}












