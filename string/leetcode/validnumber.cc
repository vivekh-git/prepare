/*
Valid Number
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
Draw a DFA depicting dependencies of state machine
if you draw a state machine - it becomes easy.
*/
class Solution {
public:
    bool isNumber(string s) {
		int b = 0; int e = s.length() - 1;
		while (b < s.length() && s[b] == ' ') b++;
		while (e >= 0 && s[e] == ' ') e--;
		// stip leading and trailing spaces
		return isNumberUtil(s.substr(b, e-b+1));
    }
	
	bool isNumberUtil(string s) {
		int pos = 0;
		int state = 0;
		while (pos < s.length()) {
			char ch = s[pos];
			switch(state) {
			case 0:
				if (ch == '+' || ch == '-')
					state = 1;				
				else if (ch == '.')
					state = 3;
				else if (ch >= '0' && ch <= '9')
					state = 2;
				else
					return false;
				break;
			case 1:
				if (ch == '.')
					state = 3;
				else if (ch >= '0' && ch <= '9')
					state = 2;
				else
					return false;
				break;
			case 2:
				if (ch >= '0' && ch <= '9')
					state = 2;
				else if (ch == '.') // you cannot go to 3 but goto 4 - Reason. "." -> should be false. So case 3 should not end in done.
					state = 3;      // However "5." -> should be true. To support this, from case 2, with . - you goto state 4
				else if (ch == 'e' || ch == 'E')
					state = 5;
				else
					return false;
				break;
			case 3: 
				if (ch >= '0' && ch <= '9') // this will not goto done state. SO after . without a number, we have to see a number
					state = 4;
				else 
					return false;   
				break;
			case 4:
				if (ch >= '0' && ch <= '9')
					state = 4;
				else if (ch == 'e' || ch == 'E')
					state = 5;
				else 
					return false;
				break;
			case 5:
				if (ch >= '0' && ch <= '9')
					state = 7;
				else if (ch == '+' || ch == '-')
					state = 6;
				else 
					return false;
				break;
			case 6:
				if (ch >= '0' && ch <= '9')
					state = 7;
				else
					return false;
				break;
			case 7:
				if (ch >= '0' && ch <= '9')
				 	state = 7;
				else
					return false;
				break;
			}
			pos++;
		}
		if (state == 2 || state == 3 || state == 4 || state == 7)
			return true;
		else
			return false;
	}
};
