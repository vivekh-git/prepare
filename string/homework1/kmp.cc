#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * Complete the function below.
 */
bool KMP(string strText, string strPattern) {


}



int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    bool res;
    string _strText;
    getline(cin, _strText);
    
    string _strPattern;
    getline(cin, _strPattern);
    
    res = KMP(_strText, _strPattern);
    cout << res << endl;
    
    //fout.close();
    return 0;
}