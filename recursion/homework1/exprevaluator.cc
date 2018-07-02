#include <bits/stdc++.h>
#include <map>
#include <string>

using namespace std;



/*
 * Complete the function below.
222
2*2*2
2*2s2
2*2+2

vector<char> op = {}'*', '+', ''};
str = "222"
output = 2*2*

permute(str, op, sdx, output) {
   if (str.length() <= 1)
      print output + str[sdx];
   else {
      output += str[sdx];
	  for (int j = 0; j < op.length(); j++)
	     output += op[j]
         permute(str,op, sdx+1,output);
		 output.pop_back();
       }
	   output.pop_back();
   }
}

 */
/*
take a character  - use one of operator and take another char and find sum and compute remaining, and recurse
f (222, 0, 24, output)
bool f(str, idx, remaining, output)
   if (remaining == 0 && idx == str.length())
	    print output;
	    return true;
   else if (remaining <= 0 && idx != str.length())
        // bactrack idx--
		// dont print output
	    return false;
   else {
        // remaining 24, output = "", idx =  0
		int sum = 0;
        char ch = str[idx]; output += ch;
        bool flag = f(str, idx+1, remaining - ch, output);
        if (flag)
   }
*/
/*
vector<string> expressionCreator(string strDigits, int iK) {
    
}
*/
//p (234, op, 0, output)

int eval (vector<string> digits, vector<char> ops);
	

void permute(string& str, vector<char>& op, int sdx, string& output, vector<string>& oarr, int sum, vector<string>& digits, vector<char>& ops ) {
	if (sdx == str.length()) {
		int s = eval(digits, ops);
		if (s == sum) {
			oarr.push_back(output + "=" + to_string(sum));
		}
		//cout << "FINAL:" << output << endl;
		//cout << "FINAL:" << s << endl;
		return;
	}
	else if (sdx == str.length()-1) {
		digits.push_back(string(1,str[sdx]));
		int s = eval(digits, ops);
		if (s == sum) {
			oarr.push_back(output + str[sdx] + "=" + to_string(sum));
		}
		digits.pop_back();
		//cout << "FINAL:" << output + str[sdx] << endl;
		//cout << "FINAL:" << s << endl;
		return;
	}
    else {
		digits.push_back(string(1,str[sdx]));
		output.push_back(str[sdx]);
	    for (int j = 0; j < op.size(); j++) {			
			ops.push_back(op[j]);
			output.push_back(op[j]);
            permute(str,op, sdx+1,output, oarr, sum, digits, ops);
			 
			ops.pop_back();
			output.pop_back(); // pops operator
        }
		digits.pop_back();
		output.pop_back(); // pops digit
    }
}

void printvec(vector<string> st) {
	for (int i = 0; i < st.size(); i++) {
		cout << st[i]<< endl;
	}
}

void printvec(vector<char> st) {
	for (int i = 0; i < st.size(); i++) {
		cout << st[i]<< endl;
	}	
}

void print_stack(stack<string> digitst) {
	cout << "printing digit st" << endl;
	while (!digitst.empty()) {
		cout << digitst.top() << endl;
		digitst.pop();
	}
}

// 2, 3, 4
// + *
// + 0
// * 0

int eval (vector<string> digits, vector<char> ops) {
	unordered_map<char, int> orank = { {'\0', 3}, {'*', 2}, {'+', 1} };
	
	//printvec(digits);
	//printvec(ops);
	
	stack<char> opst;
	stack<string> digitst; int digitindex = 0;
	//cout << "pushing digit - " << digits[digitindex] << endl;
	digitst.push(digits[digitindex++]);
	
	for (int i=0; i< ops.size(); i++) {
		//cout << "ops vector - " << ops[i] << endl;
		if (opst.empty()) {
			//cout << "opst empty" << endl;
			//cout << "pushing digit - "  << digits[digitindex] << endl;
			//cout << "pushing op - " << ops[i] << endl;
			digitst.push(digits[digitindex++]);
			opst.push(ops[i]);
		}
		else if (orank[ops[i]] < orank[opst.top()]) {
			// lower precedence is coming up - first eval stack
			// pop the operator
			// compute the number and keep it in sum
			char c = opst.top(); opst.pop();
			//cout << "op - " << c << endl;
			//print_stack(digitst);
			//cout << "finished printing stack" << endl;
			string d1 = digitst.top(); digitst.pop();
			if (digitst.empty()) digitst.push(digits[digitindex++]);
			string d2 = digitst.top(); digitst.pop();
			//cout << "d1, d2 - " << d1 << " - " << d2 << endl;
			if (c == '\0') {
				string s = d2+d1;
				//cout << "s - " << s << endl;
				stringstream ss(s);
				int x = 0;
				ss >> x;
				//cout << "pushing digitst " << x << endl;
				//cout << "before" << endl;
				//print_stack(digitst);
				digitst.push(to_string(x));
				//cout << "after " << endl;
				//print_stack(digitst);
			}
			else if (c == '*') {
				stringstream ss1(d1);
				stringstream ss2(d2);
				int x1 = 0; int x2 = 0;
				ss1 >> x1; ss2 >> x2;
				int x = x1 * x2;
				digitst.push(to_string(x));
			}
			else { // c == + - will not happen unless end of string scenario
				stringstream ss1(d1);
				stringstream ss2(d2);
				int x1 = 0; int x2 = 0;
				ss1 >> x1; ss2 >> x2;
				int x = x1 + x2;
				digitst.push(to_string(x));
			}
			//cout << "pushing op - " << ops[i] << endl;
			opst.push(ops[i]);
		}
		else {
			digitst.push(digits[digitindex++]);
			opst.push(ops[i]);
		}
	}
	if (digitindex < digits.size())
		digitst.push(digits[digitindex++]);
	
	int sum = 0;
	while (! opst.empty())	{
		char c = opst.top(); opst.pop();
		//cout << "op - " << c << endl;
		string d1 = digitst.top(); digitst.pop();
		string d2 = digitst.top(); digitst.pop();
		//cout << "d1, d2 - " << d1 << " - " << d2 << endl;
		if (c == '\0') {
			string s = d2+d1;
			//cout << "s - " << s << endl;
			stringstream ss(s);
			int x = 0;
			ss >> x;
			//cout << "conv int " << x << endl;
			//sum += x;
			digitst.push(to_string(x));
		}
		else if (c == '*') {
			stringstream ss1(d1);
			stringstream ss2(d2);
			int x1 = 0; int x2 = 0;
			ss1 >> x1; ss2 >> x2;
			int x = x1 * x2;
			//sum += x;
			digitst.push(to_string(x));
		}
		else { // c == + - will not happen unless end of string scenario
			stringstream ss1(d1);
			stringstream ss2(d2);
			int x1 = 0; int x2 = 0;
			ss1 >> x1; ss2 >> x2;
			int x = x1 + x2;
			//sum += x;
			digitst.push(to_string(x));
		}
	}
	if (!digitst.empty()) { 
		string d = digitst.top(); digitst.pop();
		stringstream ss(d);
		ss >> sum;
	}
	return sum;
}

vector<string> expressionCreator(string& strDigits, int iK) {
    vector<char> op = {'*', '\0', '+'};
	string output;

	vector<string> digits; vector<char> ops;
	vector<string> result;
	
	permute(strDigits, op, 0, output, result, iK, digits, ops);
	return result;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector <string> res;
    string strDigits;
    getline(cin, strDigits);

    int iK;
    cin >> iK;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	//vector<string> digits = {"1","2", "3", "4"};
	//vector<char> ops = {'\0', '*', '+'};
	//int s = eval (digits, ops);
	//cout << s << endl;
    res = expressionCreator(strDigits, iK);
	cout << "Printing Output" << endl;
	
    for(int res_i = 0; res_i < res.size(); res_i++) {
			cout << res[res_i] << endl;;
	}

    //fout.close();
    return 0;
}
