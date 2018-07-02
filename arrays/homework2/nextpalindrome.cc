#include <bits/stdc++.h>

using namespace std;

void print_arr(deque<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}


vector<int> gen_arr(int n) {
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

bool isAll9palin(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != 9)
			return false;
	}
	return true;
}

/*
 * Complete the function below.
		arr.assign(n, 0);
		arr[0] = 1; arr[arr.size()-1] = 1;
		return compute_number(arr);
 */
long next_palindrome(int n) {
	if (n < 9) return n+1;
	vector<int> arr = gen_arr(n);
	// rule 1 -- all 9 palindrome
	if (isAll9palin(arr)) {
		int n = arr.size() + 1;
		vector<int> result(arr.size()+1, 0);
		result[0] = 1; result[result.size()-1] = 1;
		return compute_number(result);
	}
	// identify left, right and center
	int sz = arr.size();
	int left = sz/2 - 1; int right; int center;
	if (sz % 2 == 0) { // even
		center = sz/2 - 1;
		right = sz/2;
	}
	else { // odd
		center = sz/2;
		right = sz/2 + 1;
	}
	// skip same digits
	while (left >= 0 && right < sz && arr[left] == arr[right]) {
		left--; right++;
	}
	
	// step2 - if palindrome - increase center, 12321 - 12421,  1221 - 1331
	// carry MSB - 12921 - 13031, 1999 9991 - 2000 0002
	if (left == -1 && sz % 2 == 0) {  // even palindrome
		left = sz/2-1; right = sz/2;
		while (arr[left] == 9) {
			arr[left] = 0; arr[right] = 0;
			left--; right++;
		}
		arr[left]++; arr[right]++;
		return compute_number(arr);
	}
	else if (left == -1 && sz % 2 != 0) { // odd palindrome
		left = sz/2-1; center = sz/2; right = sz/2+1;
		if (arr[center] != 9) {
			arr[center]++;
		}
		else {
			arr[center] = 0;
			while (arr[left] == 9) {
				arr[left] = 0; arr[right] = 0;
				left--; right++;
			}
			arr[left]++; arr[right]++;
		}
		return compute_number(arr);
	}	
	else if (arr[left] > arr[right]) { // step 3 - not palindrome - first non matching left > right
		// copy left to right
		while (left >= 0) {
			arr[right] = arr[left];
			left--; right++;
		}
		return compute_number(arr);
	}
	else { // not palindrome - first non matching left < right
		//cout << "left < right" << endl;
		// goto center and incease the center and carry MSB and copy left to right
		if (sz % 2 == 0) {
			left = sz/2-1; right = sz/2;
			while (arr[left] == 9) {
				arr[left] = arr[right] = 0;
				left--; right++;
			}
			arr[left]++;
		}
		else {
			left = sz/2-1; right = sz/2+1;
			center = sz/2; 
			if (arr[center] != 9) {
				arr[center]++;
			}
			else {
				arr[center] = 0;
				while (arr[left] == 9) {
					arr[left] = arr[right] = 0;
					left--; right++;
				}
				arr[left]++;
			}
		}
		while (left >= 0) {
			arr[right] = arr[left];
			left--; right++;
		}
		return compute_number(arr);
	}
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    long res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = next_palindrome(n);
    cout << res << endl;;

    //fout.close();
    return 0;
}