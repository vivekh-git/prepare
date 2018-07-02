#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */

void swap(vector<int>& arr, int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void groupEvenOdd(vector<int>& arr, int st, int end) {
	int low = st + 1;
	int high = st + 1;
	while (high <= end) {
		if (arr[high] % 2 == 0) {
			swap(arr, low, high);
			low++;
		}
		high++;
	}
	swap(arr, st, low-1);
}


vector <int> groupNumbers(vector <int> intArr) {
	vector<int> output = intArr;
	groupEvenOdd(output, 0, output.size()-1);
	return output;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector <int> res;
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

    res = groupNumbers(intArr);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }

    //fout.close();
    return 0;
}