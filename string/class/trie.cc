#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;
struct TrieNode {
	TrieNode* children[ALPHABET_SIZE];
	bool isWord;
	TrieNode() {
		isWord = false;
		for (int i=0; i<ALPHABET_SIZE; i++) {
			children[i] = NULL;
		}
	}
};

void insert(TrieNode* root, string str) {
	TrieNode* curr = root;
	for (int i=0; i<str.length(); i++) {
		int c = str[i] - 'a';
		if (! curr->children[c]) {
			curr->children[c] = new TrieNode;
		}
		curr = curr->children[c];
	}
	curr->isWord = true;
}

bool search(TrieNode* root, string str) {
	TrieNode* curr = root;
	for (int i=0; i<str.length(); i++) {
		int c = str[i] - 'a';
		if (! curr->children[c]) return false;
		curr = curr->children[c];
	}
	return (curr && curr->isWord);
}

struct TrieNode2 {
	unordered_map<char, TrieNode2*> children;
	bool isWord;
	TrieNode2() {
		children = {};
		isWord = false;
	}
};

void insert(TrieNode2* root, string str) {
	TrieNode2* curr = root;
	for (int i=0; i<str.length(); i++) {
		char c = str[i];
		if (curr->children.count(c) == 0)
			curr->children[c] = new TrieNode2;
		curr = curr->children[c];
	}
	curr->isWord = true;
}

bool search(TrieNode2* root, string str) {
	TrieNode2* curr = root;
	for (int i=0; i<str.length(); i++) {
		char c = str[i];
		if (curr->children.count(c) == 0)
			return false;
		curr = curr->children[c];
	}
	return (curr && curr->isWord);
}

void printAllPaths(TrieNode2* node, string result) {
	// recursive function
	if (node->isWord) cout << result << endl;
	for (unordered_map<char, TrieNode2*>::iterator it = node->children.begin(); it != node->children.end(); it++) {
		//it->first - char
		//it->second - trienode
		// push , recurse and pop
		result.push_back(it->first);
		printAllPaths(it->second, result);
		result.pop_back();
	}
}

/*
		if (c != '.' && c != '*' && curr->children.count(c) == 0)
			return;
		if (c == )
*/
void printAllPrefixMatch(TrieNode2* root, string prefix) {
	// search the prefix
	TrieNode2* curr = root;
	for (int i=0; i<prefix.length(); i++) {
		char c = prefix[i];
		curr = curr->children[c];
	}
	
	// Now print all paths and print whenever isWord is true
	printAllPaths(curr, prefix);
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    vector<string> keys = {"the", "a", "there", "byabcdefh", "theabcdefghi",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = keys.size(); 
    TrieNode2* root = new TrieNode2;
    // build trie	
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
	cout << "searching trie" << endl;
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
	cout << "searching done" << endl;
	
	// print prefix match
	cout << "prefix matching" << endl;
	printAllPrefixMatch(root, "the");
	printAllPrefixMatch(root, "by");
	cout << "prefix matching done" << endl;
	
	// regex match
	cout << "regex matching" << endl;
	printAllPrefixMatch(root, "the*");
	cout << "regex matching done" << endl;
	
	return 0;
}