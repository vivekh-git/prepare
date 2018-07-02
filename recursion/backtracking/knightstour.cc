#include <bits/stdc++.h>

using namespace std;

/*
LEARNINGS:-
1) did not set backtracking grid[r][c] to 0 after finishing recursion
2) 2 dim stop condition was not set / checked properly. After 8,8, you can set next_r, next_c to 9,9 
and check that as stop condition
*/

void print_arr(vector<vector<int>>& grid) {
	for (int i=0; i<grid.size(); i++) {
		for (int j=0; j<grid[0].size(); j++) {
			cout << grid[i][j] << "    ";
		}
		cout << endl;
	}
	cout << endl;
}



vector<pair<int, int>> find_neighbors(vector<vector<int>>& grid, int row, int col) {
	vector<pair<int, int>> neighbors;
	vector<pair<int, int>> candidates = {{row-2, col-1}, {row-2, col+1}, {row+2, col-1}, {row+2, col+1}, {row-1, col-2}, 
				  {row-1, col+2}, {row+1, col-2}, {row+1, col+2}};
	for (auto it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < grid.size() && it->second >= 0 && it->second < grid[0].size())
			neighbors.push_back(*it);
	}
	return neighbors;
}


// eg - grid[2][3] = num
bool KnightsTour(vector<vector<int>>& grid, pair<int,int> rc, int num) {
	//cout << "{" << rc.first << ", " << rc.second << "} - " << num << endl;
	if (num == grid.size() * grid[0].size()-1) {
		grid[rc.first][rc.second] = num;
		return true;
	}
	else {		
		vector<pair<int, int>> neighbors = find_neighbors(grid, rc.first, rc.second);
		for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
			//cout << "neighbor - {" << it->first << ", " << it->second << "}" << endl;
			if (*it == make_pair(0,0)) continue;
			if (grid[it->first][it->second] != 0) continue;
			grid[rc.first][rc.second] = num;
			//grid[rc.first][rc.second] = num;
			//grid[it->first][it->second] = num;
			if (KnightsTour(grid, *it, num+1)) return true;
			// backtracking - this is the key
			//grid[it->first][it->second] = 0;
			grid[rc.first][rc.second] = 0;
		}
		return false;
	}
}

/* Driver Program to test above functions */
int main() {
    int N;
	cin >> N;
	vector<vector<int>> grid(N, vector<int>(N));
	print_arr(grid);
	
	//grid[0][0] = 0;
    if (KnightsTour(grid, {0, 0}, 0) == true)
          print_arr(grid);
    else {
         cout << "No solution exists" << endl;
         print_arr(grid);
	 }
 
    return 0;
}
