#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int>& arr) {
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

// Min Count of Coin Change
/*New recurrence relation
f(amount, dset_i) -> if (amount == 0 )
						return 1;
					 else if (amount < 0)
						return 0;
					 else if (dset_i == dset_size)
						return 0;
					 else
						return 1 + min (f(amount - dset[dest_i], dset_i), f(amount, dset_i+1));
*/
// smallest number of coins needed to achieve the change
// 7 - { 1 1 1 1 1 1 1}, {5 1 1 } { 1 5 1 } { 1 1 5} - smallest number of coins  = 3
int MinSetSizeCoinChange(int amount, vector<int>& denomination, int di) {
	if (amount == 0)
		return 1;
	else if (amount < 0)
		return 0;
	else if (di == denomination.size())
		return 0;
	else
		return 1 + min (MinSetSizeCoinChange(amount-denomination[di], denomination, di), MinSetSizeCoinChange(amount, denomination, di+1));
}

// Min Count of Coin Change
/*  Recurrence Relation
  f(amount)  -> if (amount == 0)
				   return 0;
				for (int i = 0; i < denom.size(); i++) {
					x  = f(amount- denom[i]);
				}
				return 1 + min(x)

	if (amount == 0)
		return 0;
	else {
		int min = INT_MAX; int sub;
		for (int i = 0; i < denomination.size(); i++) {
			if (denomination[i] <= amount) {
				sub = MinSetSizeCoinChange(amount-denomination[i], denomination);
				//cout << "sub = " << sub << endl;
				if (sub < min)
					min = sub;
			}
		}
		if (min == INT_MAX)
			return INT_MAX;
		else
			return 1 + min;
*/
int MinSetSizeCoinChange(int amount, vector<int>& denomination) {
	if (amount == 0)
		return 0;
	else {
		int min = INT_MAX; int sub;
		for (int i = 0; i < denomination.size(); i++) {
			if (denomination[i] <= amount) {
				sub = MinSetSizeCoinChange(amount-denomination[i], denomination);
				//cout << "sub = " << sub << endl;
				if (sub < min)
					min = sub;
			}
		}
		if (min == INT_MAX)
			return INT_MAX;
		else
			return 1 + min;
	}
}


/* Recurrence Relation
  f(amount)  -> if (amount == 0)
				   return 0;
				for (int i = 0; i < denom.size(); i++) {
					x  = f(amount- denom[i]);
				}
				return 1 + min(x)
*/
int MinSetSizeCoinChangeDP(int amount, vector<int>& denomination) {
	vector<int> result(amount+1);
	result[0] = 0;
	for (int i = 1; i < amount+1; i++) {
		int min  = INT_MAX; int sub;
		for (int d = 0; d < denomination.size(); d++) {
			if (denomination[d] <= i) {
				sub = result[i-denomination[d]];
				if (sub < min)
					min = sub;
			}
		}
		if (min == INT_MAX)
			result[i] = INT_MAX;
		else
			result[i] = 1 + min;
	}
	print_arr(result);
	return result[amount];
}

vector<vector<int>> printMinSetSizeCoinChangeDP(int amount, vector<int>& denomination) {
	vector<int> result(amount+1);
	result[0] = 0;
	for (int i = 1; i < amount+1; i++) {
		int min  = INT_MAX; int sub;
		for (int d = 0; d < denomination.size(); d++) {
			if (denomination[d] <= i) {
				sub = result[i-denomination[d]];
				if (sub < min)
					min = sub;
			}
		}
		if (min == INT_MAX)
			result[i] = INT_MAX;
		else
			result[i] = 1 + min;
	}
	print_arr(result);
	cout << "Min Coin Count = " << result[amount] << endl;
	
	vector<vector<int>> coins; vector<int> arr; int A = amount;
	while (A > 0) {
		int min = INT_MAX; int mindenom;
		for (int d = 0; d < denomination.size(); d++) {
			if (denomination[d] <= A && result[A-denomination[d]] < min) {
				min = result[A-denomination[d]];
				mindenom = denomination[d];
			}
		}
		arr.push_back(mindenom);
		A = A - mindenom;
	}
	coins.push_back(arr);
	return coins;
}

/* Driver Program to test above functions */
int main() {
	int amount;
	cin >> amount;
	
	vector<int> denomination = {1,2,3};
	
	//grid[0][0] = 0;
	//int count = MinSetSizeCoinChange(amount, denomination, 0);
    vector<vector<int>> coins = printMinSetSizeCoinChangeDP(amount, denomination);
	print_arr_arr(coins);
 
    return 0;
}
