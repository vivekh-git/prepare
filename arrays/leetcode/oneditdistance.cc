#include <bits/stdc++.h>
using namespace std;

bool isOneEditDistance(string s, string t) {
        int len_s = s.length(); int len_t = t.length();
        if (abs(len_s - len_t) > 1)
            return false;
        int i = 0; int j = 0; int count = 0;
        while (i < len_s && j < len_t) {
            if(s[i] != t[j]) {
                if (count == 1) 
                    return false;
                if (len_s > len_t) {// s larger - delete from s
                    i++;
                }
                else if (len_s < len_t) { // t larger - delete from t
                    j++;
                }
                else { // equal - only replace is possible
                    i++; j++;
                }
                count++;
            }
            else {
                i++;
                j++;
            }
        }
        if (i < len_s || j < len_t) { // one of the string is smaller and different at the end
            count++;
        }
        return (count == 1);
}


int main() {
	string s = "ab";
	string t = "acb";
	bool res = isOneEditDistance(s, t);
	cout << "is one edit distance - " << res << endl;
	return 0;
}