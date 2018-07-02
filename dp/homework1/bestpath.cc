#include <bits/stdc++.h>
using namespace std;

/*
Recurrent relation
f(x,y) ->   if (x == m-1 && y == n-1)
				return arr[x][y];
			else if (x == m-1)
				return arr[x][y] + f(x, y+1);
			else if (y == n-1)
				return arr[x][y] + f(x+1, y);
			else
				return arr[x][y] + max(f(x+1, y), f(x, y+1));
*/

void print_arr(vector<vector<int>>& maze) {
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[0].size(); j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int maxPath(vector<vector<int>>& maze) {
	vector<vector<int>> result(maze.size(), vector<int>(maze[0].size()));
	for (int i = maze.size()-1; i >= 0; i--) {
		for (int j = maze[0].size()-1; j >= 0; j--) {
			if (i == maze.size()-1 && j == maze[0].size()-1)
				result[i][j] = maze[i][j];
			else if (i == maze.size()-1)
				result[i][j] = maze[i][j] + result[i][j+1];
			else if (j == maze[0].size()-1)
				result[i][j] = maze[i][j] + result[i+1][j];
			else
				result[i][j] = maze[i][j] + max(result[i+1][j], result[i][j+1]);
		}
	}
	print_arr(result);
	return result[0][0];
}



/* Driver Program to test above functions */
int main() {
	vector<vector<int>> maze = {{1,0,0,0},
								{1,1,0,1},
								{0,1,0,0},
								{1,1,1,1,}};
	print_arr(maze);

	//grid[0][0] = 0;
	int maxfish = maxPath(maze);
	cout << "maxfish = " << maxfish << endl;
 
    return 0;
}
