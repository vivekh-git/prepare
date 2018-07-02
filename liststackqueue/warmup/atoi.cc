#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
Logic
proportional to length of string - o(n) and o(1) space

have a function to check 0-9
have a function to check if + or -

loop through string one char at a time.
if space ignore
if operator (+ or -) - push to a stack, stop at first integer
if number push to another stack
if 

*/

bool checkOperator(char c) {
	return (c == '+' || c == '-');
}

bool checkNumeral(char c) {
	int i = int(c);
	return (i >= 48 && i <= 57);
}

int pow(int base, int raise) {
	int num = 1;
	for (int i = 0; i < raise; i++) {
		num = num * base;
	}
	return num;
}

int computeNumber(stack<char>& st) {
	int number = 0;
	int i = 0;
	int digit = 0;
	while (st.size() > 0) {
		char c = st.top();
		st.pop();
		digit = c - 48;
		number = number + (pow(10, i) * digit);
		i++;
	}
	return number;
}

char getOperator(stack<char>& st) {
	return st.top();
}


int atoiIK(string str) {
	stack<char> opStack;
	stack<char> numStack;
	
	for (int i = 0; i< str.length(); i++) {
		if (checkNumeral(str[i])) {
			numStack.push(str[i]);
		}
		else if (numStack.size() > 0) {
			// break on first non integer
			break;
		}
		else if (checkOperator(str[i])) {
			opStack.push(str[i]);
		}
	}

    int ret = computeNumber(numStack);
	char op = getOperator(opStack);
    if (op == '-') 
		return 0-ret;
	else
		return ret;
}



int atoiv2(string str) {
	if (str.empty()) return 0;
	int result = 0; bool opset = false; char op = '+';
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 48 && str[i] <= 57) {
			result = result*10 + (str[i] - '0');
		}
		else if (opset) {
			break;
		}
		else if (str[i] == '+' || str[i] == '-') {
			opset = true;
			op = str[i];
		}
	}
	if (op == '-')
		return -result;
    else 
		return result;
}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _str;
    getline(cin, _str);
    
    res = atoiv2(_str);
    cout << res << endl;
    
    //fout.close();
    return 0;

}
