#include <bits/stdc++.h>

using namespace std;

void print_arr(vector<vector<int>> table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 * Complete the function below.
 * 1 matrix - A1, multicost = 0
 * 2 matrix - A1, A2, multicost = p0 * p1 * p2
 * n matrix - can be parenthized in n-1 ways
 * 3 matrix - A1, A2, A3  ->  A1(A2A3), (A1A2)A3
 * 4 matrix - A, B, C, D -> A(BCD), (AB)(CD), (ABC)D
 * p -      0  1   2   3   4
 *          10 20  30  10  5
 * Split paren - 1, 2, 3  - k => 1 to end-1
 */
// minMultiplicationCost_rec(arr, 1, arr.size()-1)
int minMultiplicationCost_rec(vector<int>& arr, int start, int end) {
    if (end <= start)
        return 0;
    else if (end == start+1)
        return arr[start-1]*arr[start]*arr[end];
    else {
        int min = INT_MAX;
        for (int k = start; k < end; k++) {
            int sub = minMultiplicationCost_rec(arr, start, k) + 
                        minMultiplicationCost_rec(arr, k+1, end) + 
                        arr[start-1]*arr[k]*arr[end];
            if (sub < min)
                min = sub;
        }
        return min;
    }
}

void printParenthesis(char& name, vector<vector<int>>& result, int start, int end) {
	if (result[start][end] == 0) {
		cout << name;
		name++;
		return;
	}
	int k = result[start][end];
	cout << "(";
	printParenthesis(name, result, start, k);
	printParenthesis(name, result, k+1, end);
	cout << ")";
}

int minMultiplicationCost(vector<int>& arr) {
    int M = arr.size();
    vector<vector<int>> table(M, vector<int>(M, 0));
    vector<vector<int>> result(M, vector<int>(M, 0));
    for (int i = arr.size()-1; i >= 1; i--) {
        for (int j = 1; j < arr.size(); j++) {
            if (j > i) {
                table[i][j] = INT_MAX;
                for (int k=i; k < j; k++) {
                    int sub = table[i][k] + table[k+1][j] + arr[i-1]* arr[k] * arr[j];
                    if (sub < table[i][j] ) {
                        table[i][j] = sub;
                        result[i][j] = k;
                    }
                }
            }
        }
    }
	cout << "table" << endl;
    print_arr(table);
	cout << "result" << endl;
    print_arr(result);
	char name = 'A';
	cout << "expression:" << endl;
	printParenthesis(name, result, 1, result.size()-1);
	cout << endl;
    return table[1][arr.size()-1];
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _mtxSizes_size = 0;
    cin >> _mtxSizes_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _mtxSizes;
    int _mtxSizes_item;
    for(int _mtxSizes_i=0; _mtxSizes_i<_mtxSizes_size; _mtxSizes_i++) {
        cin >> _mtxSizes_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _mtxSizes.push_back(_mtxSizes_item);
    }
    
    res = minMultiplicationCost(_mtxSizes);
    cout << res << endl;
    
    //fout.close();
    return 0;
}
