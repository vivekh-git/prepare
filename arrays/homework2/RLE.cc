#include <bits/stdc++.h>
using namespace std;
//. 012345
/// AAAABC
//.    4
// AAAAA
string RLE(string text) {
	string result;
	
	for (int i = 0; i < text.size(); ) {
		int count = 1;
		int j = i+1;
		while (j < text.size() && text[j] == text[i]) {
			count++;
			j++;
		}
		if (count > 1 ) {
			result += to_string(count);
			//result.push_back(char(count+127));
			//result.push_back(char(count)); // char is not pushed to string - dont know why
		}
		result.push_back(text[i]);
		i = j;
	}
	return result;
}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strinput;
    getline(cin, _strinput);
    
    res = RLE(_strinput);
    cout << res << endl;
    
    //fout.close();
    return 0;
}