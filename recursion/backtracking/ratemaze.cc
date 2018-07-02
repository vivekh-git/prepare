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


bool valid(vector<vector<int>>& maze, int x, int y) {
	if (x < maze.size() && y < maze[0].size() && maze[x][y] == 1) return true;
	return false;
}

/*
RECURSIVE RELATION
f(x,y) =  if (x == m-1 && y == n-1) {
			sol[x][y] = 1;
			return true;
		  }
		  else if (x == m-1) {
 		  }
		  else if (y == n-1) {

   		  }
		  else {
			if (valid(maze, x , y)) {
			  sol[x][y] = 1;
			  if (f(x+1, y)) return true;
			  if (f(x, y+1)) return true;
			}
			return false;
		  }
*/
bool SolveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
	if (x == maze.size()-1 && y == maze[0].size()-1) {
		sol[x][y] = 1;
		return true;
	}
	else {
		if (valid(maze, x, y)) {
			sol[x][y] = 1;
			if (SolveMaze(maze, x+1, y, sol)) return true;
			if (SolveMaze(maze, x, y+1, sol)) return true;
		}
		return false;
	}
}


int CountMaze(vector<vector<int>>& maze, int x, int y) {
	
}

/* Driver Program to test above functions */
int main() {
	vector<vector<int>> maze = {{1, 0,0,0},
								{1,1,0,1},
								{0,1,0,0},
								{1,1,1,1,}};
	print_arr(maze);
	vector<vector<int>> sol(4, vector<int>(4));
	
	//grid[0][0] = 0;
    if (SolveMaze(maze, 0, 0, sol) == true)
          print_arr(sol);
    else {
         cout << "No solution exists" << endl;
         print_arr(sol);
	 }
 
    return 0;
}
