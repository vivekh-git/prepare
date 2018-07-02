#include <bits/stdc++.h>
using namespace std;

vector<int> compute_arr(int n) {
	vector<int> arr;
	while (n > 0) {
		arr.push_back(n%10);
		n = n/10;
	}
	reverse(arr.begin(), arr.end());
	return arr;
}

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

long compute_num(vector<int>& arr) {
	long result = 0;
	for (int i = 0; i < arr.size(); i++) {
		result = result*10;
		result = result + arr[i];
	}
	return result;
}

long next_higher(int n) {
	if (n < 11) return -1;
	vector<int> arr = compute_arr(n);
	int i, j;
	for (i = arr.size()-2; i >= 0; i--) 
		if (arr[i] < arr[i+1]) break;
	if (i == -1) return -1;
	sort(arr.begin()+i+1, arr.end());
	for (j = i+1; j < arr.size(); j++)
		if (arr[j] > arr[i]) break;
	swap(arr, i, j);
	print_arr(arr);
	return compute_num(arr);
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    long res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = next_higher(n);
    cout << res << endl;;

    //fout.close();
    return 0;
}