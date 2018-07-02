#include <bits/stdc++.h>

using namespace std;


void print_string_sinusoidally(string s) {
    int rowcount = 3;
    int len = s.length();
    vector<vector<char>> sArr(rowcount, vector<char>(len, ' ')); // intitializing to empty char is important
    bool up = true;
    int row = rowcount - 1;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == ' ') ch = '~';
        sArr[row][i] = ch;
        // some checks to flip up flag
        if (row == 0)
            up = false;
        else if (row == rowcount-1)
            up = true;
        if (up)
            row--;
        else
            row++;
    }
    for (int i = 0; i < rowcount; i++) {
        for (int j = 0; j < s.length(); j++) {
			if (sArr[i][j] == ' ')
				cout << j << " ";
			else
            	cout << sArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string s;
    getline(cin, s);

    print_string_sinusoidally(s);

    return 0;
}
