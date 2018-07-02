#include <iostream>
#include <vector>
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

// 92 45 67 41 74 28 87 8 67 15 59 
//                92
//           45        67
//        41    15   28  87
//      8  67 74 29
// a[4] - is the last node with children - 11/2 = 5, 11/2-1
// a[4] = 74 - l-9,r-10
void HeapifyDown(vector<int>& h, int& size, int k) {
	if (k > size/2 - 1) return;

	int left = 2*k+1;
	int right = 2*k+2;

    if (h[left] < h[right] && h[left] < h[k]) {
		swap(h, left, k);
		HeapifyDown(h, size, left);
    }
	else if (h[right] < h[k]) {
		swap(h, right, k);
		HeapifyDown(h, size, right);
	}
	// base case
	return;
}

void BuildHeap(vector<int>& h, int& size) {
	for (int i = size/2-1; i>=0; i--) {
		HeapifyDown(h, size, i);
	}
}

int getMin(vector<int>& h, int& size) {
	if (size > 0) {
		int ret = h[0];
		// move last element to root
		h[0] = h[size-1];
		size--;
		HeapifyDown(h, size, 0);
		return ret;
	}
	return -1;
}

void heap_sort(vector<int>& arr) {
	vector<int> buffer;
	int size = arr.size();
	BuildHeap(arr, size);
	while (size > 0) {
		int min = getMin(arr, size);
	    buffer.push_back(min);
	}
    for (int i=0; i < buffer.size(); i++) {
    	arr[i] = buffer[i];
    }
}



int main() {
  std::vector<int> arr  { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr2 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr3 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr4 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr5 { 45, 41, 28, 92, 74, 67, 87, 8, 67, 15, 59 };
  //selection_sort(arr);
  //bubble_sort(arr2);
  //insertion_sort(arr3);
  //merge_sort(arr4);
  print_arr(arr);
  heap_sort(arr);
  print_arr(arr);
  
  print_arr(arr2);
  heap_sort(arr2);
  print_arr(arr2);
  
  print_arr(arr3);
  heap_sort(arr3);
  print_arr(arr3);
  
  print_arr(arr4);
  heap_sort(arr4);
  print_arr(arr4);
  
  print_arr(arr5);
  heap_sort(arr5);
  //print_arr(arr);
  //print_arr(arr2);
  //print_arr(arr3);
  //print_arr(arr4);
  print_arr(arr5);

  //std::vector<std::string> arr6 {"vivek", "reya", "sudha", "hari", "ram", "ramesh"};
  //quick_sort(arr6);
  //print_arr(arr6);

  return 0;
}
