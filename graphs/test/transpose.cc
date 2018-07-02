#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 315;

struct Node
{
	int val;
	vector<Node *> neighbours;
	Node(int _val = 0)
	{
		val = _val;
		neighbours.clear();
	}
};


/*
 * Complete the function below.
 * Logic - iterate through all nodes and build a new graph with reverse edges.
 */
Node* _clone(Node* node, unordered_map<Node*, Node*>& clonehash) {
	if (! node) return NULL;
	else if (clonehash.count(node) != 0)
		return clonehash[node];
	Node* clone = new Node(node->val);
	clonehash[node] = clone;
	// dfs on neighbors
	for (int i = 0; i < node->neighbours.size(); i++) {
		Node* cloneneighbor = _clone(node->neighbours[i], clonehash);
		// reverse the edge.
		cloneneighbor->neighbors.push_back(clone);
	}
	return clone;
}

Node *build_other_graph(Node *node) {
	unordered_map<Node*, Node*> clonehash;
	return _clone(node, clonehash);
}

void helper_dfs(Node *reversed_node, unordered_map<int, Node *> &reversed)
{
	reversed[reversed_node->val] = reversed_node;
	int n = reversed_node->neighbours.size();
	for (int i = 0; i < n; i++)
	{
		if (reversed.find(reversed_node->neighbours[i]->val) == reversed.end())
		{
			helper_dfs(reversed_node->neighbours[i], reversed);
		}
	}
}

unordered_map<int, Node *> helper_get_all_addresses_in_reversed_graph(Node * reversed_node)
{
	unordered_map<int, Node *> reversed;
	helper_dfs(reversed_node, reversed);
	return reversed;
}

string helper(int graph_nodes, vector<int> graph_from, vector<int> graph_to)
{
	unordered_map<int, Node *> original;
	for (int i = 1; i <= graph_nodes; i++)
	{
		original[i] = new Node(i);
	}
	set<pair<int, int>> edges;
	int graph_edges = graph_from.size();
	for (int i = 0; i < graph_edges; i++)
	{
		original[graph_from[i]]->neighbours.push_back(original[graph_to[i]]);

		edges.insert({graph_from[i], graph_to[i]});
	}	 

	unordered_map<int, Node *> reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]));

	if (reversed.size() != graph_nodes)
	{
		return "Wrong Answer!";
	}

	for (auto it = reversed.begin(); it != reversed.end(); it++)
	{
		if (1 > it->first || it->first > graph_nodes)
		{
			return "Wrong Answer!";
		}
		if (original[it->first] == reversed[it->first])
		{
			return "Wrong Answer!";
		}
		int n = it->second->neighbours.size();
		//cout << "no of edges of node " << it->first << " = " << n << endl;
		for (int i = 0; i < n; i++)
		{
			int val = it->second->neighbours[i]->val;
			//cout << "to = " << val << endl;
			auto itttt = edges.find({val, it->first}); 
			if (itttt == edges.end())
			{
				return "Wrong Answer!";
			}
			edges.erase(itttt);
		}
	}
	if (edges.size() > 0)
	{
		return "Wrong Answer!";
	}
	return "Correct Answer!";
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string res;
    int graph_nodes = 0;
    int graph_edges = 0;

    cin >> graph_nodes >> graph_edges;

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int graph_i = 0; graph_i < graph_edges; graph_i++) {
        cin >> graph_from[graph_i] >> graph_to[graph_i];
    }

    res = helper(graph_nodes, graph_from, graph_to);
    cout << res << endl;

    //fout.close();
    return 0;
}
