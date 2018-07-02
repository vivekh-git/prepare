#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
 * Complete the function below.
 */
/*
RECURRENCE RELATION - S - source, N - source length ,D - destination, M - dest length
ED(i, j) ->
      if (j == M)
        return Delete_cost(1) * N-i;
      if (i == N)
        return Insert_cost(1) * M-j
      if (S[i] == D[j])
        return 0+ED(i+1, j+1)
      else {
        return min(
          Cr+Ed(i+1, j+1), Ci+Ed(i, j+1), Cd+Ed(i+1, j)
        );
      }
*/
void print_table(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int levenshteinDistance(string strWord1, string strWord2) {
    int N = strWord1.length(); int M = strWord2.length();
    vector<vector<int>> table(N+1, vector<int>(M+1));
    for (int i=N; i>=0; i--) {
        for (int j=M; j>=0; j--) {
			cout << "i:" << i << ", j:" << j << endl;
            if (j == M) {
                table[i][j] = N-i ;
				cout << table[i][j] << endl;;
			}
            else if (i == N) {
                table[i][j] = M-j ;
				cout << table[i][j] << endl;
			}
            else if (strWord1[i] == strWord2[j]) {
                table[i][j] = table[i+1][j+1];
				cout << table[i][j] << endl;
			}
            else {
                int cr = 1 + table[i+1][j+1];
                int ci = 1 + table[i][j+1];
                int cd = 1 + table[i+1][j];
                table[i][j] = (ci < cr) ? ci : cr;
                table[i][j] = (cd < table[i][j]) ? cd : table[i][j];
				cout << table[i][j] << endl;
            }
        }
    }
	print_table(table);
    return table[0][0];
}


int levenshteinDistance2(string strWord1, string strWord2) {
    int N = strWord1.length(); int M = strWord2.length();
    vector<vector<int>> table(N+1, vector<int>(M+1));
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < M+1; j++) {
			cout << "i:" << i << ", j:" << j << endl;
            if (i == 0) {
                table[i][j] = j ;
				cout << table[i][j] << endl;;
			}
            else if (j == 0) {
                table[i][j] = i;
				cout << table[i][j] << endl;
			}
            else if (strWord1[i-1] == strWord2[j-1]) {
                table[i][j] = table[i-1][j-1];
				cout << table[i][j] << endl;
			}
            else {
                int cr = 1 + table[i-1][j-1];
                int ci = 1 + table[i][j-1];
                int cd = 1 + table[i-1][j];
                table[i][j] = (ci < cr) ? ci : cr;
                table[i][j] = (cd < table[i][j]) ? cd : table[i][j];
				cout << table[i][j] << endl;
            }
        }
    }
	print_table(table);
    return table[N][M];
}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _strWord1;
    getline(cin, _strWord1);
    
    string _strWord2;
    getline(cin, _strWord2);
    
    res = levenshteinDistance(_strWord1, _strWord2);
    cout << res << endl;
    
    //fout.close();
    return 0;
}