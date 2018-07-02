#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
#include <algorithm>

vector <string> printTriplets(vector<int>& arr) {
	vector<string> output;
	sort(arr.begin(), arr.end());
	for (int i = 0; i< arr.size(); i++) {
		int pivot = arr[i];
		int sum = 0 - pivot;
		int low = i+1;
		int high = arr.size() - 1;
		bool match = false;
		while (low < high) {
			if (arr[low] + arr[high] > sum) {
				high--;
			}
			else if (arr[low] + arr[high] < sum) {
				low++;
			}
			else {
				// triplet found
				string buffer = to_string(pivot) + "," + to_string(arr[low]) + "," + to_string(arr[high]);
				output.push_back(buffer);
				match = true;
				low++; high--;
			}
		}
		if (! match) break;
	}
    return output;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector <string> res;
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

	cout << "calling printTriplets" << endl;
    res = printTriplets(intArr);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }

    //fout.close();
    return 0;
}