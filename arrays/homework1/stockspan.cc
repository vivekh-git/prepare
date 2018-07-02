#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

vector<int> computeSpan(vector<int>& price) {
	vector<int> span(price.size());
	stack<int> st;
	span[0] = 1;
	st.push(0);
	for (int i = 1; i < price.size(); i++) {
		while (!st.empty() && price[st.top()] <= price[i]) {
			st.pop();
		}
		span[i] = st.empty() ? i+1 : i - st.top();
		st.push(i);
	}
	return span;
}

int main() {
	vector<int> price = {7, 5, 2, 3, 2, 4, 8};
	print_arr(price);
	vector<int> span = computeSpan(price);
	print_arr(span);
	return 0;
}