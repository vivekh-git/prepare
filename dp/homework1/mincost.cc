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

int minCost_DP(vector<vector<int>>& cost, int M, int N) {
	vector<vector<int>> table(cost.size(), vector<int>(cost[0].size(), 0));
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 && j == 0)
				table[i][j] = cost[i][j];
			else if (i == 0)
				table[i][j] = cost[i][j] + table[i][j-1];
			else if (j == 0)
				table[i][j] = cost[i][j] + table[i-1][j];
			else
				table[i][j] = cost[i][j] + min(min(table[i-1][j-1], table[i][j-1]), table[i-1][j]);
		}
	}
	print_arr_arr(table);
	return table[M][N];
}

vector<pair<int,int>> print_minCost_DP(vector<vector<int>>& cost, int M, int N) {
	cout << "cost:" << endl;
	print_arr_arr(cost);
	vector<vector<int>> table(cost.size(), vector<int>(cost[0].size(), 0));
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 && j == 0)
				table[i][j] = cost[i][j];
			else if (i == 0)
				table[i][j] = cost[i][j] + table[i][j-1];
			else if (j == 0)
				table[i][j] = cost[i][j] + table[i-1][j];
			else
				table[i][j] = cost[i][j] + min(min(table[i-1][j-1], table[i][j-1]), table[i-1][j]);
		}
	}
	cout << "table: " << endl;
	print_arr_arr(table);
	vector<pair<int,int>> path; pair<int, int> pnode = {M, N};
	path.push_back(pnode);
	while (pnode != make_pair(0,0)) {
		int m = pnode.first; int n = pnode.second;
		//cout << "m = " << m << ", n = " << n << endl;
		if (m > 0 && table[m][n]-cost[m][n] == table[m-1][n]) {
			m = m-1;
		}
		else if (n > 0 && table[m][n]-cost[m][n] == table[m][n-1]) {
			n = n-1;
		}
		else if (table[m][n]-cost[m][n] == table[m-1][n-1]) {
			m = m-1; n = n-1;
		}
		pnode = make_pair(m, n);
		path.push_back(pnode);
	}
	reverse(path.begin(), path.end());
	return path;
}


int main() {
   vector<vector<int>> cost = { {1, 10, 3},
                                {1, 18, 5},
                                {3, 15, 3} };
   vector<pair<int,int>> path = print_minCost_DP(cost, 2, 2);
   for (int i = 0; i < path.size(); i++) {
	   cout << "{" <<path[i].first << "," << path[i].second << "}, ";
   }
   cout << endl;
   return 0;
}