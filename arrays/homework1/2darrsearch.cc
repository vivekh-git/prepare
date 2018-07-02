#include <bits/stdc++.h>
using namespace std;

string isPresent(vector<vector<int>> arr, int x) {
    int M = arr.size();
    int N = arr.empty() ? 0 : arr[0].size();
    int i = 0; int j = N-1;
    while (i < M and j >= 0) {
        if (x == arr[i][j])
            return "present";
        else if (x < arr[i][j]) {
            j--;
        }
        else { // greater
            i++;
        }
    }
    return "not present";
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
	/*
    int arr_rows;
    cin >> arr_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int arr_columns;
    cin >> arr_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(arr_rows);
    for (int arr_row_itr = 0; arr_row_itr < arr_rows; arr_row_itr++) {
        arr[arr_row_itr].resize(arr_columns);

        for (int arr_column_itr = 0; arr_column_itr < arr_columns; arr_column_itr++) {
            cin >> arr[arr_row_itr][arr_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i){
        int x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string res = isPresent(arr, x);

        cout << res << "\n";
    }
*/
	vector<vector<int>> arr;
	int x = 0;
	string res = isPresent(arr, x);
	cout << res << "\n";
    //fout.close();

    return 0;
}