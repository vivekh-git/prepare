#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;
enum Color {WHITE, GRAY, BLACK};


void DFS_visit(char v, unordered_map<char, list<char>>& graph, set<char>& visited, stack<char>& toposort) {
	// do something with the node and mark it visited
	visited.insert(v);
	// identify neighbors of v
	list<char> adj = graph[v];
	for (list<char>::iterator it = adj.begin(); it != adj.end(); it++) {
		if (visited.count(*it) == 0) { // not visited
			DFS_visit(*it, graph, visited, toposort);
		}
	}
	// all neighbors in adj are visited;
	toposort.push(v);
}

bool DFSUtil(int v, vector<list<int>>& graph, vector<int>& color, vector<int>& parent, int p, stack<int>& path) {
	color[v] = GRAY;
	parent[v] = p;
	
	for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
		if (color[*it] == BLACK) continue;
		else if (color[*it] == GRAY) {
			path.push(*it); path.push(v);
			return true;
		}
		else {
			if (DFSUtil(*it, graph, color, parent, v, path)) {
				return true;
			}
		}
	}
	
	color[v] = BLACK;
	return false;
}

void add_parent_to_stack(vector<int>& parent, stack<int>& path) {
	int n = path.top();
	while(parent[n] != -1) {
		path.push(parent[n]);
		n = parent[n];
	} 
}

void print_path(stack<int>& path) {
	cout << "{";
	while (! path.empty()) {
		cout << path.top() << ", "; 
		path.pop();
	}
	cout << "}" << endl;
}

bool isCycle(vector<list<int>>& graph) {
	vector<int> color(graph.size(), WHITE);
	vector<int> parent(graph.size(), -1);
	stack<int> path;
	
	for (int u = 0; u < graph.size(); u++) {
		if (color[u] == WHITE) {
			if (DFSUtil(u, graph, color, parent, -1, path)) {
				add_parent_to_stack(parent, path);
				print_path(path);
				return true;
			}
		}
	}
	
	return false;
}


void addEdge(vector<list<int>>& graph, int v, int w) {
	graph[v].push_back(w);
}


int main() {
	int V;
	cin >> V;
    vector<list<int>> graph(V);
 
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 0);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 3);
    
    cout << "Cycle exists - " << isCycle(graph) << endl;
    return 0;
}
