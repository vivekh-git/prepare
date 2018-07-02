#include <bits/stdc++.h>

using namespace std;

void print_map(unordered_map<string, string>& pred) {
	for (auto it = pred.begin(); it != pred.end(); it++) {
		cout << it->first << "->" << it->second << endl;
	}
}

vector<string> findPath(string& s1, string& s2, vector<string>& dict) {
    vector<string> paths;
    queue<string> q;
    unordered_map<string, string> pred;
    q.push(s1);
    pred[s1] = "";
    while (!q.empty()) {
        string qstr = q.front(); q.pop();
        if (qstr == s2) break;
        for (int i = 0; i < dict.size(); i++) {
            int count = 0;
            for (int j = 0; j < min(qstr.length(), dict[i].length()); j++) {
                if (qstr[j] != dict[i][j]) count++;
                if (count > 1) break;
            }
            if (count != 1) continue;
			if (pred.count(dict[i]) != 0) continue;
            q.push(dict[i]);
            pred[dict[i]] = qstr;
        }
    }
	print_map(pred);
	
    if (pred.count(s2) == 0)
        return paths;
    
    string curr = s2;
    while (curr.length() != 0) {
		cout << "inside while" << endl;
        paths.push_back(curr);
        curr = pred[curr];
    }
    reverse(paths.begin(), paths.end());
    return paths;
}

int main() {
    vector<string> dict =  {"cat", "bat", "hat", "bad", "had"};
    string a = "bat";
    string b = "had";
    vector<string> paths = findPath(a, b, dict);
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << " -> ";
    }
    cout << endl;
}