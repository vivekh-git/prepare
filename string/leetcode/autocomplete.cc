/*
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
The system have already tracked down the following sentences and their corresponding times: 
"i love you" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love leetcode" : 2 times 
Now, the user begins another search: 

Operation: input('i') 
Output: ["i love you", "island","i love leetcode"] 
Explanation: 
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored. 

Operation: input(' ') 
Output: ["i love you","i love leetcode"] 
Explanation: 
There are only two sentences that have prefix "i ". 

Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a". 

Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search. 

Note:
The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
	string word;
    int val;
    TrieNode() {
        val = 0;
		children = {{}};
    }
};

class mycompare {
public:
	mycompare() {}
	bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
		// Minheap
		if (lhs.first != rhs.first)
			return (lhs.first < rhs.first);   // min heap - stings with least score is in the root so that it can be poped if needed
		else
			return (lhs.second > rhs.second); // for same score, lexicographic sorting happens where max value goes to root - maxheap
	}
};

class AutocompleteSystem {
private:
    string userinput;
    TrieNode* root;
	TrieNode* inp;

    void insert(string key, int val) {
        TrieNode* curr = root;
        for (int i = 0; i < key.length(); i++) {
            char ch = key[i];
            if ((curr->children).count(ch) == 0)
                (curr->children)[ch] = new TrieNode();
            curr = curr->children[ch];
        }
		curr->word = key;
        curr->val += val;
    }
	
	TrieNode* prefixSearch(string input) {
		TrieNode* curr = inp;
		for (int i = 0; i < input.length(); i++) {
			char ch = input[i];
			if ((curr->children).count(ch) == 0) {
				return NULL;
			}
			curr = (curr->children)[ch];
		}
		return curr;
	}
    
    //void dfs(TrieNode* curr, string output, vector<string>& outarr) {
    //void dfs(TrieNode* curr, string output, map<int, string, std::greater<int>>& outmap) {
	void dfs(TrieNode* curr, priority_queue<pair<int, string>, vector<pair<int, string>>, mycompare>& pq) {
        if (! curr) {
			cout << "curr null inside dfs" << endl;
			return;
		}

		if (curr->word != "") {
			pq.push({curr->val, curr->word});
		}
		// it->second is the trienode
        for (auto it = curr->children.begin(); it != curr->children.end(); it++) {
            dfs(it->second, pq);
		}
    }
    
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
		inp = root;
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
			// Do i need a map here to store sentences and count ?
        }
    }
    
    vector<string> input(char c) {
        vector<string> result;
        //map<int, string> countmap;
		priority_queue<pair<int, string>, vector<pair<int, string>>, mycompare> pq;
		if (c == '#') {
            // end of user input
            // add to autocomplete system
            // clear user sentence
            insert(userinput, 1);
			// check if we need to remove last # and redo the search and return result
            userinput.clear();
			inp = root;
			return result;
		}
        else {
            userinput.push_back(c);
			//TrieNode* curr = prefixSearch(userinput);
			//(curr->children).count(ch) == 0) {
			if (inp && (inp->children).count(c) != 0)
				inp = (inp->children)[c];
			else {
				inp = NULL;
				return result;
			}
			/*
			if (curr->isWord) {
				cout << "isWord true - pushing to pq" << endl;
 				pq.push({curr->val, userinput});
			}*/
			dfs(inp, pq);
			for (int i = 0; !pq.empty() && i < 3; i++) {
				result.push_back((pq.top()).second);
				pq.pop();
			}
			//cout << "reversing result" << endl;
			//reverse(result.begin(), result.end());
			return result;
        }
    }
};

void print_arr(vector<string> arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
}
void print_arr(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
}

int main() {
	int num; string mystr;
	getline(cin, mystr);
	stringstream(mystr) >> num;
	string sentence; int count;
	vector<string> sentences; vector<int> times;
	for (int i = 0; i < num; i++) {
		getline(cin, sentence);
		cout << "sentence - " << sentence << endl;
		getline(cin, mystr);
		stringstream(mystr) >> count;
		cout << "count - " << count << endl;
		sentences.push_back(sentence); times.push_back(count);
	}
	cout << "sentences" << endl;
	print_arr(sentences);
	cout << "times" << endl;
	print_arr(times);
	
	AutocompleteSystem obj(sentences, times);
	
	int numinput;
	getline(cin, mystr);
	stringstream(mystr) >> numinput;
	cout << "numinput = " << numinput << endl;
	while (1) {
		char c;
		getline(cin, mystr);
		c = mystr[0];
		cout << "User input - " << c << endl;
		vector<string> param_1 = obj.input(c); 
		cout << "Result - " << endl;
		cout << "[ ";
		for (int i = 0; i < param_1.size(); i++) {
			cout << param_1[i] << ", ";
		}
		cout << " ]" << endl;
	}
	
	return 0;
}