#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
void print_graph(unordered_map<char, list<char>>& graph) {
	for (auto it = graph.begin(); it != graph.end(); it++) {
		cout << it->first << " -> ";
		for (auto l = (it->second).begin(); l != (it->second).end(); l++) {
			cout << *l << ",";
		}
		cout << endl;
	}
}

void DFSUtil(char node, unordered_map<char, list<char>>& graph, set<char>& visited, stack<char>& st) {
	visited.insert(node);
	for (auto l = graph[node].begin(); l != graph[node].end(); l++) {
		if (visited.count(*l) == 0) { // not visited
			DFSUtil(*l, graph, visited, st);
		}
	}
	st.push(node);
}

void topo_sort(unordered_map<char, list<char>>& graph, stack<char>& st) {
	// need visited data structure
	set<char> visited;
	for (auto it = graph.begin(); it != graph.end(); it++) {
		if (visited.count(it->first) == 0) { // not visited
			DFSUtil(it->first, graph, visited, st);
		}
	}
}


string find_order(vector<string>& words) {
	unordered_map<char, list<char>> graph;
    // build a graph
	if (words.size() > 0) {
		graph[words[0][0]].push_back({});
	}
	for (int i = 0; i < words.size()-1; i++) {
		string s1 = words[i];
		string s2 = words[i+1];
		for (int j = 0; j < min(s1.length(), s2.length()); j++) {
			if (s1[j] != s2[j]) {
				graph[s1[j]].push_back(s2[j]);
				break;
			}
		}
	}
	print_graph(graph);
    
	stack<char> st;
	topo_sort(graph, st);
    string result;
	while (!st.empty()) {
		result.push_back(st.top()); st.pop();
	}
    return result;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string res;
    int words_size = 0;
    cin >> words_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> words;
    for(int i = 0; i < words_size; i++) {
        string words_item;
        //getline(cin, words_item);
        cin >> words_item;
        words.push_back(words_item);
    }

    res = find_order(words);
    cout << res << endl;

    //fout.close();
    return 0;
}
