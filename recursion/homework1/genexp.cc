#include <bits/stdc++.h>
using namespace std;

/*
Recurrence relation
222
2*2*2
2+2*2
2*2+2
2+22
22+2
f(str, pos, expr, exp_val, curr_val, curr_val_after_last_plus, exp_arr, target)
   ->  if (pos == str.length()) {
			if (exp_val == target)
			  add exp to exp_arr
			  return;
			}
       }
	   else {
			f(str, pos+1, expr+str[pos], curr_val+str_to_int(str[pos]))
	   }

*/
// str = 234
int convert_str_int(string str) {
	int res = 0;
	for (int i = 0; i < str.length(); i++) {
		res = res * 10;
		res = res + str[i] - '0';
	}
	return res;
}


void gen_expression_util(string& str, int pos, string expr, int expr_val, int curr_val_after_last_plus, vector<string>& expr_arr, int target) {
	if (str.length() == pos) {
		//if (expr_val == target) 
			//expr_arr.push_back(expr + "=" + to_string(target));
		expr_arr.push_back(expr);
		return;
	}
	else {
		for (int i=pos; i< str.length(); i++) {
			// first join operator
			string num_to_add_str = str.substr(pos, i-pos+1);
			int num_to_add = convert_str_int(num_to_add_str);
			
			if (pos == 0) {
				gen_expression_util(str, pos+1, num_to_add_str, num_to_add, num_to_add, expr_arr, target);
			}
			else {
			// + operator
			//
				gen_expression_util(str, pos+1, expr+'+'+num_to_add_str, expr_val+num_to_add, num_to_add, expr_arr, target);
				// * operator 1 + 3 * 4 -  4-3 + 3 * 4
				gen_expression_util(str, pos+1, expr+'*'+num_to_add_str, expr_val - curr_val_after_last_plus + (curr_val_after_last_plus * num_to_add), curr_val_after_last_plus * num_to_add, expr_arr, target);
			}
		}
	}
}

vector<string> gen_expression(string& str, int target) {
	vector<string> expr_arr;
	gen_expression_util(str, 0, "", 0,  0, expr_arr, target);
	return expr_arr;
}

int main() {
	string str;
	cin >> str;
	
	int target;
	cin >> target;
	
	vector<string> results = gen_expression(str, target);
	for (auto it = results.begin(); it != results.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
