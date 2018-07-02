#include <iostream>
#include <vector>
// Start: 3.17pm
// End: 3.24pm
// Total:  7 mins
using namespace std;

void print_arr(vector<int>& arr, int odx) {
	cout << "{";
	for (int i=0; i<odx; i++) {
		cout << arr[i] << ",";
	}
	cout << "} ";
} 

/*
 f(idx) - prints subarray in output upto odx
 if (idx == len) print output
 else
    subsets(arr, idx+1, output, odx)
    output[odx] = arr[idx]
    subsets(arr, idx+1, output, odx+1)
*/
void subsets(vector<int>& arr, int idx, vector<int>& output, int odx) {
	if (idx == arr.size()) {
		print_arr(output, odx);
	}
	else {
	    subsets(arr, idx+1, output, odx);
	    output[odx] = arr[idx];
	    subsets(arr, idx+1, output, odx+1);
	}
}
 

void print_subsets(vector<int>& arr) {
	vector<int> output(arr.size());
	subsets(arr, 0, output, 0);
}


int main() {
	vector<int> arr = {1, 2, 3};
	print_subsets(arr);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}