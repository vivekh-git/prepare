#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void print_arr_arr(vector<vector<int>>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

/* Recurrence Relation
Number of ways of coin change
f(amount, dset_i) -> if (amount == 0 )
						return 1;
					 else if (amount < 0)
						return 0;
					 else if (dset_i == dset_size)
						return 0;
					 else
						f(amount - dset[dest_i], dset_i) + f(amount, dset_i+1)
// set count of coins needed to achieve the change
// 7 - { 1 1 1 1 1 1 1}, {5 1 1 }  - set count = 2 (order of coins dont matter - 1 1 5 and 1 5 1 and 5 1 1 are considered same
*/
int SetCountCoinChange(int amount, vector<int>& denomination, int di) { // pass dsize
	if (amount == 0)
		return 1;
	else if (amount < 0)
		return 0;
	else if (di == denomination.size())
		return 0;
	else
		return SetCountCoinChange(amount-denomination[di], denomination, di) + SetCountCoinChange(amount, denomination, di+1);
}

int SetCountCoinChange_DP(int amount, vector<int>& denomination) {
	vector<vector<int>> table(amount+1, vector<int>(denomination.size(), 0));
	for (int i = 0; i < amount+1; i++) {
		for (int j = 0; j < denomination.size(); j++) {
			if (i == 0)
				table[i][j] = 1;
			else {
				int x = (i >= denomination[j]) ? table[i-denomination[j]][j] : 0;
				int y = (j > 0) ? table[i][j-1] : 0;
				table[i][j] = x + y;
			}
		}
	}
	return table[amount][denomination.size()-1];
}

/* Driver Program to test above functions */
int main() {
	int amount;
	cin >> amount;
	
	vector<int> denomination = {2,5,3,6};
	
	//grid[0][0] = 0;
	//int count = SetCountCoinChange(amount, denomination, 0);
	int count = SetCountCoinChange_DP(amount, denomination);
	cout << "count = " << count << endl;
 
    return 0;
}
