#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
int maxLenMatchingParen(string str) {
	int mlen = 0;
	int mstart = 0;
	int pstart = 0;
	int length = str.length();
	stack<int> st;
	for (int i = 0; i < length; i++) {
		if (str[i] == '(') {
			st.push(i);
		}
		else {
			if (st.empty()) {
				// found a closing paran with no opening paran in stack
				pstart = i+1;
			}
			else {
				st.pop();
				int start = st.empty() ? pstart-1 : st.top();
				int size = i - start;
				if (size > mlen) {
					mlen = size;
					mstart = start + 1;
				}
			}
		}
	}
}




int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    string str;
    getline(cin, str);

    res = maxLenMatchingParen(str);
    //fout << res << endl;
    cout << res << endl;

    //fout.close();
    return 0;
}