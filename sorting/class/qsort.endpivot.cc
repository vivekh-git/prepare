#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

// [ 0 1 2 3 4 5 ]
// [ 5 2 7 1 9 4 ] - lo = 0, hi = 4, pivot = 5
// [ 9 2 7 1 5 4 ] - lo = 0, hi = 3
// [ 1 2 7 9 5 4 ] - lo = 2, hi = 1
// [ 1 2 4 9 5 7 ]
// < pivot, unseen, > pivot
// till lo-1, lo - hi-1, hi & greater
int partition(vector<int>& arr, int start, int end) {
	int lo = start;
	int hi = end - 1;
	int pivot = arr[end];
	while (lo <= hi) {
		if (arr[lo] < pivot) {
			lo++;
		}
		else {
			swap(arr, lo, hi);
			hi--;
		}
	}
	swap(arr, end, lo);
	return lo;
}

// [ 0 1 2 3 4 5 ] - index
// [ 5 2 7 1 9 4 ] - lo = 0, hi = 0, pivot = 5
// [ ]
// < pivot, > pivot, unseen
// till lo-1, lo - hi-1, hi & greater
int partition2(vector<int>& arr, int start, int end) {
	int lo = start;
	int hi = start;
	int pivot = arr[end];
	while (hi <= end-1) {
		if (arr[hi] < pivot) {
			swap(arr, lo, hi);
			lo++; hi++;
		}
		else {
			hi++;
		}
	}
	swap(arr, end, lo);
	return lo;
}



void _qsort(vector<int>& arr, int start, int end) {
	if (end > start) {
		int pivot = partition2(arr, start, end);
		_qsort(arr, start, pivot-1);
		_qsort(arr, pivot+1, end);
	}
}


void qsort(vector<int>& arr) {
	_qsort(arr, 0, arr.size()-1);
}


void print_arr(vector<int>& arr) {
	for (int i=0; i<arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size()-1) cout << ", ";
	}
	cout << endl;
}


int main() {
	vector<int> arr = {5, 2, 7, 1, 25, 17, 14};
	qsort(arr);
	print_arr(arr);
	return 0;
}