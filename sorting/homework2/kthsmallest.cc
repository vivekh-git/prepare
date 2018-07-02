#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}


void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int partition(vector<int>& arr, int start, int end) {
	int pivot = end;
	int lo = start; int hi = start;
	while (hi < end) {
		if (arr[hi] < arr[pivot]) {
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


int randPartition(vector<int>& arr, int start, int end) {
	int width = end-start+1;
	int r = rand() % width;
	swap(arr, end, start+r);
	return partition(arr, start, end);
}

int kthsmallest(vector<int>& arr, int start, int end, int k) {
	if (k > 0 && end >= start) {
		int pivot = randPartition(arr, start, end);
		if (k-1 == pivot-start) {
			return arr[pivot];
		}
		else if (k-1 < pivot-start) {
			return kthsmallest(arr, start, pivot-1, k);
		}
		else {
			return kthsmallest(arr, pivot+1, end, k-1-pivot+start);
		}
	}
	return INT_MAX;
}


int main() {
	vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
	int k = 7;
	print_arr(arr);
	int res = kthsmallest(arr, 0, arr.size()-1, k);
	print_arr(arr);
	cout << "K'th smallest element is " << res << endl;
	//print_arr(arr);
	return 0;
}