/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "vector.h"

using namespace std;

/* Prototypes */






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

void merge(Vector<int> v1, Vector<int> v2, Vector<int> &v) {
	int p, p1, p2;
	p = p1 = p2 = 0;
	while (p1 < v1.size() && p2 < v2.size()) {
		if (v1[p1] < v2[p2])
			v[p++] = v1[p1++];
		else
			v[p++] = v2[p2++];
	}
	while (p1 < v1.size()) v[p++] = v1[p1++];
	while (p2 < v2.size()) v[p++] = v2[p2++];
}

void mergeSort(Vector<int> &v) {
	// Base case: array of size 1 or 0.
	if (v.size() <= 1) return;
	
	// Split into two sub-vectors
	Vector<int> left, right;
	for (int i = 0; i < v.size() / 2; i++) {
		left += v[i];
	}
	for (int i = v.size() / 2; i < v.size(); i++) {
		right += v[i];
	}
	
	// Recursively mergeSort
	mergeSort(left);
	mergeSort(right);
	
	// Combine together
	merge(left, right, v);
}



string promptUserForFile(ifstream& infile, string prompt) {
	while (true) {
		cout << prompt;
		string filename;
		getline(cin, filename);
		infile.open(filename.c_str());
		if (!infile.fail()) return filename;
		infile.clear();
		cout << "Unable to open file. Try again." << endl;
		if (prompt == "") prompt = "Input file: ";
	}
}



int main() {
	
	ifstream infile;
	promptUserForFile(infile, "Input file: ");
	char ch;
	while (infile.get(ch)) {
		cout.put(ch);
	}
	infile.close();
	
	
	return 0;
}













