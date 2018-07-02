
#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the function below.
 */
vector<uint16_t> precompute(void) {
	vector<uint16_t> table(65536);
	for (uint32_t i = 0; i <= 0xFFFF; i++) {
		uint16_t x = i;
		int count = 0;
		for (count = 0; x; count++) {
			x = x & (x-1);
		}
		table[i] = count;
	}
	return table;
}



int printCountOfBitsSet(vector<int>& arr) {
	vector<uint16_t> table = precompute();
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		int num = arr[i];
		sum = sum + table[num & 0xFFFF] + table[num >> 16];
	}
	return sum;
}

//uint16_t
// 65536 - 16 bit max 
// uint32_t


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    int intArr_size = 0;
    cin >> intArr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> intArr;
    for(int i = 0; i < intArr_size; i++) {
        int intArr_item;
        cin >> intArr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        intArr.push_back(intArr_item);
    }

    res = printCountOfBitsSet(intArr);
    cout << res << endl;

    //fout.close();
    return 0;
}