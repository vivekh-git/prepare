#include <iostream>

using namespace std;

// approach was right
int findMissingNumber(vector<int> iList) {
	int n = iList.size() + 1;
	int realsum = n * (n+1)/2 ;
	int actualsum = 0;
	for (int j=0; j< iList.size(); j++) {
		actualsum += iList[j];
	}
    return realsum - actualsum;
}


int main() {
	vector
	
}