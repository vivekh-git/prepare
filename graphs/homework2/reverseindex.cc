#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isWord;
	int pos;
	TrieNode() {
		isWord = false;
		children = {};
		pos = -1;
	}
};




void insert(TrieNode* root, string& word, int pos) {
	TrieNode* curr = root;
	for (int i=0; i < word.length(); i++) {
		char c = word[i];
		if (curr->children.count(c) == 0) {
			curr->children[c] = new TrieNode;
		}
		curr = curr->children[c];
	}
	curr->isWord = true;
	curr->pos = pos;
}

void buildIndex(TrieNode* root, string& filetext) {
	string word;
	for (int i=0; i < filetext.length(); i++) {
		if (char(filetext[i]) == ' ' && word.empty()) continue;
		else if (char(filetext[i]) == ' ' && !word.empty()) {
			insert(root, word, i - word.length());
			word = "";
		}
		else if (char(filetext[i]) != ' ') {
			word = word + filetext[i];
		}
	}
}

int indexOf(TrieNode* root, string& word) {
	TrieNode* curr = root;
	for (int i=0; i < word.length(); i++) {
		char c = word[i];
		if (curr->children.count(c) == 0) {
			return -1;
		}
		curr = curr->children[c];
	}
	if (curr && curr->isWord)
		return curr->pos;
	else 
		return -1;
}


int main() {
	string filetext = "loren ipsum vivek lollipop lolli cupcake lollipop carrot up cupcake";
	TrieNode* root = new TrieNode;
	buildIndex(root, filetext);
		
	string word;
	getline(cin, word);
	
	cout << word.length() << endl;
	cout << indexOf(root, word) << endl;
	return 0;
}