#include <bits/stdc++.h>

using namespace std;

int pow(int base, int exp) {
    if (exp == 0)
        return 1;
    int half = pow(base, exp/2);
    if (exp % 2 == 0)
        return half * half;
    else
        return base* half * half;
}

int findFofPascalTriangle(int n) {
    vector<vector<unsigned long long int>> table(n, vector<unsigned long long int>(n, 0));
    unsigned long long int F = 0; unsigned long long int denominator = pow(10,9) + 7;
    cout << "denominator - " << denominator << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0)
                table[i][j] = 1;
            else
                table[i][j] = table[i-1][j] + table[i-1][j-1];
			if (table[i][j] >= denominator)
				table[i][j] = table[i][j] - denominator;
			//cout << table[i][j] << " ";
            F = F + ((i+1)* table[i][j]) + j+1;
			if (F >= denominator)
				F = F % denominator;	
        }
		//cout << endl;
		
		cout << "F - " << F << endl;
    }
    cout << "f - " << F << endl;
    return (int)(F % denominator);
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int res = findFofPascalTriangle(n);

    cout << res << "\n";

    //fout.close();

    return 0;
}