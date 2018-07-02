#include <bits/stdc++.h>
using namespace std;


vector<int> print_spiral(vector<vector<int>>& table) {
	vector<int> result;
	if (table.size() == 0) return result;
	int r = 0; int c = 0;
	int R = table.size(); int C = table[0].size();
	int i, j; // row / col iterators
	while (r < R && c < C) {
		// first print row in increasing order of col
		for (j = c; j < C; j++)
			result.push_back(table[r][j]);
		r++; // remove first row as it is printed
		
		// now print last col down
		for (i = r; i < R; i++)
			result.push_back(table[i][C-1]);
		C--;
		
		// now print last row from right to left
		if (r < R) { // this is the key need to understand
			for (j = C-1; j >= c; j--)
				result.push_back(table[R-1][j]);
			R--;
		}
		
		if (c < C) {
			for (i = R-1; i >= r; i--)
				result.push_back(table[i][c]);
			c++;
		}
	}
	return result;
}

void print_arr(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}
void print_res(vector<int>& result) {
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
}

int main() {
	vector<vector<int>> table1 = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	vector<vector<int>> table2 = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	vector<vector<int>> table3 = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	vector<int> result;
	cout << "table1" << endl;
	print_arr(table1);
	result= print_spiral(table1);
	print_res(result);
	cout << "table2" << endl;
	print_arr(table2);
	result = print_spiral(table2);
	print_res(result);
	cout << "table3" << endl;
	print_arr(table3);
	result = print_spiral(table3);
	print_res(result);
	return 0;
}