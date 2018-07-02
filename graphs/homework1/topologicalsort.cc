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
/*
 * Complete the function below.
 */

//#include <unordered_set>
void print_graph(unordered_map<char, list<char>>& graph) {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        cout << it->first << " -> ";
        for (auto l = (it->second).begin(); l != (it->second).end(); l++) {
            cout << *l << ", ";
        }
        cout << endl;
    }
}

void DFS_Util(char v, unordered_map<char, list<char>>& graph, set<char>& visited, stack<char>& st) {
    cout << "v - " << v << endl;
	visited.insert(v);
    list<char> neighbors = graph[v];
    for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
        if (visited.count(*it) == 0) { // not visited
            DFS_Util(*it, graph, visited, st);
        }
    }
    st.push(v);
}

void topo_sort(unordered_map<char, list<char>>& graph, stack<char>& st) {
    set<char> visited;
    for (auto it = graph.begin(); it != graph.end(); it++) {
        if (visited.count(it->first) == 0) { // not visited
            DFS_Util(it->first, graph, visited, st);
        }
    }
}

/* build a graph from vector<string> */
string findOrder(vector<string>& strDict) {
    // graph definition
    unordered_map<char, list<char>> graph;
    // build graph
    for (int i = 0; i < strDict.size()-1; i++) {
        string s1 = strDict[i];
        string s2 = strDict[i+1];
        for (int j = 0; j < min(s1.length(), s2.length()); j++) {
            if (s1[j] != s2[j]) {
                graph[s1[j]].push_back(s2[j]);
                break;
            }
        }
    }
    print_graph(graph);
    
    // do topological sort of graph
    stack<char> st;
    topo_sort(graph, st);
    
    string result;
    while (!st.empty()) {
        result.push_back(st.top()); 
        st.pop();
    }
    return result;
}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    
    int _strDict_size = 0;
    cin >> _strDict_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _strDict;
    string _strDict_item;
    for(int _strDict_i=0; _strDict_i<_strDict_size; _strDict_i++) {
        getline(cin, _strDict_item);
        _strDict.push_back(_strDict_item);
    }
    
    res = findOrder(_strDict);
    cout << res << endl;
    
    //fout.close();
    return 0;
}
