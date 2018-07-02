#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
string sortCharacters(string inString) {
	int arr[256] = {0};
	int len = inString.length();
    for (int i = 0; i < len; i++) {
    	char c = inString[i];
		arr[c]++;
    }
	
	string sortstr;
    int index = 0;
	for (int i = 0; i < 256; i++) {
		while (arr[i]) {
			sortstr += i;
		 	arr[i]--;
		}
	}
	
	return sortstr;
}




int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string res;
    string inString;
    getline(cin, inString);

    res = sortCharacters(inString);
    cout << res << endl;

    //fout.close();
    return 0;
}
