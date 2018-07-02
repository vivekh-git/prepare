#include <bits/stdc++.h>
using namespace std;
/* 
Algo

Recurrence relation
f(idx)  ->  if (idx == str.length())
				cout << str;
			else {
				for (int i=idx, i<str.length(); i++) {
					swap(str,i, idx);
					f(idx+1);
					swap(str,idx, i);
				}
			}
*/

bool PatternMatch(string& str, int sdx, string& pattern, int pdx, unordered_map<char, string>& dict) {
	if (str.length() < pattern.length())
		return false;
	// base case
	if (sdx == str.length() && pdx == pattern.length())
		return true;
	if (sdx == str.length() || pdx == pattern.length())
		return false;
	
	// pattern[pdx] - if it exists in map
	if (dict.count(pattern[pdx]) != 0) {
		string pstr = dict[pattern[pdx]];
		if (str.substr(sdx, pstr.length()) != pstr) 
			return false;
		return PatternMatch(str, sdx+pstr.length(), pattern, pdx+1, dict);
	}
	
	// pattern[pdx] do not exist - permute all possible combinations
	for (int len = 1; len <= str.length()-sdx; len++) {
		dict[pattern[pdx]] = str.substr(sdx, len);		
		if (PatternMatch(str, sdx+len, pattern, pdx+1, dict)) return true;
		dict.erase(pattern[pdx]);
	}
	return false;
}


int main() {
	string str;
	cin >> str;
	
	string pattern;
	cin >> pattern;
	
	unordered_map<char, string> dict;
	if (!PatternMatch(str, 0, pattern, 0, dict)) {
		cout << "no permutations exist" << endl;
	}
	else {
		for (auto it=dict.begin(); it!=dict.end(); it++) {
			cout << it->first << " - " << it->second << endl;
		}
	}
	
	return 0;
}