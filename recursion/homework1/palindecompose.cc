#include <bits/stdc++.h>

using namespace std;


/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

/*
 * Complete the function below.
 */

bool isPalindrome(string str) {
	int len = str.length();
	if (len <= 1)
		return true;
	else
		return (str[0] == str[len-1]) && isPalindrome(str.substr(1,len-2));
}

void print_vector(vector<string> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "|";
	}
	cout << endl;
}

string make_string(vector<string> arr) {
	string s;
	for (int i = 0; i < arr.size(); i++) {
		s += arr[i] + "|";
	}
	return s;
}


vector<string> permute(vector<string>& combolist, vector<string> combo, string population, int start) {
  cout << "permute - " << population << ", start - " << start << endl;
  // base case
  // string empty
  if (population == "") {
    //print_vector(combo);
	combolist.push_back(make_string(combo));
  }
  else {
    // slightly larger case - let us do AB - recurse to smaller one
    for (int i = start+1; i <= population.length(); i++) {
		cout << "i = " << i << endl;
		string next = population.substr(start, i);
		cout << "next - " << next << endl;

	  	if (isPalindrome(next)) {
		  	combo.push_back(next);
		  	string remaining = population.substr(i);
      	  	cout << "next - " << next << ", remaining - " << remaining << endl;
      	  	permute (combolist, combo, remaining, start);
		  	combo.pop_back();
	  	}
    }
  }
  return combolist;
}

vector<string> palindromicDecomposition(string strInput) {
    vector<string> combo;
	vector<string> combolist;
    return permute(combolist, combo, strInput, 0);
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector <string> res;
    string strInput;
    getline(cin, strInput);

    //vector<string> combo;
    //res = permute(res, combo, strInput, 0);
	res = palindromicDecomposition(strInput);
	
    for (int res_i = 0; res_i < res.size(); res_i++) {
		cout << res[res_i] << endl;;
	}

    //fout.close();
    return 0;
}
