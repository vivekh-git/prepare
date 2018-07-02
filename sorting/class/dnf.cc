#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swapstr(string& str, int pos1, int pos2) {
	char tmp = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = tmp;
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
int partition(string& str, int& mid, int start, int end) {
	int lo = start;
	mid = start;
	int hi = end - 1;
	char pivot = str[end];
	while (mid <= hi) {
		if (str[mid] < pivot) {
			swapstr(str, mid, lo);
			lo++; mid++;
		}
		else if (str[mid] == pivot) {
			mid++;
		}
		else {
			swapstr(str, mid, hi);
			hi--;
		}
	}
	swapstr(str, end, mid);
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
int partition2(string& str, int& mid, int start, int end) {
	int lo = start;
	mid = start;
	int hi = start;
	int pivot = str[end];
	while (hi <= end-1) {
		if (str[hi] < pivot) {
			swapstr(str,lo, hi); lo++;
			swapstr(str, mid, hi); mid++;
			hi++;
			//swapstr(str, lo, mid);  // lo and mid or lo and hi ?
			//lo++; mid++; hi++;
		}
		else if (str[hi] == pivot) {
			swapstr(str, mid, hi);
			mid++; hi++;
		}
		else {
			hi++;
		}
	}
	swapstr(str, end, mid);
	//cout << "start - " << start << ", end - " << end << endl;
	//print_arr(arr);
	return lo;
}



void _qsort(string& str, int start, int end) {
	if (end > start) {
		int mid;
		int pivot = partition2(str, mid, start, end);
		// pivot to mid is equal to pivot
		_qsort(str, start, pivot-1);
		_qsort(str, mid+1, end);
	}
}


void qsort(string& str) {
	_qsort(str, 0, str.length()-1);
}



int main() {
	//vector<int> arr = {2, 0, 2, 1, 1, 0, 2};
	string str = "GGGGGB";
	qsort(str);
	cout << str << endl;
	//print_arr(arr);
	return 0;
}