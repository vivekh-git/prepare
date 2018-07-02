#include <bits/stdc++.h>
using namespace std;

int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                for (int k = 0; k < C.size(); k++) {
                    for (int l =0; l < D.size(); l++) {
                        if (A[i] + B[j] + C[k] + D[l] == 0)
                            count++;
                    }
                }
            }
        }
        return count;
}

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	unordered_map<int, int> countSumMap;
	for (int i =0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (countSumMap.count(0-A[i]-B[j]) == 0)
				countSumMap[0-A[i]-B[j]] = 1;
			else
				countSumMap[0-A[i]-B[j]]++;
		}
	}
	int counter = 0;
	for (int k = 0; k < C.size(); k++) {
		for (int l = 0; l < D.size(); l++) {
			if (countSumMap.count(C[k]+D[l]) != 0)
				counter += countSumMap[C[k]+D[l]];
		}
 	}
	return counter;
}


vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result; // need atleast 4 numbers to have a result
        sort(nums.begin(), nums.end());
		// do 2 for loops for first 2 numbers and then use 2 pointer technique
		for (int i = 0; i < nums.size()-3; i++) {
			// check for dups
			if (i > 0 && nums[i] == nums[i-1]) continue;
			for (int j = i+1; j < nums.size()-2; j++) {
				// check for dups
				if (j > i+1 && nums[j] == nums[j-1]) continue;
				// Now use 2 pointer technique
				int k = j+1; int l = nums.size()-1;
				while (k < l) {
					if (k > j+1 && nums[k] == nums[k-1]) {k++; continue;} // deduping k
					// no need to dedupe l - as if 3 elements out of 4 suming to a target are deduped, 4th is automatically deduped
					int sum = nums[i] + nums[j] + nums[k] + nums[l];
					if (sum == target) {
						vector<int> res = {nums[i], nums[j], nums[k], nums[l]};
						result.push_back(res);
						k++; l--;
					}
					else if (sum > target) {
						l--;
					}
					else {
						k++;
					}
				}
			}
		}
		return result;
}


int main() {
	/*
	vector<int> A = {1,2};
	vector<int> B = {-2,-1};
	vector<int> C = {-1,2};
	vector<int> D = {0,2};
	cout << "fourcountSum = " << fourSumCount(A,B,C,D) << endl;
	*/
	vector<int> nums = {-1,0,-5,-2,-2,-4,0,1,-2};
	vector<vector<int>> res = fourSum1(nums, -9);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}