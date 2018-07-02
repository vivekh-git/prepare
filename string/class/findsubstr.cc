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

using namespace std;

/*
 * Complete the function below.
 */
// brute force - O(n3) - works - can be O(n4)
// pattern search
string findSubStr(string strText, string strPattern) {	
	int matchlen = INT_MAX; string res;
	for (int left = 0; left < strText.length(); left++) {
		for (int right = 1; right < strText.length()-left+1; right++) {
			string s = strText.substr(left, right);
			bool matched = true;
			for (int i = 0; i < strPattern.length(); i++) {
				if (s.find(strPattern[i]) == string::npos) {
					matched = false;
					break;
				}
			}
			if (matched && s.length() < matchlen) {
				matchlen = s.length();
				res = s;
			}
		}
	}
	return res;
}

// brute force - O(n3) - GOOD
void findSubStr_v2(string strText, string strPattern) {	
	set<char> control;
	for (int k = 0; k < strPattern.length(); k++) {
		control.insert(strPattern[k]);
	}
 
	string res;
	//cout << res << ", len = " << res.length() << endl;
	// TODO: can do - left + control.size() -1 < strText.length()
	for (int left = 0; left < strText.length(); left++) {
		// TODO: can do right = left+control.size()-1
		for (int right = left; right < strText.length(); right++) {
			set<char> seen;
			for (int i = left; i <= right; i++) {
				// search
				if (control.count(strText[i]) != 0) {
					seen.insert(strText[i]);
				}
			}
			if (seen.size() == control.size()) {
				//cout << "seen size - " << seen.size() << ", control size - " << control.size() << ", substr len - " << right-left+1 << endl;
				if (res.empty() || res.length() > right-left+1) {
					// found a smaller string
					res = strText.substr(left, right-left+1);
				}
			}
		}
	}
    cout << "findSubStr_v2: shortest match str - " << res << endl;
}


// O(n2)
struct result {
	int start;
	int end;
	result(): start(0), end(0) {}
	result(int s, int e) : start(s), end(e) {} 
	unsigned int length() {return end-start+1;} 
};

void findSubStr_v3(string strText, string strPattern) {	
	set<char> control;
	for (int k = 0; k < strPattern.length(); k++) {
		control.insert(strPattern[k]);
	}
	result res(INT_MIN, INT_MAX);
	cout << "st - " << res.start << endl;
	cout << "end - " << res.end << endl;
	cout << "max len = " << res.length() << endl;
 
	//cout << res << ", len = " << res.length() << endl;
	for (int left = 0; left < strText.length(); left++) {
		set<char> seen;
		for (int right = left; right < strText.length(); right++) {
			if (control.count(strText[right]) != 0) {
				seen.insert(strText[right]);
				if (seen.size() == control.size()) {
					cout << left << "--" << right << "--" << "seen size - " << seen.size() << ", control size - " << control.size() << ", substr len - " << right-left+1 << endl;
					if (res.start == INT_MIN ||  right-left+1 < res.length()) {
						res.start = left;
						res.end = right;
					}
				}
			}
		}
	}
	cout << "res.start - " << res.start << ", res.end - " << res.end << endl;
	if (res.start > INT_MIN) {
    	cout << "shortest match str - " << strText.substr(res.start, res.length()) << endl;
	}
}


// O(n) logic
// Expand, optimize
pair<int, int> findSubStr_v4(string strText, string strPattern) {	
	set<char> control;
	for (int k = 0; k < strPattern.length(); k++) {
		control.insert(strPattern[k]);
	}

    pair<int, int> result(INT_MIN, INT_MAX); 
	int left = 0;
    for (left = 0; left < strText.length(); left++) {
    	if (control.count(strText[left]) != 0)
			break;
    }

    unordered_map<char, int> seen;
	char c = strText[left];
	seen[c] = 1;
	int missing = control.size() - 1;
	//int missing = control.size();
	for (int right = left+1; right < strText.length(); right++) {
		// expand
		char r = strText[right];
		if (control.count(r) == 0) continue;
		
		if (seen.count(r) == 0 || seen[r] == 0) {
			seen[r] = 1;
			missing--;
		}
		else {
			seen[r]++;
		}
		// continue expand until missing is 0
		if (missing != 0) continue; 
		// missing is 0 - this is the first eligible window - set it in result
		if (result.first == INT_MIN || right-left < result.second-result.first) {
			result.first = left;
			result.second = right;
		}
		
		// Now optimize by shrinking left until missing is greater than 0
		for (; missing <= 0; left++) {
			char l = strText[left];
			if (seen.count(l) == 0) continue; // not the one in control - left gets incremented
			seen[l]--;
			if (seen[l] == 0) missing++;
		}
		// set left here in result
		if (right-left+1 < result.second-result.first) {
			result.first = left-1;
			result.second = right;
		}
		// now go and expand using the first for loop
	}
	
	cout << "findSubStr_v4: shortest substring matching control - " << strText.substr(result.first, result.second-result.first+1) << endl;
    return result;
}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string result;
    string _strText;
    getline(cin, _strText);
    
    string _strPattern;
    getline(cin, _strPattern);
    
    //result = findSubStr(_strText, _strPattern);
	//cout << result << endl;
	//findSubStr_v2(_strText, _strPattern);
	//findSubStr_v3(_strText, _strPattern);
    pair<int, int> r = findSubStr_v4(_strText, _strPattern);
	cout << "pair - {" << r.first << " - " << r.second << "}" << endl;
	
    //fout.close();
    return 0;
}