#include <bits/stdc++.h>
#include <functional>

using namespace std;

/*
 * Complete the function below.
 */
vector<int> topK(vector<int>& arr, int iK) {
	vector<int> output;
	priority_queue<int, vector<int>, std::greater<int>> q;
	
	int count = 0;
	while (count < arr.size()) {
		int element = arr[count];
		if (q.size() < iK) {
			q.push(element);
		}
		else if (element > q.top()) {
			q.pop();
			q.push(element);
		}
		count++;
	}
	while (! q.empty()) {
		output.push_back(q.top()); q.pop();
	}
    return output;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector <int> res;
    int iStream_size = 0;
    cin >> iStream_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> iStream;
    for(int i = 0; i < iStream_size; i++) {
        int iStream_item;
        cin >> iStream_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        iStream.push_back(iStream_item);
    }

    int iK;
    cin >> iK;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = topK(iStream, iK);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }

    //fout.close();
    return 0;
}