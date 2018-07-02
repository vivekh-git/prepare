#include <bits/stdc++.h>

using namespace std;

void print_arr(vector<int>& res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

vector<pair<int,int>> get_neighbors(int x, int y, vector<vector<int>>& graph) {
	vector<pair<int,int>> neighbors;
	vector<pair<int,int>> candidates = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}, {x-1, y-1}, {x-1, y+1}, {x+1, y-1}, {x+1, y+1}};
	for (auto it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < graph.size() && it->second >= 0 && it->second < graph[0].size())
			neighbors.push_back(*it);
	}
	return neighbors;
}

void DFSUtil(int r, int c, vector<vector<int>>& graph, vector<vector<bool>>& visited, int& size) {
	visited[r][c] = true;
	size++;
	vector<pair<int, int>> neighbors = get_neighbors(r, c, graph);
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		if (graph[it->first][it->second] != 1 || visited[it->first][it->second]) continue;
		DFSUtil(it->first, it->second, graph, visited, size);
	}
}

int sizeIslands(vector<vector<int>>& graph, int& mz, vector<int>& sizeislands) {
	int countislands = 0;
	vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));
	
	int maxsize = INT_MIN;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[0].size(); j++) {
			if (graph[i][j] == 1 && !visited[i][j]) {
				int size = 0;
				DFSUtil(i, j, graph, visited, size);
				sizeislands.push_back(size);
				if (size > maxsize) {
					maxsize = size;
				}
				countislands++;
			}
		}
	}
	
	sort(sizeislands.begin(), sizeislands.end(), std::greater<int>());
	//reverse(sizeislands.begin(), sizeislands.end());	
	mz = maxsize;
	return countislands;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> graph =  {{1,1,0,0,0},
								  {0,1,0,0,1},
								  {1,0,0,1,1},
							  	  {0,0,0,0,0},
							  	  {1,0,1,0,1}};
	int mz = 0; int count = 0;
	vector<int> sizeislands;
	
	count = sizeIslands(graph, mz, sizeislands);
	cout << "Count = " <<  count << endl;
	cout << "Maxsize = " << mz << endl; 
	print_arr(sizeislands);
	
	return 0;	
}