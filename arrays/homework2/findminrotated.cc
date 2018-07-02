#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) 
		cout << arr[i] << " ";
}

int search(vector<int>& arr, int start, int end) {
	if (end < start)
		return INT_MAX;
	
	int mid = start + (end-start)/2;
	if (arr[mid] <= arr[start]) {
		return min(arr[mid], search(arr, start, mid-1));
	}
	else {
		return min(arr[start], search(arr, mid+1, end));
	}
}


int findMinimum(vector<int>& arr) {
	return search(arr, 0, arr.size()-1);
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    int intArr_size = 0;
    cin >> intArr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> intArr;
    for(int i = 0; i < intArr_size; i++) {
        int intArr_item;
        cin >> intArr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        intArr.push_back(intArr_item);
    }

    res = printCountOfBitsSet(intArr);
    cout << res << endl;

    //fout.close();
    return 0;
}