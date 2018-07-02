/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <bits/stdc++.h>
using namespace std;
/*
struct TrieNode {
	unordered_map<char, TrieNode*> children;
	
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
    }
};
*/
#define sz 26
struct TrieNode {
	TrieNode* children[sz];
	bool isWord;
	string word;
	TrieNode() {
		isWord = false;
		for (int i = 0; i < sz; i++) 
			children[i] = NULL;
	}
	~TrieNode() {
		for (int i = 0; i < sz; i++) {
			if (children[i]) {
				delete children[i]; children[i] = NULL;
			}
		}
	}
};


vector<pair<int, int>> get_neighbors(int rows, int cols, int i, int j) {
	vector<pair<int, int>> neighbors;
	//vector<pair<int, int>> candidates = {{i, j-1}, {i, j+1}, {i-1, j-1}, {i-1, j}, {i-1, j+1}, {i+1, j-1}, {i+1, j}, {i+1, j+1}};
	vector<pair<int, int>> candidates = {{i, j-1}, {i, j+1}, {i-1, j}, {i+1, j}};    
	for (vector<pair<int,int>>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		if (it->first >= 0 && it->first < rows && it->second >= 0 && it->second < cols)
			//pair<int, int> element = {it->first, it->second };
			neighbors.push_back( {it->first, it->second });
	}
	return neighbors;
}


void dfsUtil2(vector<vector<char>>& board, int i, int j, string str, vector<vector<bool>>& visited, vector<string>& words, vector<string>& result) {
	// check if str is contained in dict
	// base case - if str do not have partial match with any word in dict - return
	cout << "entering dfsUtil, str - " << str << endl;
	bool matchfound = false;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].substr(0, str.length()) == str) {
			// partial match
			matchfound = true;
			if (words[i].length() == str.length()) {
				cout << "str - " << str << endl;
				result.push_back(str);
			}
		}
	}
	if (!matchfound) return; // base case
	cout << "matchfound true" << endl;
	vector<pair<int, int>> neighbors = get_neighbors(board.size(), board[0].size(), i, j);
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		cout << "entering dfsUtil for loop" << endl;
 		if (!visited[it->first][it->second]) {
			cout << "entering dfsUtil visited if loop" << endl;
			visited[it->first][it->second] = true;
			str.push_back(board[it->first][it->second]);
			dfsUtil2(board, it->first, it->second, str, visited, words, result);
			str.pop_back();
			visited[it->first][it->second] = false;
		}
	}
	cout << "end of for loop in dfsUtil" << endl;
}

vector<string> findWords2(vector<vector<char>>& board, vector<string>& words) {
	vector<string> result;
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				string s; s.push_back(board[i][j]);
				dfsUtil2(board, i, j, s, visited, words, result);
				visited[i][j] = false;
			}
		}
	}
	return result;   
}

void dfsUtil(TrieNode* root, vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, vector<string>& result) {
	// check if str is contained in dict using trie - base case
	int c = board[i][j] - 'a';
	if (! root->children[c])
		return;
	
	TrieNode* curr = root->children[c];
	if (!curr->word.empty()) {
		result.push_back(curr->word);
		curr->word = "";
	}
	
	vector<pair<int, int>> neighbors = get_neighbors(board.size(), board[0].size(), i, j);
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		cout << "entering dfsUtil for loop" << endl;
 		if (!visited[it->first][it->second]) {
			cout << "entering dfsUtil visited if loop" << endl;
			visited[it->first][it->second] = true;
			dfsUtil(curr, board, it->first, it->second, visited, result);
			visited[it->first][it->second] = false;
		}
	}
	cout << "end of for loop in dfsUtil" << endl;
}

void insert(TrieNode* root, string& s) {
	TrieNode* curr = root;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i] - 'a';
		if (! curr->children[c])
			curr->children[c] = new TrieNode();
		curr = curr->children[c];
	}
	curr->isWord = true;
	curr->word = s;
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	vector<string> result;
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
	
	TrieNode* root = new TrieNode();
	for (int i = 0; i < words.size(); i++)
		insert(root, words[i]);
	
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			int c = board[i][j] - 'a';
			if (! root->children[c]) continue;
			if (!visited[i][j]) {
				visited[i][j] = true;
				//string s; s.push_back(board[i][j]);
				dfsUtil(root, board, i, j, visited, result);
				visited[i][j] = false;
			}
		}
	}
	return result;   
}

int main() {
	vector<vector<char>> board =   {{'o','a','a','n'},
									{'e','t','a','e'},
									{'i','h','k','r'},
									{'i','f','l','v'}};
	vector<string> words = {"oath","pea","eat","rain"};
	vector<string> res = findWords(board, words);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}