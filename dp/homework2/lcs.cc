#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int LCS(string& str1, string& str2, int M, int N) {
	if (M == 0 || N == 0)
		return 0;
	else if (str1[M-1] == str2[N-1])
		return 1 + LCS(str1, str2, M-1, N-1);
	else
		return max(LCS(str1, str2, M-1, N), LCS(str1, str2, M, N-1));
}

int LCS_DP(string& str1, string& str2, int M, int N) {
	vector<vector<int>> table(M+1, vector<int>(N+1, 0));
	for (int m = 0; m < M+1; m++) {
		for (int n = 0; n < N+1; n++) {
			if (m == 0 || n == 0)
				table[m][n] = 0;
			else if (str1[m-1] == str2[n-1])
				table[m][n] = 1 + table[m-1][n-1];
			else
				table[m][n] = max(table[m-1][n], table[m][n-1]);
		}
	}
	print_arr(table);
	return table[M][N];
}

int LCS_DP2(string& str1, string& str2, int M, int N) {
	vector<vector<int>> table(2, vector<int>(N+1, 0));
    // bi - binary index and bindex do the same thing
	bool bi = false;
	int bindex = 0;
	for (int m = 0; m < M+1; m++) {
		bi = m&1;
		if (m % 2 == 0) bindex = 0; else bindex = 1;
		cout << "m = " << m << ", bi = " << bi << ", bindex = " << bindex << endl;
		for (int n = 0; n < N+1; n++) {
			if (m == 0 || n == 0)
				table[bi][n] = 0;
			else if (str1[m-1] == str2[n-1])
				table[bi][n] = 1 + table[1-bi][n-1];
			else
				table[bi][n] = max(table[1-bi][n], table[bi][n-1]);
		}
		print_arr(table);
	}
	cout << "bi = " << bi << endl;
	print_arr(table);
	return table[bi][N];
}


string print_LCS_DP(string& str1, string& str2, int M, int N) {
	vector<vector<int>> table(M+1, vector<int>(N+1, 0));
	for (int m = 0; m < M+1; m++) {
		for (int n = 0; n < N+1; n++) {
			if (m == 0 || n == 0)
				table[m][n] = 0;
			else if (str1[m-1] == str2[n-1])
				table[m][n] = 1 + table[m-1][n-1];
			else
				table[m][n] = max(table[m-1][n], table[m][n-1]);
		}
	}
	cout << "len = " << table[M][N] << endl;
	print_arr(table);
	
	string lcs; 
	int m = M; int n = N;
	while (m > 0 && n > 0) {
		if (str1[m-1] == str2[n-1]) {
			lcs.push_back(str1[m-1]);
			m--; n--;
		}
		else if (table[m-1][n] > table[m][n-1]) {
			m--;
		}
		else {
			n--;
		}
	}
	reverse(lcs.begin(), lcs.end());
	return lcs;
}



int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	//string lcs = print_LCS_DP(str1, str2, str1.length(), str2.length());
	//cout << "lcs = " << lcs << endl;
	int lcs_len = LCS_DP2(str1, str2, str1.length(), str2.length());
	cout << "lcs_len = " << lcs_len << endl;
	
	return 0;
}