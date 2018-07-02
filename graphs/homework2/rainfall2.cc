#include <bits/stdc++.h>

using namespace std;

class DisjointUnionSets {
private:
	int v;
	vector<int> parent;
	vector<int> rank;
public:
	DisjointUnionSets(int n) {
		v = n;
		parent.resize(v);
		rank.resize(v);
		makeSet();
	}
	void makeSet() {
		for (int i=0; i < v; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int i) {
		if (parent[i] != i) {
			parent[i] = Find(parent[i]);
		}
		return parent[i];
	}
	void Union(int x, int y) {
		int xroot = Find(x);
		int yroot = Find(y);
		if (xroot == yroot) return;
		if (rank[xroot] < rank[yroot]) {
			parent[xroot] = yroot;
		}
		else if (rank[yroot] < rank[xroot]) {
			parent[yroot] = xroot;
		}
		else {
			parent[yroot] = xroot;
			rank[xroot]++;
		}
	}
};

void print_map(map<int, int>& res) {
	for (auto it = res.begin(); it != res.end(); it++) {
		cout << it->second << " ";
	}
	cout << endl;
}


void print_arr(vector<int>& res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}

vector<pair<int,int>> get_neighbors(vector<vector<int>>& graph, int x, int y) {
	vector<pair<int,int>> neighbors;
	vector<pair<int,int>> candidates = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
	for (auto it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < graph.size() && it->second >= 0 && it->second < graph[0].size())
			neighbors.push_back(*it);
	}
	return neighbors;
}

pair<int, int> findsink(vector<vector<int>>& graph, int r, int c) {
	int minsink = graph[r][c]; pair<int, int> sink = {r,c};
	vector<pair<int,int>> neighbors = get_neighbors(graph, r, c);
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		if (graph[it->first][it->second] < minsink) {
			minsink = graph[it->first][it->second];
			sink = *it;
		}
	}
	if (sink == make_pair(r, c))
		return sink;
	return findsink(graph, sink.first, sink.second);
}

void DFSUtil(int r, int c, vector<vector<int>>& graph, vector<vector<bool>>& visited, int& size) {
	visited[r][c] = true;
	size++;
	pair<int, int> sink = findsink(graph, r, c);
	vector<pair<int, int>> neighbors = get_neighbors(graph, r, c);
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		if (visited[it->first][it->second] || findsink(graph, it->first, it->second) != sink) continue;
		DFSUtil(it->first, it->second, graph, visited, size);
	}
}

int findBasins(vector<vector<int>>& graph, int& mz, vector<int>& sizebasins) {
	int countbasins = 0;
	vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));
	
	int maxsize = INT_MIN;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[0].size(); j++) {
			if (!visited[i][j]) {
				int size = 0;
				DFSUtil(i, j, graph, visited, size);
				sizebasins.push_back(size);
				if (size > maxsize) {
					maxsize = size;
				}
				countbasins++;
			}
		}
	}
	
	sort(sizebasins.begin(), sizebasins.end(), std::greater<int>());
	mz = maxsize;
	return countbasins;
}


int findBasins2(vector<vector<int>>& graph, int& mz, vector<int>& sizearr) {
	int rows = graph.size();
	int cols = graph[0].size();
	DisjointUnionSets dus(rows*cols); 
	unordered_map<int, int> sizebasins;
	int maxsize = INT_MIN; int countbasins = 0;

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			// find lowest neighbor and union with it
			int minsink = graph[r][c]; pair<int, int> sink = {r,c};
			vector<pair<int,int>> neighbors = get_neighbors(graph, r, c);
			for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
				if (graph[it->first][it->second] < minsink) {
					minsink = graph[it->first][it->second];
					sink = *it;
				}
			}
			if (minsink != graph[r][c]) {
				dus.Union(r*rows+c, sink.first*rows+sink.second);
			}
		}
	}
	
	// compute count, size
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			int root = dus.Find(rows*r+c);
			if (sizebasins.count(root) == 0) {
				countbasins++;
				sizebasins[root] = 1;
			}
			else {
				sizebasins[root]++;
			}
			
			if (sizebasins[root] > maxsize) {
				maxsize = sizebasins[root];
			}
		}
	}
	mz = maxsize;
	
	for (auto it = sizebasins.begin(); it != sizebasins.end(); it++) {
		sizearr.push_back(it->second);
	}
	sort(sizearr.begin(), sizearr.end(), std::greater<int>());
	return countbasins;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> graph1 = {{1,5,2},
								  {2,4,7},
								  {3,6,9}};
	vector<vector<int>> graph2 = {{1,0,2,5,8},
   								  {2,3,4,7,9},
								  {3,5,7,8,9}, 
								  {1,2,5,4,3},
								  {3,3,5,2,1}};
	vector<vector<int>> graph3 = {{0,2,1,3},
							  	  {2,1,0,4},
							  	  {3,3,3,3}, 
							  	  {5,5,2,1}};
	vector<vector<int>> graph4 = {{10}};
	int mz; 
	vector<int> sizearr;
	int countbasins = findBasins2(graph1, mz, sizearr);
	//int countbasins = findBasins2(graph2, mz, sizearr);
	//int countbasins = findBasins2(graph3, mz, sizearr);
	//int countbasins = findBasins2(graph4, mz, sizearr);
	print_arr(sizearr);
	cout << "count:" << countbasins << endl;
	cout << "mz:" << mz << endl;
	return 0;	
}