#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
/*
	For the weighted graph:
	1. The number of nodes is <name>_nodes.
	2. The number of edges is <name>_edges.
	3. An edge exists between <name>_from[i] to <name>_to[i] and the weight of the edge is <name>_weight[i].
*/
/*
bool DFSUtil(int v, int dest, vector<vector<pair<int,int>>>& graph, vector<bool>& visited, long long int& size, long long int& maxsize, vector<int>& path, vector<int>& maxpath) {
	if (v == dest) {
		// dest reached
		if (size > maxsize) {
			maxsize = size;
			maxpath = path;
		}
		return true;
	}
	
	for (int i = 0; i < graph[v].size(); i++) {
		pair<int, int> n = graph[v][i];
		if (visited[n.first]) continue;
		visited[n.first] = true;
		size += n.second;
		path.push_back(n.first);
		DFSUtil(n.first, dest, graph, visited, size, maxsize, path, maxpath);
		visited[n.first] = false;
		size -= n.second;
		path.pop_back();
	}
	return false;
}*/

void DFSUtil(int v, vector<vector<pair<int,int>>>& graph, vector<bool>& visited, vector<int>& topo_order) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		pair<int, int> n = graph[v][i];
		if (!visited[n.first]) {
			DFSUtil(n.first, graph, visited, topo_order);
		}
	}
	topo_order.push_back(v);
}

vector<int> topo_sort(vector<vector<pair<int,int>>>& graph) {
	vector<bool> visited(graph.size(), false);
	vector<int> topo_order;
	
	for (int u = 1; u < graph.size(); u++) {
		if (!visited[u]) 
			DFSUtil(u, graph, visited, topo_order);
	}
	reverse(topo_order.begin(), topo_order.end());
	return topo_order;
}

vector <int> find_longest_path(int dag_nodes, vector <int> dag_from, vector <int> dag_to, vector <int> dag_weight, int from_node, int to_node) {
	vector<vector<pair<int,int>>> graph (1+dag_nodes, vector<pair<int,int>>(0));
	for (int i = 0; i < dag_from.size(); i++) {
		graph[dag_from[i]].push_back({dag_to[i], dag_weight[i]});
	}
	vector<long long int> dist(graph.size(), INT_MIN);
	vector<int> parent(graph.size(), -1);
	vector<int> path;
	
	vector<int> topo_order = topo_sort(graph);
	dist[from_node] = 0;
	parent[from_node] = -1;
	
	for (int u = 0; u < topo_order.size(); u++) {
		if (dist[topo_order[u]] == INT_MIN) continue;
		for (int i = 0; i < graph[topo_order[u]].size(); i++) {	
			pair<int, int> n = graph[topo_order[u]][i];
			if (dist[n.first] < dist[topo_order[u]] + n.second) {
				dist[n.first] = dist[topo_order[u]] + n.second;
				parent[n.first] = topo_order[u];
			}
		}
	}
	cout << "maxsize: " << dist[to_node] << endl;
	path.push_back(to_node);
	int p = parent[to_node];
	while (p != -1) {
		path.push_back(p);
		p = parent[p];
	}
	reverse(path.begin(), path.end());
	return path;
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector <int> res;
    int dag_nodes = 0;
    int dag_edges = 0;

    cin >> dag_nodes >> dag_edges;

    vector<int> dag_from(dag_edges);
    vector<int> dag_to(dag_edges);
    vector<int> dag_weight(dag_edges);

    for (int dag_i = 0; dag_i < dag_edges; dag_i++) {
        cin >> dag_from[dag_i] >> dag_to[dag_i] >> dag_weight[dag_i];
    }

    int from_node;
    cin >> from_node;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int to_node;
    cin >> to_node;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = find_longest_path(dag_nodes, dag_from, dag_to, dag_weight, from_node, to_node);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }

    //fout.close();
    return 0;
}
