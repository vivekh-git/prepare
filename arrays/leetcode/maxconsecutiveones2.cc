#include <bits/stdc++.h>
using namespace std;

// you can flip one zero to 1. meaning - in the window l to r, there can be a max of one zero
int findMaxConsecutiveOnes(vector<int>& nums) {
	if (nums.empty()) return 0;
	int k = 1; // number of zeros allowed 
	int left =0; int right = left+1; int zerosfound = 0; int maxlen = 1;
	if (nums[left] == 0) 
		zerosfound = 1;
	for (; right < nums.size(); right++) {
		if (nums[right] == 0)
			zerosfound++;
		for (; zerosfound > k; left++) {
			if (nums[left] == 0)
				zerosfound--;
		}
		if (right-left+1 > maxlen)
			maxlen = right-left+1;
	}
	return maxlen;
}


int main() {
	vector<int> nums = {1, 0, 1, 1, 0};
	cout << findMaxConsecutiveOnes(nums) << endl;
	return 0;
}