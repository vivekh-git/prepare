#include <bits/stdc++.h>
using namespace std;

void print_arr_arr(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void print_arr(vector<int>& table) {
	for (int i = 0; i < table.size(); i++) {
		cout << table[i] << " ";
	}
	cout << endl;
}

/* Recursive relation
  C(n, r) = c(n-1, r-1) + c(n-1, r)
  c(n, 0) = c(n, n) = 1
*/

int NCR(int n, int r) {
	if (n == r || r == 0)
		return 1;
	else
		return NCR(n-1, r-1) + NCR(n-1, r);
}

//  0 <= r <= n
int NCR_DP(int n, int r) {
	vector<vector<int>> table(n+1, vector<int>(r+1, 0));
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < r+1; j++) {
			if (j > i) 
				continue;
			else if (i == j || j == 0)
				table[i][j] = 1;
			else 
				table[i][j] = table[i-1][j-1] + table[i-1][j];
			
		}
	}
	print_arr_arr(table);
	return table[n][r];
}

//  0 <= r <= n
int NCR_DP2(int n, int r) {
	vector<int> table(r+1, 0);
	table[0] = 1;	
	for (int i = 1; i < n+1; i++) {
		for (int j = r+1; j > 0; j--) {
			if (j > i) continue;
			table[j] = table[j] + table[j-1];			
		}
	}
	print_arr(table);
	return table[r];
}

int main() {
	int n, r;
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter R: ";
	cin >> r;
	NCR_DP(n, r);
	int res = NCR_DP2(n, r);
	cout << "ncr = " << res << endl;
	return 0;
}