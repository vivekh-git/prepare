#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the getMergedIntervals function below.
 */
class mycompare {
public:
	bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
		// ascending sort needs max heap which need less than comparator
		return (!lhs.empty() && !rhs.empty() && lhs[0] < rhs[0]);
	}
};
vector<vector<int>> getMergedIntervals2(vector<vector<int>> inputArray) {
	sort(inputArray.begin(), inputArray.end(), mycompare());
	vector<vector<int>> result;
	stack<pair<int,int>> st;
	for (int row = 0; row < inputArray.size(); row++) {
		if (st.empty() || inputArray[row][0] > st.top().second) {
			// not overlapping - push
			st.push({inputArray[row][0], inputArray[row][1]});
		}
		else {
			// pop, merge and push - overlapping
			pair<int, int> snode = st.top(); 
			st.pop();
			// new element can be enclosed within stack - so use max of stack top end and new element end.
			st.push({snode.first, max(inputArray[row][1], snode.second)}); 
		}
	}
	while (!st.empty()) {
		vector<int> arr = {st.top().first, st.top().second};
		result.push_back(arr);
		st.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

class mycompare2 {
public:
	bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
		// ascending sort needs max heap which need less than comparator
		return (!lhs.empty() && !rhs.empty() && lhs[0] > rhs[0]);
	}
};
vector<vector<int>> getMergedIntervals(vector<vector<int>> inputArray) {
	sort(inputArray.begin(), inputArray.end(), mycompare2()); // descending sort
	vector<vector<int>> result;
	
	int index = 0;
	for (int row = 0; row < inputArray.size(); row++) {
		if (index != 0 && inputArray[row][1] >= inputArray[index-1][0]) {
			// overlapping - merge
			while (index != 0 && inputArray[row][1] >= inputArray[index-1][0]) {
				inputArray[index-1][1] = max(inputArray[index-1][1], inputArray[row][1]);
				inputArray[index-1][0] = min(inputArray[index-1][0], inputArray[row][0]);
				index--;
			}
		}
		else {
			inputArray[index][0] = inputArray[row][0];
			inputArray[index][1] = inputArray[row][1];
		}
		index++;
	}
	for (int i = 0; i < index; i++) {
		result.push_back({inputArray[i][0], inputArray[i][1]});
	}

	return result;
}
/*
1 3
2 4
5 7
6 8
*/

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
	/*
    int inputArray_rows;
    cin >> inputArray_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int inputArray_columns;
    cin >> inputArray_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> inputArray(inputArray_rows);
    for (int inputArray_row_itr = 0; inputArray_row_itr < inputArray_rows; inputArray_row_itr++) {
        inputArray[inputArray_row_itr].resize(inputArray_columns);

        for (int inputArray_column_itr = 0; inputArray_column_itr < inputArray_columns; inputArray_column_itr++) {
            cin >> inputArray[inputArray_row_itr][inputArray_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	*/
	vector<vector<int>> inputArray = {{1,3}, {5,7}, {2,4}, {6,8}};
    vector<vector<int>> res = getMergedIntervals(inputArray);

    for (int res_row_itr = 0; res_row_itr < res.size(); res_row_itr++) {
        for (int res_column_itr = 0; res_column_itr < res[res_row_itr].size(); res_column_itr++) {
            cout << res[res_row_itr][res_column_itr];

            if (res_column_itr != res[res_row_itr].size() - 1) {
                cout << " ";
            }
        }

        if (res_row_itr != res.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}