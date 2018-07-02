#include <bits/stdc++.h>

using namespace std;

int binaryStrCount(int n) {
	if (n < 1)
		return 0;
	int C0 = 1;
	int C1 = 1; int tmp = C1;
	for (int i = 1; i < n; i++) {
		tmp = C1;
		C1 = C0;
		C0 = C0 + tmp;
	}
	return C0 + C1;
}


int binaryStrCount2(int n) {
	if (n < 1)
		return 0;
	vector<int> count_str_ending_with_zero(n+1, 0);
	vector<int> count_str_ending_with_one(n+1, 0);
	count_str_ending_with_zero[1] = 1;
	count_str_ending_with_one[1] = 1;
	for (int i = 2; i <= n; i++) {
		count_str_ending_with_zero[i] = count_str_ending_with_zero[i-1] + count_str_ending_with_one[i-1];
		count_str_ending_with_one[i] = count_str_ending_with_zero[i-1];
	}
	return count_str_ending_with_zero[n] + count_str_ending_with_one[n];
}

vector<string> binaryStr(int n) {
	if (n < 1)
		return {};
	vector<vector<string>> count_str_ending_with_zero(n+1);
	vector<vector<string>> count_str_ending_with_one(n+1);
	count_str_ending_with_zero[1].push_back("0");
	count_str_ending_with_one[1].push_back("1");
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < count_str_ending_with_zero[i-1].size(); j++) 
			count_str_ending_with_zero[i].push_back(count_str_ending_with_zero[i-1][j] + "0");
		for (int j = 0; j < count_str_ending_with_one[i-1].size(); j++) 
			count_str_ending_with_zero[i].push_back(count_str_ending_with_one[i-1][j] + "0");
		for (int j = 0; j < count_str_ending_with_zero[i-1].size(); j++) 
			count_str_ending_with_one[i].push_back(count_str_ending_with_zero[i-1][j] + "1");
	}
	count_str_ending_with_zero[n].insert(count_str_ending_with_zero[n].end(), count_str_ending_with_one[n].begin(), count_str_ending_with_one[n].end());
	return count_str_ending_with_zero[n];
}

vector<string> binaryStrOpt(int n) {
	if (n < 1)
		return {};
	vector<string> str_ending_with_zero;
	vector<string> str_ending_with_one;
	str_ending_with_zero.push_back("0");
	str_ending_with_one.push_back("1");
	
	for (int i = 2; i <= n; i++) {
		vector<string> tmp;
		for (int j = 0; j < str_ending_with_zero.size(); j++) 
			tmp.push_back(str_ending_with_zero[j] + "0");
		for (int j = 0; j < str_ending_with_one.size(); j++) 
			tmp.push_back(str_ending_with_one[j] + "0");
		str_ending_with_one.clear();
		for (int j = 0; j < str_ending_with_zero.size(); j++) 
			str_ending_with_one.push_back(str_ending_with_zero[j] + "1");
		str_ending_with_zero = tmp;
	}
	str_ending_with_zero.insert(str_ending_with_zero.end(), str_ending_with_one.begin(), str_ending_with_one.end());
	return str_ending_with_zero;
}



int main() {
	int n;
	cin >> n;
	
	int res = binaryStrCount(n);
	cout << "res - " << res << endl;
	
	int res2 = binaryStrCount2(n);
	cout << "res2 - " << res2 << endl;
	
	vector<string> resarr = binaryStr(n);
	cout << "resarr - " << resarr.size() << endl;
	for (int i = 0; i < resarr.size(); i++)
		cout << resarr[i] << endl;
	
	vector<string> resarr2 = binaryStrOpt(n);
	cout << "resarr2 - " << resarr2.size() << endl;
	for (int i = 0; i < resarr2.size(); i++)
		cout << resarr2[i] << endl;
	
	return 0;
}