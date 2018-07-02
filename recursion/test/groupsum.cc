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

// start time - 8.05a
// end time - 8.15a
// total time - 10mins

/*
 * Complete the function below.
 */
bool groupSumR(vector<int>& arr, int idx, int target) {
	if (idx == arr.size()) {
		if (target == 0)
			return true;
		else 
			return false;
	}
	else {
		return groupSumR(arr, idx+1, target) || groupSumR(arr, idx+1, target- arr[idx]);
	}
}


bool groupSum(vector<int> arr, int target) {
	return groupSumR(arr, 0, target);
}


int main() {
    // ofstream fout(getenv("OUTPUT_PATH"));
    bool res;
    
    int _IntArr_size = 0;
    cin >> _IntArr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _IntArr;
    int _IntArr_item;
    for(int _IntArr_i=0; _IntArr_i<_IntArr_size; _IntArr_i++) {
        cin >> _IntArr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _IntArr.push_back(_IntArr_item);
    }
    
    int _iTarget;
    cin >> _iTarget;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = groupSum(_IntArr, _iTarget);
    cout << res << endl;
    
    //fout.close();
    return 0;
}