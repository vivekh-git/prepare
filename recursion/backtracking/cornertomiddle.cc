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

void print_arr_pair(vector<pair<int,int>>& output) {
	int i;
	for (i=0; i<output.size(); i++) {
		cout << "(" << output[i].first << ", " << output[i].second << ") ->";
	}
	if (i == output.size()) cout << "MID" << endl;
}

vector<pair<int, int>> find_neighbors(vector<vector<int>>& grid, int row, int col) {
	vector<pair<int, int>> neighbors;
	int offset = grid[row][col];
	vector<pair<int, int>> candidates = {{row-offset, col}, {row+offset, col}, {row, col-offset}, {row, col+offset}};
	for (auto it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < grid.size() && it->second >= 0 && it->second < grid[0].size())
			neighbors.push_back(*it);
	}
	return neighbors;
}


// eg - grid[2][3] = num
bool MazeTourUtil(vector<vector<int>>& grid, pair<int,int> rc, vector<vector<int>>& visited, vector<pair<int,int>>& output) {
	//cout << "{" << rc.first << ", " << rc.second << "} - " << num << endl;
	if (grid[rc.first][rc.second] == 0) {
		print_arr_pair(output);
		return true;
	}
	else {
		vector<pair<int, int>> neighbors = find_neighbors(grid, rc.first, rc.second);
		for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
			if (visited[it->first][it->second] == 1) continue;
			visited[rc.first][rc.second] = 1;
			output.push_back(*it);
			MazeTourUtil(grid, *it, visited, output);
			output.pop_back();
			visited[rc.first][rc.second] = 0;
		}
		return false;
	}
}

void MazeTour(vector<vector<int>>& grid) {
	vector<pair<int,int>> output; // path
	vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
	
	vector<pair<int,int>> corners = {{0,0}, {0,grid[0].size()-1}, {grid.size()-1, 0}, {grid.size()-1, grid[0].size()-1}};
	for (auto it = corners.begin(); it != corners.end(); it++) {
		visited[it->first][it->second] = 1;
		output.push_back(*it);
		MazeTourUtil(grid, *it, visited, output);
		output.pop_back();
		visited[it->first][it->second] = 0;
	}
}


/* Driver Program to test above functions */
int main() {
	vector<vector<int>> grid = {{ 3, 5, 4, 4, 7, 3, 4, 6, 3 },
								{ 6, 7, 5, 6, 6, 2, 6, 6, 2 },
								{ 3, 3, 4, 3, 2, 5, 4, 7, 2 },
								{ 6, 5, 5, 1, 2, 3, 6, 5, 6 },
								{ 3, 3, 4, 3, 0, 1, 4, 3, 4 },
								{ 3, 5, 4, 3, 2, 2, 3, 3, 5 },
								{ 3, 5, 4, 3, 2, 6, 4, 4, 3 },
								{ 3, 5, 1, 3, 7, 5, 3, 6, 4 },
								{ 6, 2, 4, 3, 4, 5, 4, 5, 1 }};
	print_arr(grid);
	MazeTour(grid);
    return 0;
}
