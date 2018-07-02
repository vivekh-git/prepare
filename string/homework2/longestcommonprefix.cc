#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isSeen;
	bool isWord;
	string prefix;
	TrieNode() {
		isSeen = false;
		isWord = false;
	}
};

class Util {
private:
	TrieNode* root;
public:
	Util() {
		root = new TrieNode();
	}
	void insert(string& s) {
		TrieNode* curr = root;
		for (int i = 0; i < s.length(); i++) {
			char ch = s[i];
			if (curr->children.count(ch) == 0) {
				curr->children[ch] = new TrieNode();
				curr = curr->children[ch];
			}
			else {
				curr = curr->children[ch];
				curr->isSeen = true;
			}
			curr->prefix = s.substr(0, i+1);
		}
		curr->isWord = true;
		
	}
	void dfs (TrieNode* curr, int len, int& maxlen, string& maxprefix) {
		if (!curr)
			return;
		if (curr->isSeen == true) {
			if (len > maxlen) {
				maxlen = len;
				maxprefix = curr->prefix;
			}
		}
		for (auto it = curr->children.begin(); it != curr->children.end(); it++) {
			dfs(it->second, len+1, maxlen, maxprefix);
		}
	}
	string commonPrefix(vector<string>& arr) {
		for (int i = 0; i < arr.size(); i++)
			insert(arr[i]);
		int maxlen = 0; string maxprefix = "";
		dfs(root, 0, maxlen, maxprefix);
		return maxprefix;
	}
};




// Driver program to test above function
int main() {
    vector<string> arr = {"geeksforgeeks", "geeks",
                    "geek", "geezer", "deefxyzghi", "deefxyzabc"};
 
	Util util;				
    string ans = util.commonPrefix(arr);
 
    if (ans.length())
        cout << "The longest common prefix is "
             << ans << endl;
    else
        cout << "There is no common prefix" << endl;
    return (0);
}
