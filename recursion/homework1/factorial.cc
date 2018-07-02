#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 3 mins
int factorial(int n) {
	if (n == 1) 
		return 1;
	else
		return n * factorial(n-1); 
}


// 6.48p - 6.49p - 1 min
int bunnyEars(int bunnies) {
	if (bunnies == 0)
		return 0;
	else 
		return 2 + bunnyEars(bunnies-1);
}

//1 1 2 3 5 8 13 21
int fibonacci(int n) {
	// base case
	if (n == 0)
		return 0;
	else if (n == 1) 
		return 1;
	else 
		return fibonacci(n-1) + fibonacci(n-2); 
}

// 6.51p - 6.53p - 2 mins
int bunnyEars2(int bunnies) {
	if (bunnies == 0)
		return 0;
	else if (bunnies % 2 != 0)
		return 2 + bunnyEars2(bunnies-1);
	else
		return 3 + bunnyEars2(bunnies-1);
}

// 6.53p - 6.56p - 3 mins
int triangle(int rows) {
	if (rows == 0)
		return 0;
	else 
		return rows + triangle(rows-1);
}

// sumDigits
// 6.56p - 6.58p - 2 mins
int sumDigits(int n) {
	if (n / 10 == 0)
		return n;
	else
		return (n % 10) + sumDigits(n/10);
}

// count7
// 717 yields 2
// 717 % 10 = 7 and 717/10 = 71
// 10.57p - 11.04p - 5 mins
int count7(int n) {
	if (n/10 == 0) 
		return (n%10 == 7) ? 1: 0;
	else
		return ((n % 10 == 7) ? 1: 0) + count7(n/10);
}

// count8
// 2 consecutive 8s give 2 to count while else gives 1 to count
// 8 - 1, 818 - 2, 8818 - 4
// the count of the occurrences of 8 as a digit, except that an 8 with another 8 immediately to its left counts double, so 8818 yields 4.
// 8188 - 2 + 818
// 818 - 
// 5.38a - 5.42a - 4 mins
int count8(int n) {
	if (n/10 == 0)
		return (n % 10 == 8) ? 1:0;	
	else if (n % 10 == 8 && n % 100 == 88)
		return 2 + count8(n/10);
	else if (n % 10 == 8)
		return 1 + count8(n/10);
	else 
		return 0 + count8(n/10);
}

// power of N
// 3 pow 2 = 3 * pow(3, 1). = > 3 * 3
// 3 pow 2 = if n is even 
// 5.43a - 5.47a - 4 mins
int powerN(int base, int n) {
	if (n == 1)
		return base;
	else if (n % 2 == 0)
		return powerN(base, n/2) * powerN(base, n/2);
	else 
		return base * powerN(base, n/2) * powerN(base, n/2);
}

int powerN(int base, int n) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return powerN(base, n/2) * powerN(base, n/2);
	else 
		return base * powerN(base, n/2) * powerN(base, n/2);
}


// countX
// 5.47a - 5.51a - 4mins
int countX(string str) {
	if (str.length() == 0)
		return 0;
	else if (str.at(0) == 'x')
		return 1 + countX(str.substr(1));
	else
		return 0 + countX(str.substr(1));
}

// countX("djhdjXX", 0)
int countX(string& str, int pos) {
	if (pos == str.length())
		return 0;
	else if (str[pos] == 'x')
		return 1 + countX(str, pos+1);
	else
		return countX(str, pos+1);
}

// countHi
// 5.51a - 5.54a - 3 mins
int countHi(string str) {
	if (str.length() < 2)
		return 0;
	else if (str.at(0) == 'h' && str.at(1) == 'i')
		return 1 + countHi(str.substr(2));
	else 
		return 0 + countHi(str.substr(1));
}

// countHi
// Without substring
// 5.54a - 6.00a - 6 mins
int countHiHelper(string& str, int st, int len) {
	if (len < 2)
		return 0;
	else if (str.at(st) == 'h' && str.at(st+1) == 'i')
		return 1 + countHiHelper(str, st+2, len-2);
	else 
		return 0 + countHiHelper(str, st+1, len-1);
}
int countHiNew(string str) {
	return countHiHelper(str, 0, str.length());
}

// changeXY
// without substring and do it in place
// 6.01a - 6.17a - 16 mins
string changeXYHelper(string& str, int st, int len) {
	if (len == 0)
		return str;
	else if (str.at(st) == 'x') {
		str.at(st) = 'y';
		return changeXYHelper(str, st+1, len-1);
	}
	else
		return changeXYHelper(str, st+1, len-1);
}
string changeXY(string str) {
	return changeXYHelper(str, 0, str.length());
}

// changePi
// 6.49a - 6.51a - 2mins
string changePi(string str) {
	if (str.length() < 2)
		return str;
	else if (str.at(0) == 'p' && str.at(1) == 'i')
		return "3.14" + changePi(str.substr(2));
	else 
		return str.at(0) + changePi(str.substr(1));
}

// noX
// 6.56a - 6.58a - 2 mins
string noX(string str) {
	if (str.length() == 0)
		return str;
	else if (str.at(0) == 'x')
		return noX(str.substr(1));
	else
		return str.at(0) + noX(str.substr(1));
}

// array6
// 6.59a - 7.03a - 4 mins
bool array6(vector<int> nums, int index) {
	if (nums.size() == index)
		return false;
	else if (nums[index] == 6)
		return true;
	else 
		return array6(nums, index+1);
}

// array11
// 7.04a-7.06a - 2 mins
int array11(vector<int> nums, int index) {
	if (nums.size() == index)
		return 0;
	else if (nums[index] == 11)
		return 1 + array11(nums, index+1);
	else
		return array11(nums, index+1);
}

// array220 - value followed by 10 times its value
// 7.06a-7.11a - 5 mins
bool array220(vector<int> nums, int index) {
	if (nums.size() < 2)
		return false;
	else if (index == nums.size()-1) 
		return false;
	else if (nums[index+1] == 10 * nums[index])
		return true;
	else
		return array220(nums, index+1);
}

// allStar - adjacent chars separate by *
// 7.11a - 7.14a - 3 mins
string allStar(string str) {
	if (str.length() < 2)
		return str;
	else 
		return str[0] + string("*") + allStar(str.substr(1));
}

// pairStar - identical chars are separated by *
// 6.24a - 6.28a - 4 mins
string pairStar(string str) {
	if (str.length() < 2) 
		return str;
	else if (str.at(0) == str.at(1))
		return str[0] + string("*") + pairStar(str.substr(1));
	else
		return str[0] + pairStar(str.substr(1));
}

// endX - all lowercase 'x' moved to end of string
// 6.28 - 6.32 - 4 mins
string endX(string str) {
	if (str.length() == 0)
		return str;
	else if (str.at(0) == 'x')
		return endX(str.substr(1)) + string("x");
	else 
		return str[0] + endX(str.substr(1));
}



// countPairs - count instances of char separated by a char
// 6.33p - 6.36p - 3 mins
int countPairs(string str) {
	if (str.length() < 3)
		return 0;
	else if (str.at(0) == str.at(2))
		return 1 + countPairs(str.substr(1));
	else
		return countPairs(str.substr(1));
}



// countAbc - count substrings abc and abc
// 6.36p - 7.05p - 30 mins
int countAbc(string str) {
	if (str.length() < 3)
		return 0;
	else if (str[0] == 'a' && str[1] == 'b' &&
			 (str[2] == 'a' || str[2] == 'c'))
		return 1 + countAbc(str.substr(1));
	else
		return countAbc(str.substr(1));
}



// count11 - number of non-overlapping 11
// 7.22p - 7.26p  - 4 mins
int count11(string str) {
	if (str.length() < 2)
		return 0;
	else if (str[0] == '1' && str[1] == '1')
		return 1 + count11(str.substr(2));
	else
		return count11(str.substr(1));
}

// stringClean / dedupe - adjacent chars that are same are deduped
// 7.26p- 7.29p - 3 mins
string stringClean(string str) {
	if (str.length() < 2)
		return str;
	else if (str[0] == str[1])
		return stringClean(str.substr(1));
	else
		return str[0] + stringClean(str.substr(1));
}

// countHi2 - xclude hi coming after x
// 9.06p - 9.19p - 13 mins
int countHi2(string str) {
	if (str.length() < 2)
		return 0;
	else if (str[0] == 'x' && str[1] == 'h' && str[2] == 'i')
		return countHi2(str.substr(3));
	else if (str[0] != 'x' && str[1] == 'h' && str[2] == 'i')
		return 1 + countHi2(str.substr(3));	
	else if (str[0] == 'h' && str[1] == 'i')
		return 1 + countHi2(str.substr(2));
	else
		return countHi2(str.substr(1)); 
}

// parenBit
// 9.30p - 9.44p - 14 mins
string parenBit(string str) {
	int len = str.length();
	if (len < 2)
		return "";
	else if (str[0] != '(' && str[len-1] != ')')
		return parenBit(str.substr(1, len-2));  // len-2 ?
	else if (str[0] == '(' && str[len-1] == ')')
		return str;
	else if (str[0] == '(')
		return parenBit(str.substr(0, len-1));
	else // str[len-1] == ')'
		return parenBit(str.substr(1, len-1));
}

// nestParen
// 9.45p - got stuck and took long time
bool nestParen(string str) {
	cout << "str - " << str << endl;
	int len = str.length();
	if (len < 2)
		return false;
	else if (str[0] == '(' && str[len-1] == ')')
		return true && nestParen(str.substr(1, len-2));
	// else if // no other characters in string ??
	else
		return false;
}

// strCount
// 6.03a - 6.16a - 13 mins
int strCount(string str, string sub) {
	if (str.length() < sub.length())
		return 0;
	
	std::size_t found  = str.find(sub);
	int len = sub.length();
	int next = found + len;
	cout << "found - " << found << " , next - " << next << " , len - " << len << endl;
	if (found != string::npos) 
		return 1 + strCount(str.substr(next), sub);
	else
		return strCount(str.substr(1), sub);
}


// strCopies
// 6.16a - 6.24a - 8 mins
bool strCopies(string str, string sub, int n) {
	if (str.length() < sub.length() && n > 0)
		return false;
	else if (n == 0)
		return true;
	else {
		size_t found = str.find(sub);
		if (found != string::npos)
			return strCopies(str.substr(found+1), sub, n-1);
		else
			return false; // can be false
	}
}

// strDist - largest substring starting and ending with sub
// 6.24a
int strDist(string str, string sub) {
	int len = str.length();
	int sublen = sub.length();
	if (len < sublen)
		return 0;
	// base case
	else if (str.substr(0, sublen) != sub && str.substr(len-sublen, sublen) != sub)
		return strDist(str.substr(1, len-2), sub);
	else if (str.substr(0, sublen) != sub)	
		return strDist(str.substr(1), sub);
	else if (str.substr(len-sublen, sublen) != sub)
		return strDist(str.substr(0, len-1), sub);
	else 
		return len;
}


int main() {
	string s1("x");
	cout << "s1 - " << s1 << endl;
	cout << "count - " << strDist(s1, "z") << endl;
	return 0;
}
