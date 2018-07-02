#include <bits/stdc++.h>
using namespace std;

void sort_arr(vector<int>& arr) {
	stack<int> st, tmp;
	for (int i = 0; i < arr.size(); i++) {
		st.push(arr[i]);
	}
	
	// pop element one by one
	while (!st.empty()) {
		int ele = st.top(); st.pop();
		while (!tmp.empty() && tmp.top() > ele) {
			st.push(tmp.top()); tmp.pop();
		}
		tmp.push(ele);
	}
	
	for (int i = arr.size()-1; i >= 0; i--) {
		arr[i] = tmp.top(); tmp.pop();
	}
}

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

void xor_arr(vector<int>& arr) {
	int xorprod = 0;
	for (int i = 0; i < arr.size(); i++) {
		xorprod = xorprod ^ arr[i];
	}
	// now xor element with xorprod to remove self
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = arr[i] ^ xorprod;
	}
}


int main() {
	vector<int> arr = {5, 8, 1, 9, 3, 6, 9, 8, 3, 3, 3, 4};
	print_arr(arr);
	sort_arr(arr);
	print_arr(arr);
	
	vector<int> arr2 = {2,1,5,9};
	print_arr(arr2);
	xor_arr(arr2);
	print_arr(arr2);
	
	return 0;
}