#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void merge(vector<int>& arr, int start, int mid, int end, vector<int>& buffer) {
	buffer.clear();
	//print_arr(buffer);
	
	int low = start; 
	int high = mid+1;
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
	//cout << "buffer end - " << endl;
	//print_arr(buffer);
	
	int k = start; // copy only to relavant areas of output (start is not always 0)
	for (int i = 0; i < buffer.size(); i++) {
		arr[k] = buffer[i];
		k++;
	}
}



void msort(vector<int>& arr, int start, int end, vector<int>& buffer) {
	//cout << "msort, start-"<<start<<",end-"<<end<<endl;
	if (end > start) { // terminating condition
		int mid = start + (end-start)/2;
		// recurse - need terminating condition
		msort(arr, start, mid, buffer);
		msort(arr, mid+1, end, buffer);
		merge(arr, start, mid, end, buffer);
	}
}


vector<int> merge_sort(vector<int>&arr) {
	vector<int> output = arr;
	vector<int> buffer;
	msort(output, 0, output.size()-1, buffer);
	return output;
}



int main() {
  std::vector<int> arr  { 0, -1, -2, 5, 4 };

  //selection_sort(arr);
  //bubble_sort(arr2);
  //insertion_sort(arr3);
  //merge_sort(arr4);
  
  std::vector<int> out = merge_sort(arr);
  print_arr(arr);
  print_arr(out);


  //std::vector<std::string> arr6 {"vivek", "reya", "sudha", "hari", "ram", "ramesh"};
  //quick_sort(arr6);
  //print_arr(arr6);

  return 0;
}
