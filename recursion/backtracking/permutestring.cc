#include <bits/stdc++.h>

using namespace std;

/* Recurrence relation

f(idx)  ->  if (idx == str.length())
				cout << str;
			else {
				for (int i=idx, i<str.length(); i++) {
					swap(str,i, idx);
					f(idx+1);
					swap(str,idx, i);
				}
			}
*/

void swapstr(string& str, int src, int dest) {
	char tmp = str[src];
	str[src] = str[dest];
	str[dest] = tmp;
}

bool permute(string& str, int idx) {
	if (idx == str.length()) {
		cout << str << endl;
		return true;
	}
	else {
		bool ret = false;
		for (int i = idx; i < str.length(); i++) {
			swapstr(str, i, idx);
			ret = permute(str, idx+1);
			swapstr(str, idx, i);
		}
		return ret;
	}
}


/* Recurrence relation 
f(sofar, population) -> if (population == '')
							cout << sofar << endl;
						else {
							for (int i = 0; i < population.length(); i++) {
							    f(sofar+population[i], population.substr(0, i) + population.substr(i+1));
							}
						}



*/
bool permute2(string sofar, string population) {
	//cout << "sofar - " << sofar << ", population - " << population << endl;
	if (population.length() == 0) {
		cout << sofar << endl;
		return true;
	}
	else {
		bool ret = false;
		for (int i =0; i < population.length(); i++) {
			ret = permute2(sofar+population[i], population.substr(0, i) + population.substr(i+1));
		}
		return ret;
	}
}


/* Make it efficient by preallocating output string */
bool permute3(string& output, string population) {
	//cout << "sofar - " << sofar << ", population - " << population << endl;
	if (population.length() == 0) {
		cout << output << endl;
		return true;
	}
	else {
		bool ret = false;
		for (int i =0; i < population.length(); i++) {
			output.push_back(population[i]);
			ret = permute2(output, population.substr(0, i) + population.substr(i+1));
			output.pop_back();
		}
		return ret;
	}
}


bool permute4(string& output, string population) {
	//cout << "sofar - " << sofar << ", population - " << population << endl;
	if (population.length() == 0) {
		cout << output << endl;
		return true;
	}
	else {
		bool ret = false;
		for (int i =0; i < population.length(); i++) {
			string next = output + population[0]; 		
			ret = permute4(next, population.substr(1));
			rotate(population.begin(), population.begin()+1, population.end());
		}
		return ret;
	}
}



int main() {
	string str;
	cin >> str;
	//int count = 0;
	//permute(str, 0, count);
	string output;
	if (!permute4(output, str)) {
		cout << "no permutations" << endl;
	}
	//cout << "total count - " << count << endl;
	return 0;
}