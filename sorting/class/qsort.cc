#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

int partition2(vector<int>& arr, int spos, int epos) {
	// use 2 pointers - both at start + 1
	int low = spos+1;
	int high = spos+1;
	while (high <= epos) {
		if (arr[high] < arr[spos]) {
			swap(arr, low, high);
			low++;
		}
		high++;
		
	}
	swap(arr, low-1, spos);
	return low-1;
}


int partition(vector<int>& arr, int spos, int epos) {
	// use 2 pointers - one at start + 1, one at end
	int low = spos + 1;
	int high = epos;
	while (low <= high) { // should we do equality - yes needed
		if (arr[low] < arr[spos]) {
			low++;
		}
		else {
			swap(arr, low, high);
			high--;
		}
	}
	swap(arr, spos, high);
	return high;
}


void qsort(vector<int>& arr, int spos, int epos) {
	if (epos > spos) { // terminating condition
		int pivot = partition2(arr, spos, epos);
		//recurse -- NEED terminating condition
		qsort(arr, spos, pivot-1);
		qsort(arr, pivot+1, epos);
	}
}

void quick_sort(vector<int>& arr) {
	qsort(arr, 0, arr.size()-1);
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
  quick_sort(arr);
  print_arr(arr);
  
  print_arr(arr2);
  quick_sort(arr2);
  print_arr(arr2);
  
  print_arr(arr3);
  quick_sort(arr3);
  print_arr(arr3);
  
  print_arr(arr4);
  quick_sort(arr4);
  print_arr(arr4);
  
  print_arr(arr5); cout << endl;
  quick_sort(arr5);
  //print_arr(arr);
  //print_arr(arr2);
  //print_arr(arr3);
  //print_arr(arr4);
  print_arr(arr5); cout << endl;

  //std::vector<std::string> arr6 {"vivek", "reya", "sudha", "hari", "ram", "ramesh"};
  //quick_sort(arr6);
  //print_arr(arr6);

  return 0;
}
