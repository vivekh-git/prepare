#include <bits/stdc++.h>
using namespace std;
/* Recurrence Relation
// n -> number of digits, d - particular digit, counter - sum of possible n digit combinations
f(n, d, &counter) -> if (n == 0) {
						counter++;
						return;
					}
				    neighbors = getneighbors(d);
					for (child in neighbors) {
						f(n-1, child, counter);
					}
					return;
*/
bool count(int n, int d, int& counter, unordered_map<int,list<int>>& dict) {
	if (n == 0) {
		counter++;
		return true;
	}
	list<int> neighbors = dict[d];
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		count(n-1, *it, counter, dict);
	}
	return false;
}

long count2(int n, int d, unordered_map<int,list<int>>& dict) {
	if (n == 1) {
		return 1;
	}
	list<int> neighbors = dict[d];
	long counter = 0;
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		counter += count2(n-1, *it, dict);
	}
	return counter;
}

/* Editorial -

table[numdigit][startingfrom] = table[numdigit-1][neighbor1_of_startingfrom] +
	 							table[numdigit-1][neighbor2_of_startingfrom] + ....
table[0][*] = 0
table[1][*] = 1
*/
long count_DP(int n, int d, unordered_map<int,list<int>>& dict) {
	vector<vector<long>> table(n+1, vector<long>(10, 0));
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0) {
				table[i][j] = 0;
			}
			else if (i == 1) {
				table[i][j] = 1;
			}
			else {
				list<int> neighbors = dict[j];
				for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
					table[i][j] += table[i-1][*it];
				}
			}
		}
	}
	return table[n][d];
}

int main() {
	int numDigits;
	cin >> numDigits;
	unordered_map<int,list<int>> dict = {{0, {4,6}},
										 {1, {6,8}},
										 {2, {7,9}},
										 {3, {4,8}},
										 {4, {3,9,0}},
										 {5, {}},
										 {6, {1,7,0}},
										 {7, {2,6}},
										 {8, {1,3}},
										 {9, {2,4}}
										};
   int startDigit;
   cin >> startDigit;
   
   long counter = count_DP(numDigits, startDigit, dict);
   cout << "counter = " << counter << endl;
   return 0;	
}