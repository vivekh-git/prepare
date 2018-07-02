#include <bits/stdc++.h>
using namespace std;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cmax = 0; int gmax = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                gmax++;
                if (gmax > cmax) cmax = gmax;
            }
            else {
                gmax = 0;
            }
        }
        return cmax;
    }
	
	int main() {
		vector<int> nums = {1, 1, 0, 1,1,1};
		cout << findMaxConsecutiveOnes(nums) << endl;
		return 0;
	}