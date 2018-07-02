#include <bits/stdc++.h>

using namespace std;

void print_arr_arr(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void print_arr(vector<int>& table) {
	cout << "print_arr" << endl;
	for (int i = 0; i < table.size(); i++) {
		cout << table[i] << " ";
	}
	cout << endl << endl;
}

/* line = aaa bb cc ddddd, line width = 6
strarr, size() = 4 (4 words)
aaa - 3
bb - 2
cc - 2
ddddd - 5
extras - 5x5 array, [ij] - extra space needed to fit words[i] to word[j] inclusive in linewidth
3 0 -3 -9     
0 4  1 -5     
0 0  4 -2     
0 0  0  1
linecost
27  0  I I
0  64  1 I
0   0 64 I
0   0  0 0
*/
/* Editorial
extras[i][j] is the space needed to fit words from i to j within linewidth
linecost[i][j] - cube of extraspace. if extraspace is < 0, make it INT_MAX as negative extras space 
				should not be allowed
				if j == n, it means last line - so ingore extra space needed.
				if (j == n && extraspace >= 0) linecost is 0

Cost function
C (Min Cube) -> Min Cube ( lc(0,1) + lc(2,2) + lc(3,3) or
				           lc(0,0) + lc(1,2) + lc(3,3) )
C(i, j) -> Cost of fitting linewidth for words between i and j inclusive
C(0, 0) -> Cost of fitting word 0
C(0, 1) -> Cost of fitting words from 0 to 1
C(0, 2) -> Cost of fitting words from 0 to 2
C(0, 3) -> Cost of fitting words from 0 to 3
 

C(3) - minimum cost of fitting word 0 to word 3
     - C(0) + lc[0][0],
       C(1) + lc[0][1],
       C(2) + lc[0][2],
       C[3] + lc[0][3]
*/
void printline(vector<string>& strarr, int pos1, int pos2) {
	for (int i = pos1; i <= pos2; i++)
		cout << strarr[i] << " ";
	cout << endl;
}

void printSolution(vector<string>& strarr, vector<int>& arr, int pos) {
	if (arr[pos] == 0) { // base case
		printline(strarr, arr[pos], pos);
		return;
	}
	//recurse
	printSolution(strarr, arr, arr[pos]-1);
	printline(strarr, arr[pos], pos);
	//cout << "Line number " << k << " From word num " << arr[pos] << " to word num " << pos << endl;
    return;
}


int minSpaceCost(vector<string>& strarr, int linewidth) {
	vector<vector<int>> extras(strarr.size(), vector<int>(strarr.size(), 0));
	vector<vector<int>> linecost(strarr.size(), vector<int>(strarr.size(), 0));
	vector<int> cost(strarr.size(), INT_MAX);
	vector<int> pos(strarr.size(), 0);
	for (int i = 0; i < strarr.size(); i++) {
		extras[i][i] = linewidth - strarr[i].length();
		for (int j = i+1; j < strarr.size(); j++) {
			extras[i][j] = extras[i][j-1] - strarr[j].length() - 1;
		}
	}
	print_arr_arr(extras);
	
	for (int i = 0; i < strarr.size(); i++) {
		for (int j = i; j < strarr.size(); j++) {
			if (extras[i][j] < 0)
				linecost[i][j] = INT_MAX;
			else if (i == strarr.size()-1 && extras[i][j] >= 0)
				linecost[i][j] = 0;
			else if (extras[i][j] == INT_MAX)
				linecost[i][j] = INT_MAX;
			else
				linecost[i][j] = extras[i][j] * extras[i][j] * extras[i][j];
		}
	}
	print_arr_arr(linecost);
	
	/*
	C(0) - 0
    C(4) - minimum cost of fitting word 0 to word 3
         - C(0),
           C(1) + lc[0][1],
           C(2) + lc[0][2],
           C[3] + lc[0][3]
	C(3) = 0
	*/
	print_arr(cost);
	cost[0] = linecost[0][0];
	print_arr(cost);
 	for (int j = 1; j < strarr.size(); j++) {
		for (int i = 0; i <= j; i++) {
			if (i == 0 && linecost[i][j] != INT_MAX) {
				int sub = linecost[i][j];
				if (sub < cost[j]) {
					cost[j] = sub;
					pos[j] = i;
				}
			}
			else if (i != 0 && cost[i-1] != INT_MAX && linecost[i][j] != INT_MAX) {
				int sub = cost[i-1] + linecost[i][j];
				if (sub < cost[j]) {
					cost[j] = sub;
					pos[j] = i;
				}
			}
		}
		print_arr(cost);
	}
	print_arr(cost);
	print_arr(pos);
	printSolution(strarr, pos, pos.size()-1);
	return cost[strarr.size()-1];
}


int main() {
    int res;
    
    int _strArr_size = 0;
    cin >> _strArr_size;
    cin.ignore (numeric_limits<streamsize>::max(), '\n'); 
    vector<string> _strArr;
    string _strArr_item;
    for(int _strArr_i=0; _strArr_i<_strArr_size; _strArr_i++) {
        getline(cin, _strArr_item);
        _strArr.push_back(_strArr_item);
    }
    
    int _lineWidth;
    cin >> _lineWidth;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = minSpaceCost(_strArr, _lineWidth);
    cout << res << endl;

    return 0;
}