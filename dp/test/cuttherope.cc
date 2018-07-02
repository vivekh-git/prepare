#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the max_product_from_cut_pieces function below.
 *  like sum of partition
Recurrence relation
f(i, sum) -> if (i == n || sum == n)
			    return
			 else
				f (i+1, sum) || f(i+1, sum-i)

bool isPartitionSubsets3(vector<int>& inp, int i, int k, vector<int>& arr, vector<vector<int>>& arr_arr) {
	if (k == 0) {
		arr_arr.push_back(arr);
		return true;
	}
	else if (i == inp.size()) {
		return false;
	}
	else {
		isPartitionSubsets3(inp, i+1, k, arr, arr_arr);
		arr.push_back(inp[i]);
		isPartitionSubsets3(inp, i+1, k-inp[i], arr, arr_arr);
		arr.pop_back();
		return false;
	}
}
	    


 */
void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool _max_product(int i, int sum, long product, long& max, vector<int>& arr, int n) {
	cout << i << "-" << sum << "-" << product << "-" << max << "-" << n << endl;
 	if (sum == 0) {
		if (product > max) {
			max = product;
		}
		print_arr(arr);
		return true;
	}
	else if (i == n)
		return false;
 	else {
		_max_product(i+1, sum, product, max, arr, n);
		arr.push_back(i);
		_max_product(i+1, sum-i, product*i, max, arr, n);
		arr.pop_back();
		return false;
	}
}



long max_product_from_cut_pieces(int n) {
	if (n == 0 || n == 1) return 1;
	long maxval = 0;
	for (int i = 1; i < n; i++) {
		long m = max_product_from_cut_pieces(n-i)*i;
		if (m > maxval)
			maxval = m;
		m = i*(n-i);
		if (m > maxval) maxval = m;
	}
	return maxval;
}


long max_product_from_cut_pieces2(int n) {
	vector<long> table(n+1);
	table[0] = table[1] = 1;
	for (int i = 1; i <= n; i++) {
		long maxval = 0;
		for (int j = 1; j <= i/2; j++) {
			long m = table[i-j]*j;
			long n = j*(i-j);
			if (m > maxval)
				maxval = m;
			if (n > maxval)
				maxval = n;
		}
		table[i] = maxval;
	}
	return table[n];
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long res = max_product_from_cut_pieces(n);

    cout << res << "\n";

    //fout.close();

    return 0;
}