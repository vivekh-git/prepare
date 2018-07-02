#include <bits/stdc++.h>

using namespace std;

void reverseWords(string& str) {
	string word; // to store each word found in a string
	string result; // to store reversed word string
	int i = 0;
	while (i < str.length()) {
		if (str[i] == ' ' && !word.empty()) {
			// first word found
			result = word + ' ' + result;
			word = "";
		}
		else if (str[i] != ' ') {
			word = word + str[i];
		}
		i++;
	}
	if (!word.empty())
		str = word + ' ' + result;
	else
		str = result;
	// remove trailing space introduced
	str = str.substr(0, str.size()-1);
}

void reve(char* begin, char* end) {
	char tmp;
	while (begin < end) {
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}

void reverseWords2(char* s) {
	char* wordbegin = NULL;
	char* ch = s;
	while (ch && *ch) {
		if (!wordbegin && *(ch) != ' ')
			wordbegin = ch;	
		if (wordbegin && (*(ch+1) == ' ' || *(ch+1) == '\0')) {
			reve(wordbegin, ch);
			wordbegin = NULL;
		}
		ch++;
	}
	reve(s, ch-1);
}

int main() {
	string str;
	getline(cin,str);
	cout << str << endl;
	//reverseWords(str);
	reverseWords2((char *)str.c_str());
	cout << str << endl;
	return 0;
}