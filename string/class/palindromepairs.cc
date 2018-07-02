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
#include <unordered_set>
#include <assert.h>
#include <algorithm>

using namespace std;

bool isPalindrome(string& str, int b, int e) {
	return (e <= b) || (str[e] == str[b] && isPalindrome(str, b+1, e-1));
}
 
/*
 * Complete the function below.
 */
// brute force - O(n3) - works - can be O(n4)
const int ALPHABET_SIZE = 26;
struct TrieNode {
	TrieNode* children[ALPHABET_SIZE];
	bool isWord;
	int wordIndex;
	TrieNode() {
		for (int i=0; i<ALPHABET_SIZE; i++) {
			children[i] = NULL;
		}
		isWord = false;
		wordIndex = -1;
	}
};

void TrieInsert(TrieNode* root, string& word, int index) {
	TrieNode* curr = root;
	for (int i=0; i<word.length(); i++) {
		int c = word[i] - 'a';
		if (! curr->children[c])
			curr->children[c] = new TrieNode;
		curr = curr->children[c];
	}
	curr->isWord = true;
	curr->wordIndex = index;
}


bool TrieSearch(TrieNode* root, string& word) {
	TrieNode* curr = root;
	for (int i=0; i<word.length(); i++) {
		int c = word[i] - 'a';
		if (!curr->children[c]) return false;
		curr = curr->children[c];
	}
	return curr->isWord;
}


set<pair<string, string>> findPalindromePairs_v2(vector<string>& strarr) {
	set<pair<string, string>> result;
	// build forward and inverse trie
	TrieNode* trie = new TrieNode;
	TrieNode* rtrie = new TrieNode;
	for (int i=0; i< strarr.size(); i++) {
		TrieInsert(trie, strarr[i], i);
		string rstr = strarr[i];
		reverse(rstr.begin(), rstr.end());
		TrieInsert(rtrie, rstr, i);
	}	
	
	string tmp;
	for (int i=0; i< strarr.size(); i++) {
		// word is strarr[i]
		// match the word with reverse Trie
		// bat - tab => bat - bat
		// race - car => race - rac	
		string word = strarr[i];
        string rword = strarr[i];
		reverse(rword.begin(), rword.end());
		
		tmp.clear();
		TrieNode* curr = rtrie;
		for (int j=0; j < word.length(); j++) {
			int c = word[j] - 'a';
			if (! curr->children[c]) break;
			tmp.push_back(word[j]);
			curr = curr->children[c];
			if (curr->isWord &&  curr->wordIndex != i && isPalindrome(word, j+1, word.length()-1)) {
				// check remaining of word is palindrome
				cout << "i - " << i << ", wordIndex - " << curr->wordIndex << endl;
				reverse(tmp.begin(), tmp.end());
				result.insert({word, tmp});
			}
		}
		
		// match the reverse word with regular Trie
		// car - race => rac - race - should not match
		// ab - deedba => ba - deedba - should not match
		// bag - gab => gab - gab - should match
		tmp.clear();
		curr = trie;
		for (int k=0; k < rword.length(); k++) {
			int c = rword[k] - 'a';
			if (! curr->children[c]) break;
			tmp.push_back(rword[k]);
			curr = curr->children[c];
			if (curr->isWord && curr->wordIndex != i && isPalindrome(rword, k+1, rword.length()-1)) {
				cout << "i - " << i << ", wordIndex - " << curr->wordIndex << endl;
				//reverse(tmp.begin(), tmp.end());
				result.insert({word, tmp});
			}
		}
	}
	return result;
}

set<pair<string, string>> findPalindromePairs(vector<string>& strarr) {
	set<pair<string, string>> result;
	for (int i = 0; i < strarr.size(); i++) {
		for (int j= 0; j < strarr.size(); j++) {
			if (i == j) continue;
			string palin = strarr[i] + strarr[j];
			if (isPalindrome(palin, 0, palin.size()-1)) {
				result.insert({strarr[i], strarr[j]});
			}
		}
	}
	return result;
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    vector<string> strarr = {"bat", "cat", "tab",  "race", "car"};

    set<pair<string, string>> result = findPalindromePairs(strarr);
	cout << "printing palindrome pairs" << endl;
	for (set<pair<string, string>>::iterator it=result.begin();  it!= result.end(); it++) {
		cout << "{" << (*it).first << "-" << (*it).second << "}" << endl;
	}
	    //fout.close();
    return 0;
}