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

using namespace std;

bool valid(string combo) {
	if (combo.length() == 0)
		return false;
	else {
		stack<char> st;
		for (int i = 0; i < combo.length(); i++) {
			if (combo[i] == '(') {
				st.push(combo[i]);
			}
			else {
				// )
				if (st.empty()) return false;
				st.pop();
			}
		}
		return st.empty();
	}
}


void permute(string combo, string population, unordered_map<string, int>& hash) {
	if (population.length() == 0) {
		if (valid(combo)) {
			if (hash.count(combo) == 0) {
				cout << combo << " ";
				hash[combo] = 1;
			}
		}
	}
    else {
		for (int i = 0; i < population.length(); i++) {
			string next = combo + population[i];
			// check if next is valid and if not move to next one
			string remaining = population.substr(0,i) + population.substr(i+1);
			permute(next, remaining, hash);
		}
    }
}


/*
 * Complete the function below.
 */
void Brackets(string str) {
	unordered_map<string, int> hash;
	permute ("", str, hash);

}


void WellFormedBrackets(int n = 10) {
	for (int i = 1; i <= n; i++) {
		string s = "";
		for (int j = 0; j < i; j++) {
			s += "()";
		}
		//cout << "s - " << s << endl;
		Brackets(s);
		cout << endl;
	}
}


int main() {
	int n = 3;
    WellFormedBrackets(n);
	
    return 0;
}
