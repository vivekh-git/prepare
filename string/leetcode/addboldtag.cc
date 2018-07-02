#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isWord;
	TrieNode() {
		isWord = false;
	}
};

void insert(TrieNode* root, string& s) {
	TrieNode* curr = root;
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		if (curr->children.count(ch) == 0)
			curr->children[ch] = new TrieNode();
		curr = curr->children[ch];
	}
	curr->isWord = true; 
}

class mycompare {
public:
	bool operator()(const pair<int,int>& lhs, const pair<int, int>& rhs) {
		// acending sort needs maxheap which needs less than operator
		return (lhs.first < rhs.first);
	}
};

// Use s.find and s.insert and avoid trie and merging character by character
string addBoldTag(string s, vector<string>& dict) {
	TrieNode* root = new TrieNode();
	for (int i = 0; i < dict.size(); i++)
		insert(root, dict[i]);
	
	vector<pair<int,int>> intervals;
	for (int i = 0; i < s.length(); i++) {
		TrieNode* curr = root;
		for (int j = i; j < s.length(); j++) {
			char ch = s[j];
			if (curr->children[ch] == 0) break;
			curr = curr->children[ch];
			if (curr->isWord) {
				// this is a dict word - add it to interval array
				intervals.push_back({i, j});
			}
		}
	}
	
	// merge interval array
    sort(intervals.begin(), intervals.end(), mycompare());
	stack<pair<int,int>> st;
	for (int i = 0; i < intervals.size(); i++) {
		if (st.empty() || st.top().second+1 < intervals[i].first) {
			st.push({intervals[i].first, intervals[i].second});
		}
		else {
			// pop, merge and push
			pair<int, int> snode = st.top(); st.pop();
			st.push({snode.first, max(snode.second, intervals[i].second)});
		}
	}
	/*
	stack<pair<int, int>> mergedinter;
	while (!st.empty()) {
		cout << st.top().first << " -- " << st.top().second << endl;
		mergedinter.push(st.top()); st.pop();
	}*/
	
	/*
	string result;
	for (int i = 0; i < s.length(); i++) {
		if (!mergedinter.empty() && i == mergedinter.top().first) {
			result = result + "<b>";
		}
		result += s[i];
		if (!mergedinter.empty() && i == mergedinter.top().second) {
			result = result + "</b>";
			mergedinter.pop();
		}
	}*/
	
	// better merge function 
	while (! st.empty()) {
		cout << st.top().first << " -- " << st.top().second << endl;
		pair<int,int> snode = st.top(); st.pop();
		s.insert(snode.second+1, "</b>");
		s.insert(snode.first, "<b>");
	}
	return s;
	
}



int main() {
	vector<string> dict = {"aaa", "aab", "bc"};
	string s = "aaabbcc";
	string res = addBoldTag(s, dict);
	cout << "res = " << res << endl;
	if  (res == "<b>aaabbc</b>c") {
		cout << "Result matched" << endl;
	}
	else {
		cout << "result did not match" << endl;
	}
	return 0;
}