/*
Longest common substring
*/
#include <bits/stdc++.h>
using namespace std;
// A - 65
// a - 97
// z - 122
// A - 65 - 65 = 0
// z - 122 - 65 = 57 ~ 58 elements needed. Allocated 60
struct TrieNode {
	TrieNode* children[60];
	int idx;
	TrieNode() {
		//isWord = false;
		for (int i = 0; i < 60; i++) 
			children[i] = NULL;
	}
	~TrieNode() {
		for (int i = 0; i < 60; i++) {
			if (children[i]) {
				delete children[i]; children[i] = NULL;
			}
		}
	}
};

void insert(TrieNode* curr, string& s, int idx, pair<int, int>& max, vector<string>& result) {
    int start= -1; int end = -1;
	cout << s.substr(idx) << endl;
	for (int i = idx; i < s.length(); i++) {
		int c = s[i] - 'A';
		cout << i << " - " << c << endl;
		if (! curr->children[c]) { // not existing
			curr->children[c] = new TrieNode();
		    curr = curr->children[c];
			curr->idx = i;
        }
        else { // existing / repeating
            curr = curr->children[c];
            if (start == -1) {
				cout << "setting start - " <<  curr->idx << endl;
				start = curr->idx;
			}
			cout << "setting end - " << curr->idx << endl;
            end = curr->idx;
        }
	}

    if (start != -1 && end != max.second && max.second-max.first <= end-start) {
		cout << "max - {" << max.first << "," << max.second <<"} -- start - " << start << ", end -- " << end << endl;
		max.first = start;
		max.second = end;
        result.push_back(s.substr(start, end-start+1));
    }
	//curr->isWord = true;
}


string LRS(string iString) {
    TrieNode* root = new TrieNode();
    pair<int, int> maxpos = {0,0};
    //vector<string> result;
	vector<string> result;
    for (int i=0; i < iString.length(); i++) {
        insert(root, iString, i, maxpos, result);
    }
	string res;
	for (int i = 0; i < result.size(); i++) {
	   if (i == 0) 
	      res += result[i];
	   else
	      res += "\n" + result[i];
	}
	return res;
}

void print_arr(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[i].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

vector<string> LCS(string str1, string str2) {
	int M  = str1.length(); int N = str2.length();
	vector<vector<int>> table(M, vector<int>(N, 0));	
	int mx = 0; vector<string> result;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (str1[i] == str2[j]) {
				if (i == 0 || j == 0)
					table[i][j] = 1;
				else {
					table[i][j] = 1 + table[i-1][j-1];
					if (table[i][j] > mx) {
						mx = table[i][j];
						result.clear();
						result.push_back(str1.substr(i-mx+1, mx));
					}
					else if (table[i][j] == mx) {
						result.push_back(str1.substr(i-mx+1, mx));
					}
				}
			}
			else {
				if (i == 0 || j == 0)
					table[i][j] = 0;
				else
					table[i][j] = max(table[i-1][j], table[i][j-1]);
			}
		}
	}
	//print_arr(table);
	return result; 
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    //string res;
    string str1, str2;
    getline(cin, str1);
    //res = LRS_v2(str1);
    //cout << res << endl;
    getline(cin, str2);
	vector<string> result = LCS(str1, str2);
	for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;

    return 0;
}