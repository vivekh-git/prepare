#include <string>
#include <iostream>

using namespace std;

/*
 * Complete the function below.
 */


void swapstr(string& str, int pos1, int pos2) {
	char c = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = c;
}


string DutchFlagSort(string& str) {
	if (str.length() ==  0) return "";
	int rindex = 0 ;
	int bindex = str.length() - 1;
	
	int i = 0;
	while (i <= bindex) {   // < or <= <= is needed
		if (str[i] == 'R') {
			swapstr(str, i, rindex);
			rindex++; i++;
		}
		else if (str[i] == 'B') {
			swapstr(str, i, bindex);
			bindex--;
		}
		else {
			i++;
		}
	}
	return str;
}

int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _strColoredBalls;
    getline(cin, _strColoredBalls);
    
    res = DutchFlagSort(_strColoredBalls);
    cout << res << endl;
    
    //fout.close();
    return 0;
}