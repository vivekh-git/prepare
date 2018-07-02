#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class MaxQueue {
private:
	queue<int> _q;
	queue<int> _mq;
public:
	// push_back
	void push(int n) {
		_q.push(n);
		while (!_mq.empty() && _mq.front() < n)
			_mq.pop();
		_mq.push(n);
	}
	// pop_front
	void pop() {
		if (!_q.empty()) {
			if (_q.front() == _mq.front())
				_mq.pop();
			_q.pop();
		}
	}
	int front() {
		if (!_q.empty())
			return _q.front();
		else 
			return -1;
	}
	int back() {
		if (!_q.empty())
			return _q.back();
		else
			return -1;
	}
	int getMax() {
		if (!_mq.empty()) return _mq.front();
		else return -1;
	}
};

vector<int> max_in_sliding_window(vector<int>& arr, int w) {
    if (arr.empty()) return {};
    deque<int> q;
    deque<int> mq;
    vector<int> result;
    int i = 0;
    // 1, 3, -1, -3, 5, 6, 7, w = 3
    // q:  -3, 5, 6 
    // mq: 6
    // result: 3, 3, 5, 6
    for (i = 0; i < arr.size() && i < w; i++) {
        q.push_back(arr[i]);
        while (!mq.empty() && mq.back() < arr[i])
            mq.pop_back();
        mq.push_back(arr[i]);
    }
    result.push_back(mq.front());
    for (; i < arr.size(); i++) {
        if (q.front() == mq.front())
            mq.pop_front();
        q.pop_front();
        q.push_back(arr[i]);
        while (!mq.empty() && mq.back() < arr[i])
            mq.pop_back();
        mq.push_back(arr[i]);
        result.push_back(mq.front());
    }
    return result;
}

// 3
// 1, 3, 5, 5, 10, 2, 8, 3, 1, 2
// 5, 5, 10, 10, 10, 8, 8, 3
int main() {
	ofstream fout(getenv("OUTPUT_PATH"));

	int window = 0;
	string wstr;
	getline(cin, wstr);
    stringstream wss(wstr);
	wss >> window;
	//cout << "window - " << window << endl;

	string str;
	getline(cin, str);
    vector<int> vect;
    stringstream ss(str);
    int i;
    while (ss >> i) {
		vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
	
    MaxQueue ms;
    for (i=0; i< vect.size(); i++) {
		if (i >= window) {
			if (i > 3) { 
				fout << ","; 
				//cout << ","; 
			}
			fout << ms.getMax();
			//cout << ms.getMax();
			ms.pop();
			ms.push(vect.at(i));
		}
		else {
			ms.push(vect.at(i));
		}	
	}
	if (i > window) {
		fout << ","; 
		//cout << ",";
	}
	fout << ms.getMax();
	//cout << ms.getMax();
	//cout << endl;
	
	fout.close();
	return 0;

}
