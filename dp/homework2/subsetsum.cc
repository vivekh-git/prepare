#include <bits/stdc++.h>

using namespace std;

bool subsetSumUtil(vector<long long int> arr, int n, long long int sum, int size) {
    if (sum == 0 && size > 0)
        return true;
	if (n == 0)
        return false;
    return subsetSumUtil(arr, n-1, sum-arr[n-1], size+1) || subsetSumUtil(arr, n-1, sum, size);
}


bool check_if_sum_possible(vector <long long int> arr, long long int k) {
    // subset sum problem
    // f(i, k) ->  f(i+1, k-arr[i]) || f(i+1, k)
    return subsetSumUtil(arr, arr.size(), k, 0);
}

void print_arr(vector<vector<bool>>& dp) {
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j< dp[i].size(); j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}

void print_arr(vector<int>& p) {
	for (int i = 0; i < p.size(); i++)
		cout << p[i] << " ";
	cout << endl;
}

void print_res(vector<vector<bool>>& dp, int n, int sum, vector<int>& arr, vector<int>& p) {
	// base case
	if (n == 0) {
		if (sum == 0)
			print_arr(p);
		return;
	}
	
	if (sum >= arr[n-1] && dp[n-1][sum-arr[n-1]]) { // current element considered
		p.push_back(arr[n-1]);
		print_res(dp, n-1, sum-arr[n-1], arr, p);
		p.pop_back();
	} 
	if (dp[n-1][sum])
		print_res(dp, n-1, sum, arr, p);

	return;
}

// this works only if set has positive integers. Otherwise j-arr[i-1] can result in negative index
bool isSubSet_DP(vector<int> arr, int sum) {
	int n = arr.size();
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	// set elements are rows and sum are columns
	// dp[i][j] -> checks if arr[0...i] have any subset with sum j
	vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0));
	for (int i = 0; i < n+1; i++)
		dp[i][0] = true; // arr[0... any] will have empty subset summing to 0
	for (int j = 1; j < sum+1; j++)
		dp[0][j] = false; // arr[0...0] - empty set - can not add up any sum except 0 sum
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < sum+1; j++) {
			if (j >= arr[i-1])
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	vector<int> p;
	print_arr(dp);
	print_res(dp, n, sum, arr, p);
	return dp[n][sum];
}

int main()
{
    //ostream &fout = cout;
	/*
    bool res;
    int arr_size = 0;
    cin >> arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<long long int> arr;
    for(int i = 0; i < arr_size; i++) {
        long long int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr.push_back(arr_item);
    }

    long long int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	*/
	//vector<long long int> arr = {2, 4, 6};
	//long long int k = 5;
	
	vector<int> arr = {2,3,5,6,8,10};
	int k = 10;
	//vector<int> arr= {2,4,6};
	//int k = 8;
	bool res = isSubSet_DP(arr, k);

    //bool res = check_if_sum_possible(arr, k);
    cout << res << endl;

    
    return 0;
}