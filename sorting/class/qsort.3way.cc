#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

void print_arr(vector<int>& arr) {
	for (int i=0; i<arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size()-1) cout << ", ";
	}
	cout << endl;
}

// [ 2 4 4 4 5 9 ] - desired
// [ 0 1 2 3 4 5 ] - index
// [ 5 2 4 4 9 4 ] - lo = 0, mid = 0, hi = 4, end = 5, pivot = 4
// [ 9 2 4 4 5 4 ] - lo = 0, mid = 0, hi = 3, pivot =  4
// [ ]

// [ 9 2 7 1 5 4 ] - lo = 0, hi = 3
// [ 1 2 7 9 5 4 ] - lo = 2, hi = 1
// [ 1 2 4 9 5 7 ]
// < pivot, unseen, > pivot
// till lo-1, lo - hi-1, hi & greater
int partition(vector<int>& arr, int& mid, int start, int end) {
	int lo = start;
	mid = start;
	int hi = end - 1;
	int pivot = arr[end];
	while (mid <= hi) {
		if (arr[mid] < pivot) {
			swap(arr, mid, lo);
			lo++; mid++;
		}
		else if (arr[mid] == pivot) {
			mid++;
		}
		else {
			swap(arr, mid, hi);
			hi--;
		}
	}
	swap(arr, end, mid);
	//cout << "start - " << start << ", end - " << end << endl;
	//print_arr(arr);
	return lo;
}

// [ 0 0 1 1 2 2 2 ] - lo = 2, mid = 4, hi = 6 - desired state
// [ 0 1 2 3 4 5 6 ] - index
// [ 2 0 2 1 1 0 2 ] - lo = 0, mid = 0, hi = 0, end = 6, pivot = 2
// [ 0 1 1 0 2 2 2] - lo = 4, mid = 6, hi = 6
// < pivot,   = pivot,      > pivot,    unseen
// till lo-1, lo to mid-1, mid - hi-1,  hi & greater
// [ 0 1 2 3 ] - index
// [ 0 1 1 0 ] - arr - lo = 0, mid = 0, hi = 0, end = 3, pivot = 0
// [ 0 1 1 ] - lo = 0, mid = 1, hi = 3
// < pivot,   = pivot,      > pivot,    unseen
// till lo-1, lo to mid-1, mid - hi-1,  hi & greater
int partition2(vector<int>& arr, int& mid, int start, int end) {
	int lo = start;
	mid = start;
	int hi = start;
	int pivot = arr[end];
	while (hi <= end-1) {
		if (arr[hi] < pivot) {
			swap(arr, lo, hi); lo++;
			swap(arr, mid, hi); mid++;
			hi++;
			//swap(arr, lo, mid);  // lo and mid or lo and hi ?
			//lo++; mid++; hi++;
		}
		else if (arr[hi] == pivot) {
			swap(arr, mid, hi);
			mid++; hi++;
		}
		else {
			hi++;
		}
	}
	swap(arr, end, mid);
	//cout << "start - " << start << ", end - " << end << endl;
	//print_arr(arr);
	return lo;
}



void _qsort(vector<int>& arr, int start, int end) {
	if (end > start) {
		int mid;
		int pivot = partition(arr, mid, start, end);
		// pivot to mid is equal to pivot
		_qsort(arr, start, pivot-1);
		_qsort(arr, mid+1, end);
	}
}


void qsort(vector<int>& arr) {
	_qsort(arr, 0, arr.size()-1);
}



int main() {
	vector<int> arr = {0, 0, 1, 1, 2, 2, 0, 0, 1};
	qsort(arr);
	print_arr(arr);
	return 0;
}