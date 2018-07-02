#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int pos1, int pos2) {
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

void print_arr(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(vector<int>& arr, int pivot, int start, int end) {
	int low = start;
	int high = start;
	while (high < end) {
		if (arr[high] <  pivot) {
			swap(arr, low, high);
			low++; high++;
		}
		else if (arr[high] == pivot) {
			swap(arr, end, high);
		}
		else {
			high++;
		}
	}
	swap(arr, end, low);
	// print_arr(arr);
	return low;
}


void qsort(vector<int>& nuts, vector<int>& bolts, int start, int end) {
	if (end > start) {
		int p1 = partition(nuts, bolts[start], start, end); // pass bolts[start] and not bolts[0]
		int p2 = partition(bolts, nuts[p1], start, end);
		qsort(nuts, bolts, start, p1-1);
		qsort(nuts, bolts, p1+1, end);
		return;
	}
}

void print_matching_nuts_and_bolts(vector<int>& nuts, vector<int>& bolts) {
	qsort(nuts, bolts, 0, nuts.size()-1);
	print_arr(nuts);
	print_arr(bolts);
}

int main() {
  std::vector<int> nuts  { 92, 45, 67, 41, 74, 28, 87, 8, 15, 59 };
  std::vector<int> bolts { 59, 8, 28, 41, 45, 92, 67, 74, 87, 15 };
  
  print_matching_nuts_and_bolts(nuts, bolts);

  return 0;
}
