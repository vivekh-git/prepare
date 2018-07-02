#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int>& output) {
	//cout<< "print_arr - " << odx << endl;
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << ", ";
	}
	cout << endl;
}

void swap(vector<int>& arr, int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

/*
f(idx)
if (idx == len) 
  print output
else {
  for j = idx to len-1  {}
     swap(arr, j, idx);
     f(idx+1)
     swap(arr, idx, j);
  }
}
*/
// passing by value so that original stack is not popped
void permute(vector<int>& arr, int idx) {
	if (idx == arr.size()) {
		print_arr(arr);
	}
	else {
		for (int j = idx; j<arr.size(); j++) {
			swap(arr, j , idx);
			permute(arr, idx+1);
			swap(arr, idx, j);
		}
	}
}

int main() {
	vector<int> input = {1, 2, 3};
	permute(input, 0);
	return 0;
}