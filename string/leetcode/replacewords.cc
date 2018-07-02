#include <bits/stdc++.h>
using namespace std;

/* PROBLEM
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/

#define N 26
struct TrieNode {
    TrieNode* children[N];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < N; i++)
            children[i] = NULL;
        isWord = false;
    }
    ~TrieNode() {
        for (int i = 0; i < N; i++) {
            delete children[i];
            children[i] = NULL;
        }
    }
};

class Solution {
public:
     void insert(TrieNode* _root, string word) {
        TrieNode* curr = _root;
        for (int i = 0; i < word.length(); i++) {
            int ch = word[i] - 'a';
            if (curr->children[ch] == NULL) 
                curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->isWord = true;
    }
    
    /** Returns the first prefix found in the tree */
    string search(TrieNode* _root, string word) {
        TrieNode* curr = _root;
        for (int i = 0; i < word.length(); i++) {
            int ch = word[i] - 'a';
            if (curr->isWord)
                return word.substr(0, i);
            else if (curr->children[ch] == NULL)
                return word;
            curr = curr->children[ch];
        }
        return word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(TrieNode* _root, string prefix) {
        TrieNode* curr = _root;
        for (int i = 0; i < prefix.length(); i++) {
            int ch = prefix[i] - 'a';
            if (curr->children[ch] == NULL)
                return false;
            curr = curr->children[ch];
        }
        return (curr != NULL);
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* _root = new TrieNode();
        for (int i = 0; i < dict.size(); i++)
            insert(_root, dict[i]);
        
        size_t i = 0; string newsentence;
        while (i < sentence.length()) {
            size_t j = sentence.find(' ', i);
            string word;
            if (j == i) {
                i = j+1; continue;
            }
            else if (j != string::npos) {
                word = sentence.substr(i, j-i);
                i = j + 1;
            }
            else {
                word = sentence.substr(i);
                i = sentence.length();
            }
            if (newsentence.size() != 0)
                newsentence += " ";
            newsentence += search(_root, word);   
        }
        return newsentence;
    }
    
    /*
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* _root = new TrieNode();
        for (int i = 0; i < dict.size(); i++) {
            insert(_root, dict[i]);
        }
        string word; string prefix; vector<string> outarr;
        bool wordstart = true;
        bool prefixfound = false;
        //string newsentence;
        TrieNode* curr = _root;
        for (int i = 0; i < sentence.length(); i++) {
            char ch = sentence[i];
            int c = ch - 'a';
            if (ch != ' ' && prefixfound)
                continue;
            else if (ch != ' ') {
                word.push_back(ch);
                if (wordstart && curr->children[c] != NULL) {
                    curr = curr->children[c];
                    prefix.push_back(ch);
                    if (curr->isWord) 
                        prefixfound = true;
                }
                else {
                    wordstart = false;
                }
            }
            else if (word.length() > 0 && prefix.length() > 0 && prefixfound) {
                // word split found
                // check if it exists in Trie
                outarr.push_back(prefix);
                wordstart = true;
                prefix.clear(); word.clear();
                curr = _root;
                prefixfound = false;
            }
            else if (word.length() > 0) {
                outarr.push_back(word);
                wordstart = true;
                prefix.clear(); word.clear();
                curr = _root;
                prefixfound = false;
            }
        }
        if (word.length() > 0 && prefix.length() > 0 && curr->isWord) {
            // word split found
            // check if it exists in Trie
            outarr.push_back(prefix);
            wordstart = true;
            prefix.clear(); word.clear();
            curr = _root;
            prefixfound = false;
        }
        else if (word.length() > 0) {
            outarr.push_back(word);
            wordstart = true;
            prefix.clear(); word.clear();
            curr = _root;
            prefixfound = false;
        }
        
        string newsentence;
        for (int i = 0; i < outarr.size(); i++) {
            if (i == 0)
                newsentence += outarr[i];
            else
                newsentence += ' ' + outarr[i];
        }
        return newsentence;
    }*/
    
};
