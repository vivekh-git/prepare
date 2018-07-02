#include <bits/stdc++.h>

using namespace std;

void print_graph(vector<list<pair<int,int>>>& graph) {
	for (int i=0; i<graph.size(); i++) {
		cout << i << " -> ";
		for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
			cout << "{" << it->first << ", " << it->second << "}, ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_stack(stack<int> st) {
	while (!st.empty()) {
		cout << st.top() << ", ";
		st.pop();
	}
	cout << endl << endl;
}

void DFSUtil(int v, vector<list<int>>& graph, vector<bool>& visited, stack<int>& topo_order) {
	visited[v] = true;
	for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
		if (!visited[*it]) {
			DFSUtil(*it, graph, visited, topo_order);
		}
	}
	topo_order.push(v);
}

stack<int> topo_sort(vector<list<int>>& graph) {
	vector<bool> visited(graph.size(), false);
	stack<int> topo_order;
	for (int u = 0; u < graph.size(); u++) {
		if (!visited[u]) 
			DFSUtil(u, graph, visited, topo_order);
	}
	return topo_order;
}

vector<list<int>> transpose(vector<list<int>>& graph) {
	vector<list<int>> reverse_graph(graph.size());
	for (int u = 0; u < graph.size(); u++) {
		for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
			reverse_graph[*it].push_back(u);
		}
	}
	return reverse_graph;
}

list<set<int>> StronglyConnectedComponent(vector<list<int>>& graph) {	
	list<set<int>> result;
	stack<int> topo_order = topo_sort(graph);
	print_stack(topo_order);
	
	vector<list<int>> reverse_graph = transpose(graph);
	print_graph(reverse_graph);
	vector<bool> visited(graph.size(), false);
	while (! topo_order.empty()) {
        int node = topo_order.top(); 
		topo_order.pop();
		if (visited[node]) continue;
		visited[node] = true;
		set<int> s; s.insert(node);
		for(auto it = (reverse_graph[node]).begin(); it != (reverse_graph[node]).end(); it++) {
			if (visited[(*it)]) continue;
			visited[(*it)] = true;
			s.insert((*it));
		}
		result.push_back(s);
	}
	return result;
}

vector<int> dijkstra(vector<list<pair<int,int>>>& graph) {
	vector<int> result;
	
	priority_queue<int, int> pq;
}

void addEdge(vector<list<int>>& graph, int u, int v, int w) {
	graph[u].push_back({v, w});
	graph[v].push_back({u, w});
}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int V = 9;
    vector<list<pair<int,int>>> graph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
	addEdge(graph, 6, 7, 1);
	addEdge(graph, 7, 0, 8);
	addEdge(graph, 1, 7, 11);
	addEdge(graph, 7, 8, 7);
	addEdge(graph, 2, 8, 2);
	addEdge(graph, 6, 8, 6);
	addEdge(graph, 2, 5, 4);
	addEdge(graph, 3, 5, 14);
    print_graph(graph);
	vector<int> result = dijkstra(graph);
	for (int i = 0; i< result.size(); i++) {
		cout << result[i] << ", ";
	}
	cout << endl;
    return 0;
}
