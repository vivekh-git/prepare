#include <bits/stdc++.h>

using namespace std;

/*
LEARNINGS:-
1) did not set backtracking grid[r][c] to 0 after finishing recursion
2) 2 dim stop condition was not set / checked properly. After 8,8, you can set next_r, next_c to 9,9 
and check that as stop condition
*/

/*
Recursive relation
f(row)      = if (queen is placed in all row rows)
				print_arr(grid);
			  else 
				for (int row = 0; row < grid.size(); row++) {
					if (! valid (grid, row, col)) continue;
					grid[row][col] = 1;
					f(row+1);
					grid[row][col] = 0;
				}
*/
void print_arr(vector<vector<int>>& grid) {
	for (int i=0; i<grid.size(); i++) {
		for (int j=0; j<grid[0].size(); j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// eg - grid[2][3] = num
bool valid(vector<vector<int>>& grid, int row, int col) {
	for (int r = 0; r < grid.size(); r++) 
		if (grid[r][col] == 1) return false;
	for (int c = 0; c < grid[0].size(); c++)
		if (grid[row][c] == 1) return false;
	for (int r = 0; r < grid.size(); r++)
		for (int c = 0; c < grid[0].size(); c++)
			if (abs(r-row) == abs(c-col) && grid[r][c] == 1) return false;
	return true;
}

bool PrintQueens(vector<vector<int>>& grid, int row, bool& flag) {
	
	if (row == grid.size()) {
		print_arr(grid);
		flag = true;
		return true;
	}
	else {
		for (int col = 0; col < grid[0].size(); col++) {
			if (! valid(grid, row, col)) continue;
			grid[row][col] = 1;
			/* prints only one solution */
			/*
			if (PrintQueens(grid, row+1)) {
				return true;
			}
			else {
				// backtracking - this is the key
				grid[row][col] = 0;
				continue;
			}
			*/
			/* prints all solutions */
			PrintQueens(grid, row+1, flag);
			grid[row][col] = 0;
		}
		return false;
	}
}

/* Driver Program to test above functions */
int main()
{
    int N;
	cin >> N;
	vector<vector<int>> grid(N, vector<int>(N));
	//print_arr(grid);
	bool flag = false;
	PrintQueens(grid, 0, flag);
	if (! flag) {
		cout << "No solutions exist" << endl;
	}
    return 0;
}
