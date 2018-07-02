#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void swap(vector<int>& h, int pos1, int pos2) {
	int temp = h[pos1];
	h[pos1] = h[pos2];
	h[pos2] = temp; 
}

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void MaxHeapify(vector<int>& arr, int end) {
	int size = end+1;

	for (int i=(size/2)-1; i>=0; i--) {
		int left = 2*i + 1;
		int right = 2*i + 2;
		
		if (end >= right && arr[right] > arr[left]) {
			if (arr[right] > arr[i]) {
				swap(arr, right, i);
			}
		}
		else {
			if (arr[left] > arr[i]) {
				swap(arr, left, i);
			}
		}
	}
	//print_arr(arr);
}


// 92 45 67 41 74 28 87 8 67 15 59 
//                92
//           45        67
//        41    15   28  87
//      8  67 74 29
// a[4] - is the last node with children - 11/2 = 5, 11/2-1
// a[4] = 74 - l-9,r-10
void heap_sort(vector<int>& arr) {
	//print_arr(arr);
	int end = arr.size() - 1;
	while (end > 0) {
		MaxHeapify(arr, end);
		//print_arr(arr);
		swap(arr, 0, end);
		//cout << "after swapping " << endl;
		//print_arr(arr);
		end--;
	}
}

struct node {
	int value;
	int kindex;
	int arrindex;
	node(int v, int k, int ai): value(v), kindex(k), arrindex(ai) {}
	node() {}
	bool operator()(node& ln, node& rn) const {
		return (ln.value < rn.value);
	}
};

class nodecompare {
private:
	bool _reverse;
public:
	nodecompare(const bool& rev = false) {
		_reverse = rev;
	}
	bool operator()(node& ln, node& rn) const {
		if (_reverse) {
			// desc - maxheap
			// lesser is default - maxheap is default
			return (ln.value < rn.value);
		}
		else {
			// asc - minheap
			return (ln.value > rn.value); 
		}
	}
};


vector < int > mergearrays(vector < vector < int > > arr) {
	if (arr.empty()) return {};
	bool maxflag = false; // minheap
	vector<int> output;

	if (arr[0].size() > 1 && arr[0][1] < arr[0][0]) { // desc sort - maxheap
		maxflag = true;
	}

	priority_queue<node, vector<node>, nodecompare> q(maxflag);
	
	for (int k = 0; k < arr.size(); k++) {
		node n(arr[k][0], k, 1);
		q.push(n);
	}

    int count = 0;
	while (! q.empty()) {
		node top = q.top();
		q.pop();
		output.push_back(top.value); count++;
		
		node newnode;
		newnode.kindex = top.kindex;
		newnode.arrindex = top.arrindex + 1;
		if (top.arrindex < arr.at(top.kindex).size()) {
			newnode.value = arr.at(top.kindex)[top.arrindex];
			q.push(newnode);
		}
	}
	return output;
}


int main() {
    //ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;
    
    int _iarray_rows = 0;
    int _iarray_cols = 0;
    cin >> _iarray_rows >> _iarray_cols;
    vector< vector < int > > _iarray(_iarray_rows);
    for(int _iarray_i=0; _iarray_i<_iarray_rows; _iarray_i++) {
        for(int _iarray_j=0; _iarray_j<_iarray_cols; _iarray_j++) {
            int _iarray_tmp;
            cin >> _iarray_tmp;
            _iarray[_iarray_i].push_back(_iarray_tmp);
        }
    }
    
    res = mergearrays(_iarray);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	//fout << res[res_i] << endl;
		cout << res[res_i] << endl;
    }
    
    //fout.close();
    return 0;
}