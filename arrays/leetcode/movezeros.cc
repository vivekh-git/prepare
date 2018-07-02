#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int pos1, int pos2) {
    int tmp = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = tmp;
}
void moveZeroes(vector<int>& nums) {
    if (nums.size() == 0) return;
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) continue;
        if (j <= i) j = i+1;
        for (; j < nums.size(); j++) {
            if (nums[j] == 0) continue;
            swap(nums, i, j);
            break;
        }
    }
}

void print_arr(vector<int>& nums) {
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

int main() {
	vector<int> nums = {0, 1, 0, 3, 12};
	moveZeroes(nums);
	print_arr(nums);
	return 0;
}