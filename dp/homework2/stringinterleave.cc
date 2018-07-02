#include <bits/stdc++.h>
using namespace std;

/* Recurrence Relation
f(i, j) ->  if (i == m && j == n)
				print output;
				return true;
			else if (i == m)
				output.push_back(str2[j-n]);
				print output;
				return true;
			else if (j ==n)
				output.push_back(str1[i-m]);
				print output;
				return true;
			else {
				output.push_back(s1[i]);
				f(i+1, j);
				output.pop_back();
				output.push_back(s2[j]);
				f(i, j+1);
				output.pop_back();
			}
*/
bool printStringInterleaveUtil(string& s3, int pos, string& s1, int i, string& s2, int j) {
	if (i == s1.length() && j == s2.length()) {
		cout << s3 << endl;
		return true;
	}
	else if (i == s1.length()) {
		for (int l = j; l < s2.length(); l++) {
			s3[pos] = s2[l];
			pos++;
		}
		cout << s3 << endl;
		return true;
	}
	else if (j == s2.length()) {
		for (int l = i; l < s1.length(); l++) {
			s3[pos] = s1[l];
			pos++;
		}
		cout << s3 << endl;
		return true;
	}
	else {
		s3[pos] = s1[i];
		printStringInterleaveUtil(s3, pos+1, s1, i+1, s2, j);
		s3[pos] = s2[j];
		printStringInterleaveUtil(s3, pos+1, s1, i, s2, j+1);
	}
	return false;
}

// time complexity - O(2 pow n) - because for each character - there are 2 recursive branching happening
bool checkStringInterleaveUtil(string& s1, string& s2, string& s3, int i, int j, int k) {
	if (i == s1.length() && j == s2.length() && k == s3.length()) {
		return true;
	}
	else if (i == s1.length()) {
		if (s3[k] == s2[j])
			return checkStringInterleaveUtil(s1, s2, s3, i, j+1, k+1);
	}
	else if (j == s2.length()) {
		if (s3[k] == s1[i])
			return checkStringInterleaveUtil(s1, s2, s3, i+1, j, k+1);
	}
	else {
		if (s3[k] == s1[i] && checkStringInterleaveUtil(s1, s2, s3, i+1, j, k+1))
			return true;
		if (s3[k] == s2[j] && checkStringInterleaveUtil(s1, s2, s3, i, j+1, k+1))
			return true;
	}
	return false;
}

// time complexity - O(mnk)
bool checkStrIL_DP(string& s1, string& s2, string& s3) {
	vector<vector<vector<bool>>> table(s1.length()+1, vector<vector<bool>>(s2.length()+1, vector<bool>(s3.length()+1)));
	for (int i = s1.length(); i >= 0; i--) {
		for (int j = s2.length(); j >= 0; j--) {
			for (int k = s3.length(); k >= 0; k--) {
				if (i == s1.length() && j == s2.length() && k == s3.length())
					table[i][j][k] = true;
				else if (i == s1.length()) 
					table[i][j][k] = (s3[k] == s2[j]) && table[i][j+1][k+1];
				else if (j == s2.length())
					table[i][j][k] = (s3[k] == s1[i]) && table[i+1][j][k+1];
				else
					table[i][j][k] = (s3[k] == s1[i] && table[i+1][j][k+1]) || (s3[k] == s2[j] && table[i][j+1][k+1]);
			}
		}
	}
	return table[0][0][0];
}

// time complexity - O(mn)
bool checkStrIL_DP2(string& s1, string& s2, string& s3) {
	vector<vector<bool>> table(s1.length()+1, vector<bool>(s2.length()+1));
	if (s1.length() + s2.length() != s3.length())
		return false;
	for (int i = s1.length(); i >= 0; i--) {
		for (int j = s2.length(); j >= 0; j--) {
			if (i == s1.length() && j == s2.length())
				table[i][j] = true;
			else if (i == s1.length()) 
				table[i][j] = (s3[i+j] == s2[j]) && table[i][j+1];
			else if (j == s2.length())
				table[i][j] = (s3[i+j] == s1[i]) && table[i+1][j];
			else
				table[i][j] = (s3[i+j] == s1[i] && table[i+1][j]) || (s3[i+j] == s2[j] && table[i][j+1]);
		}
	}
	return table[0][0];
}


void printStringInterleave(string& s1, string& s2) {
	string s3;
	s3.resize(s1.length() + s2.length());
	printStringInterleaveUtil(s3, 0, s1, 0, s2, 0);
} 


int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	printStringInterleave(s1, s2);
	string s3;
	cin >> s3;
	bool ret = checkStringInterleaveUtil(s1, s2, s3, 0, 0, 0);
	cout << "ret = " << ret << endl;
	bool ret2 = checkStrIL_DP(s1, s2, s3);
	cout << "ret2 = " << ret2 << endl;
	bool ret3 = checkStrIL_DP2(s1, s2, s3);
	cout << "ret3 = " << ret3 << endl;
	return 0;
}