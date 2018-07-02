#include <bits/stdc++.h>

using namespace std;
const char WILD_CHAR = '?';

void WildcardUtil(string& str, int idx) {
	if (idx == str.length()) {
		cout << str << endl;
	}
	else if (str[idx] == WILD_CHAR) {
		str[idx] = '0';
		WildcardUtil(str, idx+1);
		str[idx] = '1';
		WildcardUtil(str, idx+1);
		str[idx] = WILD_CHAR;
	}
	else {
		WildcardUtil(str, idx+1);
	}
}


void Wildcard(string& str) {
	WildcardUtil(str, 0);
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string str;
	cin >> str;
	Wildcard(str);
	return 0;
}
