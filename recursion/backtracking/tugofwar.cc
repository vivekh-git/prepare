#include <bits/stdc++.h>
using namespace std;

void TugOfWarUtil(vector<int>& arr, int pos, vector<int>& subset1, vector<int>& subset2, int sum1, int sum2, int& min_sum_diff) {
	if (pos === arr.size()) {
		return;
	}
	if (subset1.size() > (arr.size()+1)/2)
		return;
	else if (subset2.size() > (arr.size()+1)/2)
		return;
	
	//include in subset1
	subset1.push_back(arr[pos]);
	TugOfWarUtil(arr, pos+1, subset1, subset2, sum1+arr[pos], sum2, min_sum_diff);
	
	subset2.push_back(arr[pos]);
	TugOfWarUtil(arr, pos+1, subset1, subset2, sum1, sum2+arr[pos], min_sum_diff);
	
	
}

// n = 10, n/2 = 5
// n = 11, n/2 = 5
void TugOfWar(vector<int>& arr, int size) {
	vector<int>& subset1, subset2;
	int min_diff = INT_MAX
    TugOfWarUtil(arr, 0, subset1, subset2, 0, 0, min_diff);
}


// Driver program to test above functions
int main() {
	vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	
    TugOfWar(arr, arr.size());
    return 0;
}