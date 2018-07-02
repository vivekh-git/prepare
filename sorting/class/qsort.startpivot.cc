#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

// [ 0 1 2 3 4 5 ]
// [ 5 2 7 1 9 4 ] - lo = 1, hi = 5
// [ 5 2 4 1 9 7 ] - lo = 2, hi = 4
// [ 1 2 4 5 7 9 ] - lo = 4, hi = 3
// < pivot, unseen, > pivot
// till lo-1, lo - hi-1, hi & greater
int partition(vector<int>& arr, int start, int end) {
	int lo = start + 1;
	int hi = end;
	int pivot = arr[start];
	while (lo <= hi) {
		if (arr[lo] < pivot) {
			lo++;
		}
		else {
			swap(arr, lo, hi);
			hi--;
		}
	}
	swap(arr, start, lo-1);
	return lo-1;
}

// [ 0 1 2 3 4 5 ] - index
// [ 5 2 7 1 9 4 ] - lo = 1, hi = 1, end = 5
// [ 4 2 1 5 9 7 ] - lo = 4, hi = 6
// < pivot, > pivot, unseen
// till lo-1, lo - hi-1, hi & greater
int partition2(vector<int>& arr, int start, int end) {
	int lo = start + 1;
	int hi = start + 1;
	int pivot = arr[start];
	while (hi <= end) {
		if (arr[hi] < pivot) {
			swap(arr, lo, hi);
			lo++; hi++;
		}
		else {
			hi++;
		}
	}
	swap(arr, start, lo-1);
	return lo-1;
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