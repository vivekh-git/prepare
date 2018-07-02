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

using namespace std;

bool isPalindrome(string& str, int b, int e) {
	return (e <= b) || (str[e] == str[b] && isPalindrome(str, b+1, e-1));
}
 
/*
 * Complete the function below.
 */
// brute force - O(n3) - works - can be O(n4)
pair<int, int> findLongestPalindrome_v1(string str) {
	//pair<int, int> result(INT_MIN, INT_MAX);
    if (str.length() == 0) assert(0);
    for	(int e = str.length(); e > 0; e--) {
    	for (int b = 0; b < e; b++) {
    		if (isPalindrome(str, b, e))
				return {b, e};
    	}
    }
	assert(0);
}

// O(n) - manacher algorithm for finding longest palindrome substring
// O(n2)
pair<int, int> findLongestPalindrome_v2(string str) {
	pair<int, int> result(0,0);
	if (str.length() == 0) return result;
	
	for (int c=0; c<str.length(); c++) {
		// do odd palindrome
		int b=c-1;
		int e=c+1;
		while(b>=0 && e<str.length() && str[b] == str[e]) {
			b--; e++;
		}
		b++; e--;
		// set result
		if (e-b > result.second-result.first) {
			result.first = b; result.second = e;
		}
		
		// do even palindrome
		b=c;
		e=c+1;
		while(b>=0 && e<str.length() && str[b] == str[e]) {
			b--; e++;
		}
		b++; e--;
		// set result
		if (e-b > result.second-result.first) {
			result.first = b; result.second = e;
		}
	}
	return result;
}

// manacher algo
// O(n)
string longestpalindromesubstr(string& text) {
	if (text.length() == 0) return "";
	// add $ to take care of even palindrome
	string newtext; newtext.push_back('$');
	for (int i = 0; i < text.length(); i++) {
		newtext.push_back(text[i]);
		newtext.push_back('$');
	}
	int M = newtext.length();
	vector<int> T(M);  // palindrome length arr at that position
	int c = 0; int b = c-1; int e = c+1;
	for (c = 0; c < newtext.length(); ) { // c need to be incremented inside loop
		while (b >= 0 && e < newtext.length() && newtext[b] == newtext[e]) {
			b--; e++;
		}
		b++; e--;
		T[c] = e-b+1;
		// if we reach end break
		if (e == newtext.length()-1) break;
		// find newcenter - end or end+1
		int newcenter = e + (c % 2 == 0 ? 1 : 0);
		for (int j = c+1; j <= e; j++) {
			T[j] = min(T[c-(j-c)], 2*(e-j)+1);
			if (T[c-(j-c)]/2 == e-j) { // overlaps with end of current palindrome
				newcenter = j;
				break;
			}
		}
		c = newcenter;
		b = c - T[c]/2;
		e = c + T[c]/2;
	}
	int max = 0; int maxindex = 0;
	for (int i = 0; i < T.size(); i++) {
		if (T[i] > max) {
			max = T[i];
			maxindex = i;
		}
	}
	cout << "max length = " << max/2 << ", maxindex = " << maxindex << endl;
	// palindrome substr is max chars centered around maxindex and strip $
	string result;
	for (int i = maxindex-max/2; i <= maxindex+max/2; i++) {
		if (newtext[i] != '$')
			result.push_back(newtext[i]);
	}
	cout << "palindrome str = " << result << endl;
	return result;
}

string longestpalindromesubstr_DP(string& text) {
	int M = text.length();
	if (M <= 1) return text;
	vector<vector<bool>> palind(M, vector<bool>(M, false));
	pair<int, int> result = {0,0};
	for (int i = M-1; i >= 0; i--) {
		for (int j = i; j < M; j++) {
			if (i == j)
				palind[i][j] = true;
			else if (j == i+1 && text[i] == text[j])
				palind[i][j] = true;
			else if (text[i] == text[j] && palind[i+1][j-1])
				palind[i][j] = true;
			if (palind[i][j] && j-i > result.second-result.first) {
				result.first = i; result.second = j;
			}
		}
	}
	return text.substr(result.first, result.second-result.first+1);
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string result;
    string _strText;
    getline(cin, _strText);

    pair<int, int> r = findLongestPalindrome_v2(_strText);
	cout << "v1: pair - {" << r.first << " - " << r.second << "}" << endl;
	cout << "v1: longest palindrome - " << _strText.substr(r.first, r.second-r.first+1) << endl;
	
	string res = longestpalindromesubstr(_strText);
	cout << "manacher: res - " << res << endl;
	
	string maxstr = longestpalindromesubstr_DP(_strText);
	cout << "DP: maxstr - " << maxstr << endl;
    //fout.close();
    return 0;
}