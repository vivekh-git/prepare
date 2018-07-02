#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> dict;
	vector<int> result;
	for (int i = 0; i < nums1.size(); i++)
		dict.insert(nums1[i]);
	
	for (int i = 0; i < nums2.size(); i++) {
		if (dict.count(nums2[i]) != 0) {
			result.push_back(nums2[i]);
			dict.erase(nums2[i]);
		}
	}
	return result;
}


int main() {
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	vector<int> result = intersection(nums1, nums2);
	print_arr(result);
	return 0;
}