#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // moving window problem
    // [2,3,1,2,4,3], s = 7
    // left = 0, right= 3, sum = 8
	/*
left right  sum  2=7   minlen
0            2         INT_MAX
      1      5	
      2      6
	  3      8           4
1            6           3
	  4      10
2			  7
3			  6          2
	  5.      9
4			  7
			  3
	*/
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = INT_MAX;
        if (nums.empty()) return 0;
        int left = 0; int sum = nums[left]; int right = 0;
		if (sum >= s) 
			minlen = right-left + 1;
		
        for (right = left+1; right < nums.size(); right++) {
            sum += nums[right];
            if (sum < s) continue;
            // sum >= s
            if (right-left+1 < minlen) {
                minlen = right-left+1;
				cout << "1" << left << " == " << right << minlen << endl;
			}
            // shrink left
            for (; sum >= s; left++) {
                sum -= nums[left];
            }
			// take left - 1 as left -1 was pos where sum >= s
            if (right-left+2 < minlen) {
				
                minlen = right-left+2;
				cout << "2" << left << " == " << right << minlen << endl;
			}
        }
        if (sum >= s && right-left+1 < minlen) {
            minlen  = right-left+1;
			cout << "3" << left << " == " << right << minlen << endl;
		}
		if (minlen == INT_MAX)
			return 0;
        return minlen;
    }
};


class Solution2 {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
		unordered_map<int, int> dict;
		int sum = 0;
		int maxlen = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum == k) {
				maxlen = i+1;
			}
			else if (dict.count(sum-k) != 0) {
				//int left = dict[sum-k] + 1;
				//int width = i - left + 1;
				if (i-(dict[sum-k]+1)+1 > maxlen)
					maxlen = i-(dict[sum-k]+1)+1 ;
			}
			if (dict.count(sum) == 0)
				dict[sum] = i;
		}
		if (maxlen == INT_MIN)
			return 0;
		return maxlen;
    }
};

int main() {
	vector<int> nums = {1,0,-1};
	int k = -1;
	Solution2 sol;
	int minlen = sol.maxSubArrayLen(nums, k);
	cout << "minlen = " << minlen << endl;
	return 0;
}