/*
 * File: main.cpp
 * --------------
 * General tinkering
 */

#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include <vector>




using namespace std;

/* Prototypes */


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


void copyStream(istream& is, ostream& os) {
	char ch;
	while (is.get(ch)) {
		os.put(ch);
	}
}

/*
 * Another possible form of using get, from days of C:
 * int get();
 * so...
 while (true) {
 int ch = infile.get();
 if (ch == EOF) break;
 ...
 }
 
 or...
 int ch;
 while ((ch = infile.get()) != EOF) {
 ...
 }
 
 */


/* Test number two... */



int partition(Vector<int> &v, int pivotIndex, int low, int high) {
	swap(v[pivotIndex], v[low]);
	int pivot = v[low];
	int left = low + 1;
	int right = high;
	
	while (left < right) {
		while (left < right && v[right] >= pivot) right--;
		while (left < right && v[left] < pivot) left++;
		if (left < right) swap(v[left], v[right]);
	}
	if (v[low] < v[right]) return low;
	swap(v[low], v[right]);
	return right;
}

int choosePivot(Vector<int> &v, int low, int high) {
	return low;
}

void quicksort(Vector<int> &v, int low, int high) {
	if (low >= high) return;
	
	int pivotIndex = choosePivot(v, low, high);
	int partitionPoint = partition(v, pivotIndex, low, high);
	quicksort(v, low, partitionPoint - 1);
	quicksort(v, partitionPoint + 1, high);
}
























//
//int choosePivot(Vector<int> &v, int low, int high) {
//	return low;
//}
//
//int partition(Vector<int> &v, int pivotIndex, int low, int high) {
//	
//	/* Record pivot value, move pivot to front of array */
//	int pivot = v[pivotIndex];
//	swap(v[low], v[pivotIndex]);
//	
//	int left = low + 1;
//	int right = high;
//	
//	/* Move left and right markers toward the middle. Swap when a high value
//	 * is found on the left and a low value on the right.
//	 */
//	while (left < right) {
//		while (left < right && v[right] >= pivot) --right;
//		while (left < right && v[left] < pivot) ++left;
//		swap(v[left], v[right]);
//	}
//	/* If pivot is less than meeting point of pointers, pivot already in place */
//	if (pivot < v[left]) return low;
//	
//	/* Move pivot "in place" to the point where the pointers meet if it
//	 * is less than that element.
//	 */
//	else {
//		swap(v[low], v[left]);
//		return left;
//	}
//	
//}
//
//void quicksort(Vector<int> &v, int low, int high) {
//	if (low >= high) return;
//	
//	int pivotIndex = choosePivot(v, low, high);
//	int partitionIndex = partition(v, pivotIndex, low, high);
//	quicksort(v, low, partitionIndex - 1);
//	quicksort(v, partitionIndex + 1, high);
//	
//}

//int partition(Vector<int>& v, int low, int high) {
//	int pivot = v[low];
//	int left = low + 1, right = high;
//	
//	while (left < right) {
//		while (left < right && v[right] >= pivot) --right;
//		while (left < right && v[left] < pivot) ++left;
//		
//		if (left < right) swap(v[left], v[right]);
//	}
//	if (pivot < v[right]) return low;
//	swap(v[low], v[right]);
//	return right;
//}
//
//void quicksort(Vector<int> &v, int low, int high) {
//	if (low >= high) return;
//	
//	int partitionPoint = partition(v, low, high);
//	quicksort(v, low, partitionPoint - 1);
//	quicksort(v, partitionPoint + 1, high);
//}

void readVector(Vector<int> &v, int l, int r) {
	for (int i = l; i < r; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	
//	vector<int> myvector;
//	vector<int>::iterator it;
//	myvector.push_back(3);
//	myvector.push_back(2);
//	myvector.push_back(6);
//	
//	for (it = myvector.begin(); it != myvector.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//	
//	myvector.erase(myvector.begin(), myvector.end());
	
	vector<vector<int> > v;
	v.resize(5);
	vector<int> nums;
	int myints[] = {3,2,6};
	nums.assign(myints, myints+3);
	vector<int>::iterator it;
	int index = 0;
	v.insert(v.begin()+3, nums);
	vector<vector<int> >::iterator myItr = v.begin()+2;
	*myItr = nums;
	myItr = v.begin()+1;
	*myItr = nums;
	
	for (vector<vector<int> >::iterator itr = v.begin();
		 itr != v.end();
		 itr++) {
		cout << index++ << ": ";
		for (vector<int>::iterator i = (*itr).begin(); i != itr->end(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	
	return 0;
}














