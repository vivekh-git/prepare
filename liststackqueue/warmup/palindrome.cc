#include <iostream>
#include <string>
#include <locale>

using namespace std;

bool isPunctuation(char c) {
	return (c == '.' || c == ',' || c == '!' || c == '-' || c == ';' || c == ':' || c == '\'' || c == '"');
}

// use position instead of substr
bool isPalindrome(string strarr) {
    std::locale loc;
	int len = strarr.length();
	if (len > 0) {
	   if (isPunctuation(strarr[0]))
		  isPalindrome(strarr.substr(1, len-1));
	   else if (isPunctuation(strarr[len-1]))
	      isPalindrome(strarr.substr(0, len-1));
	   else 
	      return 
		  tolower(strarr[0], loc) == tolower(strarr[len-1], loc) &&
		  isPalindrome(strarr.substr(1, len-2));
    }
    return true; 
}

bool isPalindrome2(string& str) {
	return isPalindrome2(str, 0, str.length()-1);
}

bool isPalindrome(string& str, int b, int e) {
	return (e <= b) || (str[b] == str[e] && isPalindrome(str, b+1, e-1));
}

bool isPalindrome2(string& str, int b, int e) {
	if (e > b) {
		if (isPunctuation(str[b])) return isPalindrome(str, b+1, e);
		else if (isPunctuation(str[e])) return isPalindrome(str, b, e-1);
		else return (str[b] == str[e] && isPalindrome(str, b+1, e-1));
	}
	return true;
}



int main() {
	string str = "i was saw i";
	cout << isPalindrome2(str) << endl;
	return 0;
}