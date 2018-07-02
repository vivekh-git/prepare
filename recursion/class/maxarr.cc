#include <iostream>
#include <vector>

using namespace std;

/*
 f(idx, max)  
 if (idx == len) print max
 else 
    if (arr[idx] > max)
       max = arr[idx]
    f(idx+1, max)           
*/
void maxarray(vector<int>& arr, int idx, int& max) {
	if (arr.empty()) return;
	else if (idx == arr.size()) {
		cout << max << endl;
	}
	else {
		if (arr[idx] > max) {
			max = arr[idx];
		}
		maxarray(arr, idx+1, max);
	}
}

int main() {
	vector<int> arr = {3, 21, 8};
	int max = INT_MIN;
	maxarray(arr, 0, max);
	//cout << m << endl;
	return 0;
}