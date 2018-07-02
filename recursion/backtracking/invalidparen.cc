#include <bits/stdc++.h>

using namespace std;

bool isParenthesis(char ch) {
	return (ch == '(' || ch == ')');
}

bool isValid(string& str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') count++;
		else if (str[i] == ')') count--;
		if (count < 0) return false;
	}
	return (count == 0);
}

void RemoveInvalidParen(string& str) {
	if (str.empty()) return;
	queue<string> q; 
	unordered_set<string> visited;
	bool level = false;
	q.push(str);
	visited.insert(str);
	while (!q.empty()) {
		string qnode = q.front(); q.pop();
		if (isValid(qnode)) {
			cout << qnode << endl;
			level = true;
		}
		if (level) continue; // if level is true - no need to find neighbors
		// find neighbors
		for (int i = 0; i < qnode.length(); i++) {
			if (!isParenthesis(qnode[i])) continue;
			string neighbor = qnode.substr(0, i) + qnode.substr(i+1);
			if (visited.count(neighbor) == 0) {
				q.push(neighbor);
				visited.insert(neighbor);
			}
		}
	}
}


int main() {
	string str;
	cin >> str;

    RemoveInvalidParen(str);
	
	return 0;
}