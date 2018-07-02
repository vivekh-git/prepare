#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
bool hasMatchingParantheses(string str) {
	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			if (st.top() != '(') return false;
			st.pop();
		}
		else if (str[i] == '}') {
			if (st.empty() || st.top() != '{') return false;
			st.pop();
		}
		else if (str[i] == ']') {
			if (st.top() != '[') return false;
			st.pop();
		}
		else {
			// do nothing
		}
	}  
    if (! st.empty()) return false;
	else return true; 
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    string strParenExpression;
    getline(cin, strParenExpression);

    res = hasMatchingParantheses(strParenExpression);
    cout << res << endl;

    //fout.close();
    return 0;
}