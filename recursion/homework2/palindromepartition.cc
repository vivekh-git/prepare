#include <bits/stdc++.h>
using namespace std;

    bool isPalindrome(string& s, int b, int e) {
        return (e <= b || (s[b] == s[e] && isPalindrome(s, b+1, e-1)));
    }
    void print_arr(vector<string> arr) {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << ", ";
        cout << endl;
    }
    
    bool partitionUtil(int pos, string& s, vector<string> outarr, vector<vector<string>>& result) {
        if (pos == s.length()) {
            print_arr(outarr);
            result.push_back(outarr);
            return true;
        }
        for (int len = 1; len < s.length() - pos + 1; len++) {
            string sub = s.substr(pos, len);
			cout << "sub - " << sub << endl;
            if (! isPalindrome(sub, 0, sub.length()-1)) continue;
			cout << "pushing sub to outarr" << endl;
            outarr.push_back(sub);
            partitionUtil(pos+len, s, outarr, result);
            outarr.pop_back();
        }
        return false;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> outarr;
        partitionUtil(0, s, outarr, result);
        return result;
    }
	
	void print_arr(vector<vector<int>> table) {
		for (int i = 0; i < table.size(); i++) {
			for (int j = 0; j < table[0].size(); j++) {
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}
	void print_arr(vector<vector<bool>> table) {
		for (int i = 0; i < table.size(); i++) {
			for (int j = 0; j < table[0].size(); j++) {
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	bool isPalindrome2(string& s, int b, int e) {
		return (e >= b || ((s[b] == s[e]) && isPalindrome2(s, b+1, e-1)));
	}
	
	
    int minCut(string s) {
        int M = s.length();
		if (M == 0) return 0;
        vector<vector<bool>> palind(M, vector<bool>(M, false));
		vector<vector<int>> table(M, vector<int>(M, 0));
        for (int i = M-1; i >= 0; i--) {
            for (int j = i; j < M; j++) {
                if (i == j) {
					palind[i][j] = true;
                    table[i][j] = 0;
                }
				else if (j == i+1) {
					if (s[i] == s[j]) {
						palind[i][j] = true;
	                    table[i][j] = 0;
					}
					else {
						palind[i][j] = false;
						table[i][j] = 1;
					}
				}
                else {
					if (s[i] == s[j] &&  palind[i+1][j-1]) {
						palind[i][j] = true;
                    	table[i][j] = 0;
					}
               	 	else {
						palind[i][j] = false;
                    	table[i][j] = INT_MAX;
                    	for (int k = i; k < j; k++) {
                        	int sub = table[i][k] + table[k+1][j];
                        	if (1+sub < table[i][j])
                            	table[i][j] = 1 + sub;
                    	}
                	}
            	}
			}
        }
		print_arr(palind);
		cout << endl;
		print_arr(table);
        return table[0][M-1];
    }
	
	
	
int main() {
   //string s = "cabababcbc";
	string s;
	getline(cin, s);
	/*
   vector<vector<string>> res = partition(s);
   for (int i = 0; i < res.size(); i++) {
      print_arr(res[i]);
	  cout << endl << endl;
   }*/
   
   int mc = minCut(s);
   cout << "mc = " << mc << endl;
   return 0;
}