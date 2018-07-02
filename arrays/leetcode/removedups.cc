#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int u = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[u]) {
                nums[u+1] = nums[i];
                u++;
            }    
        }
        return u+1;
}
	
int main () {
	vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
	int len = removeDuplicates(nums);
	for (int i = 0; i < len; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}