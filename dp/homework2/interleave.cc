#include <bits/stdc++.h>

using namespace std;
/*










*/
bool interleave(string& A, string& B, string& C) {
	int M = A.length();
	int N = B.length();
	if (M+N != C.length())
		return false;
	vector<vector<bool>> table(M+1, vector<bool>(N+1, false));
	for (int i = M; i >= 0; i--) {
		for (int j = N; j >= 0; j--) {
			if (i == M && j == N) 
				table[i][j] = true;
			else if (i == M) 
				table[i][j] = (B[j] == C[i+j]) && table[i][j+1];
			else if (j == N) 
				table[i][j] = (A[i] == C[i+j]) && table[i+1][j];
			else
				table[i][j] = ((A[i] == C[i+j]) && table[i+1][j]) ||
								((B[j] == C[i+j]) && table[i][j+1]);
		}
	}
	return table[0][0];
}

int main() {
	string A; string B; string C;
	getline(cin, A);
	getline(cin, B);
	getline(cin, C);
	bool res = interleave(A, B, C);
	cout << "res = " << res << endl;
	return 0;
}