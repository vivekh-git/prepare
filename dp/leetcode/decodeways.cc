#include <bits/stdc++.h>
using namespace std;

int numDecodingsUtil(string& s, int len) {
	if (len == 0) return 1;
	else if (len == 1) return (s[len-1] == '0' ? 0 : 1;
	else if (s[len-1] == '0') return (s[len-2] != '1' && s[len-2] != '2') ? 0 : numDecodingsUtil(s, len-2);
	else if (s[len-2] == '0' || s[len-2] > '2' || (s[len-2] == '2' && s[len-1] > '6'))
		return numDecodingsUtil(s, len-1);
	else
		return numDecodingsUtil(s, len-1) + numDecodingsUtil(s, len-2);
}

int numDecodings(string& s) {
	return numDecodingsUtil(s, s.length());
}

int numDecodingsDP(string& s) {
	if (s.empty()) return 1; // can return 0 as well
	vector<int> table(s.length()+1, 0);
	for (int i = 0; i < s.length()+1; i++) {
		if (i == 0)
			table[i] = 1;
		else if (i == 1)
			table[i] = (s[i-1] == '0') ? 0 : 1;
        else if (s[i-1] == '0')
			table[i] = (s[i-2] != '1' && s[i-2] != '2') ? 0 : table[i-2];
		else if (s[i-2] == '0' || s[i-2] > '2' ||
			(s[i-2] == '2' && s[i-1] > '6'))
			table[i] = table[i-1];
		else
			table[i] = table[i-1] + table[i-2];
	}
	return table[s.length()];
}



int main() {
	string s = "0226";
	int res = numDecodingsDP(s);
	cout << "res - " << res << endl;
	return 0;
}