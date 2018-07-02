#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<vector<int>>& arr) {
	for (int i=0; i < arr.size(); i++) {
		for (int j=0; j < arr[i].size(); j++) {
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
f(x,y, m, n)
if (x == m-1 && y == n-1) {}
    return 1;
}
else {
    if (x == m) return 0
    else if (y == n) return 0
    else if (arr[x][y] == 0) return 0
    else 
         f(x+1, y, m, n) + f(x, y+1, m, n)
}

*/
int countofpath(vector<vector<int>>& arr, int x, int y, int m, int n) {
	if (x == m && y == n) return 1;
	else if (x == m+1 || y == n+1) return 0;
	else if (arr[x][y] == 0) return 0;
	else { // subset problem
		return countofpath(arr, x+1, y, m, n) + countofpath(arr, x, y+1, m, n);
	}
}

int countofpath2(vector<vector<int>>& arr, int m, int n) {
	if (m < 0 || n < 0) return 0;
	else if (m == 0 && n == 0) return 1;
	else if (arr[m][n] == 0) return 0;
	else { // subset problem
		return countofpath2(arr, m-1, n) + countofpath2(arr, m, n-1);
		// countofpath(arr, m-1, n-1) if diagonal movement is allowd
	}
}

int countpathdp(vector<vector<int>>& arr, int m, int n) {
	int cnt[m][n];
	
	for (int i = 0; i < m; i++) {
		cnt[i][0] = (arr[i][0]) ? 1:0;
	}
	for (int j = 0; j < n; j++) {
		cnt[0][j] = (arr[0][j] ) ? 1:0;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			cnt[i][j] = (arr[i][j]) ? (cnt[i-1][j] + cnt[i][j-1]) : 0;
			//include cnt[i-1][j-1] for diagonal movements
		}
	}
	print_arr_int(cnt, m, n);
	return cnt[m-1][n-1];
}




int main() {
	vector<vector<int>> arr = {{1, 0, 0, 0, 1}, {1, 1,1,1,1}, {0,1,0,1,1}, {1,0,1,1,1}};
	print_arr(arr);
	//int k = countofpath(arr, 0, 0, arr.size()-1, arr[0].size()-1);
	//int k = countofpath2(arr, arr.size()-1, arr[0].size()-1);
	int k = countpathdp(arr, arr.size(), arr[0].size());
	cout << k << endl;
	return 0;
}