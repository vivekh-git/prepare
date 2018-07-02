#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<string> sumZero(vector<int> arr) {
    unordered_map<int, int> dict; 
    vector<string> output;
	if (arr.size() == 1 && arr[0] == 0) {
		output.push_back(to_string(0));
		return output;
	}
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (dict.count(sum) == 0) {
            dict[sum] = i;
        }
        else {
            // sum seen before.
            int j = dict[sum];  string res;
            for (int k = j+1; k <= i; k++) {
				if (k == j+1) { res += to_string(arr[k]); }
				else { res += "," + to_string(arr[k]); }
                //output.push_back(arr[k]);
            }
            
            output.push_back(res);
            if (arr[j] == 0) {
                output.push_back(to_string(0) + ',' + res);
                output.push_back(to_string(0));
            }
        }
    }
    return output;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    vector<string> res = sumZero(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];

        if (i != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}