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
float pow(float dblbase, int ipower) {
   if (ipower == 0) {
       return 1;
   }
   else if (ipower > 0) {
       float ret = pow(dblbase, ipower/2);
       if (ipower % 2 == 0) {
           return ret * ret;
       }
       else {
           return dblbase * ret * ret;
       }
   }
   else {
       return 1/pow(dblbase, -ipower);
   }
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    float res;
    float _dblbase;
    cin >> _dblbase;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _ipower;
    cin >> _ipower;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = pow(_dblbase, _ipower);
    cout << res << endl;
    
    //fout.close();
    return 0;
}
