#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int start, int mid, int end, vector<int>& buffer) {
	buffer.clear();
	
	int low = start; int high = mid+1;
	while (low <= mid && high <= end) {
		if (arr[low] <= arr[high]) { // check for <= - this makes sort stable sort
			buffer.push_back(arr[low]); 
			low++;
		}
		else {
			buffer.push_back(arr[high]);
			high++;
		} 
	}
	while (low <= mid) {
		buffer.push_back(arr[low]);
		low++;
	}
	while (high <= end) { // right array still remaining
		buffer.push_back(arr[high]);
		high++;
	}
	int k = start; // copy only to relavant areas of arr (start is not always 0)
	for (int i = 0; i < buffer.size(); i++) {
		arr[k] = buffer[i];
		k++;
	}
}



void msort(vector<int>& arr, int start, int end, vector<int>& buffer) {
	if (end > start) { // terminating condition
		int mid = start + (end-start)/2;
		// recurse - need terminating condition
		msort(arr, start, mid, buffer);
		msort(arr, mid+1, end, buffer);
		merge(arr, start, mid, end, buffer);
	}
}


void merge_sort(vector<int>&arr) {
	vector<int> buffer;
	msort(arr, 0, arr.size()-1, buffer);
}

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
  merge_sort(arr);
  print_arr(arr);
  
  print_arr(arr2);
  merge_sort(arr2);
  print_arr(arr2);
  
  print_arr(arr3);
  merge_sort(arr3);
  print_arr(arr3);
  
  print_arr(arr4);
  merge_sort(arr4);
  print_arr(arr4);
  
  print_arr(arr5);
  merge_sort(arr5);
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
