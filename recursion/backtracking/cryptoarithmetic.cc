#include <bits/stdc++.h>

using namespace std;

/*
LEARNINGS:-
*/
void print_map(unordered_map<char, int>& dict) {
	for (auto it = dict.begin(); it != dict.end(); it++) {
		cout << it->first << " -> " << it->second << endl;
	}
}


vector<char> getDistinctChars(string& str1, string& str2, string& result) {
	unordered_set<char> visited;
	vector<char> deduparr;
	for (int i=0; i< str1.length(); i++) {
		if (visited.count(str1[i]) == 0) {
			visited.insert(str1[i]);
			deduparr.push_back(str1[i]);
		}
	}
	for (int i=0; i< str2.length(); i++) {
		if (visited.count(str2[i]) == 0) {
			visited.insert(str2[i]);
			deduparr.push_back(str2[i]);
		}
	}
	for (int i=0; i< result.length(); i++) {
		if (visited.count(result[i]) == 0) {
			visited.insert(result[i]);
			deduparr.push_back(result[i]);
		}
	}
	return deduparr;
}

int pow(int base, int exponent) {
	if (exponent == 0) {
		return 1;
	}
	int res = pow(base, exponent/2);
	if (exponent % 2 == 0) {
		return res * res;
	}
	else {
		return base * res * res;
	}
}


bool PuzzleSolveCheck(string& str1, string& str2, string& result, unordered_map<char, int>& dict) {
	int num1 = 0, num2 = 0, num_result = 0;
	//print_map(dict);
	for (int i = 0; i < str1.length(); i++) {
		// pos = str1.length()-1-i
		// exp = i
		int n = dict[str1[str1.length()-1-i]];
		num1 += pow(10, i) * n;
	}
	for (int i = 0; i < str2.length(); i++) {
		// pos = str1.length()-1-i
		// exp = i
		int n = dict[str2[str2.length()-1-i]];
		num2 += pow(10, i) * n;
	}
	for (int i = 0; i < result.length(); i++) {
		// pos = str1.length()-1-i
		// exp = i
		int n = dict[result[result.length()-1-i]];
		num_result += pow(10, i) * n;
	}
	//cout << num1 << " - " << num2 << " - " << num1+num2 << " - " << num_result << endl;
	return (num1+num2 == num_result);
}

bool CryptoSolveUtil(string& str1, string& str2, string& result, 
					 unordered_set<int>& assigned, unordered_map<char, int>& dict, 
					 vector<char>& deduparr, int idx) {
	if (idx == deduparr.size()) {
		if (PuzzleSolveCheck(str1, str2, result, dict)) {
			print_map(dict);
			return true;
		}
		else {
			return false;
		}
	}
	
	for (int i=0; i<=9; i++) {
		if (assigned.count(i) != 0) continue;
		assigned.insert(i);
		dict[deduparr[idx]] = i;
		if (CryptoSolveUtil(str1, str2, result, assigned, dict, deduparr, idx+1)) return true;
		assigned.erase(i);
		dict.erase(deduparr[idx]);
	}
	return false;
}

void CryptoSolve(string& str1, string& str2, string& result) {
	// there will be a set to track all numbers assigned already
	// there will be a map to save all character assignments
	// there need to be a list of all unique characters that need assigning - array or list is preferred to iterate with index
	vector<char> deduparr = getDistinctChars(str1, str2, result);
	unordered_set<int> assigned;
	unordered_map<char, int> dict;
	
	if (! CryptoSolveUtil(str1, str2, result, assigned, dict, deduparr, 0)) {
		cout << "No solution exists" << endl;
	}
}


/* Driver Program to test above functions */
int main() {
	string str1, str2, result;
	cin >> str1;
	cin >> str2;
	cin >> result;
	CryptoSolve(str1,str2,result);
    return 0;
}
