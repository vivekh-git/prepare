#include <bits/stdc++.h>

using namespace std;

/*
Recurrence Relation
f(start)   = if (start == str.length()) {
				print_arr(arr);
			    return true;
			}
			else {
				for (int i=start, i<str.length(); i++) {
					string word = str.substr(start, i-start+1);
					if (dict.count(word) != 0) {
						arr.push_back(word);
					    f(start+word.length());
						arr.pop_back();
					}
				}
				return false;
			}
*/
void print_arr2(vector<string>& arr) {
	for (int i=0; i<arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_arr(vector<string>& arr) {
	for (int i=0; i<arr.size(); i++) {
		cout << arr[i] << endl;
	}
}

void print_arr(vector<bool>& arr) {
	for (int i=0; i<arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_arr(vector<int>& arr) {
	for (int i=0; i<arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_arr(vector<list<string>>& arr) {
	for (int i=0; i<arr.size(); i++) {
		for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
}

bool WordBreak(string& str, int start, vector<string>& arr, unordered_set<string>& dict) {
	//cout << "str:" << str << ", start:" << start << endl;
	if (start == str.length()) {
		print_arr(arr);
		return true;
	}
	else {
		for (int i=start; i<str.length(); i++) {
			string word = str.substr(start, i-start+1);
			//cout << "word:" << word << endl;
			if (dict.count(word) != 0) {
				arr.push_back(word);
				WordBreak(str, start+word.length(), arr, dict);
				arr.pop_back();
			}
		}
		return false;
	}
}

bool WordBreak2(string& str, int start, vector<string>& arr, unordered_set<string>& dict) {
	//cout << "str:" << str << ", start:" << start << endl;
	if (start == str.length()) {
		print_arr2(arr);
		return true;
	}
	else {
		for (auto it = dict.begin(); it != dict.end(); it++) {
			int len = (*it).length();
			if (start+len > str.length())
				continue;
			if (str.substr(start, len) == *it) {
				arr.push_back(*it);
				WordBreak2(str, start+len, arr, dict);
				arr.pop_back();
			}
		}
		return false;
	}
}


// Using DP
/* Recurrence relation
   wb[i] = true if (0 to i-1 can be split into valid words) else false
   wb[0] = true // initial state
Explaination - start from pos 0.
  - go through all words in dict, if any of those words are found in str starting at that pos and matching,  
    - then mark pos+wordlen position in array as true.
    - do that for all words in dict.
  - then iterate through bool array until you find a position that is true (meaning end of a word in dict)
    - repeat iterating through dict and finding words starting at this position in string
    - mark pos+wordlen as true in bool array.
  - this is expensive for large dictionaries.
Alternative - start from pos 0.
  - go from next position to end of string as length and compute various substrings and check if they are present in dict
  - if they are present in dict, mark those position as true in bool array.
  - jump to the next position in string where bool array is true as it marks word end and repeat the process.
*/
bool WordBreak_DP(string& str, unordered_set<string>& dict) {
	vector<int> wb(str.length()+1, -1);
	wb[0] = 0;
	
	for (int i = 0; i < str.length(); i++) {
		// wb[0] - true - so will
		if (wb[i] == -1)
			continue;
		for (int len = 1; len < str.length()-i+1; len++) {
			if (wb[i+len] != -1)
				continue;
			string s = str.substr(i, len);
			if (dict.count(s) != 0) {
				wb[i+len] = i;
			}
		}
	}
	print_arr(wb);
	vector<string> out;
	int pos = wb[str.length()];
	int prev = str.length();
	while (prev && pos != -1) {
		string s = str.substr(pos, prev-pos);
		out.push_back(s);
		prev = pos;
		pos = wb[pos];
	}
	reverse(out.begin(), out.end());
	print_arr(out);
	
	return (wb[str.length()]!=-1);
}

void dfs(vector<list<string>>& wb, vector<string>& outarr, string curr, int pos) {
	if (pos == 0) {
		// trim curr
		outarr.push_back(curr.substr(0, curr.length()-1));
		return;
	}
	list<string> l = wb[pos];
	for (auto it = l.begin(); it != l.end(); it++) {
		string combo = *it + " " + curr;
		dfs(wb, outarr, combo, pos-(*it).length());
	}
}

bool WordBreak_DP2(string& str, vector<string>& outarr, unordered_set<string>& dict) {
	vector<list<string>> wb(str.length()+1);
	wb[0] = {}; // for standard purpose

	for (int i = 0; i < str.length(); i++) {
		// wb[0] - true - so will
		if (i != 0 && wb[i].empty())
			continue;
		for (int len = 1; len < str.length()-i+1; len++) {
			string s = str.substr(i, len);
			if (dict.count(s) != 0) {
				wb[i+len].push_back(s);
			}
		}
	}
	print_arr(wb);
	
	// do a dfs on wb to compute all possible combinations
	// store the string combos in outarr;
	// possible combo string - combo
	if (wb[str.length()].empty())
		return false;
	dfs(wb, outarr, "", str.length());
    print_arr(outarr);
	return true;
}


/* Driver Program to test above functions */
int main()
{
	unordered_set<string> dict = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream",
									"icecream", "man", "go", "mango", "and"};
	
	string str;
	cin >> str;

	vector<string> arr;
	WordBreak2(str, 0, arr, dict);
	
	vector<string> outarr;
	bool ret= WordBreak_DP2(str, outarr, dict);
	cout << "ret = " << ret << endl;

    return 0;
}
