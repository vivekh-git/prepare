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
#include <string>

using namespace std;

int shortestChainLen(string start, string target, set<string>& dict) {
	return 0;
}

bool isAdjacent(string word1, string word2) {
	if (word1.length() != word2.length()) return false;
	int count = 0;
	for (int i = 0; i < word1.length(); i++) {
		if (word1[i] != word2[i]) {
			count++;
			if (count > 1) return false;
		}
	}
	return (count == 1);
}

void print_arr(vector<string>& paths) {
	for (int i = 0; i < paths.size(); i++) {
		cout << paths[i];
		if (i != paths.size()-1) cout << " -> ";
	}
	cout << endl;
}

vector<string> shortestChainPath(string start, string target, set<string>& dict) {
	queue<string> q;
	unordered_map<string, string> pred;
	unordered_map<string, int> dist;
	vector<string> paths;
	if (start.length() != target.length()) return paths;
	q.push(start);
	pred[start] = "";
	dist[start] = 0;
	while (!q.empty()) {
		string qnode = q.front(); q.pop();
		// check for terminating condition
		if (qnode == target) 
			break;
		// get neightbors - dict words that are adjacent
		set<string>::iterator it;
		for (it = dict.begin(); it != dict.end(); it++) {
			if (isAdjacent(*it, qnode)) { // adjacent neightbor
				if (pred.count(*it) == 0) { // not yet visited or can be removed from dict
					q.push(*it);
					pred[*it] = qnode;
					dist[*it] = 1 + dist[qnode];
				}
			}
			// removing visited string from dict is more efficient
		}
	}
	
	if (pred.count(target) == 0) 
		return paths;
	
	string curr = target;
	while (curr.length() != 0) {
		paths.push_back(curr);
		curr = pred[curr];
	}
	reverse(paths.begin(), paths.end());
	return paths;
}

int main() {
	set<string> D;
	/*
	D.insert("poon");
	D.insert("plee");
	D.insert("same");
	D.insert("poie");
	D.insert("plie");
	D.insert("poin");
	D.insert("plea");
	string start = "toon";
	string target = "plea";*/
	D.insert("cat");
	D.insert("bat");
	D.insert("hat");
	D.insert("bad");
	D.insert("had");
	string start = "bat";
	string target = "had";
	vector<string> res = shortestChainPath(start, target, D);
	print_arr(res); 
	return 0;
}