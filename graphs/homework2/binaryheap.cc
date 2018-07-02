#include <bits/stdc++.h>

using namespace std;

void swap(vector<pair<int,int>>& arr, int pos1, int pos2) {
	pair<int,int> tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

class MinHeap {
private:
	vector<pair<int,int>> harr;
	unordered_map<int,int> pos;
	//int heap_size;
	void heapify_down(int i) {
		int left = 2*i + 1;
		int right = 2*i + 2;
		int smallest = i;
		if (left < size()  && harr[left].second < harr[smallest].second)
			smallest = left;
		if (right < size() && harr[right].second < harr[smallest].second)
			smallest = right;
		if (smallest != i) {
			pos[harr[smallest].first] = i;
			pos[harr[i].first] = smallest;
			swap(harr, i, smallest);
			heapify_down(smallest);
		}
	}
	void heapify_up(int i) {
		int parent = (i-1)/2;
		// check if node at i and its parent viloate heap property
		if (i && harr[parent].second > harr[i].second) {
			pos[harr[parent].first] = i;
			pos[harr[i].first] = parent;
			swap(harr, parent, i);
			heapify_up(parent);
		}
	}
public:
	MinHeap() {}
	int size() {
		return harr.size();
	}
	bool empty() {
		return size() == 0;
	}
	void insert(pair<int,int> x) { // you can call push as well
		// insert at the end and heapify_up
		harr.push_back(x);
		pos[x.first] = size()-1;
		heapify_up(size()-1);
	}
	void decreaseKey(int v, int new_val) {
		if (pos.count(v) == 0 || pos[v] >= size()) { cout << "v not present in pos" << endl; return;}
		int i = pos[v];
		harr[i].second = new_val;
		heapify_up(i);
	}
	bool isInMinHeap(int v) {
		return (pos.count(v)!= 0 && pos[v] < size());
	}
	pair<int,int> getMin() {
		if (size() == 0) return {-1,-1};
		return harr[0];
	}
	pair<int,int> extractMin() {
		if (empty()) return {INT_MAX, INT_MAX};
		pair<int,int> root = harr[0];
		//harr[0] = harr.back();
		// swap positions in pos vector
		pos[harr[0].first] = size()-1;
		pos[harr.back().first] = 0;
		harr[0] = harr.back();
		pos.erase(harr.back().first);
		harr.pop_back();
		//pos.pop_back();
		heapify_down(0);
		return root;
	}
	void deleteKey(int v) {
		decreaseKey(v, INT_MIN);
		extractMin();
	}
	
	void print_arr() {
		cout << "printing ..." << endl;
		for (int i = 0; i < size(); i++)
			cout << "(" << harr[i].first << "," << harr[i].second << "), ";
		cout << endl;
	}
};

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << ",";
}
void printPath(vector<int>& parent, int i) {
	vector<int> path;
	while (i != -1) {
		path.push_back(i);
		i = parent[i];
	}
	reverse(path.begin(), path.end());
	print_arr(path);
}

void print_distances(vector<int>& dist, vector<int>& parent, int source) {
	for (int i = 1; i < dist.size(); i++) {
		cout << source << " -> " << i << "->" << dist[i] << "(";
		printPath(parent, i);
		cout << ")" << endl;
	}
}

void djikstra(vector<list<pair<int,int>>>& graph, int source) {
	vector<int> dist(graph.size(), INT_MAX);
	vector<int> parent(graph.size());
	MinHeap mh;
	for (int v = 0; v < graph.size(); v++) {
		mh.insert({v, dist[v]});
	}
	dist[source] = 0;
	parent[source] = -1;
	mh.decreaseKey(source, dist[source]);
	while (!mh.empty()) {
		pair<int,int> node = mh.extractMin();
		int u = node.first;
		for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
			if (mh.isInMinHeap(it->first) && dist[u] != INT_MAX && dist[u] + it->second < dist[it->first]) {
				dist[it->first] = dist[u] + it->second;
				parent[it->first] = u;
				mh.decreaseKey(it->first, dist[it->first]);
			}
		}
	}
	print_distances(dist, parent, source);
}


int main() {
	vector<list<pair<int,int>>> graph = {
		{{1,4}, {7,8}},
		{{0,4}, {2,8}, {7,11}},
		{{1,8}, {3,7}, {8,2}, {5,4}},
		{{2,7}, {4,9}, {5,14}},
		{{3,9}, {5,10}},
		{{4,10}, {3,14}, {2,4}, {6,2}},
		{{5,2}, {7,1}, {8,6}},
		{{6,1}, {0,8}, {1,11}, {8,7}},
		{{7,7}, {6,6}, {2,2}}
	};
	int source = 0;
	djikstra(graph, source);
  	return 0; 
}