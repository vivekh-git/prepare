#include <bits/stdc++.h>
using namespace std;

void print_arr(int *bracket, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << *((bracket+i*n)+j) << " ";
		}
		cout << endl;
	}
}
void print_arr(vector<vector<int>>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void printParenthesis(int i, int j, vector<vector<int>>& result, char& name) {
	if (i == j) {
		cout << name;
		name++;
	}
	else {
		int k = result[i][j];
		cout << "(";
		printParenthesis(i, k, result, name);
		printParenthesis(k+1, j, result, name);
		cout << ")";
	}
}

int minValue(int start, int end, vector<int>& arr) {
	cout << "start - " << start << ", end - " << end << endl;
    if (end < start+1)
        return 0;
    else if (end == start+1)
        return arr[start-1]*arr[start]*arr[end];
    else {
        int min = INT_MAX;
        for (int k=start; k < end; k++) {
			cout << "k = " << k << endl;
            int sub = minValue(start, k, arr) + minValue(k+1, end, arr) + arr[start-1]*arr[k]*arr[end];
            if (sub < min)
                min = sub;
        }
		cout << "min = " << min << endl;
        return min;
    }
}
	
int minValue_DP(vector<int>& arr) {
	vector<vector<int>> table(arr.size(), vector<int>(arr.size(), 0));
	vector<vector<int>> result(arr.size(), vector<int>(arr.size(), 0));
	for (int i = arr.size()-1; i >= 1; i--) {
		for (int j = 0; j < arr.size(); j++) {
			if (j < i+1) {
				table[i][j] = 0;
			}
			else {
				table[i][j] = INT_MAX;
				for (int k = i; k < j; k++) {
					int cost = table[i][k] + table[k+1][j] + arr[i-1]*arr[k]*arr[j];
					if (cost < table[i][j]) {
						table[i][j] = cost;
						result[i][j] = k;
					}
				}
			}
		}
	}
	cout << "table:" << endl;
	print_arr(table);
	cout << "result:" << endl;
	print_arr(result);
	
	char name = 'A';	
	printParenthesis(1, result.size()-1, result, name);
	cout << endl;
	return table[1][arr.size()-1];
}

int minMultiplicationCost(vector<int>& arr) {
    //return minValue(1, arr.size()-1, arr);
	return minValue_DP(arr);
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
