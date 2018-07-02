#include <bits/stdc++.h>
using namespace std;
/* Recurrence Relation
f(i, k) -> max value for objects from i to n whose weight do not exceed k
f(i, k) ->  if (k < 0)
				return INT_MIN;
			else if (k == 0)
				return 0;
			else if (i == n)
				return 0;
			else
				return max(f(i+1, k), v[i]+f(i+1, k-w[i]));
*/
int maxValue(int i, int k, vector<int>& values, vector<int>& weights) {
	if (k < 0)
		return INT_MIN;
	else if (k == 0)
		return 0;
	else if (i == values.size())
		return 0;
	else {
		return max(
					maxValue(i+1, k, values, weights), 
		    		values[i]+maxValue(i+1, k-weights[i], values, weights)
					);
	}
}

int maxValue_DP(int W, vector<int>& values, vector<int>& weights) {
	vector<vector<int>> table(values.size()+1, vector<int>(W+1, 0));
	for (int i = values.size(); i >= 0; i--) {
		for (int k = 0; k < W+1; k++) {
			if (k == 0)
				table[i][k] = 0;
			else if (i == values.size())
				table[i][k] = 0;
			else if (k >= weights[i] && values[i]+table[i+1][k-weights[i]] > table[i+1][k])
				table[i][k] = values[i]+table[i+1][k-weights[i]];
			else 
				table[i][k] = table[i+1][k];
		}
	}
	return table[0][W];
}

int main() {
	vector<int> values = {60,100,120};
	vector<int> weights = {10,20,30};
	int W = 50;
	int m1 = maxValue(0, W, values, weights);
	cout << "m1 = " << m1 << endl;
	int m2 = maxValue_DP(W, values, weights);
	cout << "m2 = " << m2 << endl;
	return 0;
}