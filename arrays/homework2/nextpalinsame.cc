#include <bits/stdc++.h>
using namespace std;

vector<int> compute_arr(int n) {
	vector<int> arr;
	while (n > 0) {
		arr.push_back(n%10);
		n = n /10;
	}
	reverse(arr.begin(), arr.end());
	return arr;
}

long compute_number(vector<int>& arr) {
	long result = 0;
	for (int i = 0; i < arr.size(); i++) {
		result = result * 10;
		result = result + arr[i];
	}
	return result;
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

long next_palindrome_with_same_digits(int n) {
	if (n < 1000) {
		cout << "input with 3 or less digits" << endl;
		return -1; // cannot generate for 3 digit palindrome
	}
	vector<int> arr = compute_arr(n);
	int sz = arr.size();
	int left, right, center;
	if (sz % 2 == 0) { // even
		left = center = sz/2-1;
		right = sz/2;
	}
	else { // odd
		left = sz/2-1; center = sz/2; right = sz/2+1;
	}
	int i, j;
	for (i = left-1; i >= 0; i--) 
		if (arr[i] < arr[i+1])
			break;
	if (i < 0) {
		cout << "input has highest palindrome - next higher with same digits not possible" << endl;
		return -1;  // next higher palindrome not possible
	}
	sort(arr.begin()+i+1, arr.begin()+left+1);
	for (j = i+1; j <= left; j++)
		if (arr[j] > arr[i])
			break;
	swap(arr, j, i);
	// mirror the first half to second half
	while (right < arr.size() && left >= 0) {
		arr[right] = arr[left];
		right++; left--;
	}
	return compute_number(arr);
}




int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    long res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = next_palindrome_with_same_digits(n);
    cout << res << endl;;

    //fout.close();
    return 0;
}