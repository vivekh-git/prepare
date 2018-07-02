#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
// Start: 3.46p
// End: 11.00p
// Total: 8hrs
void print_arr(vector<vector<int>>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isdiagonal(int i, int j, int row, int col) {
	return (abs(i-row) == abs(j-col));
}


bool valid(vector<vector<int>>& arr, int row, int col, int debug) {
	for (int i = 0; i< arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 0) continue;
			else if (i == row || j == col) {
				//if (debug) cout << "DEBUG: row or column matching - valid returning false" << i << j << row << col << endl;
				return false;
			}
			else if (isdiagonal(i,j,row,col)) {
				//if (debug) cout << "DEBUG: diagonal matching - valid returning false" << i << j << row << col << endl;
				return false;
			}
			else continue;
		}
	}
	return true;
}

void set(vector<vector<int>>& arr, int i, int j, int val) {
	arr[i][j] = val;
}

void permute(vector<vector<int>>& arr, int rdx) {
	//cout << rdx << "-" << arr.size() <<  "-" << arr[0].size() << endl;
	if (rdx == arr.size()) {
		cout << "FINAL" << endl;
		print_arr(arr);
		//return true;
	}
	else {
		int i = rdx;
		//cout << rdx << "-" << arr.size() <<  "-" << arr[0].size() << endl;
		for (int j = 0; j < arr[0].size(); j++) {
			 int debug = 0;
			//if (rdx >= 5 && (arr[1][3] || arr[5][1] == 1)) debug =1;
			//if (debug) print_arr(arr);
			if (!valid(arr,i,j, debug)) continue;
			set(arr, i, j, 1); // first col
			/*if (rdx >= 5) {
				cout << "DEBUG2" << endl;
				print_arr(arr);
			}*/
			permute(arr, rdx+1);
			set(arr, i, j, 0);
			//swap(arr, i, idx);
		}
		//cout << rdx << "-" << arr.size() <<  "-" << arr[0].size() << endl;		
	}
	//cout << "DEBUG" << endl;
	//print_arr(arr);
	//return false;
}

void print_valid_nqueens(int n) {
	vector<vector<int>> chess(n, vector<int>(n));
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < n; j++) {
			chess[i][j] = 0;
		}
	}
	
	//print_arr(chess);
	permute(chess, 0);
}

/*
void print_arr1(vector<int>& arr) {
	cout << "{";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ",";
	}
	cout << "}" << endl;
}
void swap(vector<int>& arr, int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}
*/
/*
for int i = 0 - n
f(idx) - prints all possible permutation by swapping idx and i and keep other elements same
*/
/*
void permute(vector<int>& arr, int idx) {
	if (idx == arr.size()) {
		print_arr1(arr);
	}
	else {
		for (int i = idx; i < arr.size(); i++) {
			swap(arr, idx, i);
			permute(arr, idx+1);
			swap(arr, i, idx);
		}
	}
}

void print_permute(vector<int>& chess) {
	permute(chess, 0);
}
*/

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n = 4;
	//vector<int> chess = {1,2,3,4};
	//print_permute(chess);
	print_valid_nqueens(n);
	return 0;
}