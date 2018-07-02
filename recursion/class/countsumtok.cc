#include <iostream>
#include <vector>

using namespace std;


int countsumtok(vector<int>& arr, int idx, int remaining_total) {
	if (remaining_total == 0) {
		return 1;
	}
	else if (idx == arr.size()) { // base case
		return 0;
	}
	else { // subset problem
		return countsumtok(arr, idx+1, remaining_total) + countsumtok(arr, idx+1, remaining_total - arr[idx]);
	}
}


int main() {
	vector<int> input = {1, 2, 3, 2, 4};
	int sum = 4;
	
	int k = countsumtok(input, 0, sum);
	cout << "count - " << k << endl;
	return 0;
}