#include<bits/stdc++.h>
using namespace std;

/* count paths - f (0, 0, m, n)
f(i, j) -> 
		   if (i == m-1 && j == n-1)
			return 1;
		   if (matrix[i][j] == 0)
			return 0;
		   return f(i+1, j) + f(i, j+1);

*/
int countPaths(int r, int c, vector<vector<int>>& matrix) {
	if (r == matrix.size()-1 && c == matrix[0].size()-1)
		return 1;
	else if (matrix[r][c] == 0)
		return 0;
	else if (r == matrix.size()-1)
		return countPaths(r, c+1, matrix);
	else if (c == matrix.size()-1)
		return countPaths(r+1, c, matrix);
	else 
		return countPaths(r+1, c, matrix) + countPaths(r, c+1, matrix);
}


int numberOfPaths_rec(vector<vector<int>> matrix) {
	return countPaths(0, 0, matrix);
}

int numberOfPaths(vector<vector<int>> matrix) {
	int m = matrix.size(); int n = matrix[0].size();
	vector<vector<int>> table(m, vector<int>(n));
	for (int r = m-1; r >= 0; r--) {
		for (int c = n-1; c >= 0; c--) {
			if (r == m-1 && c == n-1)
				table[r][c] = 1;
			else if (matrix[r][c] == 0)
				table[r][c] = 0;
			else if (r == m-1)
				table[r][c] = table[r][c+1];
			else if (c == n-1)
				table[r][c] = table[r+1][c];
			else
				table[r][c] = table[r+1][c] + table[r][c+1];
		}
	}
	return table[0][0];
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int a_rows = 0;
    int a_cols = 0;
    cin >> a_rows >> a_cols;
    vector< vector < int > > a(a_rows);
    for(int a_i = 0; a_i < a_rows; a_i++) {
        for(int a_j = 0; a_j < a_cols; a_j++) {
            int a_tmp;
            cin >> a_tmp;
            a[a_i].push_back(a_tmp);
        }
    }

    res = numberOfPaths(a);
    cout << res << endl;

    //fout.close();
    return 0;
}
