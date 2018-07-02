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
/* recursive definition
string and pattern are constants
pattern can have . and *
f(i, j) = if (i == str.length) return (j== pattern.length());
		  if (j == pattern.length) return (i == str.length());

		  if (str[i] == pattern[j])
			return f(i+1, j+1);
          if (pattern[j] == .)
			return f(i+1, j+1);
		  if (pattern[j] == *)
            return f(i, j+1) || f(i+1, j); // 0 case, more case
		  return false;
*/
bool _regexmatch(string & str, int i, string& pattern, int j) {
	if (j == pattern.length()) return (i == str.length());
	
	else if (i == str.length())
		if (pattern[j] == '*')
			return _regexmatch(str, i, pattern, j+1);
		else	
			return false;

	else if (pattern[j] == '*')
		return _regexmatch(str, i, pattern, j+1) || _regexmatch(str, i+1, pattern, j);
	
	else if (str[i] == pattern[j] || pattern[j] == '.')
		return _regexmatch(str, i+1, pattern, j+1);
	
	return false;	
}

// a* - should be 0 or more as in input str
// a. - should be 1 a
// .* - should be anything
bool _regexmatch2(string & str, int i, string& pattern, int j) {
	if (j == pattern.length()) return (i == str.length());
	
	else if (j+1 < pattern.length() && pattern[j+1] == '*')
		return _regexmatch2(str, i, pattern, j+2) || (i != str.length() && (str[i] == pattern[j] || pattern[j] == '.') && _regexmatch2(str, i+1, pattern, j));
	
	else if (i != str.length() && (str[i] == pattern[j] || pattern[j] == '.'))
		return _regexmatch2(str, i+1, pattern, j+1);
	
	return false;	
}



bool RegexMatch(string& str, string& pattern) {
	return _regexmatch2(str, 0, pattern, 0);
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
    bool match = RegexMatch(_strText, _strPattern);
	cout << "str - " << _strText << ", pattern - " << _strPattern << ", match - " << match << endl;
	
    //fout.close();
    return 0;
}