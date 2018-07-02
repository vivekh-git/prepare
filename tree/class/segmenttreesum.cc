#include <bits/stdc++.h>

using namespace std;

void print_arr(vector<int>& arr) {
	cout << "printing:" << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void updateValUtil(vector<int>& stree, int ss, int se, int i, int diff, int si) {
	if (i < ss || i > se) {
		//cout << "invalid index in updateValUtil" << endl;
		return;
	}
	stree[si] = stree[si] + diff;
	int mid = ss + (se-ss)/2;
	if (se != ss) {
		updateValUtil(stree, ss, mid, i, diff, 2*si+1);
		updateValUtil(stree, mid+1, se, i, diff, 2*si+2);
	}
}

void updateVal(vector<int>& stree, vector<int>& arr, int index, int newval) {
	if (index < 0 || index > arr.size()-1) {
		cout << "invalid index in updateVal" << endl;
		return;
	}
	int diff = newval - arr[index];
	arr[index] = newval;
	updateValUtil(stree, 0, arr.size()-1, index, diff, 0);
}


int getSumUtil(vector<int>& stree, int ss, int se, int qs, int qe, int si) {
	if (qs <= ss && qe >= se) {
		return stree[si];
	}
	if (qe < ss || qs > se) {
		//cout << "invalid range in getSumUtil" << endl;
		return 0;
	}
	int mid = ss + (se-ss)/2;
	return getSumUtil(stree, ss, mid, qs, qe, 2*si+1) + getSumUtil(stree, mid+1, se, qs, qe, 2*si+2);
}


int getSum(vector<int>& stree, int leafs, int qs, int qe) {
	if (qs < 0 || qe > leafs-1 || qs > qe) {
		cout << "invalid range for getSum" << endl;
		return -1;
	}
	return getSumUtil(stree, 0, leafs-1, qs, qe, 0);
}

int constructSTUtil(vector<int>& arr, int ss, int se, vector<int>& stree, int si) {
	if (ss == se) {
		stree[si] = arr[ss];
		return stree[si];
	}
	else {
		int mid = ss + (se - ss)/2;
		stree[si] = constructSTUtil(arr, ss, mid, stree, 2*si+1) + constructSTUtil(arr, mid+1, se, stree, 2*si+2);
		return stree[si];
	}
}

void constructST(vector<int>& arr, vector<int>& stree) {
	int leafs = arr.size();
	int height = (int)(ceil(log2(leafs)));
	int n = 2 * pow(2, height) + 1;
	stree.resize(n);
	constructSTUtil(arr, 0, leafs-1, stree, 0);
}

int main() {
	vector<int> arr = {1, 3, 5, 7, 9, 11};
	vector<int> stree;
	constructST(arr, stree);
	print_arr(arr);
	print_arr(stree);
	
	int sum = getSum(stree, arr.size(), 1, 3);
	cout << "Sum from 1 to 3 = " << sum << endl;
	
	updateVal(stree, arr, 1, 4);
	int sum2 = getSum(stree, arr.size(), 1, 3);
	cout << "New sum from 1 to 3 = " << sum2 << endl;
	return 0;
}