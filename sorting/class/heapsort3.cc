#include <bits/stdc++.h>

using namespace std;

void print_arr(vector<int>& arr) {
	for (int i=0; i< arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

class MinHeap {
private:
	vector<int> harr;
	//int heap_size;
	void heapify_down(int i) {
		int left = 2*i + 1;
		int right = 2*i + 2;
		int smallest = i;
		if (left < size()  && harr[left] < harr[smallest])
			smallest = left;
		if (right < size() && harr[right] < harr[smallest])
			smallest = right;
		if (smallest != i) {
			swap(harr, i, smallest);
			heapify_down(smallest);
		}
	}
	void heapify_up(int i) {
		int parent = (i-1)/2;
		// check if node at i and its parent viloate heap property
		if (i && harr[parent] > harr[i]) {
			swap(harr, parent, i);
			heapify_up(parent);
		}
	}
public:
	MinHeap() {}
	/*
	MinHeap(vector<int>& arr) {
		harr = arr;
		heap_size = arr.size();
        for (int i = heap_size/2-1; i >= 0; i--) {
        	Heapify(i);
        }
	}
	*/
	int size() {
		return harr.size();
	}
	bool empty() {
		return size() == 0;
	}
	void insert(int x) { // you can call push as well
		// insert at the end and heapify_up
		harr.push_back(x);
		heapify_up(size()-1);
	}
	void decreaseKey(int i, int new_val) {
		if (i >= size()) return;
		harr[i] = new_val;
		heapify_up(i);
	}	
	int getMin() {
		if (size() == 0) return -1;
		return harr[0];
	}
	int extractMin() {
		if (size() <= 0) return INT_MAX;
		int root = harr[0];
		harr[0] = harr.back();
		harr.pop_back();
		heapify_down(0);
		return root;
	}
	int replaceMin(int x) {
		if (size() == 0) return -1;
		int root = harr[0];
		harr[0] = x;
		if (x > root)
			heapify_down(0);
		return root;
	}
	void deleteKey(int i) {
		if (i >= size()) return;
		decreaseKey(i, INT_MIN);
		extractMin();
	}
	void print_arr() {
		for (int i = 0; i < size(); i++)
			cout << harr[i] << " ";
		cout << endl;
	}
};

void test(vector<int>& arr) {
    //vector<int> harr;
	MinHeap mh;
	for (int i = 0; i < 2; i++)
		mh.insert(arr[i]);
	mh.print_arr();
	mh.deleteKey(1);
	for (int i = 2; i < 6; i++)
		mh.insert(arr[i]);
	cout << "extractMin - " << mh.extractMin() << endl;
	cout << "getMin - " << mh.getMin() << endl;
	mh.decreaseKey(2,1);
	cout << "getMin - " << mh.getMin() << endl;
}

// kth largest element
// Sort only k largest elements in array
void sortK(vector<int>& arr, int k) {
    //vector<int> harr;
	MinHeap mh;
	for (int i = 0; i <= k && i < arr.size(); i++)
		mh.insert(arr[i]);
	
	int index = 0;
	for (int i = k+1; i < arr.size(); i++) {
		arr[index++] = mh.replaceMin(arr[i]);
	}
	while (index < arr.size()) {
		arr[index++] = mh.extractMin();
	}
}

// kth largest element
// Sort only k largest items in array
void sortKSortedArray(vector<int>& arr, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i <= k; i++) {
		pq.push(arr[i]);
	}
	int index = 0;
	for (int i = k+1; i < arr.size(); i++) {
		arr[index++] = pq.top(); pq.pop();
		pq.push(arr[i]);
	}
	while (!pq.empty()) {
		arr[index++] = pq.top(); pq.pop();
	}
}



int main() {
  vector<int> arr  { 2, 6, 3, 12, 56, 8}; int k = 3;
  sortK(arr, k);
  //sortKSortedArray(arr, k);
  print_arr(arr);
  
  vector<int> a = {3,2,15,5,4,45};
  test(a);
  print_arr(a);
  
  vector<int> arr2 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  vector<int> arr3 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  vector<int> arr4 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  vector<int> arr5 { 45, 41, 28, 92, 74, 67, 87, 8, 67, 15, 59 };

  
  return 0; 
}