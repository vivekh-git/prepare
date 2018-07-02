#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(vector<int>& arr, int st, int end) {
	int low = st+1;
	int high = st+1;
	while (high <= end) {
		if (arr[high] < arr[st]) {
			swap(arr, low, high);
			low++;
		}
		high++;
	}
	swap(arr, low-1, st);
	return low-1;
}

int findk(vector<int>& arr, int st, int end, int k) {
	//cout << "findk: " << st << " : " << end << " : " << k << endl;
	if (end >= st) {
		int pivot = partition(arr, st, end);
		if (pivot == k) {
			return arr[pivot];
		}
		else if (pivot > k) {
			return findk(arr, st, pivot-1, k);
		}
		else {
			return findk(arr, pivot+1, end, k);
		}
	}
	return -1;
}


int findkthelement(vector<int>& arr, int k) {
	return findk(arr, 0, arr.size()-1, k-1);
}

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	std::vector<int> arr  { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
    print_arr(arr);
	int k = 9;
	cout << "finding " << k << " th element" << endl; 
    int kelement = findkthelement(arr, k);	
	cout << kelement << endl;
	print_arr(arr);
	sort(arr.begin(), arr.end());
	print_arr(arr);
	return 0;
}