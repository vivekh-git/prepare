#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(vector<int>& arr, int pos1, int pos2) {
        int tmp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = tmp;
    }
    
    int partition(vector<int>& arr, int start, int end) {
        int pivot = end;
        int lo = start; int hi = start;
        while (hi < end) {
            if (arr[hi] < arr[pivot]) {
                swap(arr, hi, lo);
                lo++; hi++;
            }
            else {
                hi++;
            }
        }
        swap(arr, end, lo);
        return lo;
    }
    
    int randomPartition(vector<int>& nums, int start, int end) {
        //int width = end-start+1;
        //int r = rand()%width;
        //swap(nums, end, start+r);
        return partition(nums, start, end);
    }
    
    int findkthlargest(vector<int>& nums, int start, int end, int k) {
        if (k > 0 && k <= end-start+1) {
            int pivot = randomPartition(nums, start, end);
            if (k-1 == end-pivot)
                return nums[pivot];
            else if (end-pivot < k-1)
                return findkthlargest(nums, start, pivot-1, (k-(end-pivot+1)));
            else
                return findkthlargest(nums, pivot+1, end, k); 
        }
        return INT_MIN;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return findkthlargest(nums, 0, nums.size()-1, k);
    }
};

int main() {
	vector<int> arr = {3,2,3,1,2,4,5,5,6};
	int k = 4;
	Solution sol;
	int res = sol.findKthLargest(arr, k);
	cout << "res = " << res << endl;
	return 0;
}