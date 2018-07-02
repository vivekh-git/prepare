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
f(row, col) = if (all 8x8 cells are assigned)
				return true
			  else 
				if (grid[row][col] != 0) return f(next cell);
				for (int num = 1; num <= 9; num++) {
					if (! valid (grid, row, col, num)) continue;
					grid[row][col] = num;
					if (f(next cell)) return true;
					grid[row][col] = 0;
				}
				return false;
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

void find_next(vector<vector<int>>& grid, int row, int col, int& next_row, int& next_col) {
	if (col < grid[0].size()-1) {
		next_col = col+1;
		next_row = row;
	}
	else if (row < grid.size()-1) {
		next_col = 0;
		next_row = row+1;
	}
	else {
		// all elements are assigned - just assigning stop condition
		next_row=9; next_col=9;
	}
}

// eg - grid[2][3] = num
bool valid(vector<vector<int>>& grid, int row, int col, int num) {
	for (int r = 0; r < grid.size(); r++) {
		if (grid[r][col] == num) return false;
	}
	for (int c = 0; c < grid[0].size(); c++) {
		if (grid[row][c] == num) return false;
	}
	int cube_st_row = 3 * (row/3);
	int cube_st_col = 3 * (col/3);
	for (int i = cube_st_row; i < cube_st_row+3; i++) {
		for (int j = cube_st_col; j < cube_st_col+3; j++) {
			if (grid[i][j] == num) return false;
		}
	}
	return true;
}

bool SudokuSolve(vector<vector<int>>& grid, int row, int col) {
	int next_row, next_col;
	find_next(grid, row, col, next_row, next_col);
	
	if (row >= grid.size()) {
		return true;
	}
	else {	
		if (grid[row][col] != 0) {
			return SudokuSolve(grid, next_row, next_col);
		}
		for (int num = 1; num <= 9; num++) {
			if (! valid(grid, row, col, num)) continue;
			grid[row][col] = num;
			if (SudokuSolve(grid, next_row, next_col)) return true;
			// backtracking - this is the key
			grid[row][col] = 0;
		}
		return false;
	}
}

/* Driver Program to test above functions */
int main()
{
    // 0 means unassigned cells
	vector<vector<int>> grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      			{5, 2, 0, 0, 0, 0, 0, 0, 0},
                      		  	{0, 8, 7, 0, 0, 0, 0, 3, 1},
                      		  	{0, 0, 3, 0, 1, 0, 0, 8, 0},
                      		  	{9, 0, 0, 8, 6, 3, 0, 0, 5},
                      		  	{0, 5, 0, 0, 9, 0, 6, 0, 0},
                      		  	{1, 3, 0, 0, 0, 0, 2, 5, 0},
                      		  	{0, 0, 0, 0, 0, 0, 0, 7, 4},
                      		  	{0, 0, 5, 2, 0, 6, 3, 0, 0}};
	print_arr(grid);
    if (SudokuSolve(grid, 0, 0) == true)
          print_arr(grid);
    else
         cout << "No solution exists" << endl;
 
    return 0;
}
