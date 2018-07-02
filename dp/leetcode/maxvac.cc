#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int f(int wk, int prevcity, vector<vector<int>>& flights, vector<vector<int>>& days) {
	        if (wk == days[0].size())
	            return 0;
	        int n = days.size();  // number of cities
	        int maxres = INT_MIN;
	        for (int i = 0; i < n; i++) {
	            if (i != prevcity && flights[prevcity][i] != 1) continue; // skip
	            int sub = days[i][wk] + f(wk+1, i, flights, days);
	            if (sub > maxres)
	                maxres = sub;
	        }
	        return maxres;
	}
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (days.empty()) return 0;
        //return f(0, 0, flights, days);
        int n = days.size(); int wks = days[0].size();
        if (n == 0 || wks == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(wks+1, 0));
        for (int wk = wks-1; wk >= 0; wk--) {
            for (int i = 0; i < n; i++) {
                dp[i][wk] = days[i][wk] + dp[i][wk+1];
                for (int city = 0; city < n; city++) {
                    if (flights[i][city] == 1) 
                         dp[i][wk] = max(days[city][wk] + dp[city][wk+1], dp[i][wk]);
                }
            }
        }
        return dp[0][0];
    }
};


int main() {
	vector<vector<int>> flights = {{0,1,1},
									{1,0,1},
									{1,1,0}};
	vector<vector<int>> days = {{1,3,1},
								{6,0,3},
								{3,3,3}};
	Solution sol;
	int res = sol.maxVacationDays(flights, days);
	cout << "res - " << res << endl;							
}