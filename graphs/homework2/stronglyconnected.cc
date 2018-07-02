#include <bits/stdc++.h>

using namespace std;

void print_graph(vector<list<int>>& graph) {
	for (int i=0; i<graph.size(); i++) {
		cout << i << " -> ";
		for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
			cout << *it << ", ";
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

void addEdge(vector<list<int>>& graph, int u, int v) {
	graph[u].push_back(v);
}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int V = 7;
    vector<list<int>> graph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 6);
    print_graph(graph);
    list<set<int>> result = StronglyConnectedComponent(graph);
    for (auto it = result.begin(); it != result.end(); it++) {
		for (auto st = it->begin(); st != it->end(); st++) {
			cout << *st << ", ";
		}
		cout << endl;
    }
    return 0;
}
