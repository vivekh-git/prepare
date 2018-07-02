#include <bits/stdc++.h>
using namespace std;
//// NOTE: compute LIS for all elements prior. 
//  if any of those elements is less than current, 
//.     then LIS of current is 1 more than LIS of the element smaller than current. 
//. Compute max of this.

/* Recurrence relation
L(i)   = 1 + max ( L(j)) for j= 0 -> i and arr[j] < arr[i] or
L(i)   = 1 if no such j exists

L(arr, n, max_ref) -> if (n == 0)
						return 1;
					  int max_ending_here = 1;
					  for (int i =0; i < n; i++) {
						int sub = L(arr, i , max_ref);
						if (arr[i] < arr[n] && 1+sub > max_ending_here )
							max_ending_here = 1+sub;
					  }
					  if (max_ending_here > max_ref)
						max_ref = max_ending_here;
					  return max_ending_here;
*/
int _LIS(vector<int>& arr, int size, int& max_lis) {
	//cout << "size = " << size << endl;
	if (size == 1)
		return 1;
	
	int max_ending_here = 1;
	for (int i = 1; i < size; i++) {
		int sub = _LIS(arr, i, max_lis);
		//cout << "sub = " << sub << endl;
		if (arr[i-1] < arr[size-1] && 1+sub > max_ending_here) {
			max_ending_here = 1+sub;
		}
	}
	//cout << "max_end_here = " << max_ending_here << endl;
	
	if (max_ending_here > max_lis)
		max_lis = max_ending_here;
	
	return max_ending_here;
}


int _LIS2(vector<int>& arr, int end, int& max_lis) {
	//cout << "end = " << end << endl;
	if (end == 0)
		return 1;
	
	int max_ending_here = 1;
	for (int i = 0; i < end; i++) {
		int sub = _LIS2(arr, i, max_lis);
		//cout << "sub = " << sub << endl;
		if (arr[i] < arr[end] && 1+sub > max_ending_here) {
			max_ending_here = 1+sub;
		}
	}
	//cout << "max_end_here = " << max_ending_here << endl;
	
	if (max_ending_here > max_lis)
		max_lis = max_ending_here;
	
	return max_ending_here;
}


int LIS(vector<int>& arr) {
	int max_lis = 1;
	//_LIS(arr, arr.size(), max_lis);
	_LIS2(arr, arr.size()-1, max_lis);
	return max_lis;
} 

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int LIS_DP(vector<int>& arr) {
	vector<int> result(arr.size(), 1);
	
	int max_lis = 1;
	for (int r = 0; r < result.size(); r++) {
		for (int i = 0; i < r; i++) {
			if (arr[i] < arr[r] && 1+result[i] > result[r]) {
				result[r] = 1+result[i];
				if (result[r] > max_lis)
					max_lis = result[r];
			}	
		}
	}
	print_arr(result);
	
	int max = result[0];
	for (int i = 1; i < result.size(); i++) {
		if (result[i] > max)
			max = result[i];
	}
	cout << "max_lis: " << max_lis << endl;
	cout << "max: " << max << endl;
	return max;
}


void print_arr(vector<int>& res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}



void LIS_print_DP(vector<int>& arr) {
	vector<vector<int>> result(arr.size());
	result[0].push_back(arr[0]);
	
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && result[j].size()+1 > result[i].size())
				result[i] = result[j];
		}
		result[i].push_back(arr[i]);
	}
	
	vector<int> maxlis = result[0]; int maxlissize = 1;
	for (int i = 1; i < result.size(); i++) {
		if (result[i].size() > maxlis.size()) {
			maxlis = result[i];
			maxlissize = result[i].size();
		}
	}
	print_arr(maxlis);
	cout << "LIS size: " << maxlissize << endl;
}



int main() {
	vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 20};
	//vector<int> arr = {33, 22, 9, 32, 21, 50, 41, 60};
	int lis = LIS_DP(arr);
	cout << "lis = " << lis << endl;
	return 0;
}