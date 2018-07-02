#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<vector<int>>& table) {
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

/*
 * Complete the function below.
 */
/* Recurrence Relation
f(i, j) -> max (
				c(i) + min(f(i+2, j), f(i+1, j-1)),
				c(j) + min(f(i+1, j-1), f(i, j-2))
				)
        = c(i) when i == j
		= max(c(i), c(j)) when j == i+1
Editorial - f(i, j) - max value player 1 can win in arr between 1 and j inclusive
Player 1 can choose between c(i) and c(j). 
If player1 chooses c(i), player2 can choose between c(i+1) and c(j). 
  So player1 can get to pick next turn between c[i+2 - j] or c[i+1, j-1] depending on player2's choice.
  Since player2 will optimize for his max gain, player will get min of the choices.
  Hence - c(i) + min(f(i+2, j), f(i+1, j-1)).
We can do same reasoning if player1 goes with C(j) and since player1 is optimizing for his max gain, 
  we have to pick max of 2 choices.
*/
int maxWin(vector<int>& coins) {
	vector<vector<int>> table(coins.size(), vector<int>(coins.size(), 0));
	for (int i = coins.size()-1; i >= 0; i--) {
		for (int j = i; j < coins.size(); j++) {
			if (i == j) {
				table[i][j] = coins[i];
			}
			else if (j == i+1) {
				table[i][j] = max(coins[i], coins[j]);
			}
			else {
				table[i][j] = max(
									coins[i] + min(table[i+2][j], table[i+1][j-1]),
									coins[j] + min(table[i][j-2], table[i+1][j-1])
								 );
			}
		}
	}
	//print_arr(table);
	return table[0][coins.size()-1];
}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    /*
    int _intCoins_size = 0;
    cin >> _intCoins_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _intCoins;
    int _intCoins_item;
    for(int _intCoins_i=0; _intCoins_i<_intCoins_size; _intCoins_i++) {
        cin >> _intCoins_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _intCoins.push_back(_intCoins_item);
    }
    */
	vector<int> _intCoins = {8,15,3,7};
    res = maxWin(_intCoins);
    cout << res << endl;
    
    //fout.close();
    return 0;
}
