#include <bits/stdc++.h>

using namespace std;

void print_arr(vector<int>& dp) {
	for (int i = 0; i < dp.size(); i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
}

void print_arr(vector<list<int>>& dplist) {
	for (int i = 0; i < dplist.size(); i++) {
		cout << i << " -> ";
		for (auto it = dplist[i].begin(); it != dplist[i].end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}


int IntegerBreak(int n) {
	vector<int> dp(n+1, 0);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i+1; j++) {
			if (i+j <= n) {
				dp[i+j] = max(max(dp[i], i) * max(dp[j], j), dp[i+j]);
			}
		}
	}
	print_arr(dp);
	return dp[n];
}

int product(list<int>& l) {
	if (l.empty()) return 0;
	int res = 1;
	for (auto it = l.begin(); it != l.end(); it++) {
		res = res * (*it);
	}
	return res;
}


int IntegerBreak_DP1(int n) {
	vector<int> dp(n+1);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i+1; j++) {
			if (i+j <= n)
				dp[i+j] = max(max(dp[i], i) * max(dp[j], j), dp[i+j]);
		}
	}
	print_arr(dp);
	return dp[n];
}


int IntegerBreak_DP2(int n) {
	vector<int> dp(n+1);
	vector<list<int>> dplist(n+1);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i+1; j++) {
			if (i+j <= n) {
				int ip = max(dp[i], i);
				int jp =  max(dp[j], j);
				int m = ip * jp;
				if (m > dp[i+j]) {
					list<int> l;
					if (dp[i] > i) {
						for (auto it = dplist[i].begin(); it != dplist[i].end(); it++)
							l.push_back(*it);
					}
					else {
						l.push_back(i);
					}
					if (dp[j] > j) {
						for (auto it = dplist[j].begin(); it != dplist[j].end(); it++)
							l.push_back(*it);
					}
					else {
						l.push_back(j);
					}
					dp[i+j] = m;
					dplist[i+j] = l;
				}
			}
		}
	}
	print_arr(dp);
	print_arr(dplist);
	return dp[n];
}


int prod(list<int>& l) {
	if (l.empty()) return 0;
	int res = 1;
	for (auto it = l.begin(); it != l.end(); it++)
		res = res * (*it);
	return res;
}

int IntegerBreak_DP3(int n) {
	//vector<int> dp(n+1);
	vector<list<int>> dplist(n+1);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i+1; j++) {
			if (i+j <= n) {
				int ip = max(prod(dplist[i]), i);
				int jp =  max(prod(dplist[j]), j);
				int m = ip * jp;
				if (m > prod(dplist[i+j])) {
					list<int> l;
					if (prod(dplist[i]) > i) {
						for (auto it = dplist[i].begin(); it != dplist[i].end(); it++)
							l.push_back(*it);
					}
					else {
						l.push_back(i);
					}
					if (prod(dplist[j]) > j) {
						for (auto it = dplist[j].begin(); it != dplist[j].end(); it++)
							l.push_back(*it);
					}
					else {
						l.push_back(j);
					}
					//dp[i+j] = m;
					dplist[i+j] = l;
				}
			}
		}
	}
	//print_arr(dp);
	print_arr(dplist);
	return prod(dplist[n]);
}


int IntegerBreak_DP(int n) {
	//vector<int> dp(n+1, 0);
	vector<list<int>> dplist(n+1);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < i+1; j++) {
			if (i+j <= n) {
				list<int> l;
				int ip = product(dplist[i]);
				int jp = product(dplist[j]);
				int ijp = product(dplist[i+j]);
				int m = max(i, ip) * max(j, jp);
				//int m = max(dp[i], i) * max(dp[j], j);
				if (m > ijp) {
					if (ip > i)
						for (auto it = dplist[i].begin(); it != dplist[i].end(); it++)
							l.push_back(*it);
					else 
						l.push_back(i);
					if (jp > j)
						for (auto it = dplist[j].begin(); it != dplist[j].end(); it++)
							l.push_back(*it);
					else 
						l.push_back(j);
					dplist[i+j] = l;
				}
			}
		}
	}
	//print_arr(dp);
	print_arr(dplist);
	return product(dplist[n]);
}


/*
 2 = 1*1
 3 = 1*2
 4 = 2*2
 5 = 3*2
 6 = 3*3
*/
int IntegerBreak2(int n) {
	int result = 0;
	if (n < 2)
		return -1;
	else if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n == 4)
		return 4;
	else if (n % 3 == 0) 
		return pow(3, n/3);
    else if (n % 3 == 2)
		return pow(3, n/3)*2;
	else if (n % 3 == 1)
		return pow(3, (n-4)/3)*4;
	else
		return -1;		
}


int main() {
	int n;
	cin >> n;
	int res1 = IntegerBreak_DP3(n);
	cout << res1 << endl;
	return 0;
}